// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
#![allow(dead_code)]
use std::{
    error::Error,
    fmt::{Debug, Display},
};

// 导出所有语法树节点的枚举变体，方便外部使用
pub use self::{
    Atom::*, BTerm::*, CTerm::*, Defs::*, Expr::*, Factor::*, Statement::*, Term::*, Type::*,
    Unit::*,
};

/// 空函数，用于占位或测试
pub fn do_nothing() {}

/// 解析错误结构体，包含错误信息和可选的源代码位置信息
pub struct ParseErr {
    message: Box<dyn Error>,
    span: Option<lrpar::Span>,
}
impl<E> From<E> for ParseErr
where
    E: Into<Box<dyn Error>>,
{
    fn from(v: E) -> Self {
        Self {
            message: v.into(),
            span: None,
        }
    }
}
impl Debug for ParseErr {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.message)
    }
}
impl Display for ParseErr {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        <Self as Debug>::fmt(&self, f)
    }
}
impl Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        <Self as Debug>::fmt(self, f)
    }
}
/// 标识符类型，使用字符串表示
pub type Ident = String;

/// 类型枚举，表示语言支持的数据类型
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Type {
    Int,    // 整数类型
    Bool,   // 布尔类型
    Never,  // 永不返回的类型（用于函数返回类型）
}
/// 表达式枚举，表示语言的表达式结构
#[derive(Debug)]
pub enum Expr {
    Or(Box<Expr>, Term),    // 逻辑或表达式
    Xor(Box<Expr>, Term),   // 逻辑异或表达式
    ETerm(Term),            // 终结表达式（直接包含Term）
}

/// 项枚举，表示表达式中的项
#[derive(Debug)]
pub enum Term {
    And(Box<Term>, BTerm),  // 逻辑与表达式
    TCTerm(BTerm),          // 终结项（直接包含BTerm）
}

/// 布尔项枚举，表示布尔表达式
#[derive(Debug)]
pub enum BTerm {
    Not(CTerm),             // 逻辑非表达式
    BCTerm(CTerm),          // 终结布尔项（直接包含CTerm）
}

/// 比较项枚举，表示比较表达式
#[derive(Debug)]
pub enum CTerm {
    GEq(Box<CTerm>, Factor),  // 大于等于比较
    LT(Box<CTerm>, Factor),   // 小于比较
    EQ(Box<CTerm>, Factor),   // 等于比较
    CTFactor(Factor),         // 终结比较项（直接包含Factor）
}

/// 因子枚举，表示加减运算
#[derive(Debug)]
pub enum Factor {
    Plus(Box<Factor>, Atom),   // 加法运算
    Minus(Box<Factor>, Atom),  // 减法运算
    FAtom(Atom),               // 终结因子（直接包含Atom）
}

/// 原子枚举，表示乘除运算
#[derive(Debug)]
pub enum Atom {
    Mult(Box<Atom>, Unit),   // 乘法运算
    Div(Box<Atom>, Unit),    // 除法运算
    AUnit(Unit),             // 终结原子（直接包含Unit）
}
/// 单元枚举，表示最基本的表达式单元
#[derive(Debug)]
pub enum Unit {
    Identifier(Ident),      // 标识符（变量名）
    True,                   // 布尔值 true
    False,                  // 布尔值 false
    Call(Ident, Args),      // 函数调用
    Grouping(Box<Expr>),    // 括号分组表达式
    Number(i64),            // 数字字面量
}

/// 参数结构体，表示函数参数（标识符 + 类型）
#[derive(Debug, PartialEq, Eq)]
pub struct Parameter(pub Ident, pub Type);

/// 参数列表结构体，包含多个参数
#[derive(Debug, PartialEq, Eq)]
pub struct Params(pub Vec<Parameter>);

/// 参数表达式列表结构体，用于函数调用
#[derive(Debug)]
pub struct Args(pub Vec<Expr>);

/// 函数体结构体，包含多个语句
#[derive(Debug)]
pub struct Body(pub Vec<Statement>);
/// 语句枚举，表示程序中的各种语句
#[derive(Debug)]
pub enum Statement {
    Def(Defs),              // 定义语句（变量或函数定义）
    Assign(Ident, Expr),    // 赋值语句
    IfElse(Expr, Body, Body), // if-else条件语句
    While(Expr, Body),      // while循环语句
    Return(Expr),           // return返回语句
}

/// 定义枚举，表示变量或函数的定义
#[derive(Debug)]
pub enum Defs {
    LocalVarDef(Ident, Type, Expr),  // 局部变量定义（标识符，类型，初始值）
    GlobalDecl(Ident, Type),         // 全局变量声明
    FunctionDef(Ident, Params, Type, Body), // 函数定义（标识符，参数，返回类型，函数体）
    FunctionDecl(Ident, Params, Type), // 函数声明（标识符，参数，返回类型）
}

/// 程序结构体，包含多个定义
#[derive(Debug)]
pub struct Program(pub Vec<Defs>);

/// 通用枚举，可以包含任何语法树节点的引用
/// 用于遍历或处理不同类型的语法节点
#[derive(Debug, Clone, Copy)]
pub enum Any<'a> {
    Ty(&'a Type),      // 类型引用
    E(&'a Expr),       // 表达式引用
    S(&'a Statement),  // 语句引用
    D(&'a Defs),       // 定义引用
    B(&'a Body),       // 函数体引用
    As(&'a Args),      // 参数列表引用
    Ps(&'a Params),    // 参数定义列表引用
    P(&'a Parameter),  // 参数引用
    A(&'a Atom),       // 原子表达式引用
    U(&'a Unit),       // 单元表达式引用
    F(&'a Factor),     // 因子表达式引用
    BT(&'a BTerm),     // 布尔项引用
    CT(&'a CTerm),     // 比较项引用
    T(&'a Term),       // 项引用
    PR(&'a Program),   // 程序引用
}

/// 将两个Result类型的值追加到向量中
/// 
/// # 参数
/// - `lhs`: 包含向量的Result
/// - `rhs`: 要追加到向量的单个值的Result
/// 
/// # 返回
/// 包含追加后向量的Result，如果任一输入出错则返回ParseErr
pub fn append<U, E>(lhs: Result<Vec<U>, E>, rhs: Result<U, E>) -> Result<Vec<U>, ParseErr>
where
    E: Into<ParseErr> + Debug + 'static,
{
    let mut lhs_: Vec<U> = lhs.map_err(|err| err.into())?;
    lhs_.push(rhs.map_err(|err| err.into())?);
    Ok(lhs_)
}
