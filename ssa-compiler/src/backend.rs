// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
use std::collections::HashMap;

use crate::ir::{Displayable, SSAOperator, CFG};
use parser_defs::Type;
use register_allocation::Allocator;

/// `to_assembly` 函数：将SSA控制流图转换为汇编代码字符串
/// 
/// 参数：
/// - mut cfg: CFG<SSAOperator> - SSA形式的控制流图（可变引用）
/// - fun_name: &str - 函数名称，用于生成全局符号标签
/// 
/// 返回值：String - 完整的汇编代码字符串
/// 
/// 功能：执行完整的后端代码生成流程，生成RISC-V RV64汇编代码
/// 这是编译器后端的顶层入口函数，协调所有后端处理阶段
pub fn to_assembly(mut cfg: CFG<SSAOperator>, fun_name: &str) -> String {
    // 阶段1：SSA形式转换（SSA Conventionalization）
    // 将SSA形式的控制流图转换为传统的非SSA形式
    // 主要任务：消除Phi函数，为寄存器分配做准备
    register_allocation::conventionalize_ssa(&mut cfg);

    // 阶段2：寄存器分配（Register Allocation）
    // 使用图着色算法将虚拟寄存器分配到物理寄存器
    // 返回值：
    //   - cfg: 分配后的控制流图（传统形式）
    //   - coloring: 虚拟寄存器到物理寄存器的映射
    let (mut cfg, coloring) = register_allocation::RISCV64::allocate(cfg);
    
    // 阶段3：添加过程序言和尾声（Procedure Prologues/Epilogues）
    // 根据RISC-V ABI规范，插入函数调用和返回的栈帧管理代码
    // 包括：保存/恢复调用者保存寄存器、调整栈指针等
    register_allocation::RISCV64::add_procedure_prologues(&mut cfg, &coloring);

    // 阶段4：指令选择（Instruction Selection）
    // 将平台无关的IR指令转换为RISC-V RV64目标指令
    // 同时根据寄存器分配结果替换虚拟寄存器为物理寄存器
    let native = instruction_selection::select_instructions(cfg, &coloring);
    
    // 阶段5：控制流图线性化（CFG Linearization）
    // 将图结构的控制流图转换为线性指令序列
    // 这是代码生成的最后一步，生成可以直接汇编的指令序列
    let linear = native.linearize();
    
    // 阶段6：汇编代码格式化（Assembly Formatting）
    // 将线性指令序列格式化为完整的汇编代码字符串
    // 包括：架构属性、全局符号声明、函数标签、指令序列
    format!(
        ".attribute arch, \"rv64imd\"  // 架构属性：RISC-V 64位，支持整数、乘法、除法扩展
.globl {fun_name}          // 声明全局符号，使函数对其他模块可见
{fun_name}:                // 函数标签：函数入口点
{}",                       // 指令序列占位符
        Displayable(&linear)  // 使用Displayable trait格式化指令序列
    )
}


pub fn globals_to_assembly(globals: HashMap<String, Type>) -> String {
    let names = globals
        .keys()
        .map(|key| format!(".globl {}\n", key))
        .collect::<String>();
    let asm = globals
        .into_keys()
        .map(|key| format!("{}: .dword 0\n", key))
        .collect::<String>();
    format!(
        ".attribute arch, \"rv64imd\"
{names}
.section .data
{asm}"
    )
}
mod register_allocation {
    use std::collections::{HashMap, HashSet};
    use std::fmt::Display;

    use crate::ir::{Operator, SSAOperator, VReg, VRegGenerator, CFG};
    use crate::util;

    pub trait Allocator<NR> {
        fn allocate(ssa: CFG<SSAOperator>) -> (CFG<Operator>, HashMap<VReg, NR>);
        fn add_procedure_prologues(cfg: &mut CFG<Operator>, allocs: &HashMap<VReg, NR>);
    }

    /// RegisterSet trait 定义了物理寄存器集合的通用接口
    /// 使得寄存器分配算法可以独立于具体的架构实现
    pub trait RegisterSet: Sized + Into<usize> + TryFrom<usize> + Clone {
        /// 分配错误类型：当颜色无法映射到物理寄存器时返回的错误
        type AllocationError;
        
        /// 返回可用的物理寄存器数量（最大颜色数）
        /// 例如：RV64 有 24 个可用寄存器（不包括保留寄存器）
        fn max_regs() -> usize;
        
        /// 将颜色编号转换为物理寄存器
        /// 这是图着色算法的最后一步，将抽象的颜色编号映射到具体的物理寄存器
        fn from_colors(
            colors: &[u64],           // 颜色编号数组：每个虚拟寄存器分配的颜色
            pins: &HashMap<u64, Self>, // 固定寄存器映射：某些颜色必须映射到特定物理寄存器
        ) -> Result<Vec<Self>, Self::AllocationError>;
    }

    pub struct RISCV64 {}

    #[repr(usize)]
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RV64Reg {
        X0 = 0,   // zero
        X1 = 1,   // ra
        X2 = 2,   // sp
        X3 = 3,   // gp
        X4 = 4,   // tp
        X5 = 5,   // t0
        X6 = 6,   // t1
        X7 = 7,   // t2
        X8 = 8,   // s0
        X9 = 9,   // s1
        X10 = 10, // a0
        X11 = 11,
        X12 = 12,
        X13 = 13,
        X14 = 14,
        X15 = 15,
        X16 = 16,
        X17 = 17, // a7
        X18 = 18, // s2
        X19 = 19,
        X20 = 20,
        X21 = 21,
        X22 = 22,
        X23 = 23,
        X24 = 24,
        X25 = 25,
        X26 = 26,
        X27 = 27, // s11
        X28 = 28, // t3
        X29 = 29,
        X30 = 30,
        X31 = 31, // t6
    }
    impl Display for RV64Reg {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RV64Reg::X0 => write!(f, "x0"),
                RV64Reg::X1 => write!(f, "x1"),
                RV64Reg::X2 => write!(f, "x2"),
                RV64Reg::X3 => write!(f, "x3"),
                RV64Reg::X4 => write!(f, "x4"),
                RV64Reg::X5 => write!(f, "x5"),
                RV64Reg::X6 => write!(f, "x6"),
                RV64Reg::X7 => write!(f, "x7"),
                RV64Reg::X8 => write!(f, "x8"),
                RV64Reg::X9 => write!(f, "x9"),
                RV64Reg::X10 => write!(f, "x10"),
                RV64Reg::X11 => write!(f, "x11"),
                RV64Reg::X12 => write!(f, "x12"),
                RV64Reg::X13 => write!(f, "x13"),
                RV64Reg::X14 => write!(f, "x14"),
                RV64Reg::X15 => write!(f, "x15"),
                RV64Reg::X16 => write!(f, "x16"),
                RV64Reg::X17 => write!(f, "x17"),
                RV64Reg::X18 => write!(f, "x18"),
                RV64Reg::X19 => write!(f, "x19"),
                RV64Reg::X20 => write!(f, "x20"),
                RV64Reg::X21 => write!(f, "x21"),
                RV64Reg::X22 => write!(f, "x22"),
                RV64Reg::X23 => write!(f, "x23"),
                RV64Reg::X24 => write!(f, "x24"),
                RV64Reg::X25 => write!(f, "x25"),
                RV64Reg::X26 => write!(f, "x26"),
                RV64Reg::X27 => write!(f, "x27"),
                RV64Reg::X28 => write!(f, "x28"),
                RV64Reg::X29 => write!(f, "x29"),
                RV64Reg::X30 => write!(f, "x30"),
                RV64Reg::X31 => write!(f, "x31"),
            }
        }
    }
    impl RV64Reg {
        const ALLOCATION_ORDER: [Self; 24] = [
            Self::X5,
            Self::X6,
            Self::X7,
            Self::X28,
            Self::X29,
            Self::X30,
            Self::X31,
            Self::X10,
            Self::X11,
            Self::X12,
            Self::X13,
            Self::X17,
            Self::X8,
            Self::X9,
            Self::X18,
            Self::X19,
            Self::X20,
            Self::X21,
            Self::X22,
            Self::X23,
            Self::X24,
            Self::X25,
            Self::X26,
            Self::X27,
        ];
        fn callee_saved(&self) -> bool {
            #[allow(clippy::match_like_matches_macro)]
            match self {
                RV64Reg::X8
                | RV64Reg::X9
                | RV64Reg::X18
                | RV64Reg::X19
                | RV64Reg::X20
                | RV64Reg::X21
                | RV64Reg::X22
                | RV64Reg::X23
                | RV64Reg::X24
                | RV64Reg::X25
                | RV64Reg::X26
                | RV64Reg::X27 => true,
                _ => false,
            }
        }
        fn get_param_reg(n: u64) -> Option<RV64Reg> {
            use RV64Reg::*;
            match n {
                0 => Some(X10),
                1 => Some(X11),
                2 => Some(X12),
                3 => Some(X13),
                4 => Some(X14),
                5 => Some(X15),
                6 => Some(X16),
                7 => Some(X17),
                _ => None,
            }
        }
    }
    impl From<RV64Reg> for usize {
        fn from(reg: RV64Reg) -> Self {
            reg as usize
        }
    }
    
    impl RegisterSet for RV64Reg {
        type AllocationError = ();  // 简单错误类型
        
        fn max_regs() -> usize {
            24  // RV64 可用寄存器数量
        }
        
        fn from_colors(
            colors: &[u64],
            pins: &HashMap<u64, Self>,
        ) -> Result<Vec<Self>, Self::AllocationError> {
            // 步骤1：获取可用的物理寄存器（排除已固定的寄存器）
            let mut avail = Self::ALLOCATION_ORDER
                .into_iter()
                .filter(|k| !pins.values().any(|k2| k2 == k));
            
            // 步骤2：为每个颜色分配物理寄存器
            colors
                .iter()
                .map(|color| {
                    // 优先使用固定寄存器映射
                    pins.get(color)
                        .cloned()  // 如果颜色被固定，使用固定寄存器
                        .or_else(|| avail.next())  // 否则使用下一个可用寄存器
                })
                .collect::<Option<Vec<Self>>>()  // 收集结果，如果所有颜色都成功分配
                .ok_or(())  // 如果分配失败，返回错误
        }
    }

    impl std::convert::TryFrom<usize> for RV64Reg {
        type Error = &'static str;

        fn try_from(value: usize) -> Result<Self, Self::Error> {
            use RV64Reg::*;
            match value {
                0 => Ok(X0),
                1 => Ok(X1),
                2 => Ok(X2),
                3 => Ok(X3),
                4 => Ok(X4),
                5 => Ok(X5),
                6 => Ok(X6),
                7 => Ok(X7),
                8 => Ok(X8),
                9 => Ok(X9),
                10 => Ok(X10),
                11 => Ok(X11),
                12 => Ok(X12),
                13 => Ok(X13),
                14 => Ok(X14),
                15 => Ok(X15),
                16 => Ok(X16),
                17 => Ok(X17),
                18 => Ok(X18),
                19 => Ok(X19),
                20 => Ok(X20),
                21 => Ok(X21),
                22 => Ok(X22),
                23 => Ok(X23),
                24 => Ok(X24),
                25 => Ok(X25),
                26 => Ok(X26),
                27 => Ok(X27),
                28 => Ok(X28),
                29 => Ok(X29),
                30 => Ok(X30),
                31 => Ok(X31),
                _ => Err("register number too high"),
            }
        }
    }

    /// `InterferenceGraph`（冲突图）是**寄存器分配**中的核心数据结构，用于表示虚拟寄存器之间的冲突关系
    /// 主要作用是:
    ///     1. 存储冲突关系：记录哪些虚拟寄存器不能分配到同一个物理寄存器
    ///     2. 支持图着色算法：为寄存器分配提供基础数据结构
    ///     3. 支持寄存器合并：允许合并不冲突的寄存器对
    ///     4. 支持冲突查询：快速检查两个寄存器是否冲突
    struct InterferenceNode {
        live_range: VReg,       // 虚拟寄存器编号（活跃范围）
        edge_with: Vec<usize>,  // 与该节点冲突的其他节点索引列表
    }
    struct InterferenceGraph {
        nodes: Vec<InterferenceNode>,   // 所有节点的向量
        index: HashMap<VReg, usize>,    // 寄存器编号到节点索引的映射
    }

    impl InterferenceGraph {
        /// 创建新的空冲突图
        fn new() -> Self {
            Self {
                nodes: Vec::new(),      // 空节点向量
                index: HashMap::new(),  // 空索引映射
            }
        }

        /// 合并两个寄存器（将from合并到into）
        /// 于寄存器合并优化，减少寄存器数量
        fn merge(&mut self, into: VReg, from: VReg) {
            /// 确保两个寄存器都在图中
            if !self.index.contains_key(&into) {
                self.maybe_insert(into);
            }

            if !self.index.contains_key(&from) {
                self.maybe_insert(from);
            }

            /// 获取两个寄存器的节点索引
            let into_node = self.index[&into];
            let from_node = self.index[&from];

            /// 遍历from节点的所有冲突边
            for edge in std::mem::take(&mut self.nodes[from_node].edge_with) {
                /// 更新冲突节点的边列表：移除from节点，添加into节点
                self.nodes[edge].edge_with = std::mem::take(&mut self.nodes[edge].edge_with)
                    .into_iter()
                    .filter(|&n| n != from_node && n != into_node)
                    .collect();
                self.nodes[edge].edge_with.push(into_node);
                
                /// 将冲突边添加到into节点
                self.nodes[into_node].edge_with.push(edge);
            }

            /// 对into节点的边列表进行排序和去重
            self.nodes[into_node].edge_with.sort();
            self.nodes[into_node].edge_with.dedup();

            /// 移除from节点的索引（from节点成为垃圾数据）
            self.index.remove(&from); // garbage left
        }
        
        /// 可能插入新节点（如果不存在则插入）
        fn maybe_insert(&mut self, vreg: VReg) -> Option<&InterferenceNode> {
            /// 如果寄存器已存在，返回现有节点
            if let Some(&index) = self.index.get(&vreg) {
                return Some(&self.nodes[index]);
            }

            /// 插入新节点
            self.index.insert(vreg, self.nodes.len()); // 记录索引映射
            self.nodes.push(InterferenceNode {
                live_range: vreg,       // 寄存器编号
                edge_with: Vec::new(),  // 空冲突列表
            });
            None    // 返回None表示插入了新节点
        }
        
        /// 获取节点的可变引用
        fn get_mut(&mut self, vreg: &VReg) -> Option<&mut InterferenceNode> {
            self.index
                .get(vreg)
                .and_then(|index| self.nodes.get_mut(*index))
        }

        /// 获取节点的不可变引用
        fn get(&self, vreg: &VReg) -> Option<&InterferenceNode> {
            self.index
                .get(vreg)
                .and_then(|index| self.nodes.get(*index))
        }

        ///  检查两个寄存器之间是否有冲突边
        fn check_edge(&self, vreg1: &VReg, vreg2: &VReg) -> bool {
            /// 获取两个寄存器的索引
            if let (Some(index), Some(index2)) = (self.index.get(vreg1), self.index.get(vreg2)) {
                /// 检查第一个节点的边列表是否包含第二个节点
                self.nodes[*index].edge_with.contains(index2)
            } else {
                false   // 任一寄存器不存在，返回false
            }
        }

        /// 添加冲突边（表示两个寄存器冲突）
        fn add_edge(&mut self, vreg1: VReg, vreg2: VReg) {
            /// 确保两个寄存器都在图中
            if !self.index.contains_key(&vreg1) {
                self.maybe_insert(vreg1);
            }

            if !self.index.contains_key(&vreg2) {
                self.maybe_insert(vreg2);
            }

            /// 获取两个寄存器的索引
            let (&index1, &index2) = (
                self.index.get(&vreg1).unwrap(),
                self.index.get(&vreg2).unwrap(),
            );

            /// 如果边不存在，则添加双向边
            if !self.nodes[index1].edge_with.contains(&index2) {
                self.nodes[index1].edge_with.push(index2);
                self.nodes[index2].edge_with.push(index1);
            }
        }
    }

    /// ColoringResult::0 := Assigned registers (result[i] = r means live range at index graph.nodes[i] has register r).
    /// ColoringResult::1 := Coalesced registers.
    type ColoringResult<R> = (Vec<R>, HashSet<(VReg, VReg)>);
    impl InterferenceGraph {
        fn to_dot(&self) -> String {
            self.to_dot_colored::<RV64Reg>(None)
        }
        fn to_dot_colored<R: RegisterSet>(&self, colors: Option<Vec<R>>) -> String {
            let max_color = colors
                .as_deref()
                .and_then(|vec| vec.iter().map(|c| c.clone().into()).max())
                .map(|n| n + 1);
            let mut interferences = String::new();
            let mut attributes = String::new();
            for (i, node) in self.nodes.iter().enumerate() {
                if let Some(ref vec) = colors {
                    attributes.push_str(&format!(
                        "{}[style=filled; fillcolor=\"{},1.0,1.0\"]\n",
                        node.live_range,
                        vec[i].clone().into() as f64 / max_color.unwrap() as f64
                    ));
                }
                for node2 in &node.edge_with {
                    interferences.push_str(&format!(
                        "{} -- {}\n",
                        node.live_range, self.nodes[*node2].live_range
                    ));
                }
            }
            format!(
                "
strict graph G {{
{attributes}
{interferences}
}}"
            )
        }
        
        /// `find_coloring` 函数是寄存器分配中图着色算法（Graph Coloring）的核心实现
        /// 该函数使用Z3求解器（SMT求解器）来解决寄存器分配的图着色问题，
        /// 将冲突图中的节点（虚拟寄存器）着色（分配到物理寄存器），
        /// 同时最大化寄存器合并（coalescing）的数量
        ///具体来说，函数的主要功能是：
        ///    1. 构建SMT约束：将寄存器分配问题转化为SMT（可满足性模理论）问题
        ///    2. 处理固定寄存器：确保某些虚拟寄存器被固定到特定的物理寄存器
        ///    3. 最大化寄存器合并：尽可能合并可以共享同一物理寄存器的虚拟寄存器
        ///    4. 解决冲突约束：确保冲突的寄存器分配到不同的物理寄存器
        ///    5. 返回着色方案：返回虚拟寄存器到物理寄存器的映射关系
        fn find_coloring<R: RegisterSet>(
            &self,
            pins: &HashMap<VReg, R>,           // 固定寄存器映射：某些虚拟寄存器必须分配到特定物理寄存器
            coalescable: HashSet<(VReg, VReg)>, // 可合并的寄存器对集合：这些寄存器对可以分配到同一物理寄存器
        ) -> Result<ColoringResult<R>, ()> {   // 返回结果：成功返回着色方案，失败返回错误
            // 步骤1：导入Z3库并初始化
            use z3::ast::*;
            
            // 获取最大可用颜色数（物理寄存器数量）
            let max_colors = R::max_regs();
            
            // 创建Z3配置，启用模型生成（用于获取着色方案）
            let mut config = z3::Config::new();
            config.set_model_generation(true);
            
            // 创建Z3上下文
            let context = z3::Context::new(&config);
            
            // 创建Z3优化求解器（用于最大化寄存器合并）
            let solver = z3::Optimize::new(&context);

            // 步骤2：为冲突图中的每个节点创建Z3整数变量
            // 每个变量表示一个虚拟寄存器分配到的颜色（物理寄存器编号）
            let nodes_z3: Vec<Int<'_>> = self
                .nodes
                .iter()
                .map(|node| Int::new_const(&context, node.live_range.to_string()))
                .collect::<Vec<_>>();

            // 步骤3：为每个物理寄存器创建Z3整数变量
            // 这些变量用于表示物理寄存器本身，确保它们互不相同
            let nodes_native_regs: Vec<_> = (0..max_colors)
                .map(|num| Int::new_const(&context, format!("REG_{num}")))
                .collect();

            // 步骤4：添加约束：所有物理寄存器必须互不相同
            // 这确保每个物理寄存器都有唯一的编号
            for i in 0..max_colors {
                for k in (i + 1)..max_colors {
                    // 添加约束：REG_i ≠ REG_k
                    solver.assert(
                        &nodes_native_regs[i]
                            ._safe_eq(&nodes_native_regs[k])
                            .unwrap()
                            .not(),
                    );
                }
            }
            
            // 步骤5：处理固定寄存器约束
            // 确保某些虚拟寄存器被固定到特定的物理寄存器
            for (i, node) in self.nodes.iter().enumerate() {
                if let Some(reg) = pins.get(&node.live_range) {
                    // 添加约束：节点i的颜色 = 固定寄存器reg的编号
                    solver.assert(
                        &nodes_native_regs[reg.clone().into()]
                            ._safe_eq(&nodes_z3[i])
                            .unwrap(),
                    );
                }
            }

            // 步骤6：处理可合并寄存器对
            // 将可合并集合转换为向量以便索引访问
            let coalescable_vec: Vec<_> = coalescable.into_iter().collect();

            // 为每个可合并对创建一个布尔变量
            // 如果变量为1，表示这对寄存器被合并（分配到同一颜色）
            let coalescable_bools: Vec<_> = (0..coalescable_vec.len())
                .map(|i| Int::new_const(&context, format!("coales_bool_{i}")))
                .collect();
            
            // 为每个可合并对添加约束
            for (i, bool) in coalescable_bools.iter().enumerate() {
                // 获取可合并对中的两个寄存器对应的Z3变量
                let lr1 = &nodes_z3[self.index[&coalescable_vec[i].0]];
                let lr2 = &nodes_z3[self.index[&coalescable_vec[i].1]];
                
                // 约束1：如果bool=1，则lr1和lr2必须相等（合并到同一颜色）
                solver.assert(
                    &bool
                        ._safe_eq(&Int::from_u64(&context, 1))
                        .unwrap()
                        .implies(&lr1._eq(lr2)),
                );
                
                // 约束2：bool只能是0或1
                solver.assert(&Bool::or(
                    &context,
                    &[
                        &bool._safe_eq(&Int::from_u64(&context, 1)).unwrap(),
                        &bool._safe_eq(&Int::from_u64(&context, 0)).unwrap(),
                    ],
                ));
            }
            
            // 步骤7：创建目标函数：最大化合并的寄存器对数量
            // 这是优化目标，求解器会尝试最大化这个值
            let sum_coales_bools = coalescable_bools
                .iter()
                .fold(Int::from_u64(&context, 0), |sum, next| sum + next);

            // 步骤8：添加颜色范围约束
            // 所有颜色必须在[0, max_colors-1]范围内
            let max = Int::from_u64(&context, max_colors as u64);
            let min = Int::from_u64(&context, 0);
            for node in nodes_z3.iter().chain(nodes_native_regs.iter()) {
                // 约束：0 ≤ node < max_colors
                solver.assert(&node.lt(&max));
                solver.assert(&node.ge(&min));
            }

            // 步骤9：添加冲突边约束
            // 确保冲突的寄存器分配到不同的颜色
            let mut added_edges = HashSet::new();
            for edge in self
                .nodes
                .iter()
                .enumerate()
                .flat_map(|(i, node)| std::iter::repeat(i).zip(node.edge_with.iter().cloned()))
            {
                // 避免重复添加相同的边（因为图是无向的）
                if !added_edges.contains(&edge) {
                    let (n1, n2) = edge;
                    added_edges.insert((n2, n1));  // 记录反向边
                    
                    // 添加约束：冲突的节点必须分配到不同的颜色
                    solver.assert(&nodes_z3[n1]._safe_eq(&nodes_z3[n2]).unwrap().not());
                }
            }
            
            // 步骤10：设置优化目标并求解
            solver.maximize(&sum_coales_bools);  // 最大化合并数量
            
            // 检查是否存在可行解
            if !matches!(solver.check(&[]), z3::SatResult::Sat) {
                return Err(());  // 无解，返回错误
            }
            
            // 获取求解器模型（着色方案）
            let model = solver.get_model().unwrap();

            // 步骤11：从模型中提取着色结果
            let colors = nodes_z3
                .iter()
                .map(|node| model.eval(node, true).unwrap().as_u64().unwrap())
                .collect::<Vec<_>>();
            
            // 步骤12：处理固定寄存器的颜色映射
            let color_pins = pins
                .iter()
                .map(|(k, v)| (colors[self.index[k]], v.clone()))
                .collect();
            
            // 步骤13：提取实际被合并的寄存器对
            let coalesced = coalescable_bools
                .into_iter()
                .enumerate()
                .filter(|(_, v)| model.eval(v, true).unwrap().as_u64().unwrap() == 1)
                .map(|(i, _)| coalescable_vec[i])
                .collect();

            // 步骤14：将颜色编号转换为物理寄存器
            R::from_colors(&colors, &color_pins)
                .map_err(|_| ())
                .map(|r| (r, coalesced))  // 返回物理寄存器列表和合并的寄存器对
        }
    }

    /// `spill_liverange` 函数：将指定的活跃范围（虚拟寄存器）溢出到栈上
    /// 
    /// 参数：
    /// - cfg: &mut CFG<Operator> - 控制流图的可变引用
    /// - live_range: VReg - 要溢出的虚拟寄存器编号
    /// - ar_offset: u64 - 栈帧偏移量（以8字节为单位）
    /// 
    /// 功能：将虚拟寄存器 live_range 溢出到栈偏移 ar_offset 处
    /// 溢出过程：
    /// 1. 在寄存器使用前插入加载指令（LoadLocal）
    /// 2. 在寄存器定义后插入存储指令（StoreLocal）
    /// 3. 用新的临时寄存器替换原始寄存器引用
    /// 
    /// 注意：TODO 注释表示此函数可以进一步优化以提高效率
    /// todo could be made more efficient
    fn spill_liverange(cfg: &mut CFG<Operator>, live_range: VReg, ar_offset: u64) {
        // 步骤1：初始化虚拟寄存器生成器
        // 从当前最大寄存器号开始生成新寄存器，确保寄存器编号唯一
        let mut gen = VRegGenerator::starting_at_reg(cfg.get_max_reg());
        
        // 步骤2：遍历控制流图中的所有基本块
        for block in cfg.get_blocks_mut().iter_mut() {
            // 步骤3：处理基本块中的每条指令
            // 使用 flat_map 将每条指令可能转换为多条指令（插入加载/存储）
            block.body = std::mem::take(&mut block.body)
                .into_iter()
                .flat_map(|mut op| {
                    // 步骤3.1：为加载操作生成新的临时寄存器
                    // 这个寄存器用于存储从栈上加载的值
                    let new_lr = gen.next_reg();
                    
                    // 步骤3.2：获取指令的依赖寄存器（使用的寄存器）
                    let dependencies = op.dependencies_mut();
                    
                    // 步骤3.3：检查指令是否使用要溢出的寄存器
                    // 如果使用，需要在指令前插入加载指令
                    let mut res = if dependencies.contains(&&mut live_range.clone()) {
                        // 插入加载指令：从栈偏移 ar_offset 加载到新寄存器 new_lr
                        vec![Operator::LoadLocal(new_lr, ar_offset)]
                    } else {
                        // 不使用要溢出的寄存器，不需要插入加载指令
                        vec![]
                    };
                    
                    // 步骤3.4：替换指令中的依赖寄存器引用
                    // 将原始寄存器 live_range 替换为新寄存器 new_lr
                    dependencies.into_iter().for_each(|reg| {
                        if reg == &live_range {
                            *reg = new_lr
                        }
                    });
                    
                    // 步骤3.5：为存储操作生成另一个新的临时寄存器
                    // 这个寄存器用于存储要保存到栈上的值
                    let new_lr = gen.next_reg();
                    
                    // 步骤3.6：检查指令是否定义要溢出的寄存器
                    if let Some(lr) = op.receiver_mut() {
                        if lr == &live_range {
                            // 步骤3.6.1：替换指令的结果寄存器
                            *lr = new_lr;
                            
                            // 步骤3.6.2：在指令后插入存储指令
                            // 顺序：原始指令 -> 存储指令
                            res.append(&mut vec![op, Operator::StoreLocal(new_lr, ar_offset)]);
                            
                            // 步骤3.6.3：返回新的指令序列
                            return res;
                        }
                    }
                    
                    // 步骤3.7：如果指令不定义要溢出的寄存器，只添加原始指令
                    res.push(op);
                    res
                })
                .collect();
        }
        
        // 步骤4：更新控制流图中的最大寄存器号
        // 确保后续操作知道新的寄存器编号范围
        cfg.set_max_reg(gen.next_reg());
    }
    
    /// build_interference_graph 函数是寄存器分配中构建冲突图的核心实现
    /// 该函数的主要作用是分析控制流图中虚拟寄存器之间的冲突关系，构建冲突图（Interference Graph）
    /// 同时计算可合并的寄存器对和溢出权重
    /// 主要功能:
    ///     1. 构建冲突图：分析哪些虚拟寄存器同时活跃（冲突）
    ///     2. 识别可合并寄存器：找出可以合并的寄存器对（如复制指令）
    ///     3. 计算溢出权重：为每个寄存器计算溢出到栈上的代价权重
    fn build_interference_graph(
        cfg: &CFG<Operator>,
    ) -> (
        InterferenceGraph,
        HashSet<(VReg, VReg)>,
        HashMap<VReg, usize>,
    ) {
        /// 步骤1：初始化数据结构
        /// graph: 冲突图，存储寄存器之间的冲突关系
        let mut graph = InterferenceGraph::new();

        /// coalescable: 可合并的寄存器对集合
        /// 例如：(r1, r2) 表示 r1 和 r2 可以合并为同一个寄存器
        let mut coalescable = HashSet::new();

        /// spill_weights: 溢出权重映射表
        /// 键：寄存器编号，值：溢出到栈上的代价权重
        let mut spill_weights = HashMap::new();
        
        /// 步骤2：计算每个基本块的活跃出集合（live-out）
        /// live_out[i] 表示基本块i出口处活跃的寄存器集合
        let live_out = cfg.live_out();

        /// 步骤3：遍历所有基本块，构建冲突图
        for (i, block) in cfg.get_blocks().iter().enumerate() {
            /// 初始化当前活跃集合为基本块出口处的活跃集合
            let mut live_now = live_out[i].clone();
            
            /// 步骤4：反向遍历基本块中的指令（从后往前）
            /// 反向遍历是因为活跃变量分析是反向数据流分析
            for op in block.body.iter().rev() {
                /// 步骤4.1：为当前活跃的每个寄存器增加溢出权重
                /// 寄存器在更多指令中活跃，溢出代价越高
                for &live in &live_now {
                    *spill_weights.entry(live).or_insert(0_usize) += 1;
                }

                /// 步骤4.2：处理指令的结果寄存器（如果有的话）
                if let Some(rec) = op.receiver() {
                    /// 将结果寄存器添加到冲突图中
                    graph.maybe_insert(rec);

                    /// 结果寄存器被定义，从当前活跃集合中移除
                    /// 因为定义会"杀死"之前的活跃值
                    live_now.remove(&rec);

                    /// 步骤4.3：特殊处理复制指令（Mv）
                    if let Operator::Mv(lr1, lr2) = op {
                        /// 复制指令表示两个寄存器可以合并
                        /// 例如：Mv(r1, r2) 表示 r1 是 r2 的复制
                        coalescable.insert((*lr1, *lr2));
                        
                        /// 对于复制指令，结果寄存器与所有活跃寄存器冲突
                        /// 除了源寄存器（因为它们是同一个值）
                        live_now
                            .iter()
                            .filter(|&lr| lr != lr2) //排除源寄存器    
                            .for_each(|&lr| graph.add_edge(lr, rec));
                    } else {
                        /// 对于非复制指令，结果寄存器与所有活跃寄存器冲突
                        live_now.iter().for_each(|&lr| graph.add_edge(lr, rec));
                    }
                }

                /// 步骤4.4：将指令的依赖寄存器添加到当前活跃集合
                /// 这些寄存器在指令执行前必须是活跃的
                live_now.extend(op.dependencies());
            }
        }
        /// 步骤5：返回构建的结果
        (graph, coalescable, spill_weights)
    }
    
    /// no critical edges allowed
    /// `conventionalize_ssa` 函数是SSA形式转换（SSA Conventionalization）的核心实现
    /// 该函数的主要作用是将SSA形式的控制流图转换为传统的非SSA形式，为后续的寄存器分配做准备
    /// 函数功能:
    ///     1. 消除Phi函数：将SSA形式中的Phi函数转换为显式的复制指令
    ///     2. 处理并行复制：解决Phi函数转换过程中可能出现的循环依赖问题
    ///     3. 生成新的寄存器：为转换过程分配新的虚拟寄存器
    pub fn conventionalize_ssa(ssa: &mut CFG<SSAOperator>) {
        /// 步骤1：初始化并行复制列表
        /// 为每个基本块创建一个空的复制指令列表
        /// parallel_copies[i] 存储基本块i中需要插入的复制指令
        let mut parallel_copies = vec![Vec::new(); ssa.len()];
        
        /// 初始化虚拟寄存器生成器，从当前最大寄存器号开始
        let mut gen = VRegGenerator::starting_at_reg(ssa.get_max_reg());
        
        /// 步骤2：处理所有基本块中的Phi函数
        for block in ssa.get_blocks_mut().iter_mut() {
            /// 获取基本块中指令的可变迭代器
            let mut ops = block.body.iter_mut();
            
            /// 遍历基本块中的所有Phi函数（Phi函数在基本块开头）
            while let Some(SSAOperator::Phi(_, vec)) = ops.next() {
                /// 为Phi函数的每个操作数生成新的寄存器
                /// 例如：Phi(r3, [r1, r2]) 需要生成新寄存器 [r4, r5]
                /// gen.next_reg() 是一个寄存器生成器
                /// 每次调用返回一个新的、未被使用过的虚拟寄存器号（比如依次返回 r4, r5, r6...）
                /// repeat_with(|| gen.next_reg()) 创建了一个无限迭代器，
                /// 每次迭代都会调用一次 gen.next_reg()，生成一个新的寄存器
                /// .take(vec.len()) 限制迭代次数为 vec.len()，其中 vec 是 Phi 函数
                ///     原来的操作数向量（例如 [r1, r2]，长度为2）。这样就恰好生成了与操作数个数相同数量的新寄存器
                /// 最后 .collect() 将这些新寄存器收集到一个向量中，比如 [r4, r5]
                let new_args = std::iter::repeat_with(|| gen.next_reg())
                    .take(vec.len())
                    .collect::<Vec<_>>();

                /// 遍历Phi函数的所有前驱基本块
                for (i, pred) in block.preds.iter().enumerate() {
                    /// 如果Phi函数的操作数是u32::MAX，表示死Phi函数，跳过
                    if vec[i] == u32::MAX {
                        continue; // dead phi function
                    }

                    // 在前驱基本块的复制列表中添加复制指令
                    // 例如：在前驱基本块pred中添加 Mv(new_args[i], vec[i])
                    // 表示将原始寄存器vec[i]的值复制到新寄存器new_args[i]
                    parallel_copies[*pred].push(Operator::Mv(new_args[i], vec[i]));
                }
                /// 用新生成的寄存器替换Phi函数的操作数
                *vec = new_args;
            }
        }

        /// 步骤3：处理并行复制，解决循环依赖
        for (i, mut copies) in parallel_copies.into_iter().enumerate() {
            // found copy to non-live name
            /// 当前基本块中有需要处理的复制指令
            while !copies.is_empty() {
                /// 获取当前基本块中指令的长度（用于插入位置）
                let len = ssa.get_block(i).body.len();

                /// 步骤3.1：查找可以安全插入的复制指令
                /// 规则：目标寄存器不在任何源寄存器中（避免循环依赖）
                if let Some(op) = {
                    /// 创建选择映射：目标寄存器 -> 复制指令索引
                    let mut choices = HashMap::new();
                    let mut iter = copies.iter().enumerate();
                    
                    /// 第一步：将所有复制指令的目标寄存器添加到choices
                    while let Some((i, Operator::Mv(rec, _))) = iter.next() {
                        choices.insert(rec, i);
                    }

                    /// 第二步：从choices中移除那些作为源寄存器出现的寄存器
                    let mut iter = copies.iter();
                    while let Some(Operator::Mv(_, op)) = iter.next() {
                        choices.remove(&op);
                    }

                    /// 第三步：选择第一个可用的复制指令（如果有的话）
                    choices
                        .values()
                        .next()
                        .cloned()
                        .map(|index| copies.remove(index))
                } {
                    /// 找到可以安全插入的复制指令
                    /// 将复制指令插入到基本块的倒数第二个位置（分支指令之前）
                    ssa.get_block_mut(i)
                        .body
                        .insert(len - 1, SSAOperator::IROp(op.clone()));
                } else {
                    // break cycle
                    /// 步骤3.2：处理循环依赖（打破循环）
                    /// 当所有复制指令都形成循环依赖时，需要打破循环
                    if let Some(Operator::Mv(_, op)) = copies.last_mut() {
                        /// 生成一个新的临时寄存器
                        let new_name = gen.next_reg();

                        /// 插入一个中间复制指令：Mv(new_name, op)
                        ssa.get_block_mut(i)
                            .body
                            .insert(len - 1, SSAOperator::IROp(Operator::Mv(new_name, *op)));
                        
                        /// 更新循环中的源寄存器为新的临时寄存器
                        *op = new_name;
                    }
                }
            }
        }
        #[cfg(feature = "print-cfgs")]
        {
            println!("after conventionalizing SSA:{}\n", ssa.to_dot());
        }

        // 更新控制流图中的最大寄存器号
        ssa.set_max_reg(gen.next_reg());
    }
    
    /// `rewrite_liveranges` 函数是活跃范围重写（Live Range Rewriting）的核心实现
    /// 该函数的主要作用是将SSA形式的控制流图转换为传统形式的控制流图
    /// 同时合并Phi函数相关的寄存器，为后续的寄存器分配做准备
    /// 函数的主要功能
    ///     1. 分析Phi函数关系：使用并查集（Union-Find）分析Phi函数中寄存器的等价关系
    ///     2. 合并等价寄存器：将Phi函数中相互等价的寄存器合并为同一个寄存器
    ///     3. 消除Phi函数：将SSA形式的Phi函数转换为传统的非SSA形式
    ///     4. 重写寄存器引用：将所有指令中的寄存器引用更新为合并后的寄存器
    fn rewrite_liveranges(mut ssa: CFG<SSAOperator>) -> CFG<Operator> {
        /// 步骤1：初始化并查集，用于分析Phi函数中寄存器的等价关系
        /// 并查集可以高效地合并和查询集合关系
        let mut union_find = util::UnionFind::new();

        /// 步骤2：预分配新基本块向量，容量与原SSA CFG相同
        let mut new_blocks = Vec::with_capacity(ssa.len());
        
        /// 步骤3：分析所有基本块中的Phi函数，构建寄存器等价关系
        for block in ssa.get_blocks() {
            /// 获取基本块中指令的迭代器
            let mut ops = block.body.iter();
            
            /// 遍历基本块中的所有Phi函数（Phi函数在基本块开头）
            while let Some(SSAOperator::Phi(rec, operands)) = ops.next() {
                /// 为Phi函数的结果寄存器创建新的集合
                union_find.new_set(*rec);
                
                /// 遍历Phi函数的所有操作数寄存器
                for &op in operands {
                    /// 为每个操作数寄存器创建新的集合
                    union_find.new_set(op);

                    /// 将结果寄存器与操作数寄存器合并到同一个集合
                    /// 表示它们是等价的（通过Phi函数关联）
                    union_find.union(rec, &op);
                }
            }
        }

        /// 步骤4：处理所有基本块，重写寄存器引用
        /// 使用 std::mem::take 获取所有权，避免额外的复制
        for mut block in std::mem::take(&mut ssa.blocks) {
            /// 获取基本块中的指令体
            let mut old = std::mem::take(&mut block.body);
            
            /// 步骤5：重写每条指令中的寄存器引用
            for op in old.iter_mut() {
                /// 定义宏：重写寄存器引用
                /// 如果寄存器在并查集中有等价寄存器（leader），则替换为leader
                macro_rules! rewrite {
                        ($($x:expr),+) => {
                            {
                                $(if let Some(leader) = union_find.find($x) {
                                    *$x = *leader;
                                })+
                            }
                        };
                    }
                
                /// 根据指令类型进行不同的重写处理
                match op {
                    /// 处理普通IR指令
                    SSAOperator::IROp(op_) => match op_ {
                        /// 二元运算指令：重写所有寄存器参数
                        crate::ir::Operator::Add(x, y, z) => rewrite!(x, y, z),
                        crate::ir::Operator::Sub(x, y, z) => rewrite!(x, y, z),
                        crate::ir::Operator::Mult(x, y, z) => rewrite!(x, y, z),
                        crate::ir::Operator::Div(x, y, z) => rewrite!(x, y, z),
                        crate::ir::Operator::And(x, y, z) => rewrite!(x, y, z),
                        crate::ir::Operator::Or(x, y, z) => rewrite!(x, y, z),
                        
                        /// 复制指令：重写源和目标寄存器
                        crate::ir::Operator::Mv(x, y) => rewrite!(x, y),
                        
                        /// 其他二元运算指令
                        crate::ir::Operator::Xor(x, y, z) => rewrite!(x, y, z),
                        
                        /// 内存访问指令
                        crate::ir::Operator::Load(x, y, z) => rewrite!(x, y, z),
                        crate::ir::Operator::Store(x, y, z) => rewrite!(x, y, z),
                        
                        /// 加载地址指令
                        crate::ir::Operator::La(x, _) => rewrite!(x),
                        
                        /// 分支指令：重写比较寄存器
                        crate::ir::Operator::Bgt(x, y, _, _) => rewrite!(x, y),
                        crate::ir::Operator::Bl(x, y, _, _) => rewrite!(x, y),
                        crate::ir::Operator::Beq(x, y, _, _) => rewrite!(x, y),
                        
                        /// 加载立即数指令
                        crate::ir::Operator::Li(x, _) => rewrite!(x),
                        
                        /// 比较指令
                        crate::ir::Operator::Slt(x, y, z) => rewrite!(x, y, z),
                        
                        /// 函数调用指令：重写结果寄存器和所有参数寄存器
                        crate::ir::Operator::Call(x, _, z) => {
                            rewrite!(x);
                            for op in z {
                                rewrite!(op);
                            }
                        }

                        /// 返回指令
                        crate::ir::Operator::Return(x) => rewrite!(x),
                        
                        /// 栈内存访问指令
                        crate::ir::Operator::StoreLocal(x, _) => rewrite!(x),
                        crate::ir::Operator::LoadLocal(x, _) => rewrite!(x),
                        
                        /// 获取参数指令
                        crate::ir::Operator::GetParameter(x, _) => rewrite!(x),
                        
                        /// 其他指令不需要重写
                        _ => {}
                    },
                    /// Phi函数不需要处理，因为后面会被过滤掉
                    SSAOperator::Phi(..) => {}
                }
            }
            
            /// 步骤6：过滤掉Phi函数，只保留普通IR指令
            let new: Vec<_> = old
                .into_iter()
                .filter_map(|op| match op {
                    /// 保留普通IR指令
                    SSAOperator::IROp(op) => Some(op),
                    /// 过滤掉Phi函数
                    SSAOperator::Phi(_, _) => None,
                })
                .collect();
            /// 步骤7：创建新的基本块，包含重写后的指令
            new_blocks.push(block.into_other(new));
        }
        
        /// 步骤8：将SSA形式的CFG转换为传统形式的CFG
        ssa.into_other(new_blocks)
    }
    impl RISCV64 {

        //todo refactor some general fns out of RV64
        /// `pin_liveranges` 函数是寄存器分配中的寄存器固定（Register Pinning）阶段的核心实现。
        /// 该函数的主要作用是将特定的虚拟寄存器**固定**（pin）到特定的物理寄存器上
        /// 确保这些寄存器在后续的寄存器分配中不会被重新分配
        /// 主要功能:
        ///     1. 参数寄存器固定：将函数参数固定到ABI规定的参数寄存器
        ///     2. 返回值寄存器固定：将函数返回值固定到ABI规定的返回值寄存器
        ///     3. 函数调用寄存器固定：将函数调用的参数和返回值固定到正确的寄存器
        ///     4. 插入复制指令：在需要时插入`Mv`指令来维持程序语义
        fn pin_liveranges(cfg: &mut CFG<Operator>) -> HashMap<VReg, RV64Reg> {
            // 步骤1：初始化虚拟寄存器生成器和结果映射
            // gen: 虚拟寄存器生成器，从当前最大寄存器号开始生成新寄存器
            let mut gen = VRegGenerator::starting_at_reg(cfg.get_max_reg());
            
            // res: 结果映射，记录哪些虚拟寄存器被固定到哪些物理寄存器
            let mut res = HashMap::new();
            
            // 步骤2：遍历所有基本块
            for block in cfg.get_blocks_mut() {
                let mut i = 0;
                
                // 步骤3：遍历基本块中的所有指令
                while i < block.body.len() {
                    match &mut block.body[i] {
                        // 情况1：处理GetParameter指令（函数参数）
                        // 格式：GetParameter(目标寄存器, 参数索引)
                        Operator::GetParameter(x, n) if !res.contains_key(x) => {
                            // 获取ABI规定的参数寄存器
                            // 例如：第0个参数固定到X10，第1个参数固定到X11等
                            let pin = RV64Reg::get_param_reg(*n).unwrap();
                            
                            // 生成新的虚拟寄存器
                            let next = gen.next_reg();
                            
                            // 保存原始寄存器
                            let old = *x;
                            
                            // 将GetParameter指令的目标寄存器替换为新寄存器
                            *x = next;
                            
                            // 在GetParameter指令后插入复制指令
                            // 将新寄存器的值复制回原始寄存器
                            block.body.insert(i + 1, Operator::Mv(old, next));
                            
                            // 记录新寄存器被固定到指定的物理寄存器
                            res.insert(next, pin);
                        }
                        
                        // 情况2：处理Call指令（函数调用）
                        // 格式：Call(结果寄存器, 函数标签, 参数寄存器列表)
                        Operator::Call(rec, _, ops) if !res.contains_key(rec) => {
                            // 函数返回值固定到X10（a0寄存器）
                            let pin = RV64Reg::get_param_reg(0).unwrap();
                            
                            // 准备在调用前插入的指令列表
                            let mut before = Vec::new();
                            
                            // 为返回值生成新寄存器
                            let next = gen.next_reg();
                            let old = *rec;
                            
                            // 替换Call指令的结果寄存器
                            *rec = next;
                            
                            // 准备在调用后插入的复制指令
                            let post = Some(Operator::Mv(old, next));
                            
                            // 记录返回值寄存器固定
                            res.insert(next, pin);
                            
                            // 处理所有参数寄存器
                            for (i, op) in ops.iter_mut().enumerate() {
                                // 根据参数索引获取对应的物理寄存器
                                let pin = RV64Reg::get_param_reg(i as u64).unwrap();
                                
                                // 为参数生成新寄存器
                                let next = gen.next_reg();
                                let old = *op;
                                
                                // 替换参数寄存器
                                *op = next;
                                
                                // 在调用前插入复制指令
                                // 将原始参数值复制到新寄存器
                                before.push(Operator::Mv(next, old));
                                
                                // 记录参数寄存器固定
                                res.insert(next, pin);
                            }
                            
                            // 在调用后插入返回值复制指令
                            if let Some(operation) = post {
                                block.body.insert(i + 1, operation)
                            }
                            
                            // 在调用前插入参数复制指令
                            for operation in before {
                                block.body.insert(i, operation)
                            }
                        }
                        
                        // 情况3：处理Return指令（函数返回）
                        // 格式：Return(返回值寄存器)
                        Operator::Return(op) if !res.contains_key(op) => {
                            // 返回值固定到X10（a0寄存器）
                            let pin = RV64Reg::get_param_reg(0).unwrap();
                            
                            // 生成新寄存器
                            let next = gen.next_reg();
                            let old = *op;
                            
                            // 替换Return指令的返回值寄存器
                            *op = next;
                            
                            // 在Return指令前插入复制指令
                            // 将原始返回值复制到新寄存器
                            block.body.insert(i, Operator::Mv(next, old));
                            
                            // 记录返回值寄存器固定
                            res.insert(next, pin);
                        }
                        
                        // 其他指令：不需要处理
                        _ => {}
                    }
                    i += 1;
                }
            }
            
            // 步骤4：更新控制流图中的最大寄存器号
            cfg.set_max_reg(gen.next_reg());
            
            // 步骤5：返回寄存器固定映射
            res
        }
    }

    impl Allocator<RV64Reg> for RISCV64 {

        /// `allocate` 函数是寄存器分配（Register Allocation）的核心实现
        /// 该函数的主要作用是将虚拟寄存器分配到物理寄存器，使用图着色算法解决寄存器分配问题\
        /// 主要功能
        ///     1. 构建冲突图：分析虚拟寄存器之间的冲突关系
        ///     2. 图着色分配：使用Z3求解器进行图着色
        ///     3. 溢出处理：当寄存器不足时，将虚拟寄存器溢出到栈上
        ///     4. 合并优化：合并可以共享同一物理寄存器的虚拟寄存器
        ///     5. 最终分配：将虚拟寄存器替换为物理寄存器
        fn allocate(ssa: CFG<SSAOperator>) -> (CFG<Operator>, HashMap<VReg, RV64Reg>) {
            // 步骤1：重写活跃范围，将SSA形式的CFG转换为传统形式的CFG
            // 同时合并Phi函数相关的寄存器
            let mut lr_cfg = rewrite_liveranges(ssa);

            // 步骤2：主分配循环，使用标签'build_allocate进行循环控制
            let (graph, coloring) = 'build_allocate: loop {
                // 步骤2.1：构建冲突图、可合并寄存器集合和溢出权重
                let (mut graph, mut coalescable, mut spill_weights) =
                    build_interference_graph(&lr_cfg);
                
                // 步骤2.2：固定某些寄存器（如参数寄存器、返回值寄存器）
                let mut pins = RISCV64::pin_liveranges(&mut lr_cfg);
                
                // 步骤2.3：如果存在固定寄存器，重新构建冲突图
                if !pins.is_empty() {
                    (graph, coalescable, spill_weights) = build_interference_graph(&lr_cfg);
                }
                
                // 步骤2.4：将固定寄存器添加到冲突图中
                for lr in pins.keys() {
                    graph.maybe_insert(*lr);
                }
                
                // 步骤2.5：内部循环，尝试进行图着色
                loop {
                    match graph.find_coloring(&pins, coalescable) {
                        // 情况1：图着色失败（寄存器不足）
                        Err(_) => {
                            // 调试输出：显示冲突图
                            println!("conflict! {}", lr_cfg.to_dot());
                            
                            // 选择要溢出的活跃范围：选择溢出权重最大的活跃范围
                            let lr_to_spill = graph
                                .nodes
                                .iter()
                                .max_by_key(|node| spill_weights[&node.live_range])
                                .unwrap()
                                .live_range;
                            
                            // 获取当前分配的栈偏移量
                            let ar = *lr_cfg.get_allocated_ars_mut();
                            
                            // 执行溢出操作：将活跃范围溢出到栈上
                            spill_liverange(&mut lr_cfg, lr_to_spill, ar);
                            
                            // 增加栈偏移量，为下一个溢出预留空间
                            *lr_cfg.get_allocated_ars_mut() += 1;
                            
                            // 继续外层循环，重新尝试分配
                            continue 'build_allocate;
                        }
                        
                        // 情况2：图着色成功
                        Ok((coloring, coalesced)) => {
                            // 检查是否有需要合并的寄存器
                            let empty = coalesced.is_empty();
                            
                            // 处理所有需要合并的寄存器对
                            for (lr1, lr2) in coalesced {
                                // 如果lr1是固定寄存器，将固定关系转移到lr2
                                if let Some(pin) = pins.get(&lr1) {
                                    debug_assert!(
                                        pins.get(&lr2).is_none() || pins.get(&lr2).unwrap() == pin
                                    );
                                    pins.insert(lr2, *pin);
                                    pins.remove(&lr1);
                                }
                                
                                // 在所有基本块中合并lr1到lr2
                                for block in lr_cfg.get_blocks_mut() {
                                    let mut i = 0;
                                    while i < block.body.len() {
                                        // 情况2.1：删除冗余的复制指令 Mv(lr1, lr2)
                                        if let Operator::Mv(left, right) = block.body[i] {
                                            if left == lr1 && right == lr2 {
                                                block.body.remove(i);
                                                continue;
                                            }
                                        }
                                        
                                        // 情况2.2：替换指令中的结果寄存器
                                        let op = &mut block.body[i];
                                        if let Some(rec) = op.receiver_mut() {
                                            if *rec == lr1 {
                                                *rec = lr2;
                                            }
                                        }
                                        
                                        // 情况2.3：替换指令中的依赖寄存器
                                        for op in op.dependencies_mut() {
                                            if *op == lr1 {
                                                *op = lr2;
                                            }
                                        }
                                        i += 1;
                                    }
                                }
                            }
                            
                            // 如果没有需要合并的寄存器，分配完成
                            if empty {
                                break 'build_allocate (graph, coloring);
                            } else {
                                // 有合并操作，重新构建冲突图
                                (graph, coalescable, spill_weights) =
                                    build_interference_graph(&lr_cfg);
                            }
                        }
                    }
                }
            };

            // 步骤3：将虚拟寄存器替换为物理寄存器
            for block in lr_cfg.get_blocks_mut() {
                for op in block.body.iter_mut() {
                    // 替换指令的结果寄存器
                    if let Some(rec) = op.receiver_mut() {
                        *rec = graph
                            .index
                            .get(rec)
                            .map(|&idx| <RV64Reg as Into<usize>>::into(coloring[idx]))
                            .unwrap_or(coloring[0].into()) as u32;
                        // unwrap = no interferences at all
                    }
                    
                    // 替换指令的依赖寄存器
                    for dep in op.dependencies_mut() {
                        *dep = graph
                            .index
                            .get(dep)
                            .map(|&idx| <RV64Reg as Into<usize>>::into(coloring[idx]))
                            .unwrap_or(coloring[0].into()) as u32;
                    }
                }
            }
            
            // 调试输出：显示分配后的控制流图
            #[cfg(feature = "print-cfgs")]
            {
                println!("After register allocation:\n{}", lr_cfg.to_dot());
            }
            
            // 步骤4：返回分配结果
            (
                lr_cfg,
                coloring
                    .into_iter()
                    .map(|color| (<RV64Reg as Into<usize>>::into(color) as VReg, color))
                    .collect(),
            )
        }

        /// `add_procedure_prologues` 函数：为函数调用添加序言和尾声代码
        /// 
        /// 参数：
        /// - cfg: &mut CFG<Operator> - 控制流图的可变引用
        /// - allocs: &HashMap<VReg, RV64Reg> - 虚拟寄存器到物理寄存器的分配映射
        /// 
        /// 功能：根据RISC-V ABI规范，在函数调用点插入调用者保存寄存器的保存/恢复代码，
        ///       在函数入口/出口插入被调用者保存寄存器的保存/恢复代码
        /// 
        /// 约束：调用点必须被隔离（不包括溢出寄存器）
        /// 注释：callsites must be isolated (excluding spills);
        /// callsites must be isolated (excluding spills);
        fn add_procedure_prologues(cfg: &mut CFG<Operator>, allocs: &HashMap<VReg, RV64Reg>) {
            // 步骤1：获取当前已分配的栈帧偏移量（Activation Record Size）
            // ar 表示当前栈帧中已分配的8字节槽位数量
            let ar = *cfg.get_allocated_ars_mut();
            
            // 步骤2：初始化最大栈偏移量，用于跟踪整个函数中需要的最大栈空间
            let mut ar_max = ar;
            
            // 步骤3：计算每个基本块的活跃出集合（live-out）
            // live_out[i] 表示基本块i出口处活跃的寄存器集合
            let live_out = cfg.live_out();
            
            // 步骤4：获取所有被调用者保存寄存器（Callee-Saved Registers）
            // 这些寄存器在函数调用前后必须保持值不变
            let callee_saved = allocs.values().filter(|reg| reg.callee_saved());

            // 步骤5：遍历所有基本块，处理包含函数调用的基本块
            for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate() {
                // 步骤5.1：检查当前基本块是否包含函数调用指令
                if block.body.iter().any(|op| matches!(op, Operator::Call(..))) {
                    // 步骤5.2：初始化当前调用点的栈偏移量
                    let mut ar_ = ar;
                    
                    // 步骤5.3：验证调用点被隔离（只有一个前驱）
                    // 这是函数的前提条件，确保调用点分析的正确性
                    debug_assert_eq!(block.preds.len(), 1);
                    
                    // 步骤5.4：计算需要保存的寄存器集合
                    // 规则：寄存器在调用点活跃，且不是被调用者保存寄存器
                    let to_save: Vec<_> = live_out[i]
                        .intersection(&live_out[block.preds[0]])  // 在调用点和前驱块都活跃
                        .filter(|reg| !allocs[reg].callee_saved()) // 不是被调用者保存寄存器
                        .collect();
                    
                    // 步骤5.5：生成序言代码（调用前保存寄存器）
                    let mut prologue: Vec<_> = to_save
                        .iter()
                        .map(|&&reg| {
                            // 为每个需要保存的寄存器生成存储指令
                            let res = Operator::StoreLocal(reg, ar_);
                            ar_ += 1;  // 递增栈偏移量
                            res
                        })
                        .collect();
                    
                    // 步骤5.6：重置栈偏移量，用于尾声代码
                    let mut ar_ = ar;
                    
                    // 步骤5.7：生成尾声代码（调用后恢复寄存器）
                    let mut epilogue: Vec<_> = to_save
                        .iter()
                        .map(|&&reg| {
                            // 为每个需要恢复的寄存器生成加载指令
                            let res = Operator::LoadLocal(reg, ar_);
                            ar_ += 1;  // 递增栈偏移量
                            res
                        })
                        .collect();
                    
                    // 步骤5.8：构建新的指令序列
                    // 顺序：序言代码 + 原始指令 + 尾声代码
                    prologue.append(&mut block.body);
                    
                    // 步骤5.9：保存并移除跳转指令（如果有的话）
                    let jump = prologue.pop();
                    
                    // 步骤5.10：将尾声代码添加到序言之后
                    prologue.append(&mut epilogue);
                    
                    // 步骤5.11：恢复跳转指令（放在尾声代码之后）
                    if let Some(op) = jump {
                        prologue.push(op)
                    }
                    
                    // 步骤5.12：用新的指令序列替换原始指令序列
                    block.body = prologue;
                    
                    // 步骤5.13：更新最大栈偏移量
                    ar_max = std::cmp::max(ar_max, ar_);
                }
            }

            // 步骤6：设置当前栈偏移量为最大值
            let mut ar = ar_max;
            *cfg.get_allocated_ars_mut() = ar_max;

            // 步骤7：处理被调用者保存寄存器（Callee-Saved Registers）
            for &saved in callee_saved {
                // 步骤7.1：在函数入口保存被调用者保存寄存器
                cfg.get_block_mut(cfg.get_entry())
                    .body
                    .insert(0, Operator::StoreLocal(usize::from(saved) as VReg, ar));
                
                // 步骤7.2：在函数出口恢复被调用者保存寄存器
                cfg.get_block_mut(cfg.get_exit())
                    .body
                    .push(Operator::LoadLocal(usize::from(saved) as VReg, ar));
                
                // 步骤7.3：递增栈偏移量
                ar += 1;
            }
            
            // 步骤8：更新最终的栈帧大小
            *cfg.get_allocated_ars_mut() = ar;
        }
    }
    #[cfg(test)]
    mod tests {
        use std::collections::HashMap;

        use crate::{
            backend::register_allocation::{Allocator, RV64Reg},
            ir::{Operator, CFG},
            parser,
        };

        #[test]
        fn construct_graph() {
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
            println!("{}", crate::ir::Displayable(&body[..]));

            let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
            let mut ssa = cfg.into_ssa();
            crate::ssa::optimization_sequence(&mut ssa).unwrap();
            super::conventionalize_ssa(&mut ssa);

            let cfg = super::rewrite_liveranges(ssa);
            println!("live ranges: {}", cfg.to_dot());
            let (graph, coalescable, _) = super::build_interference_graph(&cfg);

            println!("{}", graph.to_dot());

            let coloring = graph.find_coloring::<RV64Reg>(&HashMap::default(), coalescable);
            assert!(coloring.is_ok());
            println!(
                "found coloring:\n{}",
                graph.to_dot_colored(Some(coloring.unwrap().0))
            );
        }
        #[test]
        fn allocate_program() {
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
            crate::ssa::optimization_sequence(&mut ssa).unwrap();
            super::conventionalize_ssa(&mut ssa);

            let allocation = super::RISCV64::allocate(ssa);
            println!("allocation: {:?}", allocation.1);
            println!("allocated_graph: {}", allocation.0.to_dot());
        }
        #[test]
        fn allocate_program_calls_no_spill() {
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
            crate::ssa::optimization_sequence(&mut ssa).unwrap();
            super::conventionalize_ssa(&mut ssa);

            let allocation = super::RISCV64::allocate(ssa);
            assert_eq!(
                allocation.0.blocks[3].body[0],
                Operator::Call(10, "myfun".into(), vec![10])
            );
            assert_eq!(
                allocation.0.blocks[0].body[0],
                Operator::GetParameter(10, 0)
            );
            assert_eq!(allocation.0.blocks[5].body[0], Operator::Return(10));
            println!("allocation: {:?}", allocation.1);
            println!("allocated_graph: {}", allocation.0.to_dot());
        }
        // not spilling anymore after better coalescing
        //     #[test]
        // fn allocate_program_calls_spill() {
        //     let input = "
        // myvar3 :: Bool = false;
        // lambda myfun(myvar3 :: Int, myvar5 :: Int) :: Int {
        //     myvar4 :: Int = 0;
        //     i :: Int = 100;
        //     while (i >= 0) do {
        //         myvar4 = myfun(3, myvar4);
        //         i = i - 1;
        //     }
        //    return myvar4;
        // }
        // myvar2 :: Bool = true;
        // ";

        //     let p = parser::parse_and_validate(&input).unwrap();
        //     let mut context = crate::ir::Context::new();
        //     crate::ir::translate_program(&mut context, &p);
        //     let funs = context.get_functions();
        //     let fun = funs.get("myfun").unwrap();
        //     let body = fun.get_body();

        //     let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
        //     let mut ssa = cfg.into_ssa();
        //     crate::ssa::optimization_sequence(&mut ssa).unwrap();
        //     super::conventionalize_ssa(&mut ssa);

        //     let allocation = super::RISCV64::allocate(ssa);
        //     println!("allocated: {}", allocation.0.to_dot());
        //     assert_eq!(
        //         &allocation.0.blocks[3].body[0..=2],
        //         &[
        //             Operator::LoadLocal(11, 0),
        //             Operator::Call(10, "myfun".into(), vec![10, 11]),
        //             Operator::StoreLocal(10, 0)
        //         ]
        //     );
        //     assert_eq!(
        //         allocation.0.blocks[0].body[0],
        //         Operator::GetParameter(10, 0)
        //     );
        //     println!("allocation: {:?}", allocation.1);
        //     println!("allocated_graph: {}", allocation.0.to_dot());
        // }
        #[test]
        fn program_calls_spill_prologues() {
            let input = "
        myvar3 :: Bool;
        lambda myfun(myvar3 :: Int, myvar5 :: Int) :: Int {
            myvar4 :: Int = 0;
            i :: Int = 100;
            while (i >= 0) do {
                myvar4 = myfun(3, myvar4);
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
            crate::ssa::optimization_sequence(&mut ssa).unwrap();
            super::conventionalize_ssa(&mut ssa);

            let mut allocation = super::RISCV64::allocate(ssa);
            super::RISCV64::add_procedure_prologues(&mut allocation.0, &allocation.1);
            assert!(allocation.0.blocks[3]
                .body
                .iter()
                .take(3)
                .all(|op| matches!(op, Operator::StoreLocal(..))));
        }
    }
}

mod instruction_selection {
    use std::{
        collections::{HashMap, HashSet, VecDeque},
        fmt::Display,
        rc::Rc,
    };

    use crate::ir::{Operator, VReg, CFG};

    use super::register_allocation::RV64Reg;
    #[derive(Debug, Clone, PartialEq, Eq, Hash)]
    #[allow(non_camel_case_types, clippy::upper_case_acronyms)]
    pub enum RV64Operation {
        ADD(RV64Reg, RV64Reg, RV64Reg),
        ADDI(RV64Reg, RV64Reg, i16),
        SUB(RV64Reg, RV64Reg, RV64Reg),
        SQ(RV64Reg, RV64Reg, i16),
        LQ(RV64Reg, RV64Reg, i16),
        AND(RV64Reg, RV64Reg, RV64Reg),
        OR(RV64Reg, RV64Reg, RV64Reg),
        XOR(RV64Reg, RV64Reg, RV64Reg),
        MUL(RV64Reg, RV64Reg, RV64Reg),
        DIV(RV64Reg, RV64Reg, RV64Reg),
        SLT(RV64Reg, RV64Reg, RV64Reg),
        PSEUD_LA(RV64Reg, Rc<str>),
        PSEUD_CALL(Rc<str>),
        PSEUD_RET,
        PSEUD_J(Rc<str>),
        PSEUD_LI(RV64Reg, i64),
        PSEUD_LABEL(Rc<str>),
        BEQ(RV64Reg, RV64Reg, Rc<str>),
        BGE(RV64Reg, RV64Reg, Rc<str>),
        BL(RV64Reg, RV64Reg, Rc<str>),
    }

    impl CFG<RV64Operation> {
        
        /// `linearize` 函数：将控制流图线性化为指令序列
        /// 
        /// 返回值：Vec<RV64Operation> - 线性化的RISC-V指令序列
        /// 
        /// 功能：执行深度优先的图遍历，将控制流图转换为线性指令序列
        /// 这是代码生成的最后一步，生成可以直接汇编的指令序列
        pub fn linearize(self) -> Vec<RV64Operation> {
            // 步骤1：初始化数据结构
            // placed: 记录已经放置到线性序列中的基本块标签
            let mut placed = HashSet::new();
            
            // worklist: 工作队列，用于深度优先遍历控制流图
            // 使用VecDeque作为双端队列，支持前端和后端操作
            let mut worklist = VecDeque::new();
            
            // 将入口块添加到工作队列
            worklist.push_back(self.get_block(self.get_entry()));
            
            // result: 存储最终的线性指令序列
            let mut result = Vec::new();
            
            // 步骤2：主循环 - 深度优先遍历控制流图
            // 使用while let模式匹配，从工作队列中取出下一个要处理的基本块
            while let Some(to_place) = worklist.pop_front() {
                // 步骤2.1：检查基本块是否已经处理过
                // 避免重复处理同一个基本块（循环控制流）
                if placed.contains(&to_place.label) {
                    continue;  // 已处理，跳过
                }
                
                // 步骤2.2：为当前基本块插入标签指令
                // PSEUD_LABEL是伪指令，表示基本块的标签
                result.push(RV64Operation::PSEUD_LABEL(Rc::clone(&to_place.label)));
                
                // 步骤2.3：遍历当前基本块中的所有指令
                for op in to_place.body.iter() {
                    // 根据指令类型进行不同的处理
                    match op {
                        // 情况1：处理无条件跳转指令 PSEUD_J
                        // 格式：PSEUD_J(target_label)
                        RV64Operation::PSEUD_J(t) => {
                            // 检查目标标签是否已经放置
                            if placed.contains(t) {
                                // 目标已放置：直接添加跳转指令
                                result.push(op.clone());
                            } else {
                                // 目标未放置：将目标块添加到工作队列前端
                                // 使用前端添加实现深度优先遍历
                                worklist.push_front(
                                    self.blocks.iter().find(|b| &b.label == t).unwrap(),
                                );
                            }
                        }

                        // 情况2：处理条件分支指令
                        // 包括：BEQ（相等分支）、BGE（大于等于分支）、BL（小于分支）
                        // 格式：BEQ/BGE/BL(reg1, reg2, target_label)
                        RV64Operation::BEQ(_, _, l)
                        | RV64Operation::BGE(_, _, l)
                        | RV64Operation::BL(_, _, l) => {
                            // 断言：条件分支指令必须有两个后继
                            debug_assert_eq!(to_place.children.len(), 2);
                            
                            // 获取false分支（第二个后继）
                            let r = self.get_block(to_place.children[1]);
                            
                            // 添加条件分支指令到结果序列
                            result.push(op.clone());
                            
                            // 检查false分支是否已经放置
                            if placed.contains(&r.label) {
                                // false分支已放置：添加无条件跳转到false分支
                                result.push(RV64Operation::PSEUD_J(Rc::clone(&r.label)));
                            } else {
                                // false分支未放置：将false分支添加到工作队列前端
                                worklist.push_front(r);
                            }
                            
                            // 将true分支（目标标签）添加到工作队列后端
                            // 使用后端添加，确保true分支在false分支之后处理
                            worklist.push_back(self.blocks.iter().find(|b| &b.label == l).unwrap());
                        }
                        
                        // 情况3：处理其他所有指令
                        // 包括：算术指令、内存访问指令、伪指令等
                        op => {
                            // 直接添加到结果序列
                            result.push(op.clone());
                        }
                    }
                }
                
                // 步骤2.4：标记当前基本块为已处理
                placed.insert(Rc::clone(&to_place.label));
            }
            
            // 步骤3：返回线性化的指令序列
            result
        }
    }

    impl Display for RV64Operation {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RV64Operation::ADD(r1, r2, r3) => write!(f, "add {r1},{r2},{r3}"),
                RV64Operation::ADDI(r1, r2, r3) => write!(f, "addi {r1},{r2},{r3}"),
                RV64Operation::SUB(r1, r2, r3) => write!(f, "sub {r1},{r2},{r3}"),
                RV64Operation::SQ(r1, r2, r3) => write!(f, "sd {r1},{r3}({r2})"),
                RV64Operation::LQ(r1, r2, r3) => write!(f, "ld {r1},{r3}({r2})"),
                RV64Operation::AND(r1, r2, r3) => write!(f, "and {r1},{r2},{r3}"),
                RV64Operation::OR(r1, r2, r3) => write!(f, "or {r1},{r2},{r3}"),
                RV64Operation::XOR(r1, r2, r3) => write!(f, "xor {r1},{r2},{r3}"),
                RV64Operation::MUL(r1, r2, r3) => write!(f, "mul {r1},{r2},{r3}"),
                RV64Operation::DIV(r1, r2, r3) => write!(f, "div {r1},{r2},{r3}"),
                RV64Operation::SLT(r1, r2, r3) => write!(f, "slt {r1},{r2},{r3}"),
                RV64Operation::PSEUD_LA(r1, r2) => write!(f, "la {r1},{r2}"),
                RV64Operation::PSEUD_CALL(r1) => write!(f, "call {r1}"),
                RV64Operation::PSEUD_RET => write!(f, "ret"),
                RV64Operation::PSEUD_J(r1) => write!(f, "j .{r1}"),
                RV64Operation::PSEUD_LI(r1, r2) => write!(f, "li {r1},{r2}"),
                RV64Operation::PSEUD_LABEL(l) => write!(f, ".{l}:"),
                RV64Operation::BEQ(r1, r2, r3) => write!(f, "beq {r1},{r2},.{r3}"),
                RV64Operation::BGE(r1, r2, r3) => write!(f, "bge {r1},{r2},.{r3}"),
                RV64Operation::BL(r1, r2, r3) => write!(f, "bl {r1},{r2},.{r3}"),
            }
        }
    }

    /// `select_instructions` 函数：将IR控制流图转换为RISC-V指令序列
    /// 
    /// 参数：
    /// - mut cfg: CFG<Operator> - IR控制流图（所有权传递）
    /// - allocation: &HashMap<VReg, RV64Reg> - 虚拟寄存器到物理寄存器的分配映射
    /// 
    /// 返回值：CFG<RV64Operation> - RISC-V指令的控制流图
    /// 
    /// 功能：将平台无关的IR指令转换为RISC-V 64位架构的机器指令
    /// 这是编译器后端的指令选择阶段，负责生成目标架构的指令序列
    pub fn select_instructions(
        mut cfg: CFG<Operator>,
        allocation: &HashMap<VReg, RV64Reg>,
    ) -> CFG<RV64Operation> {
        // 导入RISC-V操作枚举，简化代码
        use RV64Operation::*;
        
        // 步骤1：为每个基本块创建新的指令体向量
        // new_bodies[i] 存储基本块i转换后的RISC-V指令序列
        let mut new_bodies: Vec<Vec<RV64Operation>> = vec![Vec::new(); cfg.len()];
        
        // 步骤2：获取退出块的标签，用于返回指令
        let exit_label = Rc::clone(&cfg.get_block(cfg.get_exit()).label);

        // 步骤3：遍历所有基本块，进行指令选择
        for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate() {
            // 步骤3.1：获取基本块的原始指令体（所有权转移）
            let body = std::mem::take(&mut block.body);

            // 步骤3.2：遍历基本块中的每条IR指令
            for op in body {
                // 宏定义：处理二元运算指令
                // 将IR二元运算映射到RISC-V二元运算指令
                macro_rules! binary_op {
                    ($x:expr, $y:expr, $z:expr, $p:path) => {{
                        // 使用寄存器分配映射获取物理寄存器
                        new_bodies[i].push($p(allocation[&$x], allocation[&$y], allocation[&$z]));
                    }};
                }
                
                // 宏定义：获取物理寄存器
                // 将虚拟寄存器转换为物理寄存器
                macro_rules! get_regs {
                    ($($x:expr),+) => {
                        ($(allocation[&$x]),+)
                    };
                }
                
                // 步骤3.3：根据IR指令类型进行指令选择
                match op {
                    // 算术运算指令：直接映射到RISC-V指令
                    Operator::Add(x, y, z) => binary_op!(x, y, z, ADD),
                    Operator::Sub(x, y, z) => binary_op!(x, y, z, SUB),
                    Operator::Mult(x, y, z) => binary_op!(x, y, z, MUL),
                    Operator::Div(x, y, z) => binary_op!(x, y, z, DIV),
                    Operator::And(x, y, z) => binary_op!(x, y, z, AND),
                    Operator::Or(x, y, z) => binary_op!(x, y, z, OR),
                    
                    // 复制指令：映射到ADDI指令（加0立即数）
                    Operator::Mv(x, y) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(ADDI(x, y, 0));
                    }
                    
                    // 逻辑运算指令
                    Operator::Xor(x, y, z) => binary_op!(x, y, z, XOR),
                    
                    // 内存加载指令：分解为地址计算 + 加载
                    Operator::Load(x, y, z) => {
                        let (x, y, z) = get_regs!(x, y, z);
                        // 步骤1：计算地址：x = y + z
                        new_bodies[i].push(ADD(x, y, z));
                        // 步骤2：从内存加载：x = [x]
                        new_bodies[i].push(LQ(x, x, 0));
                    }
                    
                    // 内存存储指令：分解为地址计算 + 存储 + 地址恢复
                    Operator::Store(x, y, z) => {
                        let (x, y, z) = get_regs!(x, y, z);
                        // 断言：地址寄存器不能与源寄存器相同
                        assert!(
                            x != z,
                            "store: address register may not alias original register"
                        );
                        // 步骤1：计算地址：z = z + y
                        new_bodies[i].push(ADD(z, z, y));
                        // 步骤2：存储到内存：[z] = x
                        new_bodies[i].push(SQ(x, z, 0));
                        // 步骤3：恢复地址：z = z - y
                        new_bodies[i].push(SUB(z, z, y));
                    }
                    
                    // 加载地址指令：映射到伪指令LA
                    Operator::La(x, y) => {
                        let x = get_regs!(x);
                        new_bodies[i].push(PSEUD_LA(x, y));
                    }
                    
                    // 分支指令：大于分支映射到BGE（大于等于）
                    Operator::Bgt(x, y, z, _) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(BGE(x, y, z));
                    }
                    
                    // 分支指令：小于分支映射到BL（小于）
                    Operator::Bl(x, y, z, _) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(BL(x, y, z));
                    }
                    
                    // 无条件跳转指令：映射到伪指令J
                    Operator::J(x) => {
                        new_bodies[i].push(PSEUD_J(x));
                    }
                    
                    // 相等分支指令：映射到BEQ（相等）
                    Operator::Beq(x, y, z, _) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(BEQ(x, y, z));
                    }
                    
                    // 加载立即数指令：映射到伪指令LI
                    Operator::Li(x, y) => {
                        let x = get_regs!(x);
                        new_bodies[i].push(PSEUD_LI(x, y));
                    }
                    
                    // 小于比较指令：映射到SLT（小于设置）
                    Operator::Slt(x, y, z) => binary_op!(x, y, z, SLT),
                    
                    // 函数调用指令：映射到伪指令CALL
                    Operator::Call(_, y, z) => {
                        // 断言：参数数量不超过7个（RISC-V ABI限制）
                        debug_assert!(z.len() <= 7);
                        // 参数寄存器已在寄存器分配阶段处理
                        new_bodies[i].push(PSEUD_CALL(y));
                    }
                    
                    // 返回指令：映射到跳转到退出标签
                    Operator::Return(_) => {
                        // 返回值已在寄存器分配阶段固定到x10
                        new_bodies[i].push(PSEUD_J(Rc::clone(&exit_label)));
                    }
                    
                    // 标签指令：在CFG中不应出现
                    Operator::Label(_) => {
                        #[cfg(debug_assertions)]
                        unreachable!("label should be excluded in CFG");
                        #[cfg(not(debug_assertions))]
                        unsafe {
                            std::hint::unreachable_unchecked()
                        }
                    }
                    
                    // 获取参数指令：已在寄存器分配阶段处理
                    Operator::GetParameter(_, _) => {
                        // 参数已在寄存器分配阶段固定到正确寄存器
                    }
                    
                    // 存储到局部栈帧：映射到SQ指令
                    Operator::StoreLocal(x, y) => {
                        let x = get_regs!(x);
                        // 栈偏移量转换为字节：y * 8
                        new_bodies[i].push(SQ(x, RV64Reg::X2, (y * 8) as i16));
                    }
                    
                    // 从局部栈帧加载：映射到LQ指令
                    Operator::LoadLocal(x, y) => {
                        let x = get_regs!(x);
                        // 栈偏移量转换为字节：y * 8
                        new_bodies[i].push(LQ(x, RV64Reg::X2, (y * 8) as i16));
                    }
                    
                    // 空操作指令：忽略
                    Operator::Nop => {}
                }
            }
        }
        
        // 步骤4：创建新的基本块，包含转换后的指令
        let mut new_blocks: Vec<_> = std::mem::take(&mut cfg.blocks)
            .into_iter()
            .enumerate()
            .map(|(i, block)| block.into_other(std::mem::take(&mut new_bodies[i])))
            .collect();
        
        // 步骤5：生成函数序言代码（在入口块）
        // 5.1：保存返回地址到栈上
        new_blocks[cfg.get_entry()].body.insert(
            0,
            SQ(
                RV64Reg::X1,  // 返回地址寄存器（ra）
                RV64Reg::X2,  // 栈指针寄存器（sp）
                (*cfg.get_allocated_ars_mut() as i16) * 8,  // 栈偏移量（字节）
            ),
        );
        
        // 5.2：增加栈帧大小计数
        *cfg.get_allocated_ars_mut() += 1;
        
        // 5.3：调整栈指针（分配栈空间）
        new_blocks[cfg.get_entry()].body.insert(
            0,
            ADDI(
                RV64Reg::X2,  // 栈指针寄存器（sp）
                RV64Reg::X2,  // 源寄存器也是sp
                (*cfg.get_allocated_ars_mut() as i16) * -8,  // 负偏移，向下增长栈
            ),
        );
        
        // 步骤6：生成函数尾声代码（在退出块）
        new_blocks[cfg.get_exit()].body.extend([
            // 6.1：恢复返回地址
            LQ(
                RV64Reg::X1,  // 返回地址寄存器（ra）
                RV64Reg::X2,  // 栈指针寄存器（sp）
                (*cfg.get_allocated_ars_mut() as i16 - 1) * 8,  // 栈偏移量（字节）
            ),
            // 6.2：恢复栈指针（释放栈空间）
            ADDI(
                RV64Reg::X2,  // 栈指针寄存器（sp）
                RV64Reg::X2,  // 源寄存器也是sp
                (*cfg.get_allocated_ars_mut() as i16) * 8,  // 正偏移，向上收缩栈
            ),
            // 6.3：返回指令
            PSEUD_RET,
        ]);
        
        // 步骤7：返回转换后的控制流图
        cfg.into_other(new_blocks)
    }
    
    #[cfg(test)]
    mod tests {
        use super::super::register_allocation::*;
        use crate::{
            ir::{Displayable, CFG},
            parser,
        };

        #[test]
        fn select_instructions_loop() {
            let input = "
        myvar3 :: Bool;
        lambda myfun(myvar3 :: Int, myvar5 :: Int) :: Int {
            myvar4 :: Int = 0;
            i :: Int = 100;
            while (i >= 0) do {
                myvar4 = myfun(3, myvar4);
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
            crate::ssa::optimization_sequence(&mut ssa).unwrap();
            conventionalize_ssa(&mut ssa);

            let mut allocation = RISCV64::allocate(ssa);
            RISCV64::add_procedure_prologues(&mut allocation.0, &allocation.1);
            let native = super::select_instructions(allocation.0, &allocation.1);
            println!("native allocated: {}", native.to_dot());
            let linear = native.linearize();
            println!("linear:\n{}", Displayable(&linear));
        }
        #[test]
        fn select_instructions_fib() {
            let input = "
lambda fib(n :: Int) :: Int {
    if n < 2 then {
        return n;
    } else {}
    return fib(n - 2) + fib(n - 1);
}
        ";
            let p = parser::parse_and_validate(input).unwrap();
            let mut context = crate::ir::Context::new();
            crate::ir::translate_program(&mut context, &p);
            let funs = context.get_functions();
            let fun = funs.get("fib").unwrap();
            let body = fun.get_body();

            let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
            let mut ssa = cfg.into_ssa();
            crate::ssa::optimization_sequence(&mut ssa).unwrap();
            conventionalize_ssa(&mut ssa);

            let mut allocation = RISCV64::allocate(ssa);
            RISCV64::add_procedure_prologues(&mut allocation.0, &allocation.1);
            let native = super::select_instructions(allocation.0, &allocation.1);
            println!("native allocated: {}", native.to_dot());
            let linear = native.linearize();
            println!("linear:\n{}", Displayable(&linear));
        }
    }
}
