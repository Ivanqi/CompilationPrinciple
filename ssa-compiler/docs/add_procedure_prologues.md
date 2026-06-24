# `add_procedure_prologues` 函数分析报告

## 函数作用概述

`add_procedure_prologues` 函数是**过程序言/尾声生成**（Procedure Prologue/Epilogue Generation）的核心实现。该函数的主要作用是在函数调用点插入**调用者保存**（Caller-Saved）寄存器的保存/恢复代码，并在函数入口/出口插入**被调用者保存**（Callee-Saved）寄存器的保存/恢复代码，以遵守RISC-V ABI（应用程序二进制接口）规范。

具体来说，`add_procedure_prologues` 函数的主要作用是：
1. **调用者保存寄存器处理**：在函数调用点保存和恢复调用者保存寄存器
2. **被调用者保存寄存器处理**：在函数入口和出口保存和恢复被调用者保存寄存器
3. **栈帧管理**：管理栈偏移量，确保正确的栈空间分配
4. **ABI合规性**：确保生成的代码符合RISC-V ABI规范

## 每行代码详细注释

```rust
/// `add_procedure_prologues` 函数：为函数调用添加序言和尾声代码
/// 
/// 参数：
/// - cfg: &mut CFG<Operator> - 控制流图的可变引用
/// - allocs: &HashMap<VReg, RV64Reg> - 虚拟寄存器到物理寄存器的分配映射
/// 
/// 功能：根据RISC-V ABI规范，在函数调用点插入调用者保存寄存器的保存/恢复代码，
///       在函数入口/出口插入被调用者保存寄存器的保存/恢复代码
/// 
/// 约束：调用点必须被隔离（不包括溢出寄存器）
/// 注释：callsites must be isolated (excluding spills);
fn add_procedure_prologues(cfg: &mut CFG<Operator>, allocs: &HashMap<VReg, RV64Reg>) {
    // 步骤1：获取当前已分配的栈帧偏移量（Activation Record Size）
    // ar 表示当前栈帧中已分配的8字节槽位数量
    let ar = *cfg.get_allocated_ars_mut();
    
    // 步骤2：初始化最大栈偏移量，用于跟踪整个函数中需要的最大栈空间
    let mut ar_max = ar;
    
    // 步骤3：计算每个基本块的活跃出集合（live-out）
    // live_out[i] 表示基本块i出口处活跃的寄存器集合
    let live_out = cfg.live_out();
    
    // 步骤4：获取所有被调用者保存寄存器（Callee-Saved Registers）
    // 这些寄存器在函数调用前后必须保持值不变
    let callee_saved = allocs.values().filter(|reg| reg.callee_saved());

    // 步骤5：遍历所有基本块，处理包含函数调用的基本块
    for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate() {
        // 步骤5.1：检查当前基本块是否包含函数调用指令
        if block.body.iter().any(|op| matches!(op, Operator::Call(..))) {
            // 步骤5.2：初始化当前调用点的栈偏移量
            let mut ar_ = ar;
            
            // 步骤5.3：验证调用点被隔离（只有一个前驱）
            // 这是函数的前提条件，确保调用点分析的正确性
            debug_assert_eq!(block.preds.len(), 1);
            
            // 步骤5.4：计算需要保存的寄存器集合
            // 规则：寄存器在调用点活跃，且不是被调用者保存寄存器
            let to_save: Vec<_> = live_out[i]
                .intersection(&live_out[block.preds[0]])  // 在调用点和前驱块都活跃
                .filter(|reg| !allocs[reg].callee_saved()) // 不是被调用者保存寄存器
                .collect();
            
            // 步骤5.5：生成序言代码（调用前保存寄存器）
            let mut prologue: Vec<_> = to_save
                .iter()
                .map(|&&reg| {
                    // 为每个需要保存的寄存器生成存储指令
                    let res = Operator::StoreLocal(reg, ar_);
                    ar_ += 1;  // 递增栈偏移量
                    res
                })
                .collect();
            
            // 步骤5.6：重置栈偏移量，用于尾声代码
            let mut ar_ = ar;
            
            // 步骤5.7：生成尾声代码（调用后恢复寄存器）
            let mut epilogue: Vec<_> = to_save
                .iter()
                .map(|&&reg| {
                    // 为每个需要恢复的寄存器生成加载指令
                    let res = Operator::LoadLocal(reg, ar_);
                    ar_ += 1;  // 递增栈偏移量
                    res
                })
                .collect();
            
            // 步骤5.8：构建新的指令序列
            // 顺序：序言代码 + 原始指令 + 尾声代码
            prologue.append(&mut block.body);
            
            // 步骤5.9：保存并移除跳转指令（如果有的话）
            let jump = prologue.pop();
            
            // 步骤5.10：将尾声代码添加到序言之后
            prologue.append(&mut epilogue);
            
            // 步骤5.11：恢复跳转指令（放在尾声代码之后）
            if let Some(op) = jump {
                prologue.push(op)
            }
            
            // 步骤5.12：用新的指令序列替换原始指令序列
            block.body = prologue;
            
            // 步骤5.13：更新最大栈偏移量
            ar_max = std::cmp::max(ar_max, ar_);
        }
    }

    // 步骤6：设置当前栈偏移量为最大值
    let mut ar = ar_max;
    *cfg.get_allocated_ars_mut() = ar_max;

    // 步骤7：处理被调用者保存寄存器（Callee-Saved Registers）
    for &saved in callee_saved {
        // 步骤7.1：在函数入口保存被调用者保存寄存器
        cfg.get_block_mut(cfg.get_entry())
            .body
            .insert(0, Operator::StoreLocal(usize::from(saved) as VReg, ar));
        
        // 步骤7.2：在函数出口恢复被调用者保存寄存器
        cfg.get_block_mut(cfg.get_exit())
            .body
            .push(Operator::LoadLocal(usize::from(saved) as VReg, ar));
        
        // 步骤7.3：递增栈偏移量
        ar += 1;
    }
    
    // 步骤8：更新最终的栈帧大小
    *cfg.get_allocated_ars_mut() = ar;
}
```

## 算法流程详解

### 步骤1：栈帧管理
1. **当前栈偏移**：`ar = *cfg.get_allocated_ars_mut()`
   - 表示当前已分配的栈槽位数量
   - 每个槽位8字节（RISC-V标准）
   - 用于局部变量和溢出寄存器

2. **最大栈偏移**：`ar_max = ar`
   - 跟踪整个函数中需要的最大栈空间
   - 确保为所有保存操作分配足够的栈空间

### 步骤2：活跃变量分析
- **活跃出集合**：`live_out = cfg.live_out()`
- **作用**：确定哪些寄存器在基本块出口处仍然活跃
- **应用**：只保存活跃的寄存器，避免不必要的保存/恢复

### 步骤3：寄存器分类

#### 调用者保存寄存器（Caller-Saved Registers）
- **定义**：调用者负责保存和恢复的寄存器
- **RISC-V示例**：`x5-x7`, `x10-x17`, `x28-x31`
- **处理位置**：在函数调用点前后

#### 被调用者保存寄存器（Callee-Saved Registers）
- **定义**：被调用函数负责保存和恢复的寄存器
- **RISC-V示例**：`x8-x9`, `x18-x27`
- **处理位置**：在函数入口和出口

### 步骤4：调用点处理逻辑

#### 条件判断
```rust
if block.body.iter().any(|op| matches!(op, Operator::Call(..))) {
    // 处理包含函数调用的基本块
}
```

#### 寄存器保存规则
```rust
let to_save: Vec<_> = live_out[i]
    .intersection(&live_out[block.preds[0]])  // 规则1：在调用点和前驱块都活跃
    .filter(|reg| !allocs[reg].callee_saved()) // 规则2：不是被调用者保存寄存器
    .collect();
```

**规则解释**：
1. **活跃性要求**：寄存器必须在调用点和前驱块都活跃
   - 如果寄存器只在调用点活跃，不需要保存（调用会覆盖）
   - 如果寄存器只在前驱块活跃，不需要保存（调用后不再使用）

2. **寄存器类型**：只保存调用者保存寄存器
   - 被调用者保存寄存器由被调用函数负责保存

#### 指令序列构建
```
原始序列：        [指令1, 指令2, Call指令, 指令3, 跳转指令]
构建后序列：      [保存1, 保存2, 指令1, 指令2, Call指令, 指令3, 恢复1, 恢复2, 跳转指令]
```

### 步骤5：栈偏移管理

#### 局部偏移量
```rust
let mut ar_ = ar;  // 每个调用点有自己的偏移量计数器
```

#### 偏移量递增
```rust
let res = Operator::StoreLocal(reg, ar_);
ar_ += 1;  // 每个保存操作占用一个栈槽位
```

#### 最大偏移量跟踪
```rust
ar_max = std::cmp::max(ar_max, ar_);
```

### 步骤6：被调用者保存寄存器处理

#### 函数入口保存
```rust
cfg.get_block_mut(cfg.get_entry())
    .body
    .insert(0, Operator::StoreLocal(usize::from(saved) as VReg, ar));
```

#### 函数出口恢复
```rust
cfg.get_block_mut(cfg.get_exit())
    .body
    .push(Operator::LoadLocal(usize::from(saved) as VReg, ar));
```

#### 栈偏移递增
```rust
ar += 1;  // 每个被调用者保存寄存器占用一个栈槽位
```

## 举例说明

### 示例1：简单函数调用

```rust
// 原始控制流图（包含函数调用）
基本块0:                 // 前驱块
  Add(r1, r2, r3)       // r1, r2, r3 活跃
  J("call_block")

基本块1:                 // 调用块（包含Call指令）
  Call(r4, "func", [r1]) // 调用函数func，参数r1，结果存到r4
  J("exit")

基本块2:                 // 退出块
  Return(r4)

// 寄存器分配：
// r1 -> x10 (调用者保存寄存器)
// r2 -> x11 (调用者保存寄存器)
// r3 -> x12 (调用者保存寄存器)
// r4 -> x10 (调用者保存寄存器)

// 活跃变量分析：
// live_out[0] = {r1, r2, r3}
// live_out[1] = {r4}
// 交集：{r1, r2, r3} ∩ {r1, r2, r3} = {r1, r2, r3}

// 调用者保存寄存器检查：
// x10, x11, x12 都是调用者保存寄存器 → 都需要保存

// 调用 add_procedure_prologues 后：
基本块0:                 // 前驱块（不变）
  Add(r1, r2, r3)
  J("call_block")

基本块1:                 // 调用块（添加序言/尾声）
  StoreLocal(r1, 0)      // 序言：保存r1到栈偏移0
  StoreLocal(r2, 1)      // 序言：保存r2到栈偏移1
  StoreLocal(r3, 2)      // 序言：保存r3到栈偏移2
  Call(r4, "func", [r1]) // 原始Call指令
  LoadLocal(r1, 0)       // 尾声：恢复r1
  LoadLocal(r2, 1)       // 尾声：恢复r2
  LoadLocal(r3, 2)       // 尾声：恢复r3
  J("exit")              // 跳转指令

基本块2:                 // 退出块（不变）
  Return(r4)
```

### 示例2：被调用者保存寄存器

```rust
// 原始控制流图
基本块0:                 // 入口块
  GetParameter(r1, 0)    // 参数r1
  Add(r2, r1, 1)         // r2 = r1 + 1
  Return(r2)

// 寄存器分配：
// r1 -> x10 (调用者保存寄存器)
// r2 -> x8  (被调用者保存寄存器，s0)

// 调用 add_procedure_prologues 后：
基本块0:                 // 入口块（添加被调用者保存）
  StoreLocal(x8, 0)      // 保存被调用者保存寄存器s0
  GetParameter(r1, 0)    // 原始指令
  Add(r2, r1, 1)         // 原始指令
  LoadLocal(x8, 0)       // 恢复被调用者保存寄存器s0
  Return(r2)             // 原始指令
```

### 示例3：多个调用点

```rust
// 原始控制流图
基本块0:
  Add(r1, r2, r3)       // r1, r2, r3 活跃
  Beq(r1, 0, "call1", "call2")

基本块1:                 // 第一个调用点
  Call(r4, "func1", [r1])
  J("exit")

基本块2:                 // 第二个调用点
  Call(r5, "func2", [r2])
  J("exit")

基本块3:                 // 退出块
  Return(r4)

// 调用 add_procedure_prologues 后：
基本块0:                 // 不变
  Add(r1, r2, r3)
  Beq(r1, 0, "call1", "call2")

基本块1:                 // 第一个调用点
  StoreLocal(r1, 0)      // 保存r1（在call1活跃）
  StoreLocal(r2, 1)      // 保存r2（在call1活跃）
  StoreLocal(r3, 2)      // 保存r3（在call1活跃）
  Call(r4, "func1", [r1])
  LoadLocal(r1, 0)       // 恢复r1
  LoadLocal(r2, 1)       // 恢复r2
  LoadLocal(r3, 2)       // 恢复r3
  J("exit")

基本块2:                 // 第二个调用点
  StoreLocal(r1, 3)      // 保存r1（在call2活跃，使用不同偏移）
  StoreLocal(r2, 4)      // 保存r2（在call2活跃）
  StoreLocal(r3, 5)      // 保存r3（在call2活跃）
  Call(r5, "func2", [r2])
  LoadLocal(r1, 3)       // 恢复r1
  LoadLocal(r2, 4)       // 恢复r2
  LoadLocal(r3, 5)       // 恢复r3
  J("exit")

基本块3:                 // 退出块
  Return(r4)
```

## RISC-V ABI寄存器分类

### 调用者保存寄存器（Temporary Registers）
| 寄存器 | 名称 | 用途 |
|--------|------|------|
| x5-x7  | t0-t2 | 临时寄存器 |
| x10-x17| a0-a7 | 参数/返回值寄存器 |
| x28-x31| t3-t6 | 临时寄存器 |

### 被调用者保存寄存器（Saved Registers）
| 寄存器 | 名称 | 用途 |
|--------|------|------|
| x8-x9  | s0-s1 | 保存寄存器 |
| x18-x27| s2-s11 | 保存寄存器 |

### 特殊寄存器
| 寄存器 | 名称 | 用途 |
|--------|------|------|
| x0     | zero | 常数0 |
| x1     | ra   | 返回地址 |
| x2     | sp   | 栈指针 |
| x3     | gp   | 全局指针 |
| x4     | tp   | 线程指针 |

## 栈帧布局

### 调用前栈帧
```
高地址
+----------------+
| 保存的寄存器   |  <- 调用者保存区域
+----------------+
| 局部变量       |  <- 局部变量区域
+----------------+
| 返回地址       |  <- 低地址
+----------------+
```

### 调用后栈帧（添加序言/尾声）
```
高地址
+----------------+
| 被调用者保存   |  <- 被调用者保存区域（函数入口/出口）
+----------------+
| 调用者保存     |  <- 调用者保存区域（调用点）
+----------------+
| 局部变量       |  <- 局部变量区域
+----------------+
| 返回地址       |  <- 低地址
+----------------+
```

## 性能特点

### 时间复杂度
- **活跃变量分析**：O(N × M)，其中N是指令数，M是基本块数
- **调用点处理**：O(K × R)，其中K是调用点数，R是活跃寄存器数
- **总体复杂度**：O(N × M + K × R)

### 空间复杂度
- **栈空间**