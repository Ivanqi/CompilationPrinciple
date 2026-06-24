# 代码结构分析
```rust
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

```

# 三个选择条件详情
## 条件1:
`leaders[*pred].contains_key(val)`
作用： 确保前驱块中该值有leader（即该表达式在前驱块中是可用的）

含义: 如果前驱块中没有这个表达式的leader，说明该表达式在前驱块中不可用，不能安全提升

## 条件2： !exp.is_simple()
作用: 排除简单表达式(寄存器)

含义：is_simple() 返回true 表示表达式是 Expression::Reg(_), 即只是一个寄存器引用。我们只提升复杂的计算表达式(如加法、乘法)，不提升简单的寄存器复制

## 条件3: !new_exprs[current].contains(val_orig)
作用: 避免重复提升(在第二次运行时排除)

含义: 如果当前块已经包含了这个表达式，就不再重复提升

# 具体示例说明
## 示例1：条件分支中的部分冗余
### 原始代码
```rust
// 基本块0: x = 5, y = 10
// 基本块1: if (cond) goto 2 else goto 3
// 基本块2: z = x + y; goto 4
// 基本块3: w = x + y; goto 4
// 基本块4: result = phi(z, w)
```

### 分析过程
#### phi 翻译结果
- 从基本块2到基本块4：`x + y` → 值编号10
- 从基本块3到基本块4：`x + y` → 值编号10

#### 检查条件1
- 基本块2：`leaders[2].contains_key(10)` = true
- 基本块3：`leaders[3].contains_key(10)` = false（基本块3没有`x + y`）

#### 检查条件2
- `!exp.is_simple()` = true（`x + y`是复杂表达式，不是简单寄存器）

#### 检查条件3
- `!new_exprs[4].contains(10)` = true（基本块4还没有这个表达式）

#### 结果
- `!new_exprs[4].contains(10)` = true（基本块4还没有这个表达式）

### 优化后的代码
```rust
// 基本块0: x = 5, y = 10
// 基本块1: t = x + y; if (cond) goto 2 else goto 3
// 基本块2: z = t; goto 4
// 基本块3: w = t; goto 4
// 基本块4: result = phi(z, w)
```

## 示例2：不满足条件的表达式
### 场景: 某个表达式在前驱块中不可用
```rust
// 基本块0: x = 5
// 基本块1: if (cond) goto 2 else goto 3
// 基本块2: y = 10; z = x + y; goto 4
// 基本块3: w = x + 15; goto 4
// 基本块4: result = phi(z, w)
```

### 分析过程
#### 1. phi 翻译结果
- 从基本块2到基本块4：`x + y` → 值编号10
- 从基本块3到基本块4：`x + 15` → 值编号11

#### 检查条件1
- 基本块2：`leaders[2].contains_key(10)` = true
- 基本块3：`leaders[3].contains_key(10)` = false（基本块3没有`x + y`）

#### 结果
x + y不能被提升，因为不是所有前驱都有这个表达式

## 示例3：简单表达式被排除
### 场景: 寄存器复制操作
```rust
// 基本块0: x = 5
// 基本块1: if (cond) goto 2 else goto 3
// 基本块2: y = x; goto 4  // 寄存器复制
// 基本块3: z = x; goto 4  // 寄存器复制
// 基本块4: result = phi(y, z)
```

### 分析过程
#### 1. phi 翻译结果
- 从基本块2到基本块4：`x` → 值编号5（`Expression::Reg(x)`）
- 从基本块3到基本块4：`x` → 值编号5（`Expression::Reg(x)`）

#### 2. 检查条件2
- `!exp.is_simple()` = false（`Expression::Reg(x)`是简单表达式）

#### 3. 结果
寄存器复制操作不被提升，因为提升它不会带来性能收益

## 示例4：避免重复提升
场景: 表达式已经在当前块存在
```rust
// 基本块0: x = 5, y = 10
// 基本块1: t = x + y; if (cond) goto 2 else goto 3
// 基本块2: z = t; goto 4
// 基本块3: w = x + y; goto 4  // 重复计算
// 基本块4: result = phi(z, w)
```

第一次运行分析：
- 基本块3的`x + y`被提升到基本块1
- `new_exprs[4]`记录了这个提升

第二次运行分析：
- 条件3：`!new_exprs[4].contains(10)` = false
- 结果：不再重复提升同一个表达式

# 算法意义
## 1. 安全性保证
- __条件&#x31;__&#x786E;保表达式在前驱块中可用
- 避免在不可达路径上插入计算

## 性能优化
- __条件&#x32;__&#x53EA;提升复杂计算
- 避免无意义的寄存器复制提升

## 避免重复
- __条件&#x33;__&#x9632;止同一表达式被多次提升
- 确保算法收敛

## 部分冗余消除
- 识别跨越基本块边界的冗余计算
- 将计算提升到最早的安全位置

