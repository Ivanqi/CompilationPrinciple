# 转换前状态
```
phis[0] = []                    // 块0没有Phi函数
phis[1] = []                    // 块1没有Phi函数  
phis[2] = [g2 = Φ(g0, g1)]     // 块2有Phi函数
blocks[0].body = [g0 = ...]     // 块0的普通指令
blocks[1].body = [g1 = ...]     // 块1的普通指令
blocks[2].body = [使用g2的指令]  // 块2的普通指令
```

# 转换过程
## 处理块0
```rust
// (vec, block) = ([], 块0)
let old = std::mem::take(&mut block.body);  // old = [g0 = ...]
let mut modified = old.into_iter().map(SSAOperator::IROp).collect();  // modified = [SSAOperator::IROp(g0 = ...)]
vec.append(&mut modified);  // vec = [SSAOperator::IROp(g0 = ...)]
block.into_other(vec)  // 创建SSA形式的块0
```

## 处理块1
```rust
// (vec, block) = ([], 块1)  
let old = std::mem::take(&mut block.body);  // old = [g1 = ...]
let mut modified = old.into_iter().map(SSAOperator::IROp).collect();  // modified = [SSAOperator::IROp(g1 = ...)]
vec.append(&mut modified);  // vec = [SSAOperator::IROp(g1 = ...)]
block.into_other(vec)  // 创建SSA形式的块1
```

## 处理块2
```rust
// (vec, block) = ([g2 = Φ(g0, g1)], 块2)
let old = std::mem::take(&mut block.body);  // old = [使用g2的指令]
let mut modified = old.into_iter().map(SSAOperator::IROp).collect();  // modified = [SSAOperator::IROp(使用g2的指令)]
vec.append(&mut modified);  // vec = [g2 = Φ(g0, g1), SSAOperator::IROp(使用g2的指令)]
block.into_other(vec)  // 创建SSA形式的块2`rust

```

## 转换后结果
```
块0: [SSAOperator::IROp(g0 = ...)]
块1: [SSAOperator::IROp(g1 = ...)]  
块2: [SSAOperator::Phi(g2, [g0, g1]), SSAOperator::IROp(使用g2的指令)]
```

# 技术意义
## 指令类型统一
- __SSAOperator::IROp__：包装普通的IR指令

- __SSAOperator::Phi__：表示Phi函数

- __统一处理__：所有指令都是SSAOperator类型

## 指令顺序保证
- __Phi函数在前__：位于基本块的开头

- __普通指令在后__：位于Phi函数之后

- __正确性保证__：确保Phi函数在普通指令之前执行

## 内存管理优化
- __std::mem::take__：高效地获取block.body的所有权

- __into_iter__：消耗所有权，避免不必要的拷贝

- __append__：高效地合并两个向量
