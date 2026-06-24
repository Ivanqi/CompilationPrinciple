// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
use std::error::Error;

use crate::ir::{SSAOperator, CFG};

pub fn optimization_sequence(ssa: &mut CFG<SSAOperator>) -> Result<(), Box<dyn Error>> {
    gvn_pre::optimize(ssa);
    copy_propagation::optimize(ssa);
    #[cfg(feature = "print-cfgs")]
    {
        println!("After optimization:\n{}", ssa.to_dot());
    }
    Ok(())
}

pub mod gvn_pre {
    #![allow(clippy::too_many_arguments)]
    use std::collections::{HashMap, HashSet, LinkedList};

    use crate::ir::{Block, Operator, SSAOperator, VReg, VRegGenerator, CFG};

    pub fn optimize(cfg: &mut CFG<SSAOperator>) {
        let (mut leaders, antileaders, phigen, mut value_table) = build_sets(cfg);
        insert(cfg, &mut leaders, &antileaders, &phigen, &mut value_table);
        eliminate(cfg, &leaders, &mut value_table);
        #[cfg(feature = "print-cfgs")]
        {
            println!("After gvn-pre:\n{}", cfg.to_dot());
        }
    }

    type Value = usize;
    #[derive(Clone, Debug, PartialEq, Eq, Hash)]
    enum Expression {
        Plus(Value, Value),
        Sub(Value, Value),
        Mult(Value, Value),
        Div(Value, Value),
        And(Value, Value),
        Or(Value, Value),
        Xor(Value, Value),
        Mv(Value),
        Immediate(i64),
        /// Reg only appears in exp_gen/antileaders if the expression that generated Reg isn't numbered.
        Reg(VReg),
        Phi(Vec<VReg>),
    }
    impl Expression {
        // 表达式规范化（Canonicalization）算法
        // 是GVN-PRE（全局值编号与部分冗余消除）算法的关键组成部分
        fn canon(self) -> Self {
            match self {
                Expression::Plus(v1, v2) => {
                    // 原始表达式：Plus(10, 5)
                    // let expr = Expression::Plus(10, 5);
                    // let canon_expr = expr.canon();
                    // 规范化后：Plus(5, 10)
                    Expression::Plus(std::cmp::min(v1, v2), std::cmp::max(v1, v2))
                }
                Expression::Mult(v1, v2) => {
                    Expression::Mult(std::cmp::min(v1, v2), std::cmp::max(v1, v2))
                }
                Expression::And(v1, v2) => {
                    Expression::And(std::cmp::min(v1, v2), std::cmp::max(v1, v2))
                }
                Expression::Or(v1, v2) => {
                    Expression::Or(std::cmp::min(v1, v2), std::cmp::max(v1, v2))
                }
                Expression::Xor(v1, v2) => {
                    Expression::Xor(std::cmp::min(v1, v2), std::cmp::max(v1, v2))
                }
                e => e,
            }
        }
        fn depends_on(&self) -> Vec<Value> {
            match self {
                Expression::Sub(v1, v2)
                | Expression::Mult(v1, v2)
                | Expression::Div(v1, v2)
                | Expression::And(v1, v2)
                | Expression::Or(v1, v2)
                | Expression::Xor(v1, v2)
                | Expression::Plus(v1, v2) => vec![*v1, *v2],
                Expression::Mv(v1) => vec![*v1],
                _ => vec![],
            }
        }
        fn is_simple(&self) -> bool {
            matches!(self, Expression::Reg(_))
        }
        fn to_instruction(&self, leaders: &HashMap<Value, VReg>, rec: VReg) -> SSAOperator {
            macro_rules! generate_instr {
                ($t:path, $($x:expr),+) => {
                    SSAOperator::IROp($t(rec, $(*leaders.get($x).unwrap()),+))
                };
            }
            match self {
                Expression::Plus(x, y) => generate_instr!(Operator::Add, x, y),
                Expression::Sub(x, y) => generate_instr!(Operator::Sub, x, y),
                Expression::Mult(x, y) => generate_instr!(Operator::Mult, x, y),
                Expression::Div(x, y) => generate_instr!(Operator::Div, x, y),
                Expression::And(x, y) => generate_instr!(Operator::And, x, y),
                Expression::Or(x, y) => generate_instr!(Operator::Or, x, y),
                Expression::Xor(x, y) => generate_instr!(Operator::Xor, x, y),
                Expression::Mv(x) => generate_instr!(Operator::Mv, x),
                Expression::Immediate(i) => SSAOperator::IROp(Operator::Li(rec, *i)),
                Expression::Reg(_) => panic!("No instruction for reg value representation"),
                Expression::Phi(_) => panic!("No instruction for phi value representation"),
            }
        }
    }
    struct ValueTable {
        expressions: HashMap<Expression, Value>,
        number: Value,
        blackbox_regs: HashSet<VReg>,
    }
    impl ValueTable {
        fn new() -> Self {
            Self {
                expressions: HashMap::new(),
                number: 5,
                blackbox_regs: HashSet::new(),
            }
        }

        // 全局值编号表（ValueTable）的表达式插入逻辑，是GVN-PRE算法的核心
        // 假设当前状态：
        // expressions: {}
        // number: 5
        // 处理过程：
        // 1. 规范化：Plus(10, 5) → Plus(5, 10)
        // 2. 检查HashMap：没有Plus(5, 10)条目
        // 3. 插入新条目：Plus(5, 10) → 5
        // 4. number递增：6
        // 5. 返回值：5
        fn maybe_insert(&mut self, exp: Expression) -> Value {
            // 确保交换律运算获得相同形式
            // Plus(10, 5) → Plus(5, 10)
            // Plus(5, 10) → Plus(5, 10)
            let canon = exp.canon();
            // 使用规范化表达式作为键
            // 相同的表达式获得相同的键
            let entry = self.expressions.entry(canon);
            // 如果键不存在：插入新条目，使用当前number
            // 如果键已存在：返回现有值编号
            let value = *entry.or_insert(self.number);
            // 只有插入新条目时才递增
            // 确保每个新表达式获得唯一编号
            self.number += 1;
            value
        }
        
        /// GVN-PRE算法中强制插入表达式映核心方法
        /// 用于建立表达式到值编号的确定性映射关系
        fn insert_with(&mut self, exp: Expression, val: Value) {
            /// 1. 规范化表达式：确保交换律运算获得相同形式
            /// 例如：Plus(10, 5) → Plus(5, 10)
            let canon = exp.canon();

            /// 2. 插入映射：将规范化表达式映射到指定的值编号
            ///     HashMap::insert返回之前的值（如果存在）
            let res = self.expressions.insert(canon, val);

            /// 3. 断言检查：确保映射的一致性
            ///    条件：要么之前没有这个表达式（res.is_none()）
            ///          要么之前的值和现在要插入的值相同（res.unwrap() == val）
            let assertion = res.is_none() || res.unwrap() == val;
            debug_assert!(assertion);
        }

        /// 全局值编号表（ValueTable）的指令插入逻辑
        /// 是GVN-PRE（全局值编号与部分冗余消除）算法的核心部分
        fn maybe_insert_op(
            &mut self,
            op: &SSAOperator,
            exp_gen: &mut LinkedList<(Value, Expression)>,
            added_exps: &mut HashSet<Value>,
        ) -> Result<(Value, Option<VReg>, Expression), Option<VReg>> {
            macro_rules! value_regs {
                ($($x: expr),+) => {
                {
                    ($({
                    let new = Expression::Reg(*$x);
                    // 2. 黑盒寄存器(blackbox_regs)
                    // 标记无法进行值编号的寄存器
                    if !self.expressions.contains_key(&new) {
                        self.blackbox_regs.insert(*$x);
                    }
                    // 3. 部分冗余消除
                    // 通过值编号识别冗余计算
                    // 果表达式已存在，返回相同的值编号
                    let val = self.maybe_insert(new);
                    if !added_exps.contains(&val) {
                        // 1. 表达式生成集(exp_gen)
                        // 用于记录每个基本块生成的表达式
                        exp_gen.push_back((val, Expression::Reg(*$x)));
                        added_exps.insert(val);
                    }
                    val}
                    ),+)
                }
                };
            }
            let res = match op {
                SSAOperator::IROp(op) => match op {
                    // 示例1：加法指令处理
                    // 原始指令： add rd3, rd1, rd2
                    Operator::Add(rec, x, y) => {
                        // 源寄存器处理
                        // 假设 rd1=4, rd2=5
                        // 创建寄存器表达式: Reg(4), Reg(5)
                        // 插入值编号表，假设得到值编号：x=10, y=11
                        let (x, y) = value_regs!(x, y); // 处理源寄存器
                        // 规范化：确保操作数顺序一致
                        let res = Expression::Plus(x, y).canon(); // 创建表达式
                        // 检查表达式是否已存在，如果不存在则分配新编号
                        // 假设分配值编号：12
                        let new = self.maybe_insert(res.clone()); // 插入值编号表
                        // 建立寄存器rd3到值编号12的映射
                        self.insert_with(Expression::Reg(*rec), new); // 建立寄存器映射
                        Ok((new, Some(*rec), res))
                    }
                    Operator::Sub(rec, x, y) => {
                        let (x, y) = value_regs!(x, y);
                        let res = Expression::Sub(x, y).canon();
                        let new = self.maybe_insert(Expression::Sub(x, y));
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    Operator::Mult(rec, x, y) => {
                        let (x, y) = value_regs!(x, y);
                        let res = Expression::Mult(x, y).canon();
                        let new = self.maybe_insert(Expression::Mult(x, y));
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    Operator::Div(rec, x, y) => {
                        let (x, y) = value_regs!(x, y);
                        let res = Expression::Div(x, y).canon();
                        let new = self.maybe_insert(Expression::Div(x, y));
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    Operator::And(rec, x, y) => {
                        let (x, y) = value_regs!(x, y);
                        let res = Expression::And(x, y).canon();
                        let new = self.maybe_insert(Expression::And(x, y));
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    Operator::Or(rec, x, y) => {
                        let (x, y) = value_regs!(x, y);
                        let res = Expression::Or(x, y).canon();
                        let new = self.maybe_insert(Expression::Or(x, y));
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    Operator::Xor(rec, x, y) => {
                        let (x, y) = value_regs!(x, y);
                        let res = Expression::Xor(x, y).canon();
                        let new = self.maybe_insert(Expression::Xor(x, y));
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    // 示例2：立即数指令处理
                    // 原始指令：li rd1, 42
                    Operator::Li(rec, x) => {
                        // 立即数表达式
                        // 创建立即数表达式
                        let res = Expression::Immediate(*x).canon();
                        // 值编号分配
                        // 检查42是否已存在，假设分配值编号：13
                        let new = self.maybe_insert(Expression::Immediate(*x));
                        // 寄存器映射
                        // 建立寄存器rd1到值编号13的映射
                        self.insert_with(Expression::Reg(*rec), new);
                        Ok((new, Some(*rec), res))
                    }
                    Operator::Mv(rec, x) => {
                        let x = value_regs!(x);
                        let res = Expression::Mv(x).canon();
                        self.insert_with(Expression::Mv(x), x);
                        self.insert_with(Expression::Reg(*rec), x);
                        Ok((x, Some(*rec), res))
                    }
                    Operator::Return(x) => {
                        let new = value_regs!(x);
                        Ok((new, None, Expression::Reg(*x)))
                    }
                    //unsupported; kill sets
                    Operator::Load(x, _, _)
                    | Operator::LoadLocal(x, _)
                    | Operator::La(x, _)
                    | Operator::Slt(x, _, _)
                    | Operator::Call(x, _, _)
                    | Operator::GetParameter(x, _) => Err(Some(*x)),
                    _ => Err(None),
                },
                SSAOperator::Phi(rec, operands) => {
                    let res = Expression::Phi(operands.clone()).canon();
                    let new = self.maybe_insert(Expression::Phi(operands.clone()));
                    self.insert_with(Expression::Reg(*rec), new);
                    return Ok((new, Some(*rec), res)); //skip adding to exp_gen
                }
            };
            if let Ok((val, _, exp)) = &res {
                if !added_exps.contains(val) {
                    added_exps.insert(*val);
                    exp_gen.push_back((*val, exp.clone()));
                }
            }
            res
        }
    }

    type LeaderSet = Vec<HashMap<Value, VReg>>;
    type AntileaderSet = Vec<LinkedList<(Value, Expression)>>;
    type PhiGen = Vec<HashMap<Value, VReg>>;

    /// build_sets_phase1 函数是GVN-PRE算法的关键第一步
    /// 负责构建四个核心数据结构，为后续的可用表达式分析和部分冗余消除提供基础
    fn build_sets_phase1(
        cfg: &CFG<SSAOperator>,
        current: usize,
        exp_gen: &mut Vec<LinkedList<(Value, Expression)>>, // 表达式生成集
        phi_gen: &mut PhiGen,   // Phi函数信息
        tmp_gen: &mut Vec<HashSet<VReg>>, // 临时变量kill集
        // 领导者映射表。用于记录每个基本块中值编号到寄存器的映射关系
        leaders: &mut LeaderSet, 
        table: &mut ValueTable,
    ) {
        let block = cfg.get_block(current);
        let mut added_exps = HashSet::new();
        
        // 1. 处理当前基本快的所有指令
        for op in &block.body {
            match table.maybe_insert_op(op, &mut exp_gen[current], &mut added_exps) {
                Ok((val, Some(reg), exp)) => {
                    // 成功插入表达式
                    leaders[current].entry(val).or_insert(reg);
                    if let Expression::Phi(_) = exp {
                        phi_gen[current].entry(val).or_insert(reg);
                    }
                }
                Err(Some(killed)) => {
                    // 不支持的操作，标记kill的寄存器
                    // 防止这些寄存器参与后续的表达式分析
                    tmp_gen[current].insert(killed);
                }
                _ => {}
            }
        }

        // 2. 递归处理支配子节点
        for dom_child in block.idom_of.clone() {
            // 领导者信息从支配者传播到被支配者
            // 确保公共表达式在支配路径上的一致性
            leaders[dom_child] = leaders[current].clone();
            build_sets_phase1(cfg, dom_child, exp_gen, phi_gen, tmp_gen, leaders, table);
        }
    }

    /// Phi函数翻译（Phi Translation），是GVN-PRE算法中处理SSA形式Phi函数的关键部分
    /// 该函数的主要目的是将后继基本块的 antic_in 集合(预期可用的表达式集合)中的表达式
    /// 通过当前基本快与后继基本块之间的phi函数进行翻译
    /// 得到在当前基本块中可用的表达式集合
    fn phi_translate(
        // 一个HashMap，映射从值编号（Value）到Phi函数结果寄存器（VReg） 
        // 它标识了哪些值编号对应Phi函数    
        phi_gen: &HashMap<Value, VReg>,
        // 后继基本块的antic_in集合
        // 是一个链表，每个元素是一个值编号和表达式的对（Value, Expression）。
        antic_in_succ: &LinkedList<(Value, Expression)>,
        // 后继基本块（子节点）的SSA形式基本块
        child: &Block<SSAOperator>,
        // 当前基本块的索引
        current: usize,
        // 全局值编号表，用于管理值编号和表达式的映射
        value_table: &mut ValueTable,
    ) -> LinkedList<(Value, Expression)> {
        // result：用于存储翻译后的结果（值编号和表达式对）
        let mut result = LinkedList::new();
        // translated：记录翻译映射关系，将原始值编号映射到翻译后的新值编号
        let mut translated = HashMap::new();

        // 遍历后继基本块的antic_in集合
        // 对于后继基本块中每个预期可用的表达式，分为两种情况处理
        for (val, exp) in antic_in_succ {
            // 值编号对应Phi函数，需要翻译
            if let Some(&reg) = phi_gen.get(val) {
                // 情况1：值编号对应Phi函数，需要翻译
                // 检查值编号是否对应phi函数
                // phi_gen 存储值编号到phi 函数结果寄存器的映射
                let child_block = child;
                
                // 定位当前基本块在子节点前驱列表中的位置
                // 这个索引用于确定Phi函数中对应当前前驱的操作数
                let self_index = child_block
                    .preds
                    .iter()
                    .position(|&blk| blk == current)
                    .unwrap();

                let mut iter = child_block.body.iter();

                // 遍历子基本块中的Phi指令，找到结果寄存器匹配的Phi函数。
                while let Some(SSAOperator::Phi(rec, vec)) = iter.next() {
                    if *rec == reg {
                        // 获取翻译后的寄存器并分配新值编号
                        // 从Phi函数中取出对应前驱的操作数（寄存器）
                        // 然后为这个寄存器表达式分配一个新的值编号。
                        let translated_reg = vec[self_index];
                        // 获取当前前驱对应的操作数
                        // 为翻译后的寄存器分配新值编号
                        // 记录翻译映射关系
                        let translated_val =
                            value_table.maybe_insert(Expression::Reg(translated_reg));
                        result.push_back((translated_val, Expression::Reg(translated_reg)));
                        translated.insert(*val, translated_val);
                    }
                }
            } else {
                // 情况2：普通表达式，可能需要递归翻译操作数
                macro_rules! maybe_translate {
                        ($t:path, $($x:expr),+) => {
                            $t($(if let Some(new) = translated.get($x) {*new} else {*$x}),+)
                        }
                    }
                let updated = match exp {
                    Expression::Plus(x, y) => maybe_translate!(Expression::Plus, x, y),
                    Expression::Sub(x, y) => maybe_translate!(Expression::Sub, x, y),
                    Expression::Mult(x, y) => maybe_translate!(Expression::Mult, x, y),
                    Expression::Div(x, y) => maybe_translate!(Expression::Div, x, y),
                    Expression::And(x, y) => maybe_translate!(Expression::And, x, y),
                    Expression::Or(x, y) => maybe_translate!(Expression::Or, x, y),
                    Expression::Xor(x, y) => maybe_translate!(Expression::Xor, x, y),
                    Expression::Phi(..) => continue,
                    e => e.clone(),
                };
                let updated_val = value_table.maybe_insert(updated.clone());
                result.push_back((updated_val, updated));
                translated.insert(*val, updated_val);
            }
        }
        result
    }

    /// GVN-PRE算法的第二遍集合构建阶段，负责计算可用表达式集合（Anticipated Expressions）
    /// 这是GVN-PRE算法的核心部分，用于识别部分冗余表达式
    fn build_sets_phase2(
        cfg: &CFG<SSAOperator>,
        current: usize,
        changed: &mut bool,
        antic_out: &mut Vec<LinkedList<(Value, Expression)>>,
        antic_in: &mut Vec<LinkedList<(Value, Expression)>>,
        exp_gen: &Vec<LinkedList<(Value, Expression)>>,
        tmp_gen: &Vec<HashSet<VReg>>,
        phi_gen: &Vec<HashMap<Value, VReg>>,
        value_table: &mut ValueTable,
    ) {
        let block = cfg.get_block(current);

        // 1. 递归处理支配子节点.确保子节点先于父节点处理
        //  保证数据流分析的收敛性
        for &child in &block.idom_of {
            build_sets_phase2(
                cfg,
                child,
                changed,
                antic_out,
                antic_in,
                exp_gen,
                tmp_gen,
                phi_gen,
                value_table,
            );
        }
        #[allow(clippy::comparison_chain)]
        // 2. 计算antic_out[current]
        // println!("build_sets_phase2 - block.children : {:#?}", block.children);
        if block.children.len() > 1 {
            // 分支节点：取所有子节点antic_in的交集
            let potential_out = &antic_in[block.children[0]];
            let mut result = LinkedList::new();
            let rest = block.children[1..].iter().map(|child| &antic_in[*child]);
            // 取所有子节点antic_in的交集
            // 只有所有分支都可用的表达式才能在分支前可用
            for (val, exp) in potential_out {
                // 对于每个表达式(val, exp)
                // 检查是否所有子节点都包含这个值编号(val)
                if rest
                    .clone()
                    .map(|child_exp| child_exp.iter().map(|t| t.0).any(|v| v == *val))
                    .all(|b| b)
                {
                    result.push_back((*val, exp.clone()))
                };
            }
            if antic_out[current] != result {
                *changed = true;
            }
            antic_out[current] = result;
        } else if block.children.len() == 1 {
            // 单后继节点：进行phi翻译
            let child = block.children[0];
            let antic_in_succ = &antic_in[child];
            // 进行phi翻译，处理SSA形式的Phi函数
            let result = phi_translate(
                &phi_gen[child],
                antic_in_succ,
                cfg.get_block(child),
                current,
                value_table,
            );
            if antic_out[current] != result {
                *changed = true;
            }
            antic_out[current] = result;
        }
        // println!("bsp2 - current: {:#?}", current);
        // 3. 计算antic_in[current]
        let mut killed = HashSet::new();
        let cleaned = exp_gen[current]
            .iter()
            .chain(antic_out[current].iter())
            .filter_map(|(val, exp)| {
                // 检查依赖是否被kill
                for dependency in exp.depends_on() {
                    if killed.contains(&dependency) {
                        killed.insert(*val);
                        return None;
                    }
                }

                // 检查寄存器是否被kill
                if let Expression::Reg(r) = exp {
                    if tmp_gen[current].contains(r) {
                        killed.insert(*val);
                        return None;
                    }
                }
                Some((*val, exp.clone()))
                // not needed because exp already contains and overwrites any regs in antic_out!
                // if let Some(updated) = tmp_gen[current].get(val) {
                //     Some((*val, updated.clone()))
                // } else {
                //     Some((*val, exp.clone()))
                // }
            });
        let mut added = HashSet::new();
        let mut result = LinkedList::new();
        for v in cleaned {
            if !added.contains(&v.0) {
                added.insert(v.0);
                result.push_back(v);
            }
        }
        if antic_in[current] != result {
            *changed = true;
        }
        antic_in[current] = result;
    }

    /// 这段代码实现了全局值编号表（ValueTable）的生成
    /// 是GVN-PRE算法的核心数据结构构建阶段
    fn generate_value_table(cfg: &mut CFG<SSAOperator>) -> ValueTable {
        let mut value_table = ValueTable::new(); //  全局值编号表

        // 取支配树的逆后序遍历（RPO）
        let mut rpo = cfg.get_dom_rpo();
        // println!("rpo: {:#?}", rpo);

        // 按逆后序遍历所有基本块
        while let Some(next) = rpo.pop() {
            let block = cfg.get_block(next);
            // 处理块中的每条指令
            for op in &block.body {
                // 将指令插入到值编号表中
                println!("op: {:#?}", op);
                let _ =
                    value_table.maybe_insert_op(op, &mut LinkedList::new(), &mut HashSet::new());
            }
        }

        // 调试输出：显示值编号表的分组情况
        #[cfg(feature = "print-gvn")]
        {
            let partitioned = value_table.expressions.iter().fold(
                HashMap::<Value, HashSet<Expression>>::new(),
                |mut map, (k, v)| {
                    map.entry(*v).or_default().insert(k.clone());
                    map
                },
            );
            println!("GVN:\n{:?}", partitioned);
        }
        value_table
    }

    /// 码实现了GVN-PRE（全局值编号与部分冗余消除）算法
    /// 实现了GVN-PRE算法的集合构建阶段，负责计算四个关键数据结构
    ///     1. LeaderSet：每个基本块中的值到寄存器的映射
    ///     2. AntileaderSet：每个基本块的可用表达式集合
    ///     3. PhiGen：Phi函数生成信息
    ///     4. ValueTable：全局值编号表
    fn build_sets(cfg: &mut CFG<SSAOperator>) -> (LeaderSet, AntileaderSet, PhiGen, ValueTable) {
        // 阶段1：生成全局值编号表
        let mut value_table = generate_value_table(cfg);
        println!("value_table1: {:#?}", value_table.expressions);

        // 阶段2：初始化数据结构
        let mut exp_gen = vec![LinkedList::default(); cfg.len()]; // 表达式生成集合
        let mut tmp_gen = vec![HashSet::default(); cfg.len()];  // 临时变量生成集合
        let mut phi_gen = vec![HashMap::default(); cfg.len()]; // Phi函数生成集合
        let mut leaders = vec![HashMap::default(); cfg.len()]; // 领导者集合
        
        // 阶段3：第一遍构建集合()
        build_sets_phase1(
            cfg,
            cfg.get_entry(),
            &mut exp_gen,
            &mut phi_gen,
            &mut tmp_gen,
            &mut leaders,
            &mut value_table,
        );
        #[cfg(feature = "print-gvn")]
        {
            println! {"exp_gens: \n{:?}\n", exp_gen};
            println! {"tmp_gen: \n{:?}\n", tmp_gen};
            println! {"phi_gens: \n{:?}\n", phi_gen};
            println! {"leaders: \n{:?}\n", leaders};
        }

        // 阶段4：第二遍构建集合（迭代计算可用表达式）
        let mut changed = true;
        let mut antic_out = vec![LinkedList::default(); cfg.len()];
        let mut antic_in = vec![LinkedList::default(); cfg.len()];

        while changed {
            changed = false;
            build_sets_phase2(
                cfg,
                cfg.get_entry(),
                &mut changed,
                &mut antic_out,
                &mut antic_in,
                &exp_gen,
                &tmp_gen,
                &phi_gen,
                &mut value_table,
            );
        }
        #[cfg(feature = "print-gvn")]
        {
            println! {"antic_in: \n{:?}\n", antic_in};
        }
        // 阶段5：返回构建的四个集合
        (leaders, antic_in, phi_gen, value_table)
    }

    /// insert 函数实现了 GVN-PRE 算法的插入阶段
    /// 负责将部分冗余计算提升到更早的位置，并插入必要的phi函数
    fn insert(
        cfg: &mut CFG<SSAOperator>,
        leaders: &mut LeaderSet,
        antileaders: &AntileaderSet,
        phi_gen: &PhiGen,
        value_table: &mut ValueTable,
    ) {
        // 递归插入核心逻辑
        fn insert_recurse(
            cfg: &mut CFG<SSAOperator>,
            current: usize,
            leaders: &mut LeaderSet,
            antileaders: &AntileaderSet,
            phi_gen: &PhiGen,
            value_table: &mut ValueTable,
            changed: &mut bool,
            gen: &mut VRegGenerator,
            new_exprs: &mut Vec<HashSet<Value>>,
        ) {
            let block = cfg.get_block(current);
            // 步骤1：处理控制流合并点
            if block.preds.len() > 1 {
                // 只处理有多个前驱的基本块(控制流合并点)
                let antic = &antileaders[current];
                // 对前驱进行phi翻译。得到在前驱块上下文中的表达式集合
                let translated_preds = block
                    .preds
                    .iter()
                    .map(|&pred| {
                        (
                            pred,
                            phi_translate(&phi_gen[current], antic, block, pred, value_table),
                        )
                    })
                    .collect::<Vec<_>>();
                
                /// 找出哪些表达式需要被提升(hoist)
                ///  a. 在前驱块中，该表达式有leader(即在前驱块中已经计算过，或者已经插入过计算)
                ///  b. 表达式不是简单的(不是寄存器，即是一个实际的计算表达式)
                ///  c. 当前块(合并点) 还没有这个表达式。(通过new_exprs[current]来记录，避免重复插入)
                let to_hoist = translated_preds
                    .iter()
                    .flat_map(|(pred, expr)| {
                        expr.iter().zip(antic).enumerate().filter_map(
                            |(i, ((val, exp), (val_orig, _)))| {
                                // 条件1：前驱块中该值有leader
                                // 条件2：不是简单表达式（不是寄存器）
                                // 条件3：当前块还没有这个表达式
                                if leaders[*pred].contains_key(val)
                                    && !exp.is_simple()
                                    && !new_exprs[current].contains(val_orig)
                                // exclude on 2nd run
                                {
                                    Some(i)
                                } else {
                                    None
                                }
                            },
                        )
                    })
                    .collect::<HashSet<_>>();
                let mut new_phis = vec![Vec::default(); to_hoist.len()];
                for (pred, exprs) in translated_preds.into_iter() {
                    let mut i = 0;
                    for (k, (val, exp)) in exprs.into_iter().enumerate() {
                        if !to_hoist.contains(&k) {
                            continue;
                        }
                        let leaders = &mut leaders[pred];
                        // 步骤4：在前驱块插入计算
                        if !leaders.contains_key(&val) {
                            let new_reg = gen.next_reg();
                            let new_op = exp.to_instruction(leaders, new_reg);
                            // 保存分支指令，插入新计算，再恢复分支
                            let branch = cfg.get_block_mut(pred).body.pop();
                            cfg.get_block_mut(pred).body.push(new_op);
                            branch.and_then(|branch| {
                                cfg.get_block_mut(pred).body.push(branch);
                                Option::<()>::None
                            });
                            leaders.insert(val, new_reg);
                            new_exprs[pred].insert(val);
                            *changed = true;
                        }
                        new_phis[i].push(*leaders.get(&val).unwrap());
                        i += 1;
                    }
                }
                debug_assert!(to_hoist.len() == new_phis.len());
                // 步骤5：在当前块插入phi函数
                let mut new_body: Vec<SSAOperator> = new_phis
                    .into_iter()
                    .map(|vec| SSAOperator::Phi(gen.next_reg(), vec))
                    .collect();
                let mut phi_ptr = 0;
                for (i, (val, _)) in antic.iter().enumerate() {
                    if !to_hoist.contains(&i) {
                        continue;
                    }
                    if let SSAOperator::Phi(rec, v) = &new_body[phi_ptr] {
                        // 步骤6：更新值编号和leader信息
                        value_table.insert_with(Expression::Phi(v.clone()), *val);
                        value_table.insert_with(Expression::Reg(*rec), *val);
                        leaders[current].insert(*val, *rec);
                        new_exprs[current].insert(*val);
                    } else {
                        unreachable!("has to have phi form")
                    }
                    phi_ptr += 1;
                }
                let block = cfg.get_block_mut(current);
                // 步骤7：更新块体
                let mut old_body = std::mem::take(&mut block.body);
                new_body.append(&mut old_body);
                block.body = new_body;
            }
            // 步骤8：递归处理支配子节点
            for idom_child in cfg.get_block(current).idom_of.clone() {
                let add_exprs = new_exprs[current].clone();
                for val in add_exprs.iter() {
                    let leader = *leaders[current].get(val).unwrap();
                    leaders[idom_child].insert(*val, leader);
                }
                new_exprs[idom_child].extend(add_exprs);
                // 传播新表达式信息到支配子节点
                insert_recurse(
                    cfg,
                    idom_child,
                    leaders,
                    antileaders,
                    phi_gen,
                    value_table,
                    changed,
                    gen,
                    new_exprs,
                );
            }
        }
        // 初始化工作列表和寄存器生成器
        let mut changed = true;
        let mut gen = VRegGenerator::starting_at_reg(cfg.get_max_reg());
        let mut new_exprs = vec![HashSet::default(); cfg.len()];
        
        // 迭代直到没有变化
        while changed {
            changed = false;
            insert_recurse(
                cfg,
                cfg.get_entry(),
                leaders,
                antileaders,
                phi_gen,
                value_table,
                &mut changed,
                &mut gen,
                &mut new_exprs,
            );
        }
        cfg.set_max_reg(gen.next_reg());
        #[cfg(feature = "print-gvn")]
        {
            println! {"leaders post insert: \n{:?}\n", leaders};
        }
    }

    /// GVN-PRE算法的消除阶段（eliminate），
    /// 负责将冗余计算替换为复制指令，并删除不必要的Phi函数。
    fn eliminate(cfg: &mut CFG<SSAOperator>, leaders: &LeaderSet, value_table: &mut ValueTable) {
        /// 遍历所有基本块
        for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate() {
            // 1. 初始化当前块的领导者映射
            //    从直接支配者(idom) 继承领导者映射，如果没有支配者则创建空映射
            let mut leaders_in = block
                .idom
                .map(|idom| leaders[idom].clone())
                .unwrap_or_else(HashMap::new);
            // println!("eliminate_leaders_in: {:#?}", leaders_in);

            /// 2. 保存原始指令体，准备处理
            let mut body_old = vec![];
            std::mem::swap(&mut body_old, &mut block.body);

            /// 3. 处理每条指令，过滤和替换冗余计算
            block.body = body_old
                .into_iter()
                .filter_map(|op| {
                    macro_rules! swap_op {
                        /// 宏定义：替换操作指令为复制指令
                        ($reg:expr, $op:expr) => {{
                            /// 检查寄存器是否有领导者（即是否有相同的值编号）
                            if let Some(&leader) =
                                leaders_in.get(&value_table.maybe_insert(Expression::Reg($reg)))
                            {
                                /// 如果领导者不是自己，说明有冗余计算
                                if leader != $reg {
                                    /// 用复制指令替换原始计算指令
                                    return Some(SSAOperator::IROp(Operator::Mv($reg, leader)));
                                }
                            }
                            /// 没有冗余，保留原始指令
                            Some(SSAOperator::IROp($op))
                        }};
                    }
                    
                    /// 获取指令的结果寄存器
                    let rec = op.receiver();

                    /// 4. 根据指令类型进行处理
                    let res = match op {
                        /// 处理普通IR指令
                        SSAOperator::IROp(op) => match op {
                            /// 这些指令有结果寄存器，可能被替换为复制指令
                            Operator::Add(x, ..)
                            | Operator::Sub(x, _, _)
                            | Operator::Mult(x, _, _)
                            | Operator::Div(x, _, _)
                            | Operator::And(x, _, _)
                            | Operator::Or(x, _, _)
                            | Operator::Mv(x, _)
                            | Operator::Xor(x, _, _)
                            | Operator::Load(x, _, _)
                            | Operator::LoadLocal(x, _)
                            | Operator::La(x, _)
                            | Operator::Li(x, _)
                            | Operator::Slt(x, _, _)
                            | Operator::Call(x, _, _)
                            | Operator::GetParameter(x, _) => swap_op!(x, op),
                            /// 其他指令保持不变
                            o => Some(SSAOperator::IROp(o)),
                        },
                        /// 处理phi 函数
                        SSAOperator::Phi(x, _) => {
                            /// 检查Phi函数的结果寄存器是否有领导者
                            if let Some(&leader) =
                                leaders[i].get(&value_table.maybe_insert(Expression::Reg(x)))
                            {
                                /// 如果领导者不是自己，说明Phi函数是冗余的
                                if leader != x {
                                    /// 删除冗余的Phi函数
                                    return None;
                                }
                            }
                            /// 保留必要的Phi函数
                            Some(op)
                        }
                    };
                    /// 5. 更新当前块的领导者映射
                    if let Some(rec) = rec {
                        let val = value_table.maybe_insert(Expression::Reg(rec));
                        leaders_in.entry(val).or_insert(rec);
                    }
                    /// 返回处理后的指令
                    res
                })
                .collect();
        }
    }

    #[cfg(test)]
    mod tests {
        use std::rc::Rc;

        use super::*;
        use crate::{ir::CFG, parser};

        #[test]
        fn generate_table() {
            let input = "
        myvar3 :: Bool;
        lambda myfun(myvar3 :: Int) :: Int {
            myvar4 :: Int = 0;
            i :: Int = 100;
            while (i >= 0) do {
                if i / 2 / 2 / 2 < 2 then {
                    myvar4 = myvar4 * 3;
                } else {
                    myvar4 = myvar4 / 2;
                }
            }
           return myvar4;
        }
        myvar2 :: Bool;
        ";

            let p = parser::parse_and_validate(input).unwrap();
            let mut context = crate::ir::Context::new();
            crate::ir::translate_program(&mut context, &p);
            let funs = context.get_functions();
            let fun = funs.get("myfun").unwrap();
            let body = fun.get_body();
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
            let mut ssa = cfg.into_ssa();
            let table = generate_value_table(&mut ssa);

            for val in [
                (Expression::Immediate(100), 1),
                (Expression::Immediate(0), 3),
                (Expression::Immediate(2), 5),
                (Expression::Immediate(3), 1),
                (Expression::Immediate(1), 2),
            ] {
                let number = *table.expressions.get(&val.0).unwrap();
                let count = table
                    .expressions
                    .iter()
                    .filter(|(_, &v)| v == number)
                    .count();
                assert_eq!(count, val.1 + 1);
            }
        }

        #[test]
        fn build_sets_simple() {
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 3);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 2);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_sum = table.maybe_insert(Expression::Plus(value_5, value_3));
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 4);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 5);
            assert_eq!(*leaders[0].get(&value_sum).unwrap(), 6);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                    (value_sum, Expression::Plus(value_3, value_5))
                ]
            );
        }

        #[test]
        fn build_sets_trans() {
            let l1: Rc<str> = "Label1".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::J(Rc::clone(&l1)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(5, 4, 3),
                Operator::Return(5),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 3);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 3);
            assert_eq!(antic_in.len(), 3);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_sum = table.maybe_insert(Expression::Plus(value_3, value_5));
            let value_sub = table.maybe_insert(Expression::Sub(value_sum, value_5));
            let value_xor = table.maybe_insert(Expression::Xor(value_sub, value_sum));
            assert_eq!(leaders[0].len(), 3);
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 4);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 5);
            assert_eq!(*leaders[0].get(&value_sum).unwrap(), 6);
            assert_eq!(leaders[1].len(), 5);
            assert_eq!(*leaders[1].get(&value_3).unwrap(), 4);
            assert_eq!(*leaders[1].get(&value_5).unwrap(), 5);
            assert_eq!(*leaders[1].get(&value_sum).unwrap(), 6);
            assert_eq!(*leaders[1].get(&value_sub).unwrap(), 7);
            assert_eq!(*leaders[1].get(&value_xor).unwrap(), 8);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                    (value_sum, Expression::Plus(value_3, value_5)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                    (value_xor, Expression::Xor(value_sum, value_sub)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[1].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(6)),
                    (value_5, Expression::Reg(5)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                    (value_xor, Expression::Xor(value_sum, value_sub)),
                ]
            );
        }

        #[test]
        fn build_sets_trans_kill() {
            let l1: Rc<str> = "Label1".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Slt(3, 1, 2),
                Operator::J(Rc::clone(&l1)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(5, 4, 3),
                Operator::Return(5),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 3);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 3);
            assert_eq!(antic_in.len(), 3);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_slt = table.maybe_insert(Expression::Reg(6));
            let value_sub = table.maybe_insert(Expression::Sub(value_slt, value_5));
            let value_xor = table.maybe_insert(Expression::Xor(value_sub, value_slt));
            assert_eq!(leaders[0].len(), 2);
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 4);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 5);
            assert_eq!(leaders[1].len(), 4);
            assert_eq!(*leaders[1].get(&value_3).unwrap(), 4);
            assert_eq!(*leaders[1].get(&value_5).unwrap(), 5);
            assert_eq!(*leaders[1].get(&value_sub).unwrap(), 7);
            assert_eq!(*leaders[1].get(&value_xor).unwrap(), 8);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[1].iter().cloned()),
                &[
                    (value_slt, Expression::Reg(6)),
                    (value_5, Expression::Reg(5)),
                    (value_sub, Expression::Sub(value_slt, value_5)),
                    (value_xor, Expression::Xor(value_slt, value_sub)),
                ]
            );
        }

        #[test]
        fn build_sets_trans_nokill() {
            let l1: Rc<str> = "Label1".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Sub(3, 1, 2),
                Operator::J(Rc::clone(&l1)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Mv(6, 3),
                Operator::Sub(4, 3, 6),
                Operator::Xor(5, 4, 3),
                Operator::Return(5),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 6);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 3);
            assert_eq!(antic_in.len(), 3);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_sub1 = table.maybe_insert(Expression::Sub(value_3, value_5));
            let value_sub2 = table.maybe_insert(Expression::Sub(value_sub1, value_sub1));
            let value_xor = table.maybe_insert(Expression::Xor(value_sub2, value_sub1));
            assert_eq!(leaders[0].len(), 3);
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 7);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 8);
            assert_eq!(*leaders[0].get(&value_sub1).unwrap(), 9);
            assert_eq!(leaders[1].len(), 5);
            assert_eq!(*leaders[1].get(&value_3).unwrap(), 7);
            assert_eq!(*leaders[1].get(&value_5).unwrap(), 8);
            assert_eq!(*leaders[1].get(&value_sub1).unwrap(), 9);
            assert_eq!(*leaders[1].get(&value_sub2).unwrap(), 11);
            assert_eq!(*leaders[1].get(&value_xor).unwrap(), 12);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                    (value_sub1, Expression::Sub(value_3, value_5)),
                    (value_sub2, Expression::Sub(value_sub1, value_sub1)),
                    (value_xor, Expression::Xor(value_sub1, value_sub2)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[1].iter().cloned()),
                &[
                    (value_sub1, Expression::Reg(9)),
                    (value_sub2, Expression::Sub(value_sub1, value_sub1)),
                    (value_xor, Expression::Xor(value_sub1, value_sub2)),
                ]
            );
        }

        #[test]
        fn build_sets_if() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(5, 4, 3),
                Operator::Return(5),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(5, 4, 3),
                Operator::Return(5),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 5);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 4);
            assert_eq!(antic_in.len(), 4);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_sum = table.maybe_insert(Expression::Plus(value_3, value_5));
            let value_sub = table.maybe_insert(Expression::Sub(value_sum, value_5));
            let value_xor = table.maybe_insert(Expression::Xor(value_sub, value_sum));
            let value_and = table.maybe_insert(Expression::And(value_sub, value_sum));
            assert_eq!(leaders[0].len(), 3);
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[0].get(&value_sum).unwrap(), 8);
            assert_eq!(leaders[1].len(), 5);
            assert_eq!(*leaders[1].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[1].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[1].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[1].get(&value_sub).unwrap(), 9);
            assert_eq!(*leaders[1].get(&value_xor).unwrap(), 10);
            assert_eq!(leaders[2].len(), 5);
            assert_eq!(*leaders[2].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[2].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[2].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[2].get(&value_sub).unwrap(), 11);
            assert_eq!(*leaders[2].get(&value_and).unwrap(), 12);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                    (value_sum, Expression::Plus(value_3, value_5)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[1].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(8)),
                    (value_5, Expression::Reg(7)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                    (value_xor, Expression::Xor(value_sum, value_sub)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[2].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(8)),
                    (value_5, Expression::Reg(7)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                    (value_and, Expression::And(value_sum, value_sub)),
                ]
            );
        }
        #[test]
        fn build_sets_loop() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let l3: Rc<str> = "Label3".into();
            let l4: Rc<str> = "Label4".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::J(Rc::clone(&l4)),
                Operator::Label(Rc::clone(&l4)),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(5, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(5, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l3)),
                Operator::J(Rc::clone(&l4)),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 5);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 6);
            assert_eq!(antic_in.len(), 6);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_sum = table.maybe_insert(Expression::Plus(value_3, value_5));
            let value_sub = table.maybe_insert(Expression::Sub(value_sum, value_5));
            let value_xor = table.maybe_insert(Expression::Xor(value_sub, value_sum));
            let value_and = table.maybe_insert(Expression::And(value_sub, value_sum));
            assert_eq!(leaders[0].len(), 3);
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[0].get(&value_sum).unwrap(), 8);
            assert_eq!(leaders[1].len(), 3);
            assert_eq!(leaders[2].len(), 5);
            assert_eq!(*leaders[2].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[2].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[2].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[2].get(&value_sub).unwrap(), 9);
            assert_eq!(*leaders[2].get(&value_xor).unwrap(), 10);
            assert_eq!(leaders[3].len(), 5);
            assert_eq!(*leaders[3].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[3].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[3].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[3].get(&value_sub).unwrap(), 11);
            assert_eq!(*leaders[3].get(&value_and).unwrap(), 12);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                    (value_sum, Expression::Plus(value_3, value_5)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[1].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(8)),
                    (value_5, Expression::Reg(7)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[2].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(8)),
                    (value_5, Expression::Reg(7)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                    (value_xor, Expression::Xor(value_sum, value_sub)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[3].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(8)),
                    (value_5, Expression::Reg(7)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                    (value_and, Expression::And(value_sum, value_sub)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[4].iter().cloned()),
                &[
                    (value_sum, Expression::Reg(8)),
                    (value_5, Expression::Reg(7)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                ]
            );
        }
        #[test]
        fn build_sets_phi() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let l3: Rc<str> = "Label3".into();
            let l4: Rc<str> = "Label4".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::J(Rc::clone(&l4)),
                Operator::Label(Rc::clone(&l4)),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(3, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(3, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l3)),
                Operator::J(Rc::clone(&l4)),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 5);
            let mut ssa = cfg.into_ssa();
            let (leaders, antic_in, _, mut table) = build_sets(&mut ssa);
            assert_eq!(leaders.len(), 6);
            assert_eq!(antic_in.len(), 6);
            let value_3 = table.maybe_insert(Expression::Immediate(3));
            let value_5 = table.maybe_insert(Expression::Immediate(5));
            let value_phi1 = table.maybe_insert(Expression::Phi(vec![8, 14]));
            let value_phi2 = table.maybe_insert(Expression::Phi(vec![11, 13]));
            let value_sum = table.maybe_insert(Expression::Plus(value_3, value_5));
            let value_sub = table.maybe_insert(Expression::Sub(value_sum, value_5));
            let value_sub_phi = table.maybe_insert(Expression::Sub(value_phi1, value_5));
            let value_xor = table.maybe_insert(Expression::Xor(value_sub_phi, value_phi1));
            let value_and = table.maybe_insert(Expression::And(value_sub_phi, value_phi1));
            assert_eq!(leaders[0].len(), 3);
            assert_eq!(*leaders[0].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[0].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[0].get(&value_sum).unwrap(), 8);
            assert_eq!(leaders[1].len(), 4);
            assert_eq!(leaders[2].len(), 6);
            assert_eq!(*leaders[2].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[2].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[2].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[2].get(&value_sub_phi).unwrap(), 10);
            assert_eq!(*leaders[2].get(&value_xor).unwrap(), 11);
            assert_eq!(leaders[3].len(), 6);
            assert_eq!(*leaders[3].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[3].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[3].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[3].get(&value_sub_phi).unwrap(), 12);
            assert_eq!(*leaders[3].get(&value_and).unwrap(), 13);
            assert_eq!(leaders[4].len(), 5);
            assert_eq!(*leaders[3].get(&value_3).unwrap(), 6);
            assert_eq!(*leaders[3].get(&value_5).unwrap(), 7);
            assert_eq!(*leaders[3].get(&value_sum).unwrap(), 8);
            assert_eq!(*leaders[3].get(&value_sub_phi).unwrap(), 12);

            assert_eq!(
                Vec::from_iter(antic_in[0].iter().cloned()),
                &[
                    (value_3, Expression::Immediate(3)),
                    (value_5, Expression::Immediate(5)),
                    (value_sum, Expression::Plus(value_3, value_5)),
                    (value_sub, Expression::Sub(value_sum, value_5)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[1].iter().cloned()),
                &[
                    (value_phi1, Expression::Reg(9)),
                    (value_5, Expression::Reg(7)),
                    (value_sub_phi, Expression::Sub(value_phi1, value_5)),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[2].iter().cloned()),
                &[
                    (value_phi1, Expression::Reg(9)),
                    (value_5, Expression::Reg(7)),
                    (value_sub_phi, Expression::Sub(value_phi1, value_5)),
                    (value_xor, Expression::Xor(value_phi1, value_sub_phi)),
                    (
                        table.maybe_insert(Expression::Sub(value_xor, value_5)),
                        Expression::Sub(value_xor, value_5)
                    ),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[3].iter().cloned()),
                &[
                    (value_phi1, Expression::Reg(9)),
                    (value_5, Expression::Reg(7)),
                    (value_sub_phi, Expression::Sub(value_phi1, value_5)),
                    (value_and, Expression::And(value_phi1, value_sub_phi)),
                    (
                        table.maybe_insert(Expression::Sub(value_and, value_5)),
                        Expression::Sub(value_and, value_5)
                    ),
                ]
            );
            assert_eq!(
                Vec::from_iter(antic_in[4].iter().cloned()),
                &[
                    (value_phi2, Expression::Reg(14)),
                    (value_5, Expression::Reg(7)),
                    (
                        table.maybe_insert(Expression::Sub(value_phi2, value_5)),
                        Expression::Sub(value_phi2, value_5)
                    ),
                ]
            );
        }

        #[test]
        fn insert_phi() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let l3: Rc<str> = "Label3".into();
            let l4: Rc<str> = "Label4".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::J(Rc::clone(&l4)),
                Operator::Label(Rc::clone(&l4)),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(3, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(3, 4, 3),
                Operator::Sub(7, 3, 1),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l3)),
                Operator::Sub(6, 3, 1),
                Operator::J(Rc::clone(&l4)),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 8);
            let mut ssa = cfg.into_ssa();
            let (mut leaders, antic_in, phi_gen, mut table) = build_sets(&mut ssa);
            println!("Before insert: \n {}", ssa.to_dot());
            insert(&mut ssa, &mut leaders, &antic_in, &phi_gen, &mut table);
            println!("After insert: \n {}", ssa.to_dot());
            eliminate(&mut ssa, &leaders, &mut table);
            println!("After eliminate: \n {}", ssa.to_dot());
        }
        #[test]
        fn insert_call() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let l3: Rc<str> = "Label3".into();
            let l4: Rc<str> = "Label4".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::J(Rc::clone(&l4)),
                Operator::Label(Rc::clone(&l4)),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Call(3, Rc::from("myfun"), vec![2, 1]),
                Operator::Sub(4, 3, 2),
                Operator::Xor(3, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(3, 4, 3),
                Operator::Sub(7, 3, 1),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l3)),
                Operator::Sub(6, 3, 1),
                Operator::J(Rc::clone(&l4)),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 8);
            let mut ssa = cfg.into_ssa();
            let (mut leaders, antic_in, phi_gen, mut table) = build_sets(&mut ssa);
            println!("Before insert: \n {}", ssa.to_dot());
            insert(&mut ssa, &mut leaders, &antic_in, &phi_gen, &mut table);
            println!("After insert: \n {}", ssa.to_dot());
            eliminate(&mut ssa, &leaders, &mut table);
            println!("After eliminate: \n {}", ssa.to_dot());
            assert!(ssa
                .get_block(2)
                .body
                .iter()
                .any(|op| matches!(op, SSAOperator::IROp(Operator::Call(..)))));
        }
    }
}

pub mod copy_propagation {
    #![allow(clippy::too_many_arguments)]
    use std::collections::HashMap;

    use crate::ir::{SSAOperator, VReg, CFG};

    // Lattice（格）枚举定义，表示寄存器值的复制关系
    #[derive(Debug, PartialEq, Eq, Clone, Copy)]
    enum Lattice {
        Top, // 未知值（最不精确） - 表示我们不知道这个寄存器是否是其他寄存器的复制
        CopyOf(VReg), // 是某个寄存器的复制 - 例如 CopyOf(rd1) 表示这个寄存器是 rd1 的复制
        Bottom, // 非复制值（最精确） - 表示这个寄存器不是任何其他寄存器的复制（是计算得到的新值）
    }

    impl Lattice {
        /// 复制传播优化中的格值交汇（meet）操作
        /// 用于合并两个格值（Lattice）的信息，是数据流分析的核心部分。
        /// meet操作：计算两个格值的最大下界（最精确的共同信息）
        /// - self: 第一个格值
        /// - other: 第二个格值 
        /// - regs: 当前Phi函数的结果寄存器（用于特殊情况的处理）
        /// - rego: 另一个操作数寄存器（用于特殊情况的处理）
        fn meet(&self, other: &Lattice, regs: VReg, rego: VReg) -> Self {
            /// 匹配两个格值的所有可能组合  
            match (self, other) {
                /// 情况1：两个都是CopyOf，即都是其他寄存器的复制
                /// 例如：CopyOf(rd1) meet CopyOf(rd2)
                (Lattice::CopyOf(reg), Lattice::CopyOf(reg2)) => {
                    /// 如果复制的源寄存器相同
                    if reg == reg2 {
                        /// 结果仍然是同一个寄存器的复制
                        /// 例如：CopyOf(rd1) meet CopyOf(rd1) = CopyOf(rd1)
                        Lattice::CopyOf(*reg)
                    } else {
                        /// 如果复制的源寄存器不同，产生冲突
                        /// 例如：CopyOf(rd1) meet CopyOf(rd2) = Bottom
                        /// 因为寄存器不能同时是rd1和rd2的复制
                        Lattice::Bottom
                    }
                }
                /// 情况2：两个都是Bottom，即都不是复制
                /// 例如：Bottom meet Bottom = Bottom
                (Lattice::Bottom, Lattice::Bottom) => Lattice::Bottom,
                /// 情况3：第一个是Bottom，第二个是CopyOf
                /// 例如：Bottom meet CopyOf(rd1)
                (Lattice::Bottom, Lattice::CopyOf(reg)) => {
                    /// 特殊处理：如果当前Phi函数的结果寄存器(regs)等于复制源寄存器(reg)
                    if regs == *reg {
                        /// 例如：rd3 = φ(rd1, 计算值)
                        /// 如果rd3 == rd1，那么结果可以是CopyOf(rd1)
                        Lattice::CopyOf(regs)
                    } else {
                        /// 否则产生冲突，结果为Bottom
                        Lattice::Bottom
                    }
                }
                /// 情况4：第一个是CopyOf，第二个是Bottom
                /// 例如：CopyOf(rd1) meet Bottom
                (Lattice::CopyOf(reg), Lattice::Bottom) => {
                    /// 特殊处理：如果另一个操作数寄存器(rego)等于复制源寄存器(reg)
                    if rego == *reg {
                        /// 例如：rd3 = φ(计算值, rd1)
                        /// 如果rd3 == rd1，那么结果可以是CopyOf(rd1)
                        Lattice::CopyOf(rego)
                    } else {
                        /// 否则产生冲突，结果为Bottom
                        Lattice::Bottom
                    }
                }
                /// 情况5：至少有一个是Top（未知值）
                /// 模式匹配：Top meet X 或 X meet Top
                /// 用更精确的信息替换未知值
                /// 例如：Top meet CopyOf(rd1) = CopyOf(rd1)
                /// 例如：Top meet Bottom = Bottom
                (Lattice::Top, o) | (o, Lattice::Top) => *o,
            }
        }
    }

    /// 复制传播优化算法中的指令访问函数
    /// 负责分析每条指令的复制关系并更新格值(Lattice) 状态
    fn visit_op<'a, 'b>(
        /// 要分析的SSA指令
        op: &SSAOperator,
        /// 指令所在的基本快索引
        block: usize,
        /// 控制流图
        cfg: &CFG<SSAOperator>,
        /// 格值数组，索引是寄存器编号，值是Lattice枚举
        result: &mut [Lattice],
        /// 控制流工作列表，用于调度基本块分析
        cfg_worklist: &mut Vec<(usize, usize)>,
        /// SSA工作列表，用于调度指令分析
        ssa_worklist: &mut Vec<(&'a SSAOperator, usize)>,
        /// 记录哪些边（前驱->后继）是可执行的
        executable: &mut HashMap<(usize, usize), bool>,
        /// SSA图：寄存器 -> [(使用指令, 块索引)]
        ssa_graph: &[Vec<(&'b SSAOperator, usize)>],
    ) where
        'b: 'a, /// 生命周期约束：'b 必须至少和 'a 一样长
    {
        /// 获取指令的结果寄存器（如果有的话）
        /// 例如：add rd3, rd1, rd2 的结果寄存器是rd3
        let receiver = op.receiver();

        /// 保存旧的格值，用于后续比较是否有变化
        let old = receiver.map(|r| result[r as usize]);
        
        /// 根据指令类型进行处理
        match op {
            /// 处理普通IR指令（非Phi函数）
            SSAOperator::IROp(op_) => match op_ {
                /// 处理大于分支和小于分支指令：Bgt(x, y, true_label, false_label) 和 Bl(x, y, true_label, false_label)
                /// 这些指令比较两个寄存器，根据比较结果跳转到不同分支
                crate::ir::Operator::Bgt(x, y, _, _) | crate::ir::Operator::Bl(x, y, _, _) => {
                    /// 宏定义：添加不可执行边到工作列表
                    /// 当两个寄存器值不同时，某些分支可能不可执行
                    macro_rules! append_non_executable {
                        ($reg1:expr, $reg2:expr) => {{
                            /// 条件1：两个寄存器值不同（$reg1 != $reg2）
                            /// 条件2：true分支边不可执行（还没有标记为可执行）
                            if $reg1 != $reg2
                                && !*executable
                                    .entry((block, cfg.get_block(block).children[0]))
                                    .or_insert(false)
                            {
                                /// 将true分支边添加到工作列表
                                cfg_worklist.push((block, cfg.get_block(block).children[0]));
                            }
                            /// 条件：false分支边不可执行
                            if !*executable
                                .entry((block, cfg.get_block(block).children[1]))
                                .or_insert(false)
                            {
                                /// 将false分支边添加到工作列表
                                cfg_worklist.push((block, cfg.get_block(block).children[1]));
                            }
                        }};
                    }

                    /// 根据两个操作数寄存器的格值状态决定如何处理
                    match (result[*x as usize], result[*y as usize]) {
                        // 情况1：x是Top（未知值），无法推断分支行为
                        (Lattice::Top, _) => {}
                        // 情况2：y是Top（未知值），无法推断分支行为
                        (_, Lattice::Top) => {}
                        /// 情况3：x和y都是CopyOf，即都是其他寄存器的复制
                        /// 例如：x = CopyOf(rd1), y = CopyOf(rd2)
                        (Lattice::CopyOf(reg), Lattice::CopyOf(reg2)) => {
                            // 比较原始寄存器值是否相同
                            append_non_executable!(reg, reg2)
                        }
                        /// 情况4：x是Bottom（非复制），y是CopyOf
                        /// 例如：x是计算值，y是rd1的复制
                        (Lattice::Bottom, Lattice::CopyOf(reg)) => append_non_executable!(reg, *x),
                        /// 情况5：x是CopyOf，y是Bottom
                        (Lattice::CopyOf(reg), Lattice::Bottom) => append_non_executable!(reg, *y),
                        /// 其他情况：默认处理
                        _ => append_non_executable!(1, 2),
                    }
                }

                /// 处理无条件跳转指令：J(label)
                crate::ir::Operator::J(_) => {
                    if !*executable
                        .entry((block, cfg.get_block(block).children[0]))
                        .or_insert(false)
                    {
                        cfg_worklist.push((block, cfg.get_block(block).children[0]));
                    }
                }

                /// 处理相等分支指令：Beq(x, y, true_label, false_label)
                /// 当x == y时跳转到true分支，否则跳转到false分支
                crate::ir::Operator::Beq(x, y, _, _) => {
                    /// 宏定义：添加不可执行边到工作列表
                    macro_rules! append_non_executable {
                        ($reg1:expr, $reg2:expr) => {{
                            // 条件1：两个寄存器值不同，则true分支不可执行
                            if $reg1 != $reg2
                                && !*executable
                                    .entry((block, cfg.get_block(block).children[1]))
                                    .or_insert(false)
                            {
                                cfg_worklist.push((block, cfg.get_block(block).children[1]));
                            }
                            /// 条件2：false分支不可执行（总是检查）
                            if !*executable
                                .entry((block, cfg.get_block(block).children[1]))
                                .or_insert(false)
                            {
                                cfg_worklist.push((block, cfg.get_block(block).children[0]));
                            }
                        }};
                    }
                    /// 根据两个操作数寄存器的格值状态决定如何处理
                    match (result[*x as usize], result[*y as usize]) {
                        /// 情况1：x是Top，无法推断
                        (Lattice::Top, _) => {}
                        /// 情况2：y是Top，无法推断
                        (_, Lattice::Top) => {}
                        /// 情况3：x和y都是CopyOf
                        (Lattice::CopyOf(reg), Lattice::CopyOf(reg2)) => {
                            append_non_executable!(reg, reg2)
                        }
                        /// 情况4：x是Bottom，y是CopyOf
                        (Lattice::Bottom, Lattice::CopyOf(reg)) => append_non_executable!(reg, *x),
                        /// 情况5：x是CopyOf，y是Bottom
                        (Lattice::CopyOf(reg), Lattice::Bottom) => append_non_executable!(reg, *y),
                        /// 其他情况
                        _ => append_non_executable!(1, 2),
                    }
                }
                /// 处理移动指令：Mv(x, y) - 将寄存器y的值复制到寄存器x
                crate::ir::Operator::Mv(x, y) => {
                    /// 根据源寄存器y的格值确定目标寄存器x的格值
                    let res = match &result[*y as usize] {
                        /// 情况：y是Bottom（非复制值）
                        /// 例如：y是计算得到的结果，不是其他寄存器的复制
                        Lattice::Bottom => Lattice::CopyOf(*y),
                        /// 其他情况：直接复制y的格值
                        l => *l,
                    };
                    /// 更新寄存器x的格值
                    result[*x as usize] = res;
                }
                /// 处理其他所有指令（非分支、非跳转、非移动）
                _ => {
                    /// 如果有结果寄存器，将其标记为Bottom（非复制值）
                    /// 因为这些指令产生新的计算值，不是简单的复制
                    if let Some(receiver) = receiver {
                        result[receiver as usize] = Lattice::Bottom;
                    }
                }
            },
            /// 处理Phi函数：Phi(x, [operand1, operand2, ...])
            /// 例如：rd3 = φ(rd1, rd2) 表示rd3的值来自rd1或rd2
            SSAOperator::Phi(x, vec) => {
                /// 初始化结果为Top（未知）
                let mut res = Lattice::Top;

                /// 遍历Phi函数的所有操作数
                for (pred, reg) in vec.iter().enumerate() {
                    /// 获取前驱块索引
                    let pred = cfg.get_block(block).preds[pred];

                    /// 条件1：前驱到当前块的边是可执行的
                    /// 条件2：操作数不是未定义值（u32::MAX）
                    if *executable.entry((pred, block)).or_insert(false) && *reg != u32::MAX {
                        /// 计算当前结果与操作数格值的meet（交汇）
                        /// meet操作是格理论中的概念，用于合并两个格值
                        res = res.meet(&result[*reg as usize], *x, *reg);
                    }
                }
                /// 更新Phi函数结果寄存器的格值
                result[*x as usize] = res;
            }
        }
        /// 检查结果寄存器的格值是否有变化
        if let Some(receiver) = receiver {
            /// 比较新旧格值
            if old.unwrap() != result[receiver as usize] {
                /// 如果有变化，将使用该寄存器的所有指令添加到工作列表
                /// 因为这些指令的格值依赖可能发生了变化
                ssa_worklist.extend(ssa_graph[receiver as usize].iter())
            }
        }
    }

    /// `optimize` 函数是**复制传播优化**（Copy Propagation）的入口函数
    /// 核心步骤:
    ///     1. 通过数据流分析识别哪些寄存器是其他寄存器的复制
    ///     2. 根据识别出的复制关系，删除冗余的复制指令并替换寄存器引用
    pub fn optimize(cfg: &mut CFG<SSAOperator>) {
        /// 步骤1：构建复制关系映射表
        /// 通过调用 build_set(cfg) 进行数据流分析，得到每个寄存器的格值(Lattice)
        /// 然后过滤出哪些是其他寄存器复制的寄存器(Lattice::CopyOf(r))
        let set: HashMap<_, _> =
            /// 遍历 build_set 返回的格值向量
            /// i: 寄存器索引（从0开始）
            /// v: 该寄存器的格值（Lattice枚举）
            HashMap::from_iter(build_set(cfg).into_iter().enumerate().filter_map(|(i, v)| {
                if let Lattice::CopyOf(r) = v {
                    /// 如果格值是 CopyOf(r)，表示这个寄存器是寄存器 r 的复制
                    /// 将 (i as u32, r) 添加到结果映射表中
                    /// i as u32: 被复制的寄存器编号（目标寄存器）
                    /// r: 原始寄存器编号（源寄存器）
                    Some((i as u32, r))
                } else {
                    /// 如果不是 CopyOf，则过滤掉
                    /// 包括 Top（未知）和 Bottom（非复制值）
                    None
                }
            }));
        
        /// 步骤2：执行复制传播
        /// 将构建好的复制关系映射表传递给 propagate 函数
        /// propagate 函数会：
        ///     1. 删除所有产生冗余复制结果的指令
        ///     2. 将所有使用被复制寄存器的地方替换为使用原始寄存器
        propagate(cfg, &set);
    }

    /// 构建复制传播的格值集合
    /// 返回一个向量，索引是寄存器编号，值是Lattice枚举
    /// 主要功能:
    ///     1. 分析SSA形式的控制流图（CFG），确定每个寄存器的复制关系
    ///     2. 使用格理论（Lattice Theory）表示寄存器值的复制状态
    ///     3. 通过工作列表算法（Worklist Algorithm）迭代计算数据流信息
    ///     4. 识别可执行的边（executable edges）以优化分支分析
    fn build_set(cfg: &CFG<SSAOperator>) -> Vec<Lattice> {
        /// 1. 获取SSA图：寄存器 -> [(使用指令, 块索引)]
        ///     这个数据结构记录了每个寄存器在哪些指令中被使用
        let ssa_graph = cfg.ssa_graph();

        /// 2. 初始化CFG工作列表：存储(前驱块索引，当前块索引)
        ///     从入口块开始分析，usize:MAX 表示没有前驱(入口块)
        let mut cfg_worklist = vec![(usize::MAX, cfg.get_entry())];
        
        /// 3. 初始化SSA工作列表：存储(指令引用，块索引)
        ///     用于调度需要重新分析的指令
        let mut ssa_worklist: Vec<(&SSAOperator, usize)> = Vec::default();

        /// 4. 初始化可执行边映射：记录哪些控制流是可执行的
        ///     键：(前驱块索引，后继块索引)
        ///     值: 布尔值，表示该边是否可执行
        let mut executable = HashMap::new();

        /// 5. 初始化结果数组：为每个寄存器分配初始格值
        ///     初始值都是 Lattice::Top（未知）
        let mut result = vec![Lattice::Top; cfg.get_max_reg() as usize];

        /// 6. 主循环：当CFG工作列表或SSA工作列表非空时继续处理
        while !cfg_worklist.is_empty() || !ssa_worklist.is_empty() {
            /// 7. 处理CFG工作列表: 分析基本块
            if let Some((pred, child)) = cfg_worklist.pop() {
                /// 获取当前要分析的基本快
                let block = cfg.get_block(child);

                /// 8. 标记当前边为可执行，并检查之前是否已标记过
                ///     past变量记录之前的状态（Some(true)表示已标记过）
                let past = executable.insert((pred, child), true);
                
                /// 9. 处理块中的所有phi函数(phi函数在块的开头)
                let mut body = block.body.iter();
                while let Some(op @ SSAOperator::Phi(..)) = body.next() {
                    /// 对每个phi函数调用visit_op 进行分析
                    visit_op(
                        op, // phi函数指令
                        child, // 当前块索引
                        cfg,    // 控制流图
                        &mut result, // 格值结果数组
                        &mut cfg_worklist,  // CFG 工作列表
                        &mut ssa_worklist, // SSA 工作列表
                        &mut executable,    // 可执行边映射
                        &ssa_graph, // SSA 图
                    );
                }

                // 10. 如果当前边之前没有标记为可执行(首次访问)
                //      则处理块中的所有指令(包括phi函数之后的部分)
                if !matches!(past, Some(true)) {
                    /// 检查指令是否需要重新分析的条件:
                    /// 条件1：指令是phi函数
                    /// 条件2：指令所有块可执行的前驱边
                    for op in block.body.iter() {
                        /// 满足条件，重新分析该指令
                        visit_op(
                            op,
                            child,
                            cfg,
                            &mut result,
                            &mut cfg_worklist,
                            &mut ssa_worklist,
                            &mut executable,
                            &ssa_graph,
                        );
                    }
                }
            }
            
            /// 11. 处理SSA工作列表：重新分析受影响的指令
            if let Some((op, block)) = ssa_worklist.pop() {
                /// 检查指令是否需要重新分析的条件:
                ///     条件1；指令是phi函数
                ///     条件2：指令所在块可执行的前驱边
                if matches!(op, SSAOperator::Phi(..))
                    || cfg
                        .get_block(block)
                        .preds
                        .iter()
                        .any(|pred| *executable.entry((*pred, block)).or_insert(false))
                {
                    /// 满足条件，重新分析该指令
                    visit_op(
                        op,
                        block,
                        cfg,
                        &mut result,
                        &mut cfg_worklist,
                        &mut ssa_worklist,
                        &mut executable,
                        &ssa_graph,
                    );
                }
            }
        }
        /// 12. 返回计算完成的格值集合
        result
    }

    /// `propagate` 函数复制传播优化（Copy Propagation）的核心实现部分，位于 `copy_propagation` 模块中
    /// 该函数的主要作用将控制图(CFG) 中所有冗余的寄存器复制操作进行传播和消除
    /// `cfg: &mut CFG<SSAOperator>` - 要优化的控制流图
    /// `set: &HashMap<VReg, VReg>` - 复制关系映射表，表示哪些寄存器是其他寄存器的复制
    /// 核心功能:
    ///     1. __删除冗余的复制指令__：如果一个寄存器的值只是另一个寄存器的复制，并且这个复制关系在 
    ///     `set` 中，那么删除产生这个复制结果的指令
    ///     2. __替换寄存器引用__：将所有使用被复制寄存器的地方替换为使用原始寄存器
    fn propagate(cfg: &mut CFG<SSAOperator>, set: &HashMap<VReg, VReg>) {
        /// 遍历控制流图中的所有基本块
        for block in cfg.get_blocks_mut() {
            /// 使用 std::mem::swap 交换 block.body 和空向量，获取原始指令体
            /// 这是一种高效获取所有权的方式，避免额外的复制
            let mut old = Vec::new();
            std::mem::swap(&mut old, &mut block.body);
            
            /// 对原始指令体进行转换处理
            block.body = old
                .into_iter() // 获取所有权迭代器，消耗原始向量
                .filter_map(|op| { // 使用 filter_map 同时进行过滤和映射
                    /// 检查当前指令是否有结果寄存器（receiver）
                    if let Some(receiver) = op.receiver() {
                        /// 如果结果寄存器在复制关系映射表中（即它是冗余的复制）
                        if set.contains_key(&receiver) {
                            /// 返回 None，表示删除这条指令
                            /// 因为这条指令只是产生一个冗余的复制值
                            return None;
                        }
                    }

                    /// 如果指令没有被删除，创建一个可变的副本用于修改
                    let mut res = op;
                    
                    /// 遍历复制关系映射表中的所有条目
                    for (&k, &v) in set {
                        /// 将指令中所有使用被复制寄存器 k 的地方替换为使用原始寄存器 v
                        /// replace_reg 方法会递归地替换指令中所有出现的寄存器 k
                        res.replace_reg(k, v);
                    }

                    /// 返回修改后的指令
                    Some(res)
                })
                .collect(); /// 将迭代器结果收集回向量
        }
    }

    #[cfg(test)]
    mod tests {
        use std::rc::Rc;

        use crate::{
            ir::{Operator, SSAOperator, CFG},
            ssa::{copy_propagation::build_set, gvn_pre},
        };

        #[test]
        fn sample_phi() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let l3: Rc<str> = "Label3".into();
            let l4: Rc<str> = "Label4".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::J(Rc::clone(&l4)),
                Operator::Label(Rc::clone(&l4)),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Sub(4, 3, 2),
                Operator::Xor(3, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(3, 4, 3),
                Operator::Sub(7, 3, 1),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l3)),
                Operator::Sub(6, 3, 1),
                Operator::J(Rc::clone(&l4)),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 8);
            let mut ssa = cfg.into_ssa();
            println!("Before GVN-PRE: \n{}", ssa.to_dot());
            gvn_pre::optimize(&mut ssa);
            println!("After GVN-PRE: \n{}", ssa.to_dot());
            let lattice = build_set(&ssa);
            println!("Copy Propagation Lattice: \n{:?}", lattice);
            super::optimize(&mut ssa);
            println!("After copy propagation: \n{}", ssa.to_dot());
        }
        #[test]
        fn sample_call() {
            let l1: Rc<str> = "Label1".into();
            let l2: Rc<str> = "Label2".into();
            let l3: Rc<str> = "Label3".into();
            let l4: Rc<str> = "Label4".into();
            let body = vec![
                Operator::Li(1, 3),
                Operator::J(Rc::clone(&l4)),
                Operator::Label(Rc::clone(&l4)),
                Operator::Li(2, 5),
                Operator::Add(3, 1, 2),
                Operator::Beq(1, 2, Rc::clone(&l1), Rc::clone(&l2)),
                Operator::Label(Rc::clone(&l1)),
                Operator::Call(3, Rc::from("myfun"), vec![2, 1]),
                Operator::Sub(4, 3, 2),
                Operator::Xor(3, 4, 3),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l2)),
                Operator::Sub(4, 3, 2),
                Operator::And(3, 4, 3),
                Operator::Sub(7, 3, 1),
                Operator::J(Rc::clone(&l3)),
                Operator::Label(Rc::clone(&l3)),
                Operator::Sub(6, 3, 1),
                Operator::J(Rc::clone(&l4)),
            ];
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, vec![], 8);
            let mut ssa = cfg.into_ssa();
            println!("Before GVN-PRE: \n{}", ssa.to_dot());
            gvn_pre::optimize(&mut ssa);
            println!("After GVN-PRE: \n{}", ssa.to_dot());
            let lattice = build_set(&ssa);
            println!("Copy Propagation Lattice: \n{:?}", lattice);
            super::optimize(&mut ssa);
            println!("After copy propagation: \n{}", ssa.to_dot());
            assert!(ssa
                .get_block(2)
                .body
                .iter()
                .any(|op| matches!(op, SSAOperator::IROp(Operator::Call(..)))))
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::{
        ir::{Operator, SSAOperator, CFG},
        parser,
    };

    #[test]
    fn optimize_with_call() {
        let input = "
        myvar3 :: Bool;
        lambda myfun(myvar3 :: Int) :: Int {
            myvar4 :: Int = 0;
            i :: Int = 100;
            while (i >= 0) do {
                myvar4 = myfun(myvar4);
                i = i - 1;
            }
           return myvar4;
        }
        myvar2 :: Bool;
        ";
        let p = parser::parse_and_validate(input).unwrap();
        let mut context = crate::ir::Context::new();
        crate::ir::translate_program(&mut context, &p);
        let funs = context.get_functions();
        let fun = funs.get("myfun").unwrap();
        let body = fun.get_body();

        let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
        let mut ssa = cfg.into_ssa();
        super::gvn_pre::optimize(&mut ssa);
        assert!(ssa
            .get_blocks()
            .iter()
            .flat_map(|block| block.body.iter())
            .any(|op| matches!(op, SSAOperator::IROp(Operator::Call(..)))));
        super::copy_propagation::optimize(&mut ssa);
        assert!(ssa
            .get_blocks()
            .iter()
            .flat_map(|block| block.body.iter())
            .any(|op| matches!(op, SSAOperator::IROp(Operator::Call(..)))));
    }
}
