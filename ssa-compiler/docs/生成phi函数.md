# phi 函数
```rust
// 阶段2：生成Phi函数
for &global in globals.iter() {
    let mut queue: Vec<_> = defined_in[&global].clone();
    while let Some(next) = queue.pop() {
        for &succ in &frontiers[next] {
            let entry = SSAOperator::Phi(global, vec![global; self.blocks[succ].preds.len()]);
            if !phis[succ].contains(&entry) {
                phis[succ].push(entry);
                queue.push(succ);
            }
        }
    }
}

```

# 例子分析
## 控制流图
```
块0 (ENTRY) → 块1
块1 → 块2, 块3
块2 → 块4
块3 → 块4
块4 → EXIT

```

## 支配边界
```
frontier[0] = {}      // 入口块没有支配边界
frontier[1] = {4}     // 块1的支配边界是块4
frontier[2] = {4}     // 块2的支配边界是块4  
frontier[3] = {4}     // 块3的支配边界是块4
frontier[4] = {}      // 块4没有支配边界

```

## 全局变量分析
假设全局变量 g 在 块 2 和 块 3 中定义

```
globals = [g]
defined_in = {
    g: [2, 3]  // g在块2和块3中定义
}
```

# phi 函数生成过程
## 步骤1：处理全局变量 g
```rust
for &global in globals.iter() {  // global = g
    let mut queue: Vec<_> = defined_in[&global].clone();  // queue = [2, 3]
```

## 步骤2：处理队列中的块2
```rust
while let Some(next) = queue.pop() {  // next = 2
    for &succ in &frontiers[2] {  // frontiers[2] = [4]
        let entry = SSAOperator::Phi(g, vec![g; self.blocks[4].preds.len()]);
        // 创建Phi函数：g4 = Φ(g, g, g)  // 块4有3个前驱
        if !phis[4].contains(&entry) {
            phis[4].push(entry);  // 在块4插入Phi函数
            queue.push(4);        // 继续传播
        }
    }
}
```

## 步骤3：处理队列中的块3
```rust
while let Some(next) = queue.pop() {  // next = 3
    for &succ in &frontiers[3] {  // frontiers[3] = [4]
        let entry = SSAOperator::Phi(g, vec![g; self.blocks[4].preds.len()]);
        // 创建Phi函数：g4 = Φ(g, g, g)  // 块4有3个前驱
        if !phis[4].contains(&entry) {
            // Phi函数已存在，跳过
        }
    }
}
```

## 步骤4：处理队列中的块4
```rust
while let Some(next) = queue.pop() {  // next = 4
    for &succ in &frontiers[4] {  // frontiers[4] = []
        // 没有支配边界，结束
    }
}
```

# 最终生成的 phi 函数
## 在块4中插入的phi函数
```
块4:
  g4 = Φ(g, g, g)  // 初始Phi函数，参数都是原始变量g
```

### 在示例中的应用
- __块1__：支配块2和块3，但不支配块4 → 块4在块1的支配边界中
- __块2__：支配自己，但不支配块4 → 块4在块2的支配边界中
- __块3__：支配自己，但不支配块4 → 块4在块3的支配边界中
- __块4__：没有支配边界
