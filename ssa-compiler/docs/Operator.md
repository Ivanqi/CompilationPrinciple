# `Operator` 枚举及其方法分析报告

## 数据结构作用概述

`Operator` 枚举是编译器**中间表示（IR）**的核心数据结构，定义了所有支持的指令类型。该枚举及其相关方法提供了编译器后端所需的所有操作，包括算术运算、逻辑运算、内存访问、控制流等。

## 每行代码详细注释

```rust
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
```

## 指令类型详解

### 1. 算术运算指令
- **Add/Sub/Mult/Div**: 标准的四则运算
- **参数**: (结果寄存器, 源寄存器1, 源寄存器2)
- **示例**: `Add(r3, r1, r2)` 表示 `r3 = r1 + r2`

### 2. 逻辑运算指令
- **And/Or/Xor**: 按位逻辑运算
- **参数**: (结果寄存器, 源寄存器1, 源寄存器2)
- **示例**: `And(r3, r1, r2)` 表示 `r3 = r1 & r2`

### 3. 内存访问指令
- **Load**: 从内存加载数据
- **参数**: (结果寄存器, 偏移寄存器, 基址寄存器)
- **语义**: `rd = mem[base + offset]`
- **示例**: `Load(r3, r1, r2)` 表示 `r3 = mem[r2 + r1]`

- **Store**: 向内存存储数据
- **参数**: (值寄存器, 偏移寄存器, 基址寄存器)
- **语义**: `mem[base + offset] = value`
- **示例**: `Store(r3, r1, r2)` 表示 `mem[r2 + r1] = r3`

### 4. 控制流指令
- **Bgt/Bl/Beq**: 条件分支指令
- **参数**: (寄存器1, 寄存器2, 真分支标签, 假分支标签)
- **语义**: 比较两个寄存器，根据结果跳转到不同标签
- **示例**: `Bgt(r1, r2, "label1", "label2")` 表示 `if r1 > r2 goto label1 else goto label2`

- **J**: 无条件跳转指令
- **参数**: (目标标签)
- **语义**: 无条件跳转到指定标签
- **示例**: `J("label1")` 表示 `goto label1`

### 5. 立即数指令
- **Li**: 加载立即数
- **参数**: (结果寄存器, 立即数值)
- **语义**: 将立即数加载到寄存器
- **示例**: `Li(r1, 42)` 表示 `r1 = 42`

### 6. 比较指令
- **Slt**: 小于设置
- **参数**: (结果寄存器, 寄存器1, 寄存器2)
- **语义**: `rd = (rs1 < rs2) ? 1 : 0`
- **示例**: `Slt(r3, r1, r2)` 表示 `r3 = (r1 < r2) ? 1 : 0`

### 7. 函数调用指令
- **Call**: 函数调用
- **参数**: (结果寄存器, 函数标签, 参数寄存器列表)
- **语义**: 调用函数，将返回值存储到结果寄存器
- **示例**: `Call(r3, "myfunc", vec![r1, r2])` 表示 `r3 = myfunc(r1, r2)`

### 8. 栈内存指令
- **StoreLocal/LoadLocal**: 栈内存访问
- **参数**: (寄存器, 栈偏移)
- **语义**: 访问栈上的局部变量
- **示例**: `StoreLocal(r1, 0)` 表示 `stack[0] = r1`
- **示例**: `LoadLocal(r2, 4)` 表示 `r2 = stack[4]`

## 方法功能详解

### 1. `dependencies()` 方法
- **作用**: 获取指令依赖的寄存器（读取的寄存器）
- **返回**: 寄存器编号向量
- **示例**: `Add(r3, r1, r2).dependencies()` 返回 `[r1, r2]`

### 2. `dependencies_mut()` 方法
- **作用**: 获取指令依赖的寄存器的可变引用
- **返回**: 寄存器可变引用向量
- **用途**: 用于修改指令中的寄存器引用

### 3. `receiver()` 方法
- **作用**: 获取指令的结果寄存器（写入的寄存器）
- **返回**: `Option<VReg>`，有结果寄存器返回`Some(reg)`，否则返回`None`
- **示例**: `Add(r3, r1, r2).receiver()` 返回 `Some(r3)`
- **示例**: `J("label").receiver()` 返回 `None`

### 4. `receiver_mut()` 方法
- **作用**: 获取指令的结果寄存器的可变引用
- **返回**: `Option<&mut VReg>`
- **用途**: 用于修改指令的结果寄存器

### 5. `replace_reg()` 方法
- **作用**: 替换指令中的寄存器引用
- **参数**: `reg` - 要替换的原始寄存器，`with` - 替换后的新寄存器
- **示例**: `Add(r3, r1, r2).replace_reg(r1, r4)` 将指令变为 `Add(r3, r4, r2)`

## 举例说明

### 示例1：简单算术运算
```rust
// 原始代码：r3 = r1 + r2
let add_op = Operator::Add(3, 1, 2);

// 获取依赖寄存器
let deps = add_op.dependencies();  // 返回 [1, 2]

// 获取结果寄存器
let rec = add_op.receiver();       // 返回 Some(3)

// 替换寄存器引用
let mut add_op = Operator::Add(3, 1, 2);
add_op.replace_reg(1, 4);          // 变为 Add(3, 4, 2)
```

### 示例2：条件分支
```rust
// 原始代码：if r1 > r2 goto label1 else goto label2
let bgt_op = Operator::Bgt(1, 2, "label1".into(), "label2".into());

// 获取依赖寄存器
let deps = bgt_op.dependencies();  // 返回 [1, 2]

// 获取结果寄存器
let rec = bgt_op.receiver();       // 返回 None（分支指令没有结果寄存器）
```

### 示例3：内存访问
```rust
// 原始代码：r3 = mem[r2 + r1]
let load_op = Operator::Load(3, 1, 2);

// 获取依赖寄存器
let deps = load_op.dependencies();  // 返回 [1, 2]

// 获取结果寄存器
let rec = load_op.receiver();       // 返回 Some(3)

// 原始代码：mem[r2 + r1] = r3
let store_op = Operator::Store(3, 1, 2);

// 获取依赖寄存器
let deps = store_op.dependencies();  // 返回 [3, 1, 2]

// 获取结果寄存器
let rec = store_op.receiver();       // 返回 None（存储指令没有结果寄存器）
```

### 示例4：函数调用
```rust
// 原始代码：r3 = myfunc(r1, r2)
let call_op = Operator::Call(3, "myfunc".into(), vec![1, 2]);

// 获取依赖寄存器
let deps = call_op.dependencies();  // 返回 [1, 2]

// 获取结果寄存器
let rec = call_op.receiver();       // 返回 Some(3)
```

## 在编译器中的位置

`Operator` 枚举在编译器流程中的位置：

1. **前端翻译**：`translate_block()` 将AST转换为`Operator`序列
2. **中间优化**