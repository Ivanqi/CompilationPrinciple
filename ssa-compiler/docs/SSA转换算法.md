# 例子
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

# 阶段1： 计算支配边界和全局寄存器
```rust
let frontiers = self.get_dominance_frontiers();
let (globals, defined_in) = self.get_global_regs();
```
作用:
- 支配边界: 确定 phi 函数的插入位置
- 全局寄存器: 识别需要SSA 转换变量
- 定义位置: 记录变量在哪些块中被定义

# 阶段2：生成 phi 函数
```rust
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
示例：假设全局变量g在块2和块3中定义

## phi 函数插入过程
- 初始化队列: queue = [2, 3] (g的定义位置)
- 处理块2: 支配边界是块4 -> 在块4 插入 phi 函数
- 处理块3: 支配边界是块4 -> 在块4插入phi 函数(已存在，跳过)
- 处理块4: 支配边界是空 -> 结束

## 生成的phi函数
```
块4:
  g4 = Φ(g, g)  // 初始Phi函数，参数都是原始变量g
```

# 阶段3： 变量重命名
```rust
let mut generator = VRegGenerator::starting_at_reg(self.max_reg + 1);
let mut names: HashMap<VReg, Vec<VReg>> = HashMap::new();
self.rename_blocks(0, &globals, &mut names, &mut generator, &mut phis);
```

## 重命名过程:
### 遍历支配树
1. __块0__：g → g0
2. __块1__：g → g1
3. __块2__：g → g2
4. __块3__：g → g3
5. __块4__：更新Phi函数参数

### 重命名后的phi函数
```
块4:
  g4 = Φ(g2, g3)  // 根据来自块2或块3的不同路径选择值
```

# 阶段4: 构建SSA形式的CFG
```rust
let new_blocks: Vec<Block<SSAOperator>> = phis
    .into_iter()
    .zip(self.blocks.into_iter())
    .map(|(mut vec, mut block)| {
        let old = std::mem::take(&mut block.body);
        let mut modified = old
            .into_iter()
            .map(SSAOperator::IROp)
            .collect::<Vec<SSAOperator>>();
        vec.append(&mut modified);
        block.into_other(vec)
    })
    .collect();

```
转换结果:
- phi 函数：插入到基本快开头
- 普通指令: 转换为SSAOperator::IROp
-  控制流关系：保持不变

# 最终SSA形式
```
块0 (ENTRY): [g0 = ...]
块1: [g1 = ...]
块2: [g2 = ...]
块3: [g3 = ...]
块4: [g4 = Φ(g2, g3)] [其他指令使用g4]
```
