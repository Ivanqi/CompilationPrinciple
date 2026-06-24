# 概述
leaders 变量是 GVN-PRE 算法中领导者映射表，用于记录每个基本块中值编号到寄存器的映射关系

# 代码
```rust
type LeaderSet = Vec<HashMap<Value, VReg>>;
// leaders[current] = HashMap<值编号, 寄存器>
```
- 索引: 基本块索引
- 键: 值编号(Value)
- 值: 存储该值编号结果的寄存器(VReg)

# 核心作用
## 值编号到寄存器的映射
记录那个寄存器存储了特定值编号的结果

支持后续的表达式重用和优化

## 支配关系传播
领导者信息从支配者传播到被支配者

确保公共表达式在支配路径上的一致性

## 冗余消除基础
为后续的冗余计算消除提供映射关系

支持复制传播优化

# 具体示例分析
## 示例1：简单表达式
```
// 基本块0
li rd1, 3        // 值编号10 → 寄存器1
li rd2, 5        // 值编号11 → 寄存器2
add rd3, rd1, rd2 // 值编号12 → 寄存器3
```

leaders[0] 内容:
```
{
    10: 1,  // 值编号10映射到寄存器1
    11: 2,  // 值编号11映射到寄存器2  
    12: 3,  // 值编号12映射到寄存器3
}
```
## 示例2：支配关系传播
```
基本块0 (支配基本块1)
├─ 基本块1
└─ 基本块2
```

传播过程:
```rust
// 在build_sets_phase1中
for dom_child in block.idom_of.clone() {
    leaders[dom_child] = leaders[current].clone();  // 复制领导者映射
    build_sets_phase1(cfg, dom_child, ...);
}
```
结果:
- 基本块1继承基本块0的所有领导者映射
- 确保被支配块能访问支配块中的表达式结果

## 示例3：表达式重用
```
// 基本块0
li rd1, 3        // 值编号10
li rd2, 5        // 值编号11
add rd3, rd1, rd2 // 值编号12

// 基本块1（被基本块0支配）
add rd4, rd1, rd2 // 相同的表达式，值编号12
```
优化过程:
- 基本块0的leaders[0]包含{12: 3}
- 基本块1继承这个映射
- 发现`add rd4, rd1, rd2`与值编号12对应
- 用`mv rd4, rd3`替换`add rd4, rd1, rd2`

## 示例4：phi 函数处理
```rust
match table.maybe_insert_op(op, ...) {
    Ok((val, Some(reg), exp)) => {
        leaders[current].entry(val).or_insert(reg);
        if let Expression::Phi(_) = exp {
            phi_gen[current].entry(val).or_insert(reg);
        }
    }
    // ...
}
```
处理逻辑:
- 普通表达式：`leaders[current].entry(val).or_insert(reg)`
- Phi函数：额外记录到`phi_gen`中

# 算法流程中的角色
## 阶段1：构建集合
```rust
// 处理指令，建立领导者映射
for op in &block.body {
    match table.maybe_insert_op(op, ...) {
        Ok((val, Some(reg), exp)) => {
            leaders[current].entry(val).or_insert(reg);  // 关键行
            // ...
        }
        // ...
    }
}
```

## 阶段2：插入优化
```rust
// 使用领导者映射进行冗余消除
if leaders[*pred].contains_key(val) && !exp.is_simple() {
    // 可以重用前驱块中的计算结果
    let leader_reg = leaders[*pred].get(&val).unwrap();
    // 生成复制指令而不是重新计算
}
```

## 阶段3：消除阶段
```rust
// 使用领导者映射替换冗余计算
if let Some(&leader) = leaders_in.get(&value_table.maybe_insert(Expression::Reg($reg))) {
    if leader != $reg {
        return Some(SSAOperator::IROp(Operator::Mv($reg, leader)));  // 复制传播
    }
}
```

# 实际应用场景
## 场景1：循环不变式外提
原始循环:
```c
while (i < n) {
    x = a + b;  // a+b是循环不变式
    // ...
}
```
优化后:
```c
temp = a + b;  // 提到循环外
while (i < n) {
    x = temp;   // 使用领导者映射
    // ...
}
```
领导者映射:
- 循环外：{值编号(a+b): temp}
- 循环内：继承这个映射，用`mv x, temp`替换`add x, a, b`

## 场景2: 公共字表达式消除
```
x = a + b;
y = a + b;  // 公共子表达式
z = x * y;
```
优化过程:
- 第一个`a+b`：值编号10 → 寄存器x
- `leaders`记录：`{10: x}`
- 第二个`a+b`：发现值编号10已有领导者x
- 用mv y, x替换add y, a, b

## 场景3；条件分支合并
```rust
if (cond) {
    x = a + b;
} else {
    y = a + b;
}
z = x + y;
```
优化后:
```rust
temp = a + b;  // 提到分支前
if (cond) {
    x = temp;
} else {
    y = temp;
}
z = x + y;
```
领导者映射传播:
- 分支前: `{值编号(a+b): temp}`
- 两个分支: 继承这个映射
- 分支内: 用复制指令替换计算指令

# 总结
leaders 变量的核心作用：
- 映射维护：建立值编号到寄存器的双向映射
- 信息传播：通过支配树传播领导者信息
- 优化支持: 为冗余消除、复制传播提供基础
- 一致性保证: 确保相同表达式使用相同寄存器
