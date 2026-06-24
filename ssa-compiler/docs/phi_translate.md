# 具体示例分析
## 示例1：简单phi 函数翻译
```rust
// 控制流：
// 基本块0 → 基本块1
// 基本块2 → 基本块1
// 基本块1包含：r3 = phi(r1, r2)

// 假设：
// antic_in[1]: [(10, Expression::Reg(r3))]
// phi_gen[1]: {10: r3}  // 值编号10对应寄存器r3

// 从基本块0翻译到基本块1：
// self_index = 0 (基本块0在基本块1的前驱列表中的位置)
// 找到Phi函数：r3 = phi(r1, r2)
// translated_reg = r1 (对应前驱0的值)
// translated_val = 11 (假设新值编号)
// 结果：[(11, Expression::Reg(r1))]

// 从基本块2翻译到基本块1：
// self_index = 1 (基本块2在基本块1的前驱列表中的位置)
// translated_reg = r2 (对应前驱1的值)
// translated_val = 12 (假设新值编号)
// 结果：[(12, Expression::Reg(r2))]

```

## 示例2： 复杂表达式翻译
```rust
// 控制流：
// 基本块0 → 基本块1
// 基本块1包含：r3 = phi(r1, r2)

// 假设：
// antic_in[1]: [(13, Expression::Plus(10, 11))]  // r3 + 5
// phi_gen[1]: {10: r3}  // 值编号10对应寄存器r3

// 翻译过程：
// 1. 识别到值编号10需要翻译
// 2. 找到Phi函数：r3 = phi(r1, r2)
// 3. 从基本块0翻译：translated_reg = r1
// 4. 创建新表达式：Plus(14, 11)  // 假设r1的值编号是14
// 5. 结果：[(15, Expression::Plus(14, 11))]

```

## 示例3：递归翻译操作数
```rust
// 控制流：
// 基本块0 → 基本块1
// 基本块1包含：r3 = phi(r1, r2), r4 = phi(r5, r6)

// 假设：
// antic_in[1]: [(16, Expression::Plus(10, 12))]  // r3 + r4
// phi_gen[1]: {10: r3, 12: r4}

// 翻译过程：
// 1. 识别到值编号10和12都需要翻译
// 2. 翻译r3: r1 → 值编号17
// 3. 翻译r4: r5 → 值编号18
// 4. 创建新表达式：Plus(17, 18)
// 5. 结果：[(19, Expression::Plus(17, 18))]

```

# 算法原理详解
## 1. phi 函数识别
```rust
if let Some(&reg) = phi_gen.get(val) {
    // 值编号对应Phi函数，需要翻译
    // phi_gen存储值编号到Phi函数结果寄存器的映射
}
```

## 2. 前驱位置计算
```rust
let self_index = child_block
    .preds
    .iter()
    .position(|&blk| blk == current)
    .unwrap();
// 计算当前基本块在子节点前驱列表中的位置
// 用于确定Phi函数中对应的操作数

```

## 3. Phi函数查找
```rust
let mut iter = child_block.body.iter();
while let Some(SSAOperator::Phi(rec, vec)) = iter.next() {
    if *rec == reg {
        let translated_reg = vec[self_index];
        // 找到对应的Phi函数，获取当前前驱对应的操作数
    }
}
```

## 4. 递归翻译操作数
```rust
macro_rules! maybe_translate {
    ($t:path, $($x:expr),+) => {
        $t($(if let Some(new) = translated.get($x) {*new} else {*$x}),+)
    }
}
// 如果操作数已经被翻译，使用翻译后的值编号
// 否则使用原始值编号

```

# 具体场景示例
## 场景1： 循环不变式外提
```rust
// 原始代码：
// 基本块0: i = 0
// 基本块1: while (i < n) { a = x + y; i++ }

// SSA形式：
// 基本块1: i1 = phi(i0, i2), a = x + y

// Phi翻译：
// 从基本块0到基本块1：x+y保持不变
// 从基本块1到基本块1：x+y保持不变
// 结果：x+y可以在循环外计算
```

## 场景2：条件分支合并
```rust
// 原始代码：
// 基本块0: if (cond) goto 1 else goto 2
// 基本块1: a = x + y; goto 3
// 基本块2: b = x + y; goto 3
// 基本块3: c = phi(a, b)

// Phi翻译：
// 从基本块1到基本块3：x+y → 值编号10
// 从基本块2到基本块3：x+y → 值编号10
// 结果：x+y可以在基本块0计算

```

## 场景3：复杂表达式传播
```rust
// 原始代码：
// 基本块0: p = q + r
//
```