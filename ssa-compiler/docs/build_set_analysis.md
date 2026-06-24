# build_set 函数分析

## 函数作用概述

`build_set` 函数是复制传播优化（Copy Propagation）算法的核心部分，用于构建格值（Lattice）集合。该函数通过数据流分析确定每个寄存器是否是其他寄存器的复制，从而识别可以消除的冗余复制操作。

**主要功能**：
1. 分析SSA形式的控制流图（CFG），确定每个寄存器的复制关系
2. 使用格理论（Lattice Theory）表示寄存器值的复制状态
3. 通过工作列表算法（Worklist Algorithm）迭代计算数据流信息
4. 识别可执行的边（executable edges）以优化分支分析

## 逐行代码注释

```rust
/// 构建复制传播的格值集合
/// 返回一个向量，索引是寄存器编号，值是Lattice枚举
fn build_set(cfg: &CFG<SSAOperator>) -> Vec<Lattice> {
    // 1. 获取SSA图：寄存器 -> [(使用指令, 块索引)]
    //    这个数据结构记录了每个寄存器在哪些指令中被使用
    let ssa_graph = cfg.ssa_graph();
    
    // 2. 初始化CFG工作列表：存储(前驱块索引, 当前块索引)对
    //    从入口块开始分析，usize::MAX表示没有前驱（入口块）
    let mut cfg_worklist = vec![(usize::MAX, cfg.get_entry())];
    
    // 3. 初始化SSA工作列表：存储(指令引用, 块索引)对
    //    用于调度需要重新分析的指令
    let mut ssa_worklist: Vec<(&SSAOperator, usize)> = Vec::default();
    
    // 4. 初始化可执行边映射：记录哪些控制流边是可执行的
    //    键：(前驱块索引, 后继块索引)
    //    值：布尔值，表示该边是否可执行
    let mut executable = HashMap::new();
    
    // 5. 初始化结果数组：为每个寄存器分配初始格值
    //    初始值都是Lattice::Top（未知）
    let mut result = vec![Lattice::Top; cfg.get_max_reg() as usize];

    // 6. 主循环：当CFG工作列表或SSA工作列表非空时继续处理
    while !cfg_worklist.is_empty() || !ssa_worklist.is_empty() {
        // 7. 处理CFG工作列表：分析基本块
        if let Some((pred, child)) = cfg_worklist.pop() {
            // 获取当前要分析的基本块
            let block = cfg.get_block(child);
            
            // 8. 标记当前边为可执行，并检查之前是否已标记过
            //    past变量记录之前的状态（Some(true)表示已标记过）
            let past = executable.insert((pred, child), true);
            
            // 9. 处理块中的所有Phi函数（Phi函数在块的开头）
            let mut body = block.body.iter();
            while let Some(op @ SSAOperator::Phi(..)) = body.next() {
                // 对每个Phi函数调用visit_op进行分析
                visit_op(
                    op,                    // Phi函数指令
                    child,                 // 当前块索引
                    cfg,                   // 控制流图
                    &mut result,           // 格值结果数组
                    &mut cfg_worklist,     // CFG工作列表
                    &mut ssa_worklist,     // SSA工作列表
                    &mut executable,       // 可执行边映射
                    &ssa_graph,           // SSA图
                );
            }
            
            // 10. 如果当前边之前没有被标记为可执行（首次访问）
            //     则处理块中的所有指令（包括Phi函数之后的部分）
            if !matches!(past, Some(true)) {
                for op in block.body.iter() {
                    visit_op(
                        op,
                        child,
                        cfg,
                        &mut result,
                        &mut cfg_worklist,
                        &mut ssa_worklist,
                        &mut executable,
                        &ssa_graph,
                    );
                }
            }
        }
        
        // 11. 处理SSA工作列表：重新分析受影响的指令
        if let Some((op, block)) = ssa_worklist.pop() {
            // 检查指令是否需要重新分析的条件：
            // 条件1：指令是Phi函数
            // 条件2：指令所在块有可执行的前驱边
            if matches!(op, SSAOperator::Phi(..))
                || cfg
                    .get_block(block)
                    .preds
                    .iter()
                    .any(|pred| *executable.entry((*pred, block)).or_insert(false))
            {
                // 满足条件，重新分析该指令
                visit_op(
                    op,
                    block,
                    cfg,
                    &mut result,
                    &mut cfg_worklist,
                    &mut ssa_worklist,
                    &mut executable,
                    &ssa_graph,
                );
            }
        }
    }
    
    // 12. 返回计算完成的格值集合
    result
}
```

## 数据结构详解

### 1. Lattice（格值）枚举
```rust
enum Lattice {
    Top,           // 未知值（最不精确）
    CopyOf(VReg),  // 是某个寄存器的复制
    Bottom,        // 非复制值（最精确）
}
```

**格理论解释**：
- **Top**: 表示我们不知道这个寄存器是否是其他寄存器的复制（最不精确的信息）
- **CopyOf(r)**: 表示这个寄存器是寄存器r的复制
- **Bottom**: 表示这个寄存器不是任何其他寄存器的复制（是计算得到的新值，最精确的信息）

**偏序关系**: Bottom ≤ CopyOf(r) ≤ Top

### 2. 工作列表算法

#### CFG工作列表 (`cfg_worklist`)
- 存储 `(前驱块索引, 当前块索引)` 对
- 用于广度优先遍历控制流图
- 从入口块 `(usize::MAX, cfg.get_entry())` 开始

#### SSA工作列表 (`ssa_worklist`)
- 存储 `(&SSAOperator, 块索引)` 对
- 用于重新分析受影响的指令
- 当寄存器的格值发生变化时，使用该寄存器的所有指令会被加入此列表

### 3. 可执行边映射 (`executable`)
- 键: `(前驱块索引, 后继块索引)`
- 值: 布尔值，表示该控制流边是否可执行
- 用于优化分支分析，避免分析不可达的代码路径

## 算法流程示例

### 示例代码
考虑以下简单程序：
```
rd1 = 10        // li rd1, 10
rd2 = rd1       // mv rd2, rd1
rd3 = rd1 + rd2 // add rd3, rd1, rd2
```

### 分析步骤

#### 步骤1: 初始化
```
ssa_graph = {rd1: [(mv指令, 块0), (add指令, 块0)], ...}
cfg_worklist = [(MAX, 0)]  // 从入口块开始
result = [Top, Top, Top, Top]  // 4个寄存器
executable = {}
```

#### 步骤2: 处理入口块
- 标记边 `(MAX, 0)` 为可执行
- 处理 `li rd1, 10`:
  - rd1 标记为 Bottom（非复制值）
- 处理 `mv rd2, rd1`:
  - rd2 标记为 CopyOf(rd1)
  - 将使用 rd2 的指令加入 ssa_worklist
- 处理 `add rd3, rd1, rd2`:
  - rd3 标记为 Bottom（计算值）
  - 检查 rd1 和 rd2 的关系
  - 发现 rd2 是 rd1 的复制，可以优化

#### 步骤3: 优化结果
```
优化前: add rd3, rd1, rd2
优化后: add rd3, rd1, rd1  // 因为 rd2 = rd1
```

## 关键算法特性

### 1. 数据流分析
- **前向分析**: 从入口块开始，沿控制流方向传播信息
- **格值传播**: 使用格理论合并来自不同路径的信息
- **单调性**: 格值只能从 Top → CopyOf → Bottom 方向变化（更精确）

### 2. Phi函数处理
Phi函数的格值计算使用 `meet` 操作：
```rust
// 例如：rd3 = φ(rd1, rd2)
// 如果 rd1 = CopyOf(ra), rd2 = CopyOf(rb)
// 则 rd3 = meet(CopyOf(ra), CopyOf(rb), rd3, rd1/rd2)
```

### 3. 分支分析优化
通过 `executable` 映射识别不可达分支：
- 对于 `beq rd1, rd2, label_true, label_false`
- 如果分析发现 rd1 和 rd2 总是相等，则只有 true 分支可执行
- 如果总是不等，则只有 false 分支可执行

## 性能优化

### 1. 工作列表算法
- 避免重复分析：通过 `past` 变量检查是否首次访问
- 增量更新：只有受影响的指令才重新分析

### 2. 剪枝不可达路径
- 通过 `executable` 映射避免分析死代码
- 提高分析效率和精度

### 3. SSA图利用
- 快速找到使用某个寄存器的所有指令
- 支持高效的更新传播

## 应用场景

### 1. 复制传播优化
识别并消除冗余的复制操作：
```
优化前:
rd2 = rd1
rd3 = rd2 + 5

优化后:
rd3 = rd1 + 5  // 直接使用原始寄存器
```

### 2. 常量传播支持
与常量传播结合，可以识别更多优化机会：
```
rd1 = 10
rd2 = rd1      // rd2 也是常量10
rd3 = rd2 * 2  // 可以折叠为 rd3 = 20
```

### 3. 死代码消除
识别未被使用的复制操作：
```
rd2 = rd1      // 复制操作
...            // rd2 从未被使用
// 可以删除 rd2 = rd1
```

## 总结

`build_set` 函数实现了一个高效的数据流分析算法，用于识别寄存器间的复制关系。通过结合格理论、工作列表算法和SSA形式的优势，该算法能够：

1. **精确分析**：准确识别复制关系，避免误优化
2. **高效执行**：利用增量更新和剪枝技术减少计算量
3. **支持复杂控制流**：正确处理分支、循环和Phi函数
4. **为后续优化提供基础**：生成的格值集合直接用于复制传播优化

该算法是编译器优化流水线中的重要组成部分，能够显著提升生成代码的质量和执行效率。