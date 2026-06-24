# GVN-PRE 优化函数分析

## 函数作用概述

`gvn_pre::optimize` 函数实现了 **全局值编号与部分冗余消除**（Global Value Numbering with Partial Redundancy Elimination，简称GVN-PRE）算法。这是编译器优化中的一个重要技术，用于消除程序中的冗余计算。

**主要功能**：
1. **全局值编号**（Global Value Numbering）：为程序中所有计算表达式分配唯一编号，识别语义等价的表达式
2. **部分冗余消除**（Partial Redundancy Elimination）：将部分冗余的计算提升到更早的位置，使其完全冗余，然后消除
3. **代码提升**（Code Hoisting）：将公共子表达式提升到支配节点
4. **冗余消除**（Redundancy Elimination）：删除重复的计算

## 逐行代码注释

```rust
pub fn optimize(cfg: &mut CFG<SSAOperator>) {
    // 步骤1：构建四个核心数据结构
    // 1. leaders: 每个基本块中的值编号到寄存器的映射
    // 2. antileaders: 每个基本块的可用表达式集合（预期可用的表达式）
    // 3. phigen: Phi函数生成信息
    // 4. value_table: 全局值编号表
    let (mut leaders, antileaders, phigen, mut value_table) = build_sets(cfg);
    
    // 步骤2：插入阶段 - 将部分冗余计算提升到更早的位置
    // 分析控制流图，在适当的位置插入计算和Phi函数
    // 使部分冗余的计算变为完全冗余
    insert(cfg, &mut leaders, &antileaders, &phigen, &mut value_table);
    
    // 步骤3：消除阶段 - 删除冗余计算
    // 将冗余计算替换为复制指令，删除不必要的Phi函数
    eliminate(cfg, &leaders, &mut value_table);
    
    // 步骤4：调试输出（仅在启用print-cfgs特性时）
    #[cfg(feature = "print-cfgs")]
    {
        println!("After gvn-pre:\n{}", cfg.to_dot());
    }
}
```

## 算法三个阶段详解

### 阶段1：构建集合（build_sets）

#### 数据结构构建
```rust
// 构建四个核心数据结构：
let (mut leaders, antileaders, phigen, mut value_table) = build_sets(cfg);
```

1. **leaders**（领导者集合）：
   - 类型：`Vec<HashMap<Value, VReg>>`
   - 作用：记录每个基本块中值编号到实际寄存器的映射
   - 示例：`leaders[0][value_5] = rd3` 表示在基本块0中，值编号5对应寄存器rd3

2. **antileaders**（预期可用表达式集合）：
   - 类型：`Vec<LinkedList<(Value, Expression)>>`
   - 作用：记录每个基本块预期可用的表达式集合
   - 示例：`antileaders[1] = [(5, Plus(3,4)), (6, Sub(5,2))]`

3. **phigen**（Phi函数生成信息）：
   - 类型：`Vec<HashMap<Value, VReg>>`
   - 作用：记录Phi函数相关的值编号到寄存器映射
   - 用于Phi函数翻译（Phi Translation）

4. **value_table**（全局值编号表）：
   - 类型：`ValueTable`
   - 作用：管理表达式到值编号的全局映射
   - 确保语义等价的表达式获得相同的值编号

#### 构建过程
```rust
// build_sets函数内部流程：
fn build_sets(cfg: &mut CFG<SSAOperator>) -> (LeaderSet, AntileaderSet, PhiGen, ValueTable) {
    // 1. 生成全局值编号表
    let mut value_table = generate_value_table(cfg);
    
    // 2. 初始化数据结构
    let mut exp_gen = vec![LinkedList::default(); cfg.len()]; // 表达式生成集合
    let mut tmp_gen = vec![HashSet::default(); cfg.len()];    // 临时变量kill集合
    let mut phi_gen = vec![HashMap::default(); cfg.len()];    // Phi函数生成集合
    let mut leaders = vec![HashMap::default(); cfg.len()];    // 领导者集合
    
    // 3. 第一遍构建集合（支配树遍历）
    build_sets_phase1(cfg, cfg.get_entry(), &mut exp_gen, &mut phi_gen, 
                      &mut tmp_gen, &mut leaders, &mut value_table);
    
    // 4. 第二遍构建集合（迭代计算可用表达式）
    let mut changed = true;
    let mut antic_out = vec![LinkedList::default(); cfg.len()];
    let mut antic_in = vec![LinkedList::default(); cfg.len()];
    
    while changed {
        changed = false;
        build_sets_phase2(cfg, cfg.get_entry(), &mut changed, &mut antic_out,
                         &mut antic_in, &exp_gen, &tmp_gen, &phi_gen, &mut value_table);
    }
    
    // 5. 返回构建的四个集合
    (leaders, antic_in, phi_gen, value_table)
}
```

### 阶段2：插入阶段（insert）

#### 插入算法目标
将部分冗余的计算提升到更早的位置，使其变为完全冗余，然后可以消除。

#### 插入过程
```rust
fn insert(
    cfg: &mut CFG<SSAOperator>,
    leaders: &mut LeaderSet,
    antileaders: &AntileaderSet,
    phi_gen: &PhiGen,
    value_table: &mut ValueTable,
) {
    // 1. 初始化工作列表和寄存器生成器
    let mut changed = true;
    let mut gen = VRegGenerator::starting_at_reg(cfg.get_max_reg());
    let mut new_exprs = vec![HashSet::default(); cfg.len()];
    
    // 2. 迭代直到没有变化
    while changed {
        changed = false;
        insert_recurse(
            cfg, cfg.get_entry(), leaders, antileaders, phi_gen,
            value_table, &mut changed, &mut gen, &mut new_exprs,
        );
    }
    
    // 3. 更新最大寄存器编号
    cfg.set_max_reg(gen.next_reg());
}
```

#### 插入递归核心逻辑
```rust
fn insert_recurse(
    cfg: &mut CFG<SSAOperator>,
    current: usize,
    leaders: &mut LeaderSet,
    antileaders: &AntileaderSet,
    phi_gen: &PhiGen,
    value_table: &mut ValueTable,
    changed: &mut bool,
    gen: &mut VRegGenerator,
    new_exprs: &mut Vec<HashSet<Value>>,
) {
    let block = cfg.get_block(current);
    
    // 只处理控制流合并点（有多个前驱的基本块）
    if block.preds.len() > 1 {
        let antic = &antileaders[current];
        
        // 1. 对前驱进行Phi翻译
        let translated_preds = block.preds.iter().map(|&pred| {
            (pred, phi_translate(&phi_gen[current], antic, block, pred, value_table))
        }).collect::<Vec<_>>();
        
        // 2. 找出需要提升的表达式
        let to_hoist = translated_preds.iter()
            .flat_map(|(pred, expr)| {
                expr.iter().zip(antic).enumerate().filter_map(|(i, ((val, exp), (val_orig, _)))| {
                    // 条件1：前驱块中该值有leader
                    // 条件2：不是简单表达式（不是寄存器）
                    // 条件3：当前块还没有这个表达式
                    if leaders[*pred].contains_key(val) && !exp.is_simple() 
                       && !new_exprs[current].contains(val_orig) {
                        Some(i)
                    } else {
                        None
                    }
                })
            })
            .collect::<HashSet<_>>();
        
        // 3. 在前驱块插入计算
        for (pred, exprs) in translated_preds.into_iter() {
            for (k, (val, exp)) in exprs.into_iter().enumerate() {
                if !to_hoist.contains(&k) { continue; }
                
                let leaders = &mut leaders[pred];
                if !leaders.contains_key(&val) {
                    // 生成新寄存器并插入计算指令
                    let new_reg = gen.next_reg();
                    let new_op = exp.to_instruction(leaders, new_reg);
                    
                    // 保存分支指令，插入新计算，再恢复分支
                    let branch = cfg.get_block_mut(pred).body.pop();
                    cfg.get_block_mut(pred).body.push(new_op);
                    branch.and_then(|branch| {
                        cfg.get_block_mut(pred).body.push(branch);
                        Option::<()>::None
                    });
                    
                    leaders.insert(val, new_reg);
                    new_exprs[pred].insert(val);
                    *changed = true;
                }
            }
        }
        
        // 4. 在当前块插入Phi函数
        let mut new_body: Vec<SSAOperator> = to_hoist.iter()
            .map(|_| SSAOperator::Phi(gen.next_reg(), vec![]))
            .collect();
        
        // 5. 更新值编号和leader信息
        // ...（详细实现略）
        
        // 6. 更新块体
        let block = cfg.get_block_mut(current);
        let mut old_body = std::mem::take(&mut block.body);
        new_body.append(&mut old_body);
        block.body = new_body;
    }
    
    // 7. 递归处理支配子节点
    for idom_child in cfg.get_block(current).idom_of.clone() {
        // 传播新表达式信息到支配子节点
        insert_recurse(cfg, idom_child, leaders, antileaders, phi_gen,
                      value_table, changed, gen, new_exprs);
    }
}
```

### 阶段3：消除阶段（eliminate）

#### 消除算法目标
将冗余计算替换为复制指令，并删除不必要的Phi函数。

#### 消除过程
```rust
fn eliminate(cfg: &mut CFG<SSAOperator>, leaders: &LeaderSet, value_table: &mut ValueTable) {
    for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate() {
        // 1. 初始化当前块的领导者映射
        let mut leaders_in = block.idom.map(|idom| leaders[idom].clone())
            .unwrap_or_else(HashMap::new);
        
        // 2. 保存原始指令体
        let mut body_old = vec![];
        std::mem::swap(&mut body_old, &mut block.body);
        
        // 3. 处理每条指令，过滤和替换冗余计算
        block.body = body_old.into_iter().filter_map(|op| {
            // 检查指令是否有冗余计算
            if let Some(receiver) = op.receiver() {
                // 检查寄存器是否有领导者（即是否有相同的值编号）
                if let Some(&leader) = leaders_in.get(&value_table.maybe_insert(
                    Expression::Reg(receiver))) {
                    // 如果领导者不是自己，说明有冗余计算
                    if leader != receiver {
                        // 用复制指令替换原始计算指令
                        return Some(SSAOperator::IROp(Operator::Mv(receiver, leader)));
                    }
                }
            }
            // 保留必要的指令
            Some(op)
        }).collect();
    }
}
```

## 算法示例

### 示例程序
考虑以下简单程序：
```c
// 原始代码
x = a + b;
y = a + b;  // 冗余计算
z = x + y;
```

### GVN-PRE优化过程

#### 步骤1：全局值编号
```
表达式        值编号
a + b        #1
x            #2 (映射到#1)
y            #3 (映射到#1) - 识别为冗余
x + y        #4
```

#### 步骤2：插入阶段
- 识别 `y = a + b` 是冗余计算
- 将计算提升到合适位置
- 插入Phi函数处理控制流合并

#### 步骤3：消除阶段
```
优化前：
x = a + b;    // 计算#1
y = a + b;    // 冗余计算#1
z = x + y;    // 计算#4

优化后：
x = a + b;    // 计算#1
y = x;        // 复制指令（替换冗余计算）
z = x + x;    // 简化后的计算
```

## 关键算法特性

### 1. 全局值编号（GVN）
- **语义等价识别**：为语义等价的表达式分配相同的值编号
- **规范化处理**：处理交换律（如 `a+b` 和 `b+a` 获得相同编号）
- **值编号表**：全局管理表达式到值编号的映射

### 2. 部分冗余消除（PRE）
- **部分冗余**：表达式在某些路径上冗余，但在其他路径上不冗余
- **代码提升**：将计算提升到支配节点，使其完全冗余
- **Phi函数插入**：在控制流合并点插入Phi函数

### 3. 支配树遍历
- **支配关系**：利用支配树结构进行高效的数据流分析
- **递归处理**：从入口块开始，递归处理支配子节点
- **信息传播**：领导者信息从支配者传播到被支配者

### 4. 工作列表算法
- **迭代收敛**：使用工作列表算法直到没有变化
- **增量更新**：只有受影响的表达式才重新分析
- **高效性**：避免重复分析

## 性能优化效果

### 优化前代码
```assembly
add rd1, rd2, rd3    # 计算 a + b
mv  rd4, rd1         # x = a + b
add rd5, rd2, rd3    # 冗余计算 a + b (再次计算)
mv  rd6, rd5         # y = a + b
add rd7, rd4, rd6    # z = x + y
```

### 优化后代码
```assembly
add rd1, rd2, rd3    # 计算 a + b
mv  rd4, rd1         # x = a + b
mv  rd6, rd4         # y = x (复制，消除冗余计算)
add rd7, rd4, rd4    # z = x + x (简化计算)
```

**优化效果**：
1. **消除冗余计算**：减少一次 `a + b` 计算
2. **减少指令数**：从5条指令减少到4条指令
3. **减少寄存器使用**：减少临时寄存器需求
4. **提高执行效率**：减少计算开销

## 应用场景

### 1. 循环优化
```c
// 循环中的冗余计算
for (int i = 0; i < n; i++) {
    result = a * b + c;  // a*b 在循环中不变，但每次重新计算
}
```

**GVN-PRE优化**：
- 识别 `a * b` 是循环不变表达式
- 将计算提升到循环外
- 消除循环内的冗余计算

### 2. 条件分支优化
```c
if (condition) {
    x = a + b;
} else {
    y = a + b;  // 与then分支相同的计算
}
z = x + y;
```

**GVN-PRE优化**：
- 识别两个分支中的 `a + b` 是相同计算
- 将计算提升到分支前
- 在两个分支中使用相同的结果

### 3. 公共子表达式消除
```c
x = (a + b) * c;
y = (a + b) * d;  // a+b 是公共子表达式
```

**GVN-PRE优化**：
- 识别 `a + b` 是公共子表达式
- 计算一次，多次使用
- 消除冗余计算

## 总结

`gvn_pre::optimize` 函数实现了一个强大的编译器优化算法，结合了全局值编号和部分冗余消除技术。该算法能够：

1. **精确识别冗余**：通过全局值编号准确识别语义等价的表达式
2. **智能代码提升**：将部分冗余计算提升到合适位置，使其完全冗余
3. **高效消除冗余**：删除不必要的计算，用复制指令替换
4. **处理复杂控制流**：正确处理分支、循环和Phi函数
5. **显著提升性能**：减少计算指令，提高代码执行效率

该算法是现代编译器优化流水线中的重要组成部分，对于生成高效的目标代码至关重要。