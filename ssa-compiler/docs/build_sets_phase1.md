# 具体示例分析
## 示例1: 简单基本块处理
```
// 假设基本块0包含以下指令：
// li r1, 3
// li r2, 5  
// add r3, r1, r2

// 处理过程：
// 1. li r1, 3 → 创建立即数表达式，假设值编号：10
// 2. li r2, 5 → 创建立即数表达式，假设值编号：11
// 3. add r3, r1, r2 → 创建加法表达式，假设值编号：12

// 结果：
// exp_gen[0]: [(10, Immediate(3)), (11, Immediate(5)), (12, Plus(10, 11))]
// leaders[0]: {10: r1, 11: r2, 12: r3}
// tmp_gen[0]: {}
// phi_gen[0]: {}

```

## 示例2：包含kill指令的处理
```
// 假设基本块包含：
// load r4, [r1]  // 不支持的操作，kill r4
// add r5, r4, r2

// 处理过程：
// 1. load r4, [r1] → Err(Some(r4)) → tmp_gen.insert(r4)
// 2. add r5, r4, r2 → 由于r4被kill，表达式被过滤

// 结果：
// tmp_gen[0]: {r4}
// exp_gen[0]: 不包含add表达式
```

# 算法原理详解
## 1. 指令处理阶段
```rust
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
            tmp_gen[current].insert(killed);
        }
        _ => {}
    }
}
```

## 2. 递归传播阶段
```rust
for dom_child in block.idom_of.clone() {
    leaders[dom_child] = leaders[current].clone();  // 复制leader信息
    build_sets_phase1(cfg, dom_child, exp_gen, phi_gen, tmp_gen, leaders, table);
}
```

# 数据结构构建
## 1. 表达式生成集（exp_gen）
```rust
// 每个基本块生成的表达式列表
// 格式：LinkedList<(Value, Expression)>
exp_gen[0] = [
    (10, Immediate(3)),
    (11, Immediate(5)), 
    (12, Plus(10, 11))
]
```

## 2. 领导者集合(leaders)
```rust
// 每个基本块中值编号到寄存器的映射
// 格式：HashMap<Value, VReg>
leaders[0] = {
    10: r1,  // 值编号10对应寄存器r1
    11: r2,  // 值编号11对应寄存器r2
    12: r3   // 值编号12对应寄存器r3
}
```

## 3. 临时变量生成集(tmp_gen)
```rust
// 每个基本块中被kill的寄存器集合
// 格式：HashSet<VReg>
tmp_gen[0] = {r4}  // 寄存器r4被标记为kill
```

## 4. phi 函数生成集(phi_gen)
```rust
// 每个基本块中Phi函数相关的值编号映射
// 格式：HashMap<Value, VReg>
phi_gen[0] = {}  // 简单基本块没有Phi函数
```

# 具体场景示例
## 场景1：线性控制流
```
// 基本块0 → 基本块1 → 基本块2
// 处理过程：
// 1. 处理基本块0，构建exp_gen[0], leaders[0]
// 2. 复制leaders[0]到leaders[1]，处理基本块1
// 3. 复制leaders[1]到leaders[2]，处理基本块2
```

## 场景2: 分支控制流
```
// 基本块0 → 基本块1
//          ↘ 基本块2
// 处理过程：
// 1. 处理基本块0，构建exp_gen[0], leaders[0]
// 2. 复制leaders[0]到leaders[1]，处理基本块1
// 3. 复制leaders[0]到leaders[2]，处理基本块2
```

## 场景3：循环控制流
```
// 基本块0 → 基本块1 → 基本块2
//          ↖        ↙
// 处理过程：
// 1. 处理基本块0，构建exp_gen[0], leaders[0]
// 2. 复制leaders[0]到leaders[1]，处理基本块1
// 3. 复制leaders[1]到leaders[2]，处理基本块2
// 4. 基本块2支配基本块1，但不会重复处理
```