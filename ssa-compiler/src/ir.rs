// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
//! Intermediate Representation
//!
//! The compiler's IR is a three-address, register based code with an infinite number of registers.
//!
//! | Instruction | Ad1 | Ad2 | Ad3 |
//! | ----------- | --- | --- | --- |
//! | add ad1, ad2, ad3 | result | op1 | op2 |
//! | sub ad1, ad2, ad3 | result | op1 | op2 |
//! | mult ad1, ad2, ad3 | result | op1 | op2 |
//! | div ad1, ad2, ad3 | result | op1 | op2 |
//! | and ad1, ad2, ad3 | result | op1 | op2 |
//! | or ad1, ad2, ad3 | result | op1 | op2 |
//! | mv ad1, ad2 | result | op1 | NA |
//! | xor ad1, ad2, ad3 | result | op1 | op2 |
//! | load ad1, ad2, ad3 | result | offset | memory base |
//! | store ad1, ad2, ad3 | value | offset | memory base |
//! | la ad1, @label | result | NA | NA |
//! | bgt ad1, ad2, @taken, @else | op1 | op2 | NA |
//! | bl ad1, ad2, @taken, @else | op1 | op2 | NA |
//! | j @label | NA | NA | NA |
//! | beq ad1, ad2, @taken, @else | op1 | op2 | NA |
//! | li ad1, imm  | result | NA | NA |
//! | slt ad1, ad2, ad3 | result | op1 | op2 |
//! | call ad1, @label (ad2 ... adn) | result | arg1 | ... |
//! | return ad1 | result | NA | NA |
//!
//! - Labels are represented as immediate string arguments to the op.
//! - Memory locations are symbolic, an execution could for example
//!   assign a random value to each label.
//! - ad1, ad2, ad3 are registers.
//! - Registers hold 8 bytes.
//! - Negative numbers use 2's complement.
//! - Memory locations store a single register.
//!
//! ## Code Shape
//!
//! ```bnf
//! lin: transforms AST into IR before inserting line, returns register name of result.  
//! name: allocates register name.  
//! label: allocates memory location.  
//! body: inserts IR of AST.  
//!
//! (L) + (R) =>    add name() lin(L) lin(R)
//! (L) - (R) =>    sub name() lin(L) lin(R)
//! (L) * (R) =>    mul name() lin(L) lin(R)
//! (L) / (R) =>    div name() lin(L) lin(R)
//! (L) or (R) =>   ...
//! (L) and (R) =>  ...
//! (L) xor (R) =>  ...
//! not (L) =>      li name() -1 // r_new
//!                 xor lin(L) r_new
//! (L) >= (R) =>   slt name() lin(L) lin(R) // r_new
//!                 li name() 1 // r_new2
//!                 xor name() r_new r_new2
//! (L) < (R) =>    slt name() lin(L) lin(R)
//! (L) == (R) =>   xor name() lin(L) lin(R) // r_new
//!                 li name() 1 // r_new2
//!                 slt name() r_new r_new2
//! true =>         li name() 1
//! false =>        li name() 0
//! number =>       li name() number
//! ident = (R)     mv name() lin(R)
//! ident           name(ident) // reuse register
//! global          la name() global
//! global = (R)    la name() global // r_new
//!                 store lin(R) 0 r_new
//! if (C) then (I)
//! else (E) =>     li name() 1 // r_new
//!                 beq lin(C) r_new @l1 @l2
//!                 label(): body(I) // @l1
//!                 j @l3
//!                 label(): body(E) // @l2
//!                 j @l3
//!                 label(): ... // @l3
//! while (C)
//! do (B) =>       j @l1
//!                 label():    // @l1
//!                 li name() 0 // r_new
//!                 beq lin(C) r_ne2 @l2 @l3
//!                 label():    // @l3
//!                 body(B)
//!                 j @l1
//!                 label(): ... // @l2
//! identifier((arg0), (arg1), ...)
//! =>              j @l1
//!                 label():    // @l1
//!                 call @label(identifier) (lin(arg0), lin(arg1), ...)
//!                 j @l2
//!                 label():    // @l2
//! return (E) =>   return lin(E)
//!                 label():    // dead
//!
//! ```

use parser_defs::{Any, Type};
use std::{
    collections::{HashMap, HashSet, VecDeque},
    fmt::Display,
    rc::Rc,
};

use crate::util::SheafTable;

pub type VReg = u32;

/// `VRegGenerator`是一个三元组 `(u32, u32, String)`
/// __第一个字段__：下一个虚拟寄存器编号
/// __第二个字段__：下一个标签编号
/// __第三个字段__：标签前缀
pub struct VRegGenerator(u32, u32, String);
impl VRegGenerator {
    /// 从指定寄存器编号开始生成。在SSA转换后继续生成新寄存器
    pub fn starting_at_reg(at: u32) -> Self {
        Self(at, 0, "_LABEL_".into())
    }

    /// 使用自定义前缀生成标签
    pub fn with_prefix(prefix: String) -> Self {
        Self(0, 0, prefix)
    }

    /// 创建默认的生成器
    pub fn new() -> Self {
        Self(0, 0, "_LABEL_".into())
    }

    /// 生成下一个虚拟寄存器编号
    /// 递增计数器，返回当前值
    pub fn next_reg(&mut self) -> u32 {
        let res = self.0;
        self.0 += 1;
        res
    }

    /// 生成下一个标签名称。前缀 + 编号
    pub fn next_label(&mut self) -> String {
        let res = format!("{}{}", self.2, self.1);
        self.1 += 1;
        res
    }
}
impl Default for VRegGenerator {
    fn default() -> Self {
        Self::new()
    }
}
#[derive(Debug, PartialEq, Eq, Clone)]
pub enum Operator {
    // 算术运算指令
    Add(VReg, VReg, VReg),      // 加法：rd = rs1 + rs2
    Sub(VReg, VReg, VReg),      // 减法：rd = rs1 - rs2
    Mult(VReg, VReg, VReg),     // 乘法：rd = rs1 * rs2
    Div(VReg, VReg, VReg),      // 除法：rd = rs1 / rs2
    
    // 逻辑运算指令
    And(VReg, VReg, VReg),      // 按位与：rd = rs1 & rs2
    Or(VReg, VReg, VReg),       // 按位或：rd = rs1 | rs2
    Xor(VReg, VReg, VReg),      // 按位异或：rd = rs1 ^ rs2
    
    // 移动指令
    Mv(VReg, VReg),             // 寄存器移动：rd = rs
    
    // 内存访问指令
    Load(VReg, VReg, VReg),     // 内存加载：rd = mem[base + offset]
    Store(VReg, VReg, VReg),    // 内存存储：mem[base + offset] = value
    
    // 地址加载指令
    La(VReg, Rc<str>),          // 加载地址：rd = &label
    
    // 分支指令
    Bgt(VReg, VReg, Rc<str>, Rc<str>),  // 大于分支：if rs1 > rs2 goto label1 else goto label2
    Bl(VReg, VReg, Rc<str>, Rc<str>),   // 小于分支：if rs1 < rs2 goto label1 else goto label2
    Beq(VReg, VReg, Rc<str>, Rc<str>),  // 相等分支：if rs1 == rs2 goto label1 else goto label2
    
    // 跳转指令
    J(Rc<str>),                 // 无条件跳转：goto label
    
    // 立即数指令
    Li(VReg, i64),              // 加载立即数：rd = immediate
    
    // 比较指令
    Slt(VReg, VReg, VReg),      // 小于设置：rd = (rs1 < rs2) ? 1 : 0
    
    // 函数调用指令
    Call(VReg, Rc<str>, Vec<VReg>), // 函数调用：rd = func(args...)
    
    // 返回指令
    Return(VReg),               // 函数返回：return value
    
    // 标签指令
    Label(Rc<str>),             // 基本块标签：label:
    
    // 参数处理指令
    GetParameter(VReg, u64),    // 获取参数：rd = param[n]
    
    // 栈内存访问指令
    StoreLocal(VReg, u64),      // 存储局部变量：stack[offset] = value
    LoadLocal(VReg, u64),       // 加载局部变量：rd = stack[offset]
    
    // 空操作指令
    Nop,                        // 空操作：无效果
}

impl Operator {
    // 获取指令的依赖寄存器（使用的寄存器）
    pub fn dependencies(&self) -> Vec<VReg> {
        match self {
            // 二元运算指令：依赖两个源寄存器
            Operator::Add(_, y, z)
            | Operator::Sub(_, y, z)
            | Operator::Mult(_, y, z)
            | Operator::Div(_, y, z)
            | Operator::Bl(z, y, _, _)    // 注意：分支指令的参数顺序不同
            | Operator::Slt(_, y, z)
            | Operator::Bgt(z, y, _, _)
            | Operator::Load(_, y, z)
            | Operator::Beq(z, y, _, _)
            | Operator::And(_, y, z)
            | Operator::Xor(_, y, z)
            | Operator::Or(_, y, z) => {
                vec![*y, *z]
            }
            
            // 单操作数指令：依赖一个源寄存器
            Operator::StoreLocal(y, _) | Operator::Mv(_, y) => {
                vec![*y]
            }
            
            // 存储指令：依赖三个源寄存器
            Operator::Store(x, y, z) => {
                vec![*x, *y, *z]
            }
            
            // 函数调用指令：依赖所有参数寄存器
            Operator::Call(_, _, z) => z.clone(),
            
            // 返回指令：依赖返回值寄存器
            Operator::Return(x) => vec![*x],
            
            // 其他指令：没有依赖寄存器
            _ => vec![],
        }
    }
    
    // 获取指令的依赖寄存器（可变引用）
    pub fn dependencies_mut(&mut self) -> Vec<&mut VReg> {
        match self {
            // 二元运算指令：返回两个源寄存器的可变引用
            Operator::Add(_, y, z)
            | Operator::Sub(_, y, z)
            | Operator::Mult(_, y, z)
            | Operator::Div(_, y, z)
            | Operator::Bl(z, y, _, _)
            | Operator::Slt(_, y, z)
            | Operator::Bgt(z, y, _, _)
            | Operator::Load(_, y, z)
            | Operator::Beq(z, y, _, _)
            | Operator::And(_, y, z)
            | Operator::Xor(_, y, z)
            | Operator::Or(_, y, z) => {
                vec![y, z]
            }
            
            // 单操作数指令：返回一个源寄存器的可变引用
            Operator::StoreLocal(y, _) | Operator::Mv(_, y) => {
                vec![y]
            }
            
            // 存储指令：返回三个源寄存器的可变引用
            Operator::Store(x, y, z) => {
                vec![x, y, z]
            }
            
            // 函数调用指令：返回所有参数寄存器的可变引用
            Operator::Call(_, _, z) => z.iter_mut().collect(),
            
            // 返回指令：返回返回值寄存器的可变引用
            Operator::Return(x) => vec![x],
            
            // 其他指令：没有依赖寄存器
            _ => vec![],
        }
    }
    
    // 获取指令的结果寄存器（如果有的话）
    pub fn receiver(&self) -> Option<VReg> {
        match self {
            // 有结果寄存器的指令：返回结果寄存器
            Operator::Add(x, _, _)
            | Operator::Sub(x, _, _)
            | Operator::Mult(x, _, _)
            | Operator::Div(x, _, _)
            | Operator::And(x, _, _)
            | Operator::Or(x, _, _)
            | Operator::Mv(x, _)
            | Operator::Xor(x, _, _)
            | Operator::Load(x, _, _)
            | Operator::La(x, _)
            | Operator::Li(x, _)
            | Operator::Slt(x, _, _)
            | Operator::Call(x, _, _)
            | Operator::LoadLocal(x, _)
            | Operator::GetParameter(x, _) => Some(*x),
            
            // 没有结果寄存器的指令：返回None
            _ => None,
        }
    }
    
    // 获取指令的结果寄存器（可变引用）
    pub fn receiver_mut(&mut self) -> Option<&mut VReg> {
        match self {
            // 有结果寄存器的指令：返回结果寄存器的可变引用
            Operator::Add(x, _, _)
            | Operator::Sub(x, _, _)
            | Operator::Mult(x, _, _)
            | Operator::Div(x, _, _)
            | Operator::And(x, _, _)
            | Operator::Or(x, _, _)
            | Operator::Mv(x, _)
            | Operator::Xor(x, _, _)
            | Operator::Load(x, _, _)
            | Operator::La(x, _)
            | Operator::Li(x, _)
            | Operator::Slt(x, _, _)
            | Operator::Call(x, _, _)
            | Operator::LoadLocal(x, _)
            | Operator::GetParameter(x, _) => Some(x),
            
            // 没有结果寄存器的指令：返回None
            _ => None,
        }
    }
    
    // 替换指令中的寄存器引用
    pub fn replace_reg(&mut self, reg: VReg, with: VReg) {
        // 宏定义：替换寄存器引用
        macro_rules! replace {
            ($($x:expr),+) => {
                {
                    $(
                    if *$x == reg {
                        *$x = with;
                    }
                    )+
                }
            };
        }
        
        match self {
            // 二元运算指令：替换两个源寄存器
            Operator::Add(_, y, z)
            | Operator::Sub(_, y, z)
            | Operator::Mult(_, y, z)
            | Operator::Div(_, y, z)
            | Operator::And(_, y, z)
            | Operator::Slt(_, y, z)
            | Operator::Or(_, y, z)
            | Operator::Xor(_, y, z)
            | Operator::Bgt(z, y, _, _)
            | Operator::Bl(z, y, _, _)
            | Operator::Beq(z, y, _, _)
            | Operator::Load(_, y, z) => replace!(y, z),
            
            // 单操作数指令：替换一个源寄存器
            Operator::StoreLocal(y, _) | Operator::Return(y) | Operator::Mv(_, y) => replace!(y),
            
            // 存储指令：替换三个源寄存器
            Operator::Store(x, y, z) => replace!(x, y, z),
            
            // 函数调用指令：替换所有参数寄存器
            Operator::Call(.., z) => {
                for r in z {
                    replace!(r);
                }
            }
            
            // 其他指令：不需要替换
            _ => {}
        }
    }
}


/// `Displayable` 结构体：通用的指令序列显示包装器
/// 
/// 泛型参数：
/// - 'a: 生命周期参数，确保引用的指令序列有效
/// - O: 指令类型，可以是 Operator 或 SSAOperator
/// 
/// 功能：将指令序列包装为可显示的对象，支持多行格式化输出
pub struct Displayable<'a, O>(pub &'a [O]);

/// 为 Displayable 实现 Display trait
/// 条件：O 必须实现 Display trait（即指令本身可显示）
impl<'a, O> Display for Displayable<'a, O>
where
    O: Display,
{
    /// fmt 方法：格式化指令序列为多行文本
    /// 
    /// 参数：
    /// - self: Displayable 引用
    /// - f: 格式化器，用于输出格式化文本
    /// 
    /// 返回值：std::fmt::Result - 格式化操作结果
    /// 
    /// 功能：遍历指令序列，每行输出一个指令
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        // 遍历指令序列中的每个指令
        for op in self.0 {
            // 使用 writeln! 宏将指令写入格式化器，并添加换行符
            // ? 操作符用于错误传播：如果写入失败，立即返回错误
            writeln!(f, "{op}")?;
        }
        // 所有指令成功写入，返回 Ok
        Ok(())
    }
}

/// 为 Operator 枚举实现 Display trait
/// 功能：将各种IR指令格式化为可读的文本表示
impl Display for Operator {
    /// fmt 方法：根据指令类型进行格式化
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        // 使用模式匹配处理所有 Operator 变体
        match self {
            // 算术运算指令：格式化为 "add rd1, rd2, rd3"
            Operator::Add(rd1, rd2, rd3) => write!(f, "\tadd rd{rd1}, rd{rd2}, rd{rd3}"),
            Operator::Sub(rd1, rd2, rd3) => write!(f, "\tsub rd{rd1}, rd{rd2}, rd{rd3}"),
            Operator::Mult(rd1, rd2, rd3) => write!(f, "\tmult rd{rd1}, rd{rd2}, rd{rd3}"),
            Operator::Div(rd1, rd2, rd3) => write!(f, "\tdiv rd{rd1}, rd{rd2}, rd{rd3}"),
            
            // 逻辑运算指令
            Operator::And(rd1, rd2, rd3) => write!(f, "\tand rd{rd1}, rd{rd2}, rd{rd3}"),
            Operator::Or(rd1, rd2, rd3) => write!(f, "\tor rd{rd1}, rd{rd2}, rd{rd3}"),
            
            // 移动指令：格式化为 "mv rd1, rd2"
            Operator::Mv(rd1, rd2) => write!(f, "\tmv rd{rd1}, rd{rd2}"),
            
            // 异或运算
            Operator::Xor(rd1, rd2, rd3) => write!(f, "\txor rd{rd1}, rd{rd2}, rd{rd3}"),
            
            // 内存访问指令
            Operator::Load(rd1, rd2, rd3) => write!(f, "\tload rd{rd1}, rd{rd2}, rd{rd3}"),
            Operator::Store(rd1, rd2, rd3) => write!(f, "\tstore rd{rd1}, rd{rd2}, rd{rd3}"),
            
            // 加载地址指令：格式化为 "la rd1, @label"
            // @ 前缀表示标签（label）
            Operator::La(rd1, rd2) => write!(f, "\tla rd{rd1}, @{rd2}"),
            
            // 分支指令：格式化为 "bgt rd1, rd2, @label1, @label2"
            Operator::Bgt(rd1, rd2, rd3, rd4) => {
                write!(f, "\tbgt rd{rd1}, rd{rd2}, @{rd3}, @{rd4}")
            }
            Operator::Bl(rd1, rd2, rd3, rd4) => write!(f, "\tbl rd{rd1}, rd{rd2}, @{rd3}, @{rd4}"),
            
            // 无条件跳转指令：格式化为 "j @label"
            Operator::J(rd1) => write!(f, "\tj @{rd1}"),
            
            // 相等分支指令
            Operator::Beq(rd1, rd2, rd3, rd4) => {
                write!(f, "\tbeq rd{rd1}, rd{rd2}, @{rd3}, @{rd4}")
            }
            
            // 加载立即数指令：格式化为 "li rd1, #42"
            // # 前缀表示立即数（immediate）
            Operator::Li(rd1, rd2) => write!(f, "\tli rd{rd1}, #{rd2}"),
            
            // 小于比较指令：格式化为 "slt rd1, rd2, rd3"
            Operator::Slt(rd1, rd2, rd3) => write!(f, "\tslt rd{rd1}, rd{rd2}, rd{rd3}"),
            
            // 函数调用指令：格式化为 "call rd1, @func, ( rd2 rd3 ... )"
            Operator::Call(rd1, rd2, rd3) => {
                // 写入指令前缀：call rd1, @func, (
                write!(f, "\tcall rd{rd1}, @{rd2}, ( ")?;
                // 遍历所有参数寄存器，用空格分隔
                for reg in rd3 {
                    write!(f, "{reg} ")?;
                }
                // 写入闭合括号
                write!(f, ")")
            }
            
            // 返回指令：格式化为 "return rd1"
            Operator::Return(rd1) => write!(f, "\treturn rd{rd1}"),
            
            // 栈内存访问指令：格式化为 "loadAR rd1, AR(offset)"
            // AR 表示激活记录（Activation Record），即栈帧
            Operator::LoadLocal(rd1, imm) => write!(f, "\tloadAR rd{rd1}, AR({imm})"),
            Operator::StoreLocal(rd1, imm) => write!(f, "\tstoreAR rd{rd1}, AR({imm})"),
            
            // 标签指令：格式化为 "@label:"
            // 冒号表示标签定义位置
            Operator::Label(rd1) => write!(f, "@{rd1}:"),
            
            // 获取参数指令：格式化为 "getParam rd1, index"
            Operator::GetParameter(rd1, rd2) => write!(f, "\tgetParam rd{rd1}, {rd2}"),
            
            // 空操作指令：格式化为 "nop"
            Operator::Nop => write!(f, "nop"),
        }
    }
}

/// 为 SSAOperator 枚举实现 Display trait
/// 功能：将SSA形式的IR指令格式化为可读的文本表示
impl Display for SSAOperator {
    /// fmt 方法：根据SSA指令类型进行格式化
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        // 使用模式匹配处理 SSAOperator 的两个变体
        match self {
            // 普通IR指令：直接调用底层 Operator 的 Display 实现
            SSAOperator::IROp(op) => write!(f, "{op}"),
            
            // Phi函数：格式化为 "rd1 <- φ ( arg1 arg2 ... )"
            // φ (phi) 符号表示Phi函数，用于SSA形式中的值合并
            SSAOperator::Phi(rd1, args) => {
                // 写入Phi函数前缀：rd1 <- φ (
                write!(f, "\trd{rd1} <- \u{03D5} ( ")?;
                // 遍历所有参数
                for arg in args {
                    // 特殊处理：u32::MAX 表示未定义值（⊥）
                    if *arg == u32::MAX {
                        // 使用 Unicode 字符 ⊥ (U+22A5) 表示未定义
                        write!(f, "\u{22a5} ")?
                    } else {
                        // 正常参数：直接输出寄存器编号
                        write!(f, "{arg} ")?;
                    }
                }
                // 写入闭合括号
                write!(f, ")")
            }
        }
    }
}
pub struct Function<B> {
    body: B,
    params: Vec<VReg>,
    max_reg: VReg,
}
impl<B> Function<B> {
    pub fn get_body(&self) -> &B {
        &self.body
    }
    pub fn into_body(self) -> B {
        self.body
    }
    pub fn get_body_mut(&mut self) -> &mut B {
        &mut self.body
    }
    pub fn get_params(&self) -> &Vec<VReg> {
        &self.params
    }
    pub fn get_max_reg(&self) -> VReg {
        self.max_reg
    }
}
impl Function<Vec<Operator>> {
    pub fn into_cfg(self) -> Function<CFG<Operator>> {
        let mut res = Function {
            body: CFG::from_linear(&self.body, self.get_params(), self.get_max_reg()),
            params: self.params,
            max_reg: 0,
        };
        res.max_reg = res.body.get_max_reg();
        res
    }
}
impl Function<CFG<Operator>> {
    pub fn into_ssa(self) -> Function<CFG<SSAOperator>> {
        let mut res = Function {
            body: self.body.into_ssa(),
            params: self.params,
            max_reg: 0,
        };
        res.max_reg = res.body.get_max_reg();
        res
    }
}
pub struct Context<B> {
    pub functions: HashMap<String, Function<B>>,
    pub globals: HashMap<String, Type>,
}
impl<B> Context<B> {
    pub fn new() -> Self {
        Self {
            functions: HashMap::new(),
            globals: HashMap::new(),
        }
    }
    pub fn get_functions(&self) -> &HashMap<String, Function<B>> {
        &self.functions
    }
}
impl<B> Default for Context<B> {
    fn default() -> Self {
        Self::new()
    }
}

enum Scope {
    Local(VReg),    // 局部变量，关联虚拟寄存器
    Global, // 全局变量，无寄存器关联
}

/// 翻译整个程序到IR
/// 
/// 执行逻辑：
/// 1. 首先遍历所有定义，将全局声明、函数声明和函数定义添加到全局作用域
/// 2. 然后再次遍历所有定义，分别处理：
///    - 函数定义：创建新的作用域并翻译函数
///    - 函数声明：跳过（仅声明不定义）
///    - 全局声明：添加到上下文的全局变量表中
///    - 局部变量定义：在全局作用域中不允许，会panic
/// 
/// 参数：
/// - context: 编译上下文，用于存储翻译后的函数和全局变量
/// - program: 要翻译的AST程序
pub fn translate_program(context: &mut Context<Vec<Operator>>, program: &parser_defs::Program) {
    let defs = &program.0;
    let mut scope = SheafTable::new();
    // 第一遍：将所有全局标识符（全局变量、函数声明、函数定义）添加到全局作用域
    for g in defs {
        if let parser_defs::GlobalDecl(i, ..)
        | parser_defs::FunctionDecl(i, ..)
        | parser_defs::FunctionDef(i, ..) = g
        {
            scope.insert(i.as_str().into(), Scope::Global);
        }
    }
    // 第二遍：处理具体的定义
    for f in defs {
        // println!("f: {:#?}", f);
        match f {
            parser_defs::FunctionDef(..) => {
                // 函数定义：创建新的作用域并翻译函数
                scope.push();
                translate_function(context, &mut scope, f, VRegGenerator::new());
                scope.pop();
            }
            parser_defs::FunctionDecl(..) => {
                // 函数声明：跳过，不生成代码
            }
            parser_defs::GlobalDecl(ident, t) => {
                // 全局变量声明：添加到上下文的全局变量表
                debug_assert!(!context.globals.contains_key(ident));
                context.globals.insert(ident.clone(), *t);
            }
            parser_defs::LocalVarDef(..) => panic!("local var def at global scope"),
        }
    }
}

// /**
//  * 负责将函数定义从抽象语法树(AST) 转换为中间表示
//  *  1. 函数参数处理: 为每个参数分配虚拟寄存器
//  *  2. 作用域管理: 建立函数内部的作用域环境
//  *  3. 函数体翻译: 将函数转换为IR指令序列
//  *  4. 上下文更新: 将翻译结果存储到编译上下文中
//  * 
//  * Context<Vec<Operator>>
//  * 1. 存储所有已翻译的函数
//  * 2. 包含全局变量信息
//  * 3. 维护编译状态
//  * 
//  * SheafTable<Rc<str>, Scope>
//  * 1. 作用域管理表，支持嵌套作用域
//  * 2. 存储变量名到作用域信息的映射
//  * 3. `Scope::Local(reg)` 表示局部变量对应的寄存器
//  * 
//  * VRegGenerator
//  * 1. 虚拟寄存器生成器
//  * 2. 确保寄存器编号的唯一性
//  * 3. 支持标签生成
//  * 
//  * Function<Vec<Operator>>
//  * 1. 函数表示结构体
//  * 2. 包含指令序列、参数列表和最大寄存器编号
//  * 
//  * scope 参数的核心作用
//  * 1. 变量生命周期管理
//  *  1. 局部变量： 在定义的作用域内有效，超过作用域后自动失效
//  *  2. 全局变量：在整个程序生命周期内有效
//  *  3. 参数变量: 在函数作用域内有效
//  * 2. 作用域层次管理
//  *  1. 嵌套作用域: 支持函数内部的作用域嵌套
//  *  2. 变量遮蔽: 内层作用域可以遮蔽外层同名变量
//  *  3. 作用域隔离：不同作用域的变量互不干扰
//  * 3. 变量 - 寄存器映射
//  *  1. 局部变量：直接映射到虚拟寄存器，访问时直接使用寄存器
//  *  2. 全局变量: 不直接映射寄存器，需要通过内存访问指令
//  * 4. 类型区分指令
//  *  1. Local(VReg): 表示变量存储在寄存器中，访问效率高
//  *  2. Global: 表示变量存储在全局内存中，需要加载/存储操作
//  * 5. 编译时符号表功能
//  *  1. 符号解析: 在编译时确定变量的作用域的存储位置
//  *  2. 错误检测: 检测未定义变量或作用域错误
//  *  3. 优化基础: 为后续的寄存器分配和优化提供信息
//  */
fn translate_function(
    context: &mut Context<Vec<Operator>>,
    scope: &mut SheafTable<Rc<str>, Scope>,
    function: &parser_defs::Defs,
    mut gen: VRegGenerator,
) {
    if let parser_defs::FunctionDef(i, p, _, b) = function {
        let code = Vec::new();

        // /**
        //  * 函数参数处理
        //  * 1. 为每个函数参数分配一个唯一的虚拟寄存器
        //  * 2. 在作用域表中记录参数名到寄存器的映射
        //  * 3. 保存参数寄存器列表供后续使 用
        //  */
        let mut params = Vec::new();
        for p in p.0.iter() {
            let reg = gen.next_reg(); // 为参数分配虚拟寄存器
            scope.insert(p.0.as_str().into(), Scope::Local(reg)); // 在作用域中注册参数
            params.push(reg); // 记录参数寄存器
        }

        // /**
        //  * 函数上下文创建
        //  * 1. 在编译上下文中创建新的函数条目
        //  * 2. 初始化函数结构体，包含空的指令序列和参数信息
        //  */
        context.functions.insert(
            i.clone(),
            Function {
                body: code, // 初始为空指令序列。翻译后的IR指令序列
                params, // 参数寄存器列表
                max_reg: 0, // 初始最大寄存器编号
            },
        );

        // /**
        //  * 函数体翻译
        //  * 1. 获取函数体的可变引用
        //  * 2. 调用 translate_block 递归翻译函数体
        //  * 3. 将生成的IR 指令填充到函数体中
        //  */
       
        let code = context.functions.get_mut(i).unwrap().get_body_mut();
        translate_block(code, scope, Any::B(b), &mut gen);
        #[cfg(feature = "print-linear")]
        {
            println!("translated function {i}:\n{}", Displayable(&code));
        }

        // /**
        //  * 寄存器使用统计
        //  * 1. 记录函数中使用的最大虚拟寄存器编号
        //  * 2. 用于后续的寄存器分配和优化
        //  */
        context.functions.get_mut(i).unwrap().max_reg = gen.next_reg();
    } else {
        panic!("Expected function def")
    }
}

// /**
//  * translate_block 是一个递归下降翻译器
//  * 1. 表达式翻译: 将各种表达式转换为对应的IR指令
//  * 2. 语句翻译：处理赋值、控制流等语句
//  * 3. 作用域管理: 处理变量查找和作用域
//  * 4. 寄存器分配： 为中间结果分配虚拟寄存器
//  */
fn translate_block(
    vec: &mut Vec<Operator>,
    scope: &mut SheafTable<Rc<str>, Scope>,
    instr: parser_defs::Any<'_>,
    gen: &mut VRegGenerator,
) -> Option<VReg> {
    match instr {
        // 表达式翻译(Any:E 分支)
        Any::E(e) => match e {
            // 逻辑运算
            // 1. 递归翻译左右操作数
            // 2. 为结果分配新寄存器
            // 3. 生成 Or 指令
            parser_defs::Expr::Or(l, r) => {
                let left = translate_block(vec, scope, Any::E(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::T(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Or(next, left, right));
                Some(next)
            }
            // 异或运算
            parser_defs::Expr::Xor(l, r) => {
                let left = translate_block(vec, scope, Any::E(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::T(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Xor(next, left, right));
                Some(next)
            }
            parser_defs::Expr::ETerm(i) => translate_block(vec, scope, Any::T(i), gen),
        },
        Any::S(s) => match s {
            parser_defs::Statement::Def(d) => translate_block(vec, scope, Any::D(d), gen),
            // 赋值语句
            parser_defs::Statement::Assign(i, v) => {
                let value = translate_block(vec, scope, Any::E(v), gen).unwrap();
                if let Some(Scope::Local(reg)) = scope.get(i.as_str()) {
                    vec.push(Operator::Mv(*reg, value));    // 局部变量赋值
                } else if let Some((i, Scope::Global)) = scope.get_key_value(i.as_str()) {
                    //  全局变量赋值
                    let intermediate = gen.next_reg();
                    vec.push(Operator::Li(intermediate, 0));
                    let intermediate2 = gen.next_reg();
                    vec.push(Operator::La(intermediate2, Rc::clone(i)));
                    vec.push(Operator::Store(value, intermediate, intermediate2));
                } else {
                    panic!("Did not find variable")
                }
                None
            }
            // 条件语句
            parser_defs::Statement::IfElse(c, t, e) => {
                let c = translate_block(vec, scope, Any::E(c), gen).unwrap();
                let l1: Rc<_> = gen.next_label().into();    // then 分支标签
                let l2: Rc<_> = gen.next_label().into();    // else 分支标签
                let l3: Rc<_> = gen.next_label().into();    // 合并标签
                let next = gen.next_reg();
                vec.push(Operator::Li(next, 1));
                vec.push(Operator::Beq(c, next, Rc::clone(&l1), Rc::clone(&l2)));
                vec.push(Operator::Label(Rc::clone(&l1)));
                translate_block(vec, scope, Any::B(t), gen); // 翻译then分支
                vec.push(Operator::J(Rc::clone(&l3)));
                vec.push(Operator::Label(Rc::clone(&l2)));
                translate_block(vec, scope, Any::B(e), gen); // 翻译else分支
                vec.push(Operator::J(Rc::clone(&l3)));
                vec.push(Operator::Label(Rc::clone(&l3)));
                None
            }
            // 循环语句
            parser_defs::Statement::While(c, b) => {
                let l1: Rc<_> = gen.next_label().into(); // 循环头标签
                let l2: Rc<_> = gen.next_label().into(); // 退出标签
                let l3: Rc<_> = gen.next_label().into(); // 循环体标签
                let next = gen.next_reg();
                vec.push(Operator::J(Rc::clone(&l1)));
                vec.push(Operator::Label(Rc::clone(&l1)));
                let c = translate_block(vec, scope, Any::E(c), gen).unwrap();
                vec.push(Operator::Li(next, 0));
                vec.push(Operator::Beq(c, next, Rc::clone(&l2), Rc::clone(&l3)));
                vec.push(Operator::Label(Rc::clone(&l3)));
                translate_block(vec, scope, Any::B(b), gen);
                vec.push(Operator::J(Rc::clone(&l1)));
                vec.push(Operator::Label(Rc::clone(&l2)));
                None
            }
            parser_defs::Statement::Return(e) => {
                let l1: Rc<_> = gen.next_label().into();
                let reg = translate_block(vec, scope, Any::E(e), gen).unwrap();
                vec.push(Operator::Return(reg));
                vec.push(Operator::Label(Rc::clone(&l1)));
                None
            }
        },
        Any::D(def) => match def {
            // 局部变量定义
            parser_defs::Defs::LocalVarDef(i, _, e) => {
                let res = translate_block(vec, scope, Any::E(e), gen).unwrap();
                scope.insert(i.as_str().into(), Scope::Local(res)); // 注册到作用域
                Some(res)
            }
            parser_defs::Defs::GlobalDecl(..) => panic!("Nested global decl"),
            parser_defs::Defs::FunctionDef(..) => panic!("Nested function def"),
            parser_defs::Defs::FunctionDecl(..) => panic!("Nested function decl"),
        },
        Any::B(parser_defs::Body(v)) => {
            for v in v {
                translate_block(vec, scope, Any::S(v), gen);
            }
            None
        }
        Any::As(_) => panic!("Args handled in call"),
        Any::Ps(_) | Any::P(_) => panic!("Params handled in function def"),
        // 乘除运算
        Any::A(atom) => match atom {
            parser_defs::Atom::Mult(l, r) => {
                let left = translate_block(vec, scope, Any::A(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::U(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Mult(next, left, right));
                Some(next)
            }
            parser_defs::Atom::Div(l, r) => {
                let left = translate_block(vec, scope, Any::A(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::U(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Div(next, left, right));
                Some(next)
            }
            parser_defs::Atom::AUnit(i) => translate_block(vec, scope, Any::U(i), gen),
        },
        Any::U(u) => match u {
            // 变量访问
            parser_defs::Unit::Identifier(i) => {
                // 局部变量访问
                if let Some(Scope::Local(reg)) = scope.get(i.as_str()) {
                    Some(*reg)  // 直接返回局部变量寄存器
                } // 全局变量访问
                else if let Some((i, Scope::Global)) = scope.get_key_value(i.as_str()) {
                    // 全局变量需要加载
                    let intermediate = gen.next_reg();
                    let intermediate2 = gen.next_reg();
                    vec.push(Operator::Li(intermediate, 0));
                    vec.push(Operator::La(intermediate2, i.clone()));
                    let result = gen.next_reg();
                    vec.push(Operator::Load(result, intermediate, intermediate2));
                    Some(result)
                } else {
                    panic!("Did not find variable")
                }
            }
            // 布尔常量
            parser_defs::Unit::True => {
                let res = gen.next_reg();
                vec.push(Operator::Li(res, 1)); // true = 1
                Some(res)
            }
            parser_defs::Unit::False => {
                let res = gen.next_reg();
                vec.push(Operator::Li(res, 0)); // false = 0
                Some(res)
            }
            // 函数调用
            parser_defs::Unit::Call(f, parser_defs::Args(args)) => {
                let mut regs = Vec::with_capacity(args.capacity());
                for a in args {
                    regs.push(translate_block(vec, scope, Any::E(a), gen).unwrap());
                }
                let result = gen.next_reg();
                let (name, _) = scope.get_key_value(f.as_str()).unwrap();
                let l1 = gen.next_label().into();
                let l2 = gen.next_label().into();
                vec.push(Operator::J(Rc::clone(&l1)));
                vec.push(Operator::Label(Rc::clone(&l1)));
                vec.push(Operator::Call(result, Rc::clone(name), regs));
                vec.push(Operator::J(Rc::clone(&l2)));
                vec.push(Operator::Label(Rc::clone(&l2)));
                Some(result)
            }
            parser_defs::Unit::Grouping(e) => translate_block(vec, scope, Any::E(e), gen),
            parser_defs::Unit::Number(c) => {
                let res = gen.next_reg();
                vec.push(Operator::Li(res, *c));
                Some(res)
            }
        },
        // 加减运算
        Any::F(f) => match f {
            parser_defs::Factor::Plus(l, r) => {
                let left = translate_block(vec, scope, Any::F(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::A(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Add(next, left, right));
                Some(next)
            }
            parser_defs::Factor::Minus(l, r) => {
                let left = translate_block(vec, scope, Any::F(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::A(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Sub(next, left, right));
                Some(next)
            }
            parser_defs::Factor::FAtom(i) => translate_block(vec, scope, Any::A(i), gen),
        },
        Any::BT(bt) => match bt {
            parser_defs::BTerm::Not(i) => {
                let expr = translate_block(vec, scope, Any::CT(i), gen).unwrap();
                let intermediate = gen.next_reg();
                vec.push(Operator::Li(intermediate, -1));
                let result = gen.next_reg();
                vec.push(Operator::Xor(result, intermediate, expr));
                Some(result)
            }
            parser_defs::BTerm::BCTerm(i) => translate_block(vec, scope, Any::CT(i), gen),
        },
        // 比较运算
        Any::CT(ct) => match ct {
            // 大于等于
            parser_defs::CTerm::GEq(l, r) => {
                let left = translate_block(vec, scope, Any::CT(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::F(r), gen).unwrap();
                let next = gen.next_reg();
                let next2 = gen.next_reg();
                let next3 = gen.next_reg();
                vec.push(Operator::Slt(next, left, right));
                vec.push(Operator::Li(next2, 1));
                vec.push(Operator::Xor(next3, next2, next));
                Some(next3)
            }
            // 小于
            parser_defs::CTerm::LT(l, r) => {
                let left = translate_block(vec, scope, Any::CT(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::F(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::Slt(next, left, right));
                Some(next)
            }
            parser_defs::CTerm::EQ(l, r) => {
                let left = translate_block(vec, scope, Any::CT(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::F(r), gen).unwrap();
                let next = gen.next_reg();
                let next2 = gen.next_reg();
                let next3 = gen.next_reg();
                vec.push(Operator::Xor(next, left, right));
                vec.push(Operator::Li(next2, 1));
                vec.push(Operator::Slt(next3, next, next2));
                Some(next3)
            }
            parser_defs::CTerm::CTFactor(i) => translate_block(vec, scope, Any::F(i), gen),
        },
        Any::T(t) => match t {
            parser_defs::Term::And(l, r) => {
                let left = translate_block(vec, scope, Any::T(l), gen).unwrap();
                let right = translate_block(vec, scope, Any::BT(r), gen).unwrap();
                let next = gen.next_reg();
                vec.push(Operator::And(next, left, right));
                Some(next)
            }
            parser_defs::Term::TCTerm(i) => translate_block(vec, scope, Any::BT(i), gen),
        },
        _ => panic!("Unexpected instr"),
    }
}

/// `SSAOperator` 是SSA（Static Single Assignment，静态单赋值）编译器中间表示（IR）的核心数据结构
#[derive(Debug, PartialEq, Eq, Clone)]
pub enum SSAOperator {
    /// IROp(Operator): 包装普通的IR操作符
    /// IROp变体：包装普通的Operator（中间表示操作符）
    /// 用于表示普通的算术、逻辑、内存访问等操作
    IROp(Operator),
    /// Phi(VReg, Vec<VReg>): 表示Phi函数，用于在控制流合并点选择正确的值
    /// Phi变体：表示Phi函数，这是SSA形式的关键组成部分
    /// 第一个参数：目标寄存器（接收Phi函数结果的寄存器）
    /// 第二个参数：源寄存器向量（来自不同前驱块的值）
    /// Phi函数在控制流合并点根据来自哪个前驱块选择相应的值
    Phi(VReg, Vec<VReg>),
}

/// SSAOperator实现方法
impl SSAOperator {
    /// receiver方法：返回操作的结果寄存器（如果有的话）
    /// 返回值：Option<VReg> - 如果有结果寄存器则返回Some(寄存器编号)，否则返回None
    pub fn receiver(&self) -> Option<VReg> {
        /// 使用模式匹配处理不同的SSAOperator变体
        match self {
            /// 如果是普通的IR操作，调用其receiver方法
            SSAOperator::IROp(op) => op.receiver(),
            /// 如果是Phi函数，返回Phi函数的目标寄存器（第一个参数）
            /// 使用*x解引用获取寄存器值，因为x是&VReg类型
            SSAOperator::Phi(x, _) => Some(*x),
        }
    }

    /// replace_reg方法：替换操作中使用的寄存器引用
    /// - reg: VReg - 要替换的原始寄存器编号
    /// - with: VReg - 替换后的新寄存器编号
    /// 这个方法用于在SSA重命名阶段更新寄存器引用
    pub fn replace_reg(&mut self, reg: VReg, with: VReg) {
        /// 使用模式匹配处理不同的SSAOperator变体
        match self {
            /// 如果是普通的IR操作，调用其replace_reg方法
            SSAOperator::IROp(o) => o.replace_reg(reg, with),
            /// 如果是Phi函数，需要遍历所有源寄存器并替换匹配的寄存器
            SSAOperator::Phi(_, vec) => {
                /// 遍历Phi函数的所有源寄存器
                for r in vec {
                    /// 检查当前寄存器是否等于要替换的寄存器
                    if *r == reg {
                        /// 如果匹配，将其替换为新寄存器
                        *r = with;
                    }
                }
            }
        }
    }
}
/**
 * 控制流图中的基本块结构
 * 
 * 基本块是控制流图的基本构建单元，包含：
 * - 一个入口点（标签）
 * - 一系列顺序执行的指令
 * - 控制流关系（前驱和后继）
 * - 支配关系信息
 * 
 * 泛型参数 O 表示块中指令的类型，可以是 Operator 或 SSAOperator
 */
#[derive(Debug)]
pub struct Block<O> {
    /// 基本块的标签名称，用于标识和跳转
    pub label: Rc<str>,
    /// 基本块中包含的指令序列
    pub body: Vec<O>,
    /// 前驱块索引列表：哪些块可以跳转到当前块
    pub preds: Vec<usize>,
    /// 后继块索引列表：当前块可以跳转到哪些块
    pub children: Vec<usize>,
    /// 直接支配者（Immediate Dominator）索引
    /// - None：入口节点没有支配者
    /// - Some(index)：支配当前块的最接近的块
    pub idom: Option<usize>,
    /// 被当前块直接支配的块索引列表
    pub idom_of: Vec<usize>,
    /// 直接后支配者（Reverse Immediate Dominator）索引
    /// 用于后支配树分析
    pub r_idom: Option<usize>,
    /// 被当前块直接后支配的块索引列表
    pub r_idom_of: Vec<usize>,
}

impl<O> Block<O> {
    /**
     * 创建一个空的基本块
     * 
     * 参数：
     * - label: 基本块的标签名称
     * 
     * 返回：
     * - 初始化的空基本块，所有列表为空，支配关系为None
     */
    fn empty(label: &Rc<str>) -> Self {
        Self {
            label: Rc::clone(label),
            body: Vec::new(),
            preds: Vec::new(),
            children: Vec::new(),
            idom: None,
            idom_of: Vec::new(),
            r_idom: None,
            r_idom_of: Vec::new(),
        }
    }
    
    /**
     * 将基本块转换为包含不同类型指令的块
     * 
     * 用于在编译流程中转换基本块的指令类型，例如：
     * - 从 Operator 转换为 SSAOperator
     * - 保持控制流和支配关系不变
     * 
     * 参数：
     * - self: 当前基本块
     * - body: 新的指令序列
     * 
     * 返回：
     * - 包含新指令类型的基本块，其他属性保持不变
     */
    pub fn into_other<T>(self, body: Vec<T>) -> Block<T> {
        Block {
            label: self.label,
            body,
            preds: self.preds,
            children: self.children,
            idom: self.idom,
            idom_of: self.idom_of,
            r_idom: self.r_idom,
            r_idom_of: self.r_idom_of,
        }
    }
}

// `CFG<O>` 是控制流图（Control Flow Graph）的核心数据结构
/// 泛型参数 O 表示基本块中指令的类型，可以是：
/// - Operator: 普通中间表示指令
/// - SSAOperator: SSA形式的中间表示指令
#[derive(Debug)]
#[allow(clippy::upper_case_acronyms)]
pub struct CFG<O> {
    /// blocks: 基本块向量，存储控制流图中的所有基本块
    /// 每个基本块包含：
    /// - 标签（label）：基本块的唯一标识符
    /// - 指令序列（body）：基本块中顺序执行的指令
    /// - 前驱列表（preds）：哪些块可以跳转到当前块
    /// - 后继列表（children）：当前块可以跳转到哪些块
    /// - 支配关系信息：用于优化分析
    pub blocks: Vec<Block<O>>,
    
    /// entry: 入口块索引，表示程序的起始执行点
    /// 总是为0，对应标签为"ENTRY"的基本块
    entry: usize,
    
    /// exit: 出口块索引，表示程序的结束执行点
    /// 总是为 blocks.len() - 1，对应标签为"EXIT"的基本块
    exit: usize,
    
    /// max_reg: 当前函数中使用的最大虚拟寄存器编号
    /// 用于：
    /// 1. 寄存器分配：确定虚拟寄存器的数量范围
    /// 2. 新寄存器生成：确保生成唯一的寄存器编号
    /// 3. 内存分配：确定寄存器相关数据结构的大小
    max_reg: VReg,
    
    /// allocated_ars: 已分配的栈帧偏移量（Activation Record Size）
    /// 用于：
    /// 1. 栈帧管理：记录函数调用时需要分配的栈空间大小
    /// 2. 局部变量存储：确定局部变量在栈上的偏移位置
    /// 3. 寄存器溢出：当寄存器不足时，将变量溢出到栈上
    allocated_ars: u64,
}
impl<O> CFG<O> {
    pub fn get_allocated_ars_mut(&mut self) -> &mut u64 {
        &mut self.allocated_ars
    }
    pub fn into_other<A>(self, blocks: Vec<Block<A>>) -> CFG<A> {
        CFG {
            blocks,
            entry: self.entry,
            exit: self.exit,
            max_reg: self.max_reg,
            allocated_ars: 0,
        }
    }
    pub fn get_blocks(&self) -> &[Block<O>] {
        &self.blocks
    }
    pub fn get_blocks_mut(&mut self) -> &mut [Block<O>] {
        &mut self.blocks
    }
    pub fn get_entry(&self) -> usize {
        self.entry
    }
    pub fn get_exit(&self) -> usize {
        self.exit
    }
    pub fn get_max_reg(&self) -> VReg {
        self.max_reg
    }
    pub fn set_max_reg(&mut self, max_reg: VReg) {
        self.max_reg = max_reg;
    }
    pub fn get_block(&self, i: usize) -> &Block<O> {
        self.blocks.get(i).unwrap()
    }
    pub fn is_empty(&self) -> bool {
        self.blocks.is_empty()
    }
    pub fn len(&self) -> usize {
        self.blocks.len()
    }
    pub fn get_block_mut(&mut self, i: usize) -> &mut Block<O> {
        self.blocks.get_mut(i).unwrap()
    }

    /// Returns the indices of a reverse post-order walk on the dominator tree.
    /// Last() constitutes first element;
    /// 支配树的逆后序遍历（Reverse Post-Order）算法，是编译器优化中用于分析控制流图结构的重要算法
    pub fn get_dom_rpo(&self) -> Vec<usize> {
        fn postorder<O>(s: &CFG<O>, current: usize, acc: &mut Vec<usize>) {
            let block = &s.blocks[current];
            // 递归处理所有被支配的子块
            // 后序遍历顺序；左子树 -> 右子树 -> 根节点
            for &child in &block.idom_of {
                postorder(s, child, acc); // 先递归处理所有子节点
            }
            // 后序访问：先处理子节点，再访问当前节点
            acc.push(current); // 再访问当前节点
        }
        let mut res = Vec::with_capacity(self.len());
        postorder(self, 0, &mut res); // 从入口块（索引0）开始
        res
    }

    // 广度优先搜索（BFS）反向距离计算算法
    //  用于计算从指定块到其他所有块的最短反向路径距离
    fn bfs_reverse(
        &self,
        total_blocks: usize,                    // 总块数，用于初始化输出数组大小
        block: usize,                           // 起始块索引
        selector: fn(&Block<O>) -> &Vec<usize>, // 选择器函数，决定遍历方向
    ) -> Vec<usize> {
        // 初始化距离数组，所有块初始距离为最大值（表示不可达）
        let mut outputs = vec![usize::MAX; total_blocks];

        // 起始块到自身的距离为0
        outputs[block] = 0;

        // 获取起始块
        let block = &self.blocks[block];

        // 初始化队列，用于BFS遍历
        let mut queue: VecDeque<(usize, usize)> = VecDeque::new();

        // 将起始块的所有前驱/后继加入队列
        queue.extend(selector(block).iter().cloned().zip(std::iter::repeat(1)));

        // BFS 主循环：处理队列中的每个节点
        while let Some((pred, dist)) = queue.pop_front() {
            // 获取当前邻居得旧距离
            let old = outputs[pred];

            // 如果新距离更小，更新距离
            if dist < old {
                // 更新距离
                outputs[pred] = dist;

                // 获取当前邻居块
                let block = &self.blocks[pred];
                
                // 将当前邻居得所有前驱/后继加入队列，距离+1
                queue.extend(
                    selector(block)
                        .iter()
                        .cloned()
                        .zip(std::iter::repeat(dist + 1)),
                );
            }
        }
        // 返回距离数组
        outputs
    }
    
    // 全对最短路径(APSP) 反向距离计算算法
    //  1. 用于计算控制流图中所有块之间的最短反向路径距离
    fn apsp_reverse(&self, postdominance: bool) -> Vec<Vec<usize>> {
        // 1. 选择器函数定义
        // - 支配计算: 使用前驱块(preds)
        // - 后支配计算: 使用后继块(children)
        let selector: fn(&Block<O>) -> &Vec<usize> = if !postdominance {
            |block| &block.preds
        } else {
            |block| &block.children
        };

        // 2. 初始化距离矩阵
        // - block_len: 基本块总数
        // - inner: 每个块的初始距离向量，全部设为最大值（表示不可达）
        let block_len = self.blocks.len();
        let inner = vec![usize::MAX; block_len];

        // 3. 创建输出矩阵
        // - output: block_len × block_len 的二维向量
        // - 每个元素 output[i][j] 表示从块j到块i的最短反向距离
        let mut output: Vec<Vec<usize>> = Vec::from_iter(std::iter::repeat(inner).take(block_len));
        
        // 4. 为每个块计算反向距离
        // - 遍历所有块作为目标块
        // - 对每个目标块i，计算从所有其他块到i的最短反向距离
        for (i, val) in output.iter_mut().enumerate() {
            *val = self.bfs_reverse(block_len, i, selector);
        }

        // 5. 返回完整的距离矩阵
        output
    }
    /// calculates dominance frontiers for each block.
    /// Must be a valid CFG as constructed by 'from_linear'.
    /// 支配边界计算算法。是 SSA 转换中的关键步骤
    pub fn get_dominance_frontiers(&self) -> Vec<HashSet<usize>> {
        let blocks = self.blocks.len();
        let mut frontier = vec![HashSet::new(); blocks];

        // 遍历所有基本块
        for (i, block) in self.blocks.iter().enumerate() {
            // 遍历当前块的所有前驱
            for &pred in &block.preds {
                if let Some(idom) = block.idom {
                    let mut current = pred;
                    // 沿着支配链向上遍历，直到遇到当前块的直接支配者
                    while idom != current {
                        // 将当前块添加到前驱块的支配边界中
                        frontier[current].insert(i);
                        // 继续向上遍历支配链
                        if let Some(next) = self.blocks[current].idom {
                            current = next;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        frontier
    }
    pub fn get_postdominance_frontiers(&self) -> Vec<HashSet<usize>> {
        let blocks = self.blocks.len();
        let mut frontier = vec![HashSet::new(); blocks];
        for (i, block) in self.blocks.iter().enumerate() {
            for &child in &block.children {
                if let Some(r_idom) = block.r_idom {
                    let mut current = child;
                    while r_idom != current {
                        frontier[current].insert(i);
                        if let Some(next) = self.blocks[current].r_idom {
                            current = next;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        frontier
    }

    // 支配者计算
    pub fn calculate_idoms(&self, postdominance: bool) -> Vec<Option<usize>> {
        // 1. 初始化阶段
        //  1. `doms[i]`: 存储块i的所有支配者集合
        //  2. 初始时，每个块支配所有块（除了根节点）
        //  3. 根节点（入口或出口）只支配自己
        let mut doms = vec![HashSet::from_iter(0..self.blocks.len()); self.blocks.len()];
        let mut idoms = vec![None; self.blocks.len()];
        let root = if !postdominance {
            self.get_entry()
        } else {
            self.get_exit()
        };
        doms[root] = HashSet::from([root]);
        let mut changed = true;

        // 选择器函数
        //  1. 支配计算: 使用前驱(preds)
        //  2. 后支配计算: 使用后继(children)
        //  3. 统一处理两种支配关系
        let selector: fn(&Block<O>) -> &Vec<usize> = if !postdominance {
            |block: &Block<O>| &block.preds // 前驱块
        } else {
            |block: &Block<O>| &block.children  // 后继块
        };

        // 收敛性
        //  1. __终止条件__：当没有块的支配者集合发生变化时
        //  2. __收敛保证__：支配者集合是单调递减的，最终会收敛
        while changed {
            changed = false;

            for (i, block) in self.blocks.iter().enumerate() {
                let mut new: HashSet<_> = if let Some(fst) = selector(block).first() {

                    // 为实现: doms[i] = {i} ∪ (∩_{p ∈ preds(i)} doms[p])
                    //  1. 块 i 的支配者 = 块 i 自身 + 所有前驱块支配者的共同部分
                    //  2. 如果一个块要支配当前块，它必须支配所有进入当前块的路径


                    // selector(block)
                    //  1. 根据 postdominance 标志选择前驱或后继
                    //  2. 支配计算：返回 block.preds（前驱块）
                    //  3. 后支配计算：返回 block.children（后继块）
                    // .iter().map(|n| &doms[*n])
                    //  1. 遍历所有前驱/后继块
                    //  2. 获取每个块的支配者集合 doms[*n]
                    //  3. 产生一个支配者集合的迭代器
                    // .fold(doms[*fst].clone(), ...)
                    //  1. 使用第一个前驱/后继块的支配者集合作为初始值
                    //  2. fst 是第一个前驱/后继块的索引
                    // acc.intersection(next).cloned().collect()
                    //  1. 计算当前累积集合 acc 与下一个集合 next 的交集
                    //  2. 将交集结果转换为新的 HashSet
                  
                    // ∩_{p ∈ preds(i)} doms[p]
                    selector(block)
                        .iter()
                        .map(|n| &doms[*n])
                        .fold(doms[*fst].clone(), |acc, next| {
                            // intersection（交集）：获取同时属于两个集合的所有元素
                            acc.intersection(next).cloned().collect()
                        }) 
                } else {
                    HashSet::new()
                };
                new.insert(i);  //{i} ∪
                if new != doms[i] {
                    changed = true;
                    doms[i] = new;
                }
            }
        }

        // 在支配者计算中的应用
        //  1. __距离比较__：选择距离最近的支配者作为直接支配者
        //  2. __路径优化__：确保选择最接近的支配者
        //  3. __支配树构建__：基于最短路径构建支配树
        let apsp_reverse = self.apsp_reverse(postdominance);

        // 距离选择
        // 块4的支配者集合: {0, 1, 4}
        // 比较距离：
        // apsp_reverse[4][0] = 3  // 块0到块4的距离
        // apsp_reverse[4][1] = 2  // 块1到块4的距离
        // 选择距离最小的支配者：块1
        // idoms[4] = Some(1)
        for (i, mut set) in doms.into_iter().enumerate() {
            set.remove(&i); // 移除自己
            let idom = set.into_iter().min_by_key(|&v| apsp_reverse[i][v]); // 选择距离最近的支配者
            idoms[i] = idom;
        }
        idoms
    }
}
impl<O> CFG<O>
where
    O: Display,
{
    /// `to_dot` 函数：将控制流图转换为 Graphviz DOT 格式字符串
    /// 
    /// 返回值：String - Graphviz DOT 格式的字符串
    /// 
    /// 功能：生成控制流图、支配树和后支配树的可视化表示
    /// 使用 Graphviz DOT 语言描述图结构，可用于生成 PNG、SVG 等格式的图像
    pub fn to_dot(&self) -> String {
        // 步骤1：初始化字符串构建器
        // adjacencies: 存储控制流边（基本块之间的跳转关系）
        let mut adjacencies = String::new();
        
        // attributes: 存储节点属性（基本块标签和指令内容）
        let mut attributes = String::new();
        
        // dominance: 存储支配树边（正向支配关系）
        let mut dominance = String::new();
        
        // postdominance: 存储后支配树边（反向支配关系）
        let mut postdominance = String::new();

        // 步骤2：遍历所有基本块，构建图结构
        for (i, block) in self.blocks.iter().enumerate() {
            // 步骤2.1：构建控制流边
            // 格式：源块索引 -> 目标块索引
            // 例如：0->1 表示块0跳转到块1
            adjacencies.extend(block.children.iter().map(|j| format!("{i}->{j}\n")));
            
            // 步骤2.2：构建节点属性
            attributes.push_str(&format!(
                "{i}[label=\"{{{0}|{1}}}\"]\ndom{i}[label=\"{0}\"]\npdom{i}[label=\"{0}\"]\n",
                block.label,  // 基本块标签（如 "ENTRY"、"EXIT"、"LABEL_0"）
                // 格式化基本块中的指令
                Displayable(&block.body)
                    .to_string()
                    .chars()
                    .filter(|&c| c != '\t')  // 移除制表符
                    .flat_map(|c| match c {
                        '\n' => "\\n".chars().collect(),  // 换行符转义为 \n
                        '<' => "\\<".chars().collect(),   // 小于号转义为 \<
                        c => vec![c],                     // 其他字符保持不变
                    })
                    .collect::<String>()  // 收集为字符串
            ));
            
            // 步骤2.3：构建支配树边
            // 格式：支配者 -> 被支配者
            // 例如：dom0->dom1 表示块0支配块1
            if let Some(idom) = block.idom {
                dominance.push_str(&format!("dom{}->dom{i}\n", idom));
            }
            
            // 步骤2.4：构建后支配树边
            // 格式：后支配者 -> 被后支配者
            // 例如：pdom4->pdom3 表示块4后支配块3
            if let Some(idom) = block.r_idom {
                postdominance.push_str(&format!("pdom{}->pdom{i}\n", idom))
            }
        }
        
        // 步骤3：构建完整的 DOT 格式字符串
        format!(
            "
    digraph G {{
    node [shape=record]

    {adjacencies}

    subgraph cluster_dominance {{
    label=\"dom tree\"
    {dominance}
    }}

    subgraph cluster_postdominance {{
    label=\"postdom tree\"
    {postdominance}
    }}

    {attributes}}}"
        )
    }
}
impl CFG<Operator> {
    pub fn from_linear(
        code: impl AsRef<[Operator]>,
        params: impl AsRef<[VReg]>,
        max_reg: VReg,
    ) -> Self {
        let code = code.as_ref();
        // 创建标签到块索引的映射
        // 初始化块列表，包含入库块
        // 设置块计数器
        let mut labels: HashMap<Rc<str>, usize> = HashMap::new();
        let mut blocks = Vec::from([Block::empty(&Rc::from("ENTRY"))]);
        let mut i = blocks.len();

        // 扫描所有标签指令，建立标签映射
        // 为每个标签创建对应的基本块
        // 添加出口块
        for op in code.iter() {
            if let Operator::Label(s) = op {
                labels.insert(Rc::clone(s), i);
                i += 1;
                blocks.push(Block::empty(s));
            }
        }
        blocks.push(Block::empty(&Rc::from("EXIT")));
        let exit_idx = blocks.len() - 1;
        let mut start = 0;
        let mut block_idx = 0;

        // 例子: docs/ir_to_cfg.md
        // 控制流分析阶段
        // 1. 标签分割: 将线性代码按标签分割成基本块
        // 2. 跳转分析: 分析无条件跳转指令，建立控制流边
        // 3. 块体填充: 将指令填充到对应的基本块中
        for (i, op) in code.iter().enumerate() {
            match op {
                Operator::Label(_) => {
                    // 处理标签：分割基本块
                    // 1. 基本块分割: 遇到标签指令时，将当前指令序列分割成一个基本块
                    // 2. 默认连接: 如果基本快没有显式的后继，默认连接到出口块
                    // 3. 指针更新: 更新起始位置和块索引，准备处理下一个基本块
                    let block: &mut Block<Operator> = &mut blocks[block_idx];
                    block.body = Vec::from(&code[start..i]);
                    if block.children.is_empty() {
                        block.children.push(exit_idx); //exit 默认连接到出口
                        blocks[exit_idx].preds.push(block_idx);
                    }
                    block_idx += 1;
                    start = i + 1;
                }
                Operator::J(s) => {
                    // 无条件跳转
                    // 1. 目标解释: 通过标签映射找到跳转目标的基本块索引
                    // 2. 边建立: 在当前块的后继列表中添加目标块
                    // 3. 前驱更新：在目标块的前驱列表中添加当前块
                    // 4. 去重检查: 避免重复添加相同的控制流边
                    let block = &mut blocks[block_idx];
                    let target = *labels.get(s.as_ref()).unwrap();
                    if !block.children.contains(&target) {
                        block.children.push(target);
                        blocks[target].preds.push(block_idx);
                    }
                }
                Operator::Beq(_, _, t, f)
                | Operator::Bl(_, _, t, f)
                | Operator::Bgt(_, _, t, f) => {
                    // 条件分支
                    // 1. 双路分支：条件分支指令有两个目标(true 分支 和 false 分支)
                    // 2. 并行处理: 同时处理两个分支目标
                    // 3. 边建立: 为两个目标分别建立控制流动
                    // 4. 前驱更新: 在两个目标块的前驱列表中都添加当前块
                    for s in [t, f] {
                        let block = &mut blocks[block_idx];
                        let target = *labels.get(s.as_ref()).unwrap();
                        if !block.children.contains(&target) {
                            block.children.push(target);
                            blocks[target].preds.push(block_idx);
                        }
                    }
                }
                _ => {}
            }
            // 块体填充
            // 1. 指令收集: 将当前基本块的所有指令手机到块体中
            // 2. 连续处理: 处理从起始位置当前指令的所有指令
            blocks[block_idx].body = Vec::from(&code[start..]);
        }

        // 参数处理阶段
        // 1. 在入口块中添加参数加载指令
        // 2. 将函数参数转换 GetParameter 操作
        blocks[0].body = params
            .as_ref()
            .iter()
            .map(|&vr| Operator::GetParameter(vr, vr as u64))
            .chain(std::mem::take(&mut blocks[0].body).into_iter())
            .collect();

        let mut gc_map = vec![usize::MAX; blocks.len()];
        let exit = blocks.len() - 1;
        let mut blocks: Vec<_> = blocks.into_iter().enumerate().collect();
        // 不可达块清理阶段
        //  1. 删除不可达的基本快
        //  2. 保留入口块和出口块
        //  3. 迭代清理知道没有更多可删除的块
        let mut pruned = HashSet::new();    // 记录已被删除的块索引
        let mut changed = true; // 控制迭代循环的标志
        
        // 删除条件分析
        // 1. 条件1： `block.preds.is_empty()` - 块没有前驱
        // 2. 条件2: `block.preds.iter().all(|idx| pruned.contains(idx))` - 所有前驱都已被删除
        // 3. 条件3：`*old != 0` - 不是入口块（索引0）
        // 4. 条件4: `*old != exit` - 不是出口块

        // 删除逻辑:
        //  1. 如果满足所有条件, 标记为已删除(pruned.insert(*old))
        //  2. 返回 false 表示从列表中删除该块
        //  3. 设置 changed = true 表示需要继续迭代
        while changed {
            changed = false;
            blocks.retain(|(old, block)| {
                if (block.preds.is_empty() || block.preds.iter().all(|idx| pruned.contains(idx)))
                    && *old != 0
                    && *old != exit
                {
                    changed = true;
                    pruned.insert(*old);
                    false
                } else {
                    true
                }
            });
        }

        // 索引重映射: `gc_map[old] = new` - 建立旧索引到新索引的映射
        // 前驱清理: `b.preds.retain(|pred| !pruned.contains(pred))` - 删除指向已删除块的前驱
        let mut blocks: Vec<Block<_>> = blocks
            .into_iter()
            .enumerate()
            .map(|(new, (old, mut b))| {
                gc_map[old] = new; // // 建立旧索引到新索引的映射
                debug_assert_ne!(new, usize::MAX);
                b.preds.retain(|pred| !pruned.contains(pred));
                b
            })
            .collect();
        // 索引重映射阶段
        // 1. 重新映射块索引，填补删除块的空缺
        // 2. 更新前驱和后继关系

        for block in &mut blocks {
            // 前驱索引重映射
            // `std::mem::take(&mut block.preds)`：获取前驱列表的所有权，原位置置为空
            // `.into_iter()`：转换为迭代器
            // `.map(|i| gc_map[i])`：将旧索引映射为新索引
            // `.collect()`：重新收集为新的前驱列表
            block.preds = std::mem::take(&mut block.preds)
                .into_iter()
                .map(|i| gc_map[i])
                .collect();

            // 后继索引重映射
            // 同样的逻辑应用于后继列表
            // 确保所有控制流边指向正确的块索引
            block.children = std::mem::take(&mut block.children)
                .into_iter()
                .map(|i| gc_map[i])
                .collect();
        }
        // 出口索引更新
        // 重新计算出口块的索引（总是最后一个块）
        // 确保出口索引指向正确的块
        let exit = blocks.len() - 1;
        debug_assert_eq!(blocks[exit].label, Rc::from("EXIT"));
        let mut result = Self {
            blocks,
            entry: 0,
            exit,
            max_reg,
            allocated_ars: 0,
        };
        // 支配关系计算阶段
        // 1. 关键边分割: 处理前前驱多后继复杂控制流
        // 2. 支配关系计算: 计算直接支配这和后支配者
        // 3. 支配树构建：建立支配树结构
        result.split_critical();

        // idoms(直接支配者)
        //  1. __含义__：Immediate Dominator，直接支配者
        //  2. 方向：从入口到出口的正向支配关系
        //  3. __作用__：构建正向支配树，用于SSA转换和优化
        let idoms = result.calculate_idoms(false);
        
        // r_idoms（直接后支配者）
        //  1. __含义__：Reverse Immediate Dominator，直接后支配者
        //  2. __方向__：从出口到入口的反向支配关系
        //  3. __作用__：构建后支配树，用于死代码消除和程序分析
        let r_idoms = result.calculate_idoms(true);

        // 构建正向支配树
        for (i, k) in idoms.into_iter().enumerate() {
            if let Some(_k) = k {
                result.blocks[i].idom = k;
                result.blocks[_k].idom_of.push(i);
            }
        }

        // 构建后支配树
        for (i, k) in r_idoms.into_iter().enumerate() {
            if let Some(_k) = k {
                result.blocks[i].r_idom = k;
                result.blocks[_k].r_idom_of.push(i);
            }
        }

        #[cfg(feature = "print-cfgs")]
        {
            println!("CFG <from-linear>:");
            println!("{}", result.to_dot());
        }
        result
    }
   
    // 关键分割算法
    fn split_critical(&mut self) {
        // 1. 初始化阶段
        //  1. 创建标签生成器，用于生成新的基本块标签
        //  2. 准备要添加的新块列表
        //  3. 设置当前索引为现有块数量
        let mut gen = VRegGenerator::with_prefix("_CRITICAL_".into());
        let mut to_append = vec![];
        let mut current_idx = self.blocks.len();

        // 2. 关键边检测
        //  1. __源块__：有多个后继（`children.len() > 1`）
        //  2. __目标块__：有多个前驱（`preds.len() > 1`）
        //  3. 同时满足这两个条件的就是关键边
        for i in 0..self.blocks.len() {
            if self.blocks[i].children.len() <= 1 {
                continue;
            }
            let block = &self.blocks[i];
            for (k, child_) in block.children.clone().into_iter().enumerate() {
                if self.blocks[child_].preds.len() > 1 {
                    // 关键边检测成功
                    let label: Rc<str> = gen.next_label().into();
                    let child_label = self.blocks[child_].label.clone();
                    let block = &mut self.blocks[i];

                    // 分支指令更新
                    //  1. 找到源块中的分支指令
                    //  2. 将指向目标块的标签替换为新创建的中间块标签
                    if let Some(
                        Operator::Bgt(_, _, s1, s2)
                        | Operator::Bl(_, _, s1, s2)
                        | Operator::Beq(_, _, s1, s2),
                    ) = block.body.last_mut()
                    {
                        if *s1 == child_label {
                            *s1 = Rc::clone(&label); // 将原始标签替换为 _CRITICAL_0
                        } else if *s2 == child_label {
                            *s2 = Rc::clone(&label); // 将原始标签替换为 _CRITICAL_0
                        }
                    }

                    // 中间块创建
                    //  1. 标签： 新生成的唯一标签
                    //  2. 前驱: 只有源块一个前驱
                    //  3. 后继：只有目标块一个后继
                    //  4. 指令: 仅包含无条件跳转到目标块的指令
                    let mut new = Block::empty(&label);
                    let child = &mut self.blocks[child_];
                    new.children = vec![child_];
                    new.preds = vec![i];
                    new.body = vec![Operator::J(Rc::clone(&child.label))];
                    to_append.push(new);

                    // 控制流关系更新
                    //  1. 更新目标块的前驱关系：源块 -> 中间块
                    //  2. 更新源块的后继关系: 目标块 -> 中间块
                    //  3. 递增索引准备下一个中间块
                    child.preds.iter_mut().for_each(|pred| {
                        if *pred == i {
                            *pred = current_idx;
                        }
                    });
                    self.blocks[i].children[k] = current_idx;
                    current_idx += 1;
                }
            }
        }
        self.blocks.append(&mut to_append);
    }
    
    /// SSA 变量重命名算法
    fn rename_blocks(
        &mut self,
        block: usize,
        globals: &Vec<VReg>,
        names: &mut HashMap<VReg, Vec<VReg>>, // 变量版本栈：跟踪变量的当前版本
        generator: &mut VRegGenerator,
        phis: &mut Vec<Vec<SSAOperator>>,
    ) {
        let current = block;

        // 阶段1： 为全局变量压栈
        for &global in globals.iter() {
            let last = names.entry(global).or_default();
            let next = last.last().cloned().unwrap_or(u32::MAX); // undefined
            last.push(next); // 进入块时压栈
        }

        // 阶段2: 重命名 phi函数的目标寄存器
        for op in &mut phis[current] {
            if let SSAOperator::Phi(rec, _) = op {
                let old = *rec;
                // names.get_mut(&old)：获取原始变量的版本栈的可变引用
                // .last_mut().unwrap()：获取栈顶元素的可变引用
                // generator.next_reg()：生成新的唯一寄存器编号
                // *... = ...：将栈顶元素替换为新寄存器编号
                *(names.get_mut(&old).unwrap().last_mut().unwrap()) = generator.next_reg();
                // 将Phi函数的目标寄存器更新为新的寄存器编号
                // 完成重命名
                *rec = *names[&old].last().unwrap();
            }
        }

        // 阶段3：局部变量映射表
        let mut locals = HashMap::new();
        
        // 宏定义：更新变量名(使用操作) 
        macro_rules! update_name {
            ($name:expr) => {
                #[allow(clippy::unnecessary_mut_passed)]
                if globals.contains($name) {
                    let old = *$name;
                    // 全局变量: 使用栈顶版本
                    *$name = *names[&old].last().unwrap();
                } else if let Some(&v) = locals.get($name) {
                    // 局部变量: 使用映射版本
                    *$name = v;
                }
            };
        }

        // 宏定义: 设置变量名(定义操作)
        macro_rules! set_name {
            ($name:expr) => {
                if globals.contains($name) {
                    // 全局变量: 生成新版本并更新栈
                    let old = *$name;
                    *(names.get_mut(&old).unwrap().last_mut().unwrap()) = generator.next_reg();
                    *$name = *names[&old].last().unwrap();
                } else {
                    // 局部变量: 生成新版本并记录映射
                    let old = *$name;
                    *$name = generator.next_reg();
                    locals.insert(old, *$name);
                }
            };
        }

        // 阶段4：重命名普通指令中的寄存器
        for op in &mut self.blocks[current].body {
            match op {
                // 二元运算指令：更新源寄存器，设置目标寄存器
                Operator::Add(x, y, z)
                | Operator::Sub(x, y, z)
                | Operator::Mult(x, y, z)
                | Operator::Div(x, y, z)
                | Operator::Xor(x, y, z)
                | Operator::Slt(x, y, z)
                | Operator::Load(x, y, z)
                | Operator::And(x, y, z)
                | Operator::Or(x, y, z) => {
                    update_name!(y);
                    update_name!(z);
                    set_name!(x);
                }

                // 存储指令：更新所有寄存器
                Operator::Store(x, y, z) => {
                    update_name!(x);
                    update_name!(y);
                    update_name!(z);
                }

                // 单操作数指令：设置目标寄存器
                Operator::LoadLocal(x, _)
                | Operator::Li(x, _)
                | Operator::La(x, _)
                | Operator::GetParameter(x, _) => {
                    set_name!(x);
                }

                // 移动指令：更新源寄存器，设置目标寄存器
                Operator::Mv(x, y) => {
                    update_name!(y);
                    set_name!(x);
                }

                // 分支指令：更新源寄存器
                Operator::Bgt(x, y, _, _)
                | Operator::Bl(x, y, _, _)
                | Operator::Beq(x, y, _, _) => {
                    update_name!(y);
                    update_name!(x);
                }

                // 函数调用：更新参数寄存器，设置目标寄存器
                Operator::Call(x, _, z) => {
                    for name in z {
                        update_name!(name);
                    }
                    set_name!(x);
                }

                // 存储和返回指令：更新源寄存器
                Operator::StoreLocal(x, _) | Operator::Return(x) => {
                    update_name!(x);
                }
                _ => {}
            }
        }

        // 阶段5：清理局部变量映射
        std::mem::take(&mut locals);

        // 阶段6：更新后继块中Phi函数的参数
        for &child in self.blocks[current].children.iter() {
            for phi in &mut phis[child] {
                if let SSAOperator::Phi(_, args) = phi {
                    let selfpos = self.blocks[child]
                        .preds
                        .iter()
                        .position(|&v| v == current)
                        .unwrap();

                    update_name!(&mut args[selfpos]);
                }
            }
        }

        // 阶段7：递归处理被支配的块
        // 1. __深度优先__：按照支配树顺序遍历
        // 2. __状态保持__：每个块的变量状态独立
        // 3. __正确性保证__：确保SSA形式的单赋值性质
        for idomsucc in self.blocks[current].idom_of.clone() {
            self.rename_blocks(idomsucc, globals, names, generator, phis);
        }

        // 阶段8：为全局变量弹栈
        for global in globals.iter() {
            // 离开块时弹栈
            // 压栈: 保存当前状态，支持递归处理
            // 弹栈: 恢复父块的状态
            names.get_mut(global).unwrap().pop();
        }
    }
    
    /// to_ssa transforms the CFG into SSA form.
    /// SSA 转换算法
    pub fn into_ssa(mut self) -> CFG<SSAOperator> {
        // 阶段1：计算支配边界和全局寄存器
        let frontiers = self.get_dominance_frontiers();
        let (globals, defined_in) = self.get_global_regs();
        let mut phis = vec![vec![]; self.blocks.len()];
        
        // 阶段2：生成Phi函数
        //phase 1: generate phi functions
        for &global in globals.iter() {
            let mut queue: Vec<_> = defined_in[&global].clone();
            while let Some(next) = queue.pop() {
                for &succ in &frontiers[next] {
                    let entry =
                        SSAOperator::Phi(global, vec![global; self.blocks[succ].preds.len()]);
                    if !phis[succ].contains(&entry) {
                        phis[succ].push(entry);
                        queue.push(succ);   // 继续传播
                    }
                }
            }
        }

        // 阶段3：变量重命名
        let mut generator = VRegGenerator::starting_at_reg(self.max_reg + 1);
        let mut names: HashMap<VReg, Vec<VReg>> = HashMap::new();
        self.rename_blocks(0, &globals, &mut names, &mut generator, &mut phis);
        
        // 阶段4：构建SSA形式的CFG。例子: 合并CFG.md
        // 1. 负责奖phi函数和重命名后的普通指令合并，构建最终的SSA形式控制流图
        let new_blocks: Vec<Block<SSAOperator>> = phis
            .into_iter() // 将phis转换为迭代器，消耗所有权
            .zip(self.blocks.into_iter()) // // 将phis和原始块配对，形成(phi_list, block)元组
            .map(|(mut vec, mut block)| { // // 对每个(phi_list, block)对进行处理
                // 1. 获取原始块中的指令序列
                let old = std::mem::take(&mut block.body);
                // // 2. 将普通Operator转换为SSAOperator::IROp
                let mut modified = old
                    .into_iter()    // 将指令序列转换为迭代器
                    .map(SSAOperator::IROp)  // 将每个Operator包装为SSAOperator::IROp
                    .collect::<Vec<SSAOperator>>(); // 收集为SSAOperator向量
                
                // 3. 将Phi函数列表和转换后的普通指令合并
                vec.append(&mut modified);
                // 4. 将基本块转换为SSAOperator类型
                block.into_other(vec)
            })
            .collect();  // 收集所有转换后的块

        // 阶段5：返回SSA形式的CFG
        let result = CFG {
            blocks: new_blocks,
            entry: self.entry,
            exit: self.exit,
            max_reg: generator.next_reg(),
            allocated_ars: 0,
        };
        let _ = result;
        #[cfg(feature = "print-cfgs")]
        {
            println!("CFG <to-ssa>:");
            println!("{}", result.to_dot());
        }
        result
    }

    /// gets global regs and the blocks that they are used in.
    /// 全局寄存器分析算法
    /// 用于识别SSA转换中需要处理的全局变量及其定义位置
    fn get_global_regs(&self) -> (Vec<VReg>, HashMap<VReg, Vec<usize>>) {
        // 1. 初始化数据结构
        let mut exposed = HashSet::new();
        let mut defined_in: HashMap<VReg, HashSet<usize>> = HashMap::new();

        // 2. 遍历所有基本块
        for (i, block) in self.blocks.iter().enumerate() {
            let mut killed = HashSet::new();
            // 2. 遍历块中的每条指令
            for op in &block.body {
                // 宏定义：测试并插入暴露的寄存器
                macro_rules! test_and_insert {
                    ($reg:expr) => {
                        if !killed.contains($reg) {
                            exposed.insert(*$reg);
                        }
                    };
                }
                // 4. 根据指令类型分析类型分析寄存器使用
                match op {
                    // 二元运算指令：使用两个源寄存器，定义一个目标寄存器
                    Operator::Add(x, y, z)
                    | Operator::Slt(x, y, z)
                    | Operator::Sub(x, y, z)
                    | Operator::Mult(x, y, z)
                    | Operator::Div(x, y, z)
                    | Operator::And(x, y, z)
                    | Operator::Or(x, y, z)
                    | Operator::Xor(x, y, z)
                    | Operator::Load(x, y, z)
                    | Operator::Store(x, y, z) => {
                        test_and_insert!(y); // 检查源寄存器y是否暴露
                        test_and_insert!(z); // 检查源寄存器z是否暴露
                        killed.insert(x);    // 目标寄存器x被定义（杀死）
                        defined_in.entry(*x).or_default().insert(i);  // 记录x在块i中被定义
                    }
                    // 单操作数指令：定义一个目标寄存器
                    Operator::LoadLocal(x, _)
                    | Operator::GetParameter(x, ..)
                    | Operator::La(x, ..)
                    | Operator::Li(x, ..) => {
                        killed.insert(x); // 目标寄存器x被定义（杀死）
                        defined_in.entry(*x).or_default().insert(i); // 记录x在块i中被定义
                    }
                    // 移动指令：使用一个源寄存器，定义一个目标寄存器
                    Operator::Mv(x, y) => {
                        test_and_insert!(y); // 检查源寄存器y是否暴露
                        killed.insert(x);    // 目标寄存器x被定义（杀死）
                        defined_in.entry(*x).or_default().insert(i); // 记录x在块i中被定义
                    }
                    // 函数调用指令：使用多个参数寄存器，定义一个目标寄存器
                    Operator::Call(x, _, args) => {
                        for vr in args {
                            test_and_insert!(vr);  // 检查每个参数寄存器是否暴露
                        }
                        killed.insert(x); // 目标寄存器x被定义（杀死）
                        defined_in.entry(*x).or_default().insert(i); // 记录x在块i中被定义
                    }
                     // 分支指令：使用两个源寄存器
                    Operator::Bgt(y, z, _, _)
                    | Operator::Bl(y, z, _, _)
                    | Operator::Beq(y, z, _, _) => {
                        test_and_insert!(y); // 检查源寄存器y是否暴露
                        test_and_insert!(z); // 检查源寄存器z是否暴露
                    }
                    // 存储和返回指令：使用一个源寄存器
                    Operator::StoreLocal(y, _) | Operator::Return(y) => {
                        test_and_insert!(y); // 检查源寄存器y是否暴露
                    }
                    _ => {}
                }
            }
        }
        // 5. 返回结果
        (
            exposed.into_iter().collect(),
            defined_in
                .into_iter()
                .map(|(k, v)| (k, v.into_iter().collect()))
                .collect(),
        )
    }
    
    /// `live_out` 函数是**活跃变量分析**（Live Variable Analysis）的核心实现。
    /// 该函数的主要作用是计算控制流图中每个基本块出口处的活跃寄存器集合，这是寄存器分配和优化的重要基础
    /// 主要功能:
    ///     1. 计算活跃出集合：确定每个基本块出口处哪些寄存器是活跃的（值在后续会被使用）
    ///     2. 反向数据流分析：从出口向入口传播活跃信息
    ///     3. 迭代求解：使用工作列表算法迭代计算直到收敛
    pub fn  live_out(&self) -> Vec<HashSet<VReg>> {
        /// 步骤1：初始化数据结构
        /// live_ins[i]: 基本块i入口处的活跃寄存器集合
        let mut live_ins = vec![HashSet::new(); self.len()];
        
        /// live_outs[i]: 基本块i出口处的活跃寄存器集合
        let mut live_outs = vec![HashSet::new(); self.len()];

        /// defs[i]: 基本块i中定义的寄存器集合（被赋值的寄存器）
        let mut defs = vec![HashSet::new(); self.len()];

        /// 步骤2：分析每个基本块，收集定义和使用信息
        for (i, block) in self.get_blocks().iter().enumerate() {
            /// 遍历基本块中的每条指令
            for op in block.body.iter() {
                /// 宏定义：插入依赖寄存器（使用的寄存器）
                /// 规则：如果寄存器在基本块中没有被定义，则它是活跃的
                macro_rules! insert_deps {
                    ($($x:expr),+) => {
                        {
                            $(if !defs[i].contains($x) {
                                live_ins[i].insert(*$x);
                            })+
                        }
                    };
                }

                /// 根据指令类型处理寄存器使用
                match op {
                    /// 二元运算指令：使用两个源寄存器
                    crate::ir::Operator::Add(_, y, z)
                    | crate::ir::Operator::Sub(_, y, z)
                    | crate::ir::Operator::Mult(_, y, z)
                    | crate::ir::Operator::Slt(_, y, z)
                    | crate::ir::Operator::Div(_, y, z)
                    | crate::ir::Operator::Or(_, y, z)
                    | crate::ir::Operator::Xor(_, y, z)
                    | crate::ir::Operator::Load(_, y, z)
                    | crate::ir::Operator::And(_, y, z) => insert_deps!(y, z),

                    /// 存储指令：使用三个源寄存器
                    crate::ir::Operator::Store(x, y, z) => insert_deps!(x, y, z),
                    
                    /// 存储局部变量和移动指令：使用一个源寄存器
                    crate::ir::Operator::StoreLocal(y, _) | crate::ir::Operator::Mv(_, y) => {
                        insert_deps!(y)
                    }

                    /// 分支指令：使用两个条件寄存器
                    crate::ir::Operator::Bl(x, y, ..)
                    | crate::ir::Operator::Beq(x, y, ..)
                    | crate::ir::Operator::Bgt(x, y, ..) => insert_deps!(x, y),
                    
                    /// 函数调用指令：使用所有参数寄存器
                    crate::ir::Operator::Call(.., z) => {
                        for rc in z {
                            insert_deps!(rc);
                        }
                    }

                    /// 返回指令：使用返回值寄存器
                    crate::ir::Operator::Return(x) => insert_deps!(x),
                    
                    /// 其他指令：没有寄存器使用
                    _ => {}
                }
                
                /// 记录指令的结果寄存器（如果有的话）
                if let Some(rec) = op.receiver() {
                    defs[i].insert(rec);
                }
            }
        }

        /// 步骤3：迭代计算活跃变量集合（反向数据流分析）
        let mut changed = true;

        /// 迭代直到没有变化（收敛）
        while changed {
            changed = false;

            /// 遍历所有基本块
            for i in 0..self.len() {
                /// 步骤3.1：计算live_out[i] = ∪_{s∈succ(i)} live_in[s]
                /// 后继块的活跃入集合的并集
                let succs = self.get_block(i).children.iter();
                let mut new = HashSet::new();
                for succ in succs {
                    new.extend(live_ins[*succ].iter());
                }

                /// 如果live_out[i]发生变化，标记为changed
                if new != live_outs[i] {
                    changed = true;
                    live_outs[i] = new;
                }

                /// 步骤3.2：计算live_in[i] = use[i] ∪ (live_out[i] - def[i])
                /// 保存旧的live_in[i]
                let old = std::mem::take(&mut live_ins[i]);
                
                /// 计算新的live_in[i]
                let mut new = old.clone();
                /// live_out[i] - def[i]：出口活跃但不在本块定义的寄存器
                new.extend(live_outs[i].clone().difference(&defs[i]));
                
                /// 如果live_in[i]发生变化，标记为changed
                if new != old {
                    changed = true;
                }
                live_ins[i] = new;
            }
        }
        /// 步骤4：返回活跃出集合
        live_outs
    }
}

impl CFG<SSAOperator> {
    pub fn live_out(&self) -> Vec<HashSet<VReg>> {
        let ssa = self;
        let mut live_ins = vec![HashSet::new(); ssa.len()];
        let mut live_outs = vec![HashSet::new(); ssa.len()];
        let mut phi_uses = vec![HashSet::new(); ssa.len()];
        let mut defs = vec![HashSet::new(); ssa.len()];

        for (i, block) in ssa.get_blocks().iter().enumerate() {
            for op in block.body.iter() {
                macro_rules! insert_deps {
                    ($($x:expr),+) => {
                        {
                            $(if !defs[i].contains($x) {
                                live_ins[i].insert(*$x);
                            })+
                        }
                    };
                }
                match op {
                    SSAOperator::IROp(op) => match op {
                        crate::ir::Operator::Add(_, y, z)
                        | crate::ir::Operator::Sub(_, y, z)
                        | crate::ir::Operator::Mult(_, y, z)
                        | crate::ir::Operator::Slt(_, y, z)
                        | crate::ir::Operator::Div(_, y, z)
                        | crate::ir::Operator::Or(_, y, z)
                        | crate::ir::Operator::Xor(_, y, z)
                        | crate::ir::Operator::Load(_, y, z)
                        | crate::ir::Operator::And(_, y, z) => insert_deps!(y, z),
                        crate::ir::Operator::Store(x, y, z) => insert_deps!(x, y, z),
                        crate::ir::Operator::StoreLocal(y, _) | crate::ir::Operator::Mv(_, y) => {
                            insert_deps!(y)
                        }
                        crate::ir::Operator::Bl(x, y, ..)
                        | crate::ir::Operator::Beq(x, y, ..)
                        | crate::ir::Operator::Bgt(x, y, ..) => insert_deps!(x, y),
                        crate::ir::Operator::Call(.., z) => {
                            for rc in z {
                                insert_deps!(rc);
                            }
                        }
                        crate::ir::Operator::Return(x) => insert_deps!(x),
                        _ => {}
                    },
                    SSAOperator::Phi(_, vec) => {
                        for (i, reg) in vec.iter().enumerate() {
                            phi_uses[block.preds[i]].insert(*reg);
                        }
                    }
                }
                if let Some(rec) = op.receiver() {
                    defs[i].insert(rec);
                }
            }
        }

        let mut changed = true;

        while changed {
            changed = false;
            for i in 0..ssa.len() {
                let succs = ssa.get_block(i).children.iter();
                let mut new = phi_uses[i].clone();
                for succ in succs {
                    new.extend(live_ins[*succ].iter());
                }
                if new != live_outs[i] {
                    changed = true;
                    live_outs[i] = new;
                }

                let old = std::mem::take(&mut live_ins[i]);
                let mut new = old.clone();
                new.extend(live_outs[i].clone().difference(&defs[i]));
                if new != old {
                    changed = true;
                }
                live_ins[i] = new;
            }
        }

        live_outs
    }

    /// 用于构建SSA形式的使用链(Use Chain)
    /// 记录每个寄存器在哪些指令中被使用
    /// 函数签名: 返回一个二维向量，表示SSA图
    /// 外层向量: 索引是寄存器编号(0..max_reg - 1)
    /// 内层向量: 该寄存器被使用的所有位置
    /// 每个元素: (使用该寄存器的指令引用，所在基本块索引)
    pub fn ssa_graph(&self) -> Vec<Vec<(&SSAOperator, usize)>> {
        /// 1. 初始化结果数据结构: 为每个可能的寄存器创建一个空列表
        /// self.max_reg 表示当前函数中使用的最大寄存器编号+1
        /// 例如: 如果 max_reg = 10，则创建10个空向量（对应寄存器0-9）
        let mut result = vec![Vec::default(); self.max_reg as usize];
        
        /// 2. 遍历所有基本块
        /// i: 基本块索引(0, 1, 2, ....)
        /// block: 基本块引用
        for (i, block) in self.blocks.iter().enumerate() {
            /// 3. 遍历基本块中的每条指令
            for op in &block.body {
                /// 宏定义: 将操作数推送到对应的寄存器使用列表中
                /// 这个宏可以处理1个或多个操作数
                /// 例如: push_operands!(x, y) 会将x和y都添加到对应的列表中
                macro_rules! push_operands {
                    ($($x:expr),+) => {
                        {$(result[*$x as usize].push((op, i));)+}
                    };
                }

                /// 4. 根据指令类型处理操作数
                match op {
                    /// 处理普通IR指令(非Phi 函数)
                    SSAOperator::IROp(op_) => match op_ {
                        /// 二元运算指令：记录两个源寄存器的使用
                        /// 格式：Operator::Add(结果寄存器, 源寄存器1, 源寄存器2)
                        /// 只记录源寄存器（x, y），不记录结果寄存器
                        Operator::Add(_, x, y) => push_operands!(x, y),
                        Operator::Sub(_, x, y) => push_operands!(x, y),
                        Operator::Mult(_, x, y) => push_operands!(x, y),
                        Operator::Div(_, x, y) => push_operands!(x, y),
                        Operator::Or(_, x, y) => push_operands!(x, y),
                        /// 存储指令：记录源寄存器的使用
                        /// StoreLocal(值寄存器, 内存位置)
                        Operator::StoreLocal(x, _) => push_operands!(x),
                        /// 移动指令：记录源寄存器的使用
                        /// Mv(目标寄存器, 源寄存器)
                        Operator::Mv(_, x) => push_operands!(x),
                        /// 异或运算：记录两个源寄存器的使用
                        Operator::Xor(_, x, y) => push_operands!(x, y),
                        /// 加载指令：记录基址寄存器和偏移寄存器的使用
                        /// Load(结果寄存器, 偏移寄存器, 基址寄存器)
                        Operator::Load(_, x, y) => push_operands!(x, y),
                        /// 存储指令：记录值、偏移、基址三个寄存器的使用
                        /// Store(值寄存器, 偏移寄存器, 基址寄存器)
                        Operator::Store(z, x, y) => push_operands!(x, y, z),
                        /// 分支指令：记录两个条件寄存器的使用
                        /// Bgt(寄存器1, 寄存器2, 真分支标签, 假分支标签)
                        Operator::Bgt(x, y, _, _) => push_operands!(x, y),
                        Operator::Bl(x, y, _, _) => push_operands!(x, y),
                        Operator::Beq(x, y, _, _) => push_operands!(x, y),
                        /// 比较指令：记录两个源寄存器的使用
                        /// Slt(结果寄存器, 寄存器1, 寄存器2)
                        Operator::Slt(_, x, y) => push_operands!(x, y),
                        /// 函数调用指令：记录所有参数寄存器的使用
                        /// Call(结果寄存器, 函数标签, 参数寄存器列表)
                        Operator::Call(_, _, vec) => {
                            for &o in vec {
                                result[o as usize].push((op, i))
                            }
                        }
                        /// 返回指令：记录返回值寄存器的使用
                        Operator::Return(x) => push_operands!(x),
                        /// 其他指令：不记录操作数使用
                        /// 包括：Li(立即数), La(标签), Label, J(跳转)等
                        _ => {}
                    },
                    /// 处理Phi函数
                    /// Phi(结果寄存器, 操作数寄存器列表)
                    /// 例如：rd5 = φ(rd3, rd4) 表示rd5的值来自rd3或rd4
                    SSAOperator::Phi(_, v) => {
                        /// 遍历Phi函数的所有操作数
                        /// 过滤掉无效值（u32::MAX表示未定义）
                        for &o in v.iter().filter(|&&r| r != u32::MAX) {
                            /// 将操作数寄存器添加到使用列表中
                            result[o as usize].push((op, i));
                        }
                    }
                }
            }
        }
        /// 5. 返回构建完成的SSA图
        result
    }
}

#[cfg(test)]
mod test {
    use proptest::prelude::*;
    use proptest::prop_oneof;
    use proptest::strategy::Strategy;

    use crate::util::SheafTable;

    use super::Operator;
    use super::CFG;
    use std::collections::HashSet;
    use std::collections::VecDeque;
    use std::rc::Rc;

    #[test]
    fn build_cfg_jmp() {
        let l1 = Rc::from("L1");
        let input = vec![
            Operator::Nop,
            Operator::Nop,
            Operator::J(Rc::clone(&l1)),
            Operator::Label(Rc::clone(&l1)),
            Operator::Nop,
            Operator::Nop,
            Operator::Return(2),
        ];
        let output = CFG::from_linear(input, [], 2);
        println!("{output:?}")
    }

    #[test]
    fn build_cfg_branch() {
        let l1 = Rc::from("L1");
        let l2 = Rc::from("L2");
        let l3 = Rc::from("L3");
        let header = Rc::from("Header");
        let input = vec![
            Operator::Nop,
            Operator::J(Rc::clone(&header)),
            Operator::Label(Rc::clone(&header)),
            Operator::Nop,
            Operator::Beq(0, 0, Rc::clone(&l1), Rc::clone(&l2)),
            Operator::Label(Rc::clone(&l1)),
            Operator::Nop,
            Operator::J(Rc::clone(&l3)),
            Operator::Label(Rc::clone(&l2)),
            Operator::Nop,
            Operator::J(Rc::clone(&l3)),
            Operator::Label(Rc::clone(&l3)),
            Operator::Return(2),
        ];
        let output = CFG::from_linear(input, [], 2);
        assert_eq!(output.blocks[0].children.len(), 1);
        assert_eq!(output.blocks[1].children.len(), 2);
        assert_eq!(output.blocks[2].children.len(), 1);
        assert_eq!(output.blocks[3].children.len(), 1);
        assert_eq!(output.blocks[4].children.len(), 0);
        assert_eq!(output.blocks[4].preds.len(), 2);

        assert_eq!(output.blocks[0].idom, None);
        assert_eq!(output.blocks[1].idom.unwrap(), 0);
        assert_eq!(output.blocks[2].idom.unwrap(), 1);
        assert_eq!(output.blocks[3].idom.unwrap(), 1);
        assert_eq!(output.blocks[4].idom.unwrap(), 1);
        println!("{output:?}")
    }

    #[test]
    fn build_cfg_while() {
        let l1 = Rc::from("L1");
        let l2 = Rc::from("L2");
        let l3 = Rc::from("L3");
        let input = vec![
            Operator::Nop,
            Operator::J(Rc::clone(&l1)),
            Operator::Label(Rc::clone(&l1)),
            Operator::Li(33, 0),
            Operator::Beq(34, 33, Rc::clone(&l2), Rc::clone(&l3)),
            Operator::Label(Rc::clone(&l3)),
            Operator::Nop,
            Operator::J(Rc::clone(&l1)),
            Operator::Label(Rc::clone(&l2)),
            Operator::Nop,
        ];
        let output = CFG::from_linear(input, [], 34);
        assert_eq!(output.blocks[0].children.len(), 1);
        assert_eq!(output.blocks[1].children.len(), 2);
        assert_eq!(output.blocks[2].children.len(), 1);
        assert_eq!(output.blocks[3].children.len(), 0);
        assert_eq!(output.blocks[1].preds.len(), 2);

        println!("{output:?}");

        assert_eq!(output.blocks[0].idom, None);
        assert_eq!(output.blocks[1].idom.unwrap(), 0);
        assert_eq!(output.blocks[2].idom.unwrap(), 1);
    }

    proptest! {
        #[test]
        fn test_reachable(cfg in any_with::<CFG<Operator>>((20, 20, 20))) {
            let dot = cfg.to_dot();
            let mut found = HashSet::new();
            let mut visited = HashSet::new();
            let mut queue = VecDeque::new();
            found.insert(cfg.get_exit());
            queue.push_back(0);
            while let Some(nxt) = queue.pop_front() {
                visited.insert(nxt);
                found.insert(nxt);
                queue.extend(cfg.blocks[nxt].children.iter().filter(|child| !visited.contains(child)));
            }
            assert!(found.len() == cfg.blocks.len(), "unreachable block in {dot}\n");
        }

        #[test]
        fn test_correct_labels(cfg in any_with::<CFG<Operator>>((20, 20, 20))) {
            for block in &cfg.blocks {
                if let Some(Operator::Bgt(_, _, s1, s2) | Operator::Bl(_, _, s1, s2) | Operator::Beq(_, _, s1, s2)) = block.body.last() {
                    assert!(block.children.len() <= 2 && !block.children.is_empty(), "{}", cfg.to_dot());
                    for &child in &block.children {
                        let child = &cfg.blocks[child];
                        assert!(child.label == *s1 || child.label == *s2);
                    }
                } else if let Some(Operator::J(s1)) = block.body.last() {
                    assert_eq!(block.children.len(), 1);
                    assert_eq!(&cfg.blocks[block.children[0]].label, s1);
                }
            }
        }

        #[test]
        fn test_ssa_one_definition(cfg in any_with::<CFG<Operator>>((20, 20, 20))) {
            let dot = cfg.to_dot();
            let ssa = cfg.into_ssa();
            let ssa_dot = ssa.to_dot();
            let mut defined = HashSet::new();
            for block in ssa.blocks {
                for op in block.body {
                    match op {
                        crate::ir::SSAOperator::IROp(op) => match op {
                            Operator::Add(x, _, _)  |
                            Operator::Sub(x, _, _)  |
                            Operator::Mult(x, _, _)  |
                            Operator::Div(x, _, _)  |
                            Operator::And(x, _, _)  |
                            Operator::Or(x, _, _)  |
                            Operator::Mv(x, _)  |
                            Operator::Xor(x, _, _)  |
                            Operator::Load(x, _, _)  |
                            Operator::La(x, _)  |
                            Operator::LoadLocal(x, _) |
                            Operator::Li(x, _)  |
                            Operator::Slt(x, _, _)  |
                            Operator::Call(x, _, _)  |
                            Operator::GetParameter(x, _) =>  {
                                assert!(!defined.contains(&x), "original: {dot}\n ssa: {ssa_dot}\n");
                                defined.insert(x);
                            },
                            _ => {}
                        },
                        crate::ir::SSAOperator::Phi(x, _) => {
                            assert!(!defined.contains(&x), "original: {dot}\n ssa: {ssa_dot}\n");
                            defined.insert(x);
                        }
                    }
                }
            }
        }

        #[test]
        fn test_ssa_reaching_definition(cfg in any_with::<CFG<Operator>>((20, 20, 20))) {
            fn check_reaching_recursive(ssa: & CFG<super::SSAOperator>, names: &mut SheafTable<super::VReg, bool>, current: usize) {
                let block = &ssa.blocks[current];
                let ssa_dot = ssa.to_dot();
                names.push();
                macro_rules! check_def {
                    ($name:expr) => {
                        assert!(names.get($name).is_some(), "\nssa: {ssa_dot}\nin block: {}\nchecking name: {}\n", block.label, *$name);
                    }
                }

                macro_rules! create_def {
                    ($name:expr) => {
                        names.insert(*$name, true);
                    }
                }
                for op in &block.body {
                    match op {
                        crate::ir::SSAOperator::IROp(op) => match op {
                            Operator::Add(x, y, z)
                            | Operator::Sub(x, y, z)
                            | Operator::Mult(x, y, z)
                            | Operator::Div(x, y, z)
                            | Operator::Xor(x, y, z)
                            | Operator::Slt(x, y, z)
                            | Operator::Load(x, y, z)
                            | Operator::Store(x, y, z)
                            | Operator::And(x, y, z)
                            | Operator::Or(x, y, z) => {
                                check_def!(y);
                                check_def!(z);
                                create_def!(x);
                            }
                            Operator::LoadLocal(x, _) | Operator::Li(x, _) | Operator::La(x, _) | Operator::GetParameter(x, _) => {
                                create_def!(x);
                            }
                            Operator::Mv(x, y) => {
                                check_def!(y);
                                create_def!(x);
                            }
                            Operator::Bgt(x, y, _, _)
                            | Operator::Bl(x, y, _, _)
                            | Operator::Beq(x, y, _, _) => {
                                check_def!(y);
                                check_def!(x);
                            }
                            Operator::Call(x, _, z) => {
                                for name in z {
                                    check_def!(name);
                                }
                                create_def!(x);
                            }
                            Operator::StoreLocal(x, _) | Operator::Return(x) => {
                                check_def!(x);
                            }
                            _ => {}
                                    },
                        crate::ir::SSAOperator::Phi(x, _) => {
                            create_def!(x);
                        },
                    }
                }
                for &child in &block.idom_of {
                    check_reaching_recursive(ssa, names, child);
                }
                names.pop();
            }
            let ssa = cfg.into_ssa();
            let mut names = SheafTable::new();
            check_reaching_recursive(&ssa, &mut names, 0);
        }
    }

    proptest! {

        #![proptest_config(ProptestConfig {
            .. ProptestConfig::default()
        })]

        #[test]
        fn test_ssa_non_critical_edge(cfg in any_with::<CFG<Operator>>((10, 10, 10))) {
            let ssa = cfg.into_ssa();

            for block in &ssa.blocks {
                if block.children.len() > 1 {
                    for &child in &block.children {
                        let child = &ssa.blocks[child];
                        assert!(child.preds.len() <= 1);
                    }
                }
            }
        }

        // #[test]
        // fn test_ssa_print(cfg in any_with::<CFG<Operator>>((20, 20, 30))) {
        //     println!("\nLinear:\n{}\n", cfg.to_dot());
        //     let ssa = cfg.to_ssa();
        //     println!("\nSSA:\n{}\n", ssa.to_dot());
        // }

    }

    fn arbitrary_stmt(
        reg1: super::VReg,
        reg2: super::VReg,
        reg3: super::VReg,
        label: Rc<str>,
    ) -> impl Strategy<Value = Operator> {
        prop_oneof![
            Just(Operator::Nop),
            Just(Operator::Add(reg1, reg2, reg3)),
            Just(Operator::Sub(reg1, reg2, reg3)),
            Just(Operator::Mult(reg1, reg2, reg3)),
            Just(Operator::Div(reg1, reg2, reg3)),
            Just(Operator::And(reg1, reg2, reg3)),
            Just(Operator::Or(reg1, reg2, reg3)),
            Just(Operator::Xor(reg1, reg2, reg3)),
            Just(Operator::La(reg1, label)),
            Just(Operator::Load(reg1, reg2, reg3)),
            Just(Operator::Slt(reg1, reg2, reg3)),
            Just(Operator::Store(reg1, reg2, reg3)),
            Just(Operator::Load(reg1, reg2, reg3)),
            Just(Operator::Mv(reg1, reg2)),
            any::<i64>().prop_map(move |i| Operator::Li(reg1, i)),
            any::<u64>().prop_map(move |i| Operator::LoadLocal(reg1, i)),
            any::<u64>().prop_map(move |i| Operator::StoreLocal(reg1, i)),
        ]
    }

    fn arbitrary_branch(
        reg1: super::VReg,
        reg2: super::VReg,
        label1: Rc<str>,
        label2: Rc<str>,
    ) -> impl Strategy<Value = Operator> {
        prop_oneof![
            Just(Operator::Beq(
                reg1,
                reg2,
                Rc::clone(&label1),
                Rc::clone(&label2)
            )),
            Just(Operator::Bl(
                reg1,
                reg2,
                Rc::clone(&label1),
                Rc::clone(&label2)
            )),
            Just(Operator::Bgt(
                reg1,
                reg2,
                Rc::clone(&label1),
                Rc::clone(&label2)
            )),
        ]
    }

    fn arbitrary_block(
        len: usize,
        children: Vec<Rc<str>>,
        reg_range: impl Strategy<Value = super::VReg> + Clone + 'static,
    ) -> impl Strategy<Value = Vec<Operator>> {
        let body = proptest::collection::vec(
            (
                reg_range.clone(),
                reg_range.clone(),
                reg_range.clone(),
                "[a-z]*",
            )
                .prop_flat_map(|(reg1, reg2, reg3, lb)| {
                    arbitrary_stmt(reg1, reg2, reg3, Rc::from(&lb[..]))
                }),
            len,
        );
        let body: BoxedStrategy<Vec<Operator>> = if children.len() == 2 {
            body.prop_flat_map(move |v| {
                let b: BoxedStrategy<Operator> = (
                    reg_range.clone(),
                    reg_range.clone(),
                    Just(Rc::clone(&children[0])),
                    Just(Rc::clone(&children[1])),
                )
                    .prop_flat_map(|(reg1, reg2, lb1, lb2)| arbitrary_branch(reg1, reg2, lb1, lb2))
                    .boxed();
                b.prop_map(move |b| v.iter().cloned().chain(std::iter::once(b)).collect())
            })
            .boxed()
        } else if children.len() == 1 {
            body.prop_map(move |v| {
                v.into_iter()
                    .chain(std::iter::once(Operator::J(Rc::clone(&children[0]))))
                    .collect()
            })
            .boxed()
        } else {
            body.boxed()
        };

        body
    }

    fn generate_linear(
        reg_range: u32,
        block_len: usize,
        mut worklist: VecDeque<Rc<str>>,
        potential_blocks: Vec<Rc<str>>,
        done: HashSet<Rc<str>>,
        result: Vec<Vec<Operator>>,
    ) -> BoxedStrategy<Vec<Vec<Operator>>> {
        if let Some(nxt) = worklist.pop_front() {
            let copy_nxt = Rc::clone(&nxt);
            (
                proptest::collection::vec(proptest::sample::select(potential_blocks.clone()), 0..3)
                    .prop_filter("try to branch to self", move |vals| {
                        !vals.contains(&copy_nxt)
                    }),
                Just(worklist),
                Just(potential_blocks),
                Just(done),
                Just(result),
                Just(nxt),
            )
                .prop_flat_map(
                    move |(vals, mut worklist, potential_blocks, mut done, result, nxt)| {
                        for lb in &vals {
                            if !done.contains(lb) {
                                worklist.push_back(Rc::clone(lb));
                                done.insert(Rc::clone(lb));
                            }
                        }
                        let res = (
                            Just(result),
                            arbitrary_block(block_len, vals, 0_u32..reg_range),
                        )
                            .prop_map(move |(result, new)| {
                                result
                                    .into_iter()
                                    .chain(std::iter::once(
                                        std::iter::once(Operator::Label(Rc::clone(&nxt)))
                                            .chain(new.into_iter())
                                            .collect::<Vec<_>>(),
                                    ))
                                    .collect::<Vec<_>>()
                            });
                        (Just(worklist), Just(potential_blocks), Just(done), res).prop_flat_map(
                            move |(worklist, potential_blocks, done, res)| {
                                generate_linear(
                                    reg_range,
                                    block_len,
                                    worklist,
                                    potential_blocks,
                                    done,
                                    res,
                                )
                            },
                        )
                    },
                )
                .boxed()
        } else {
            Just(result).boxed()
        }
    }
    impl Arbitrary for CFG<Operator> {
        type Parameters = (usize, u32, usize);

        fn arbitrary_with((len, reg_range, block_len): Self::Parameters) -> Self::Strategy {
            let potential_blocks: Vec<Rc<str>> = (0..len)
                .map(|n| format!("LABEL_{}", n))
                .map(|s| Rc::from(&s[..]))
                .collect();
            let mut worklist: VecDeque<Rc<str>> = VecDeque::new();
            worklist.push_back(Rc::from("ENTRY"));
            let done: HashSet<Rc<str>> = HashSet::new();

            let linear = generate_linear(
                reg_range,
                block_len,
                worklist,
                potential_blocks,
                done,
                Vec::new(),
            )
            .prop_map(move |result| result.into_iter().flatten().skip(1).collect::<Vec<_>>());

            let cfg = linear.prop_map(move |linear| {
                CFG::from_linear(linear, (0..=reg_range).collect::<Vec<_>>(), reg_range + 1)
            });

            cfg.boxed()
        }

        type Strategy = BoxedStrategy<CFG<Operator>>;
    }
}
