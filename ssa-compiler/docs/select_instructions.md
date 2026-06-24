# `select_instructions` 函数分析报告

## 函数作用概述

`select_instructions` 函数是**指令选择**（Instruction Selection）的核心实现。该函数的主要作用是将**中间表示**（Intermediate Representation，IR）的控制流图转换为**目标架构**（RISC-V 64位）的机器指令序列。这是编译器后端的关键阶段，负责将平台无关的IR指令映射到具体的RISC-V指令。

具体来说，`select_instructions` 函数的主要作用是：
1. **指令映射**：将IR操作符映射到RISC-V指令
2. **寄存器映射**：将虚拟寄存器映射到物理寄存器
3. **栈帧管理**：生成函数序言和尾声代码
4. **ABI合规**：确保生成的代码符合RISC-V ABI规范
5. **控制流处理**：处理跳转和分支指令

## 每行代码详细注释

```rust
/// `select_instructions` 函数：将IR控制流图转换为RISC-V指令序列
/// 
/// 参数：
/// - mut cfg: CFG<Operator> - IR控制流图（所有权传递）
/// - allocation: &HashMap<VReg, RV64Reg> - 虚拟寄存器到物理寄存器的分配映射
/// 
/// 返回值：CFG<RV64Operation> - RISC-V指令的控制流图
/// 
/// 功能：将平台无关的IR指令转换为RISC-V 64位架构的机器指令
/// 这是编译器后端的指令选择阶段，负责生成目标架构的指令序列
pub fn select_instructions(
        mut cfg: CFG<Operator>,
        allocation: &HashMap<VReg, RV64Reg>,
    ) -> CFG<RV64Operation> {
        // 导入RISC-V操作枚举，简化代码
        use RV64Operation::*;
        
        // 步骤1：为每个基本块创建新的指令体向量
        // new_bodies[i] 存储基本块i转换后的RISC-V指令序列
        let mut new_bodies: Vec<Vec<RV64Operation>> = vec![Vec::new(); cfg.len()];
        
        // 步骤2：获取退出块的标签，用于返回指令
        let exit_label = Rc::clone(&cfg.get_block(cfg.get_exit()).label);

        // 步骤3：遍历所有基本块，进行指令选择
        for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate() {
            // 步骤3.1：获取基本块的原始指令体（所有权转移）
            let body = std::mem::take(&mut block.body);

            // 步骤3.2：遍历基本块中的每条IR指令
            for op in body {
                // 宏定义：处理二元运算指令
                // 将IR二元运算映射到RISC-V二元运算指令
                macro_rules! binary_op {
                    ($x:expr, $y:expr, $z:expr, $p:path) => {{
                        // 使用寄存器分配映射获取物理寄存器
                        new_bodies[i].push($p(allocation[&$x], allocation[&$y], allocation[&$z]));
                    }};
                }
                
                // 宏定义：获取物理寄存器
                // 将虚拟寄存器转换为物理寄存器
                macro_rules! get_regs {
                    ($($x:expr),+) => {
                        ($(allocation[&$x]),+)
                    };
                }
                
                // 步骤3.3：根据IR指令类型进行指令选择
                match op {
                    // 算术运算指令：直接映射到RISC-V指令
                    Operator::Add(x, y, z) => binary_op!(x, y, z, ADD),
                    Operator::Sub(x, y, z) => binary_op!(x, y, z, SUB),
                    Operator::Mult(x, y, z) => binary_op!(x, y, z, MUL),
                    Operator::Div(x, y, z) => binary_op!(x, y, z, DIV),
                    Operator::And(x, y, z) => binary_op!(x, y, z, AND),
                    Operator::Or(x, y, z) => binary_op!(x, y, z, OR),
                    
                    // 复制指令：映射到ADDI指令（加0立即数）
                    Operator::Mv(x, y) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(ADDI(x, y, 0));
                    }
                    
                    // 逻辑运算指令
                    Operator::Xor(x, y, z) => binary_op!(x, y, z, XOR),
                    
                    // 内存加载指令：分解为地址计算 + 加载
                    Operator::Load(x, y, z) => {
                        let (x, y, z) = get_regs!(x, y, z);
                        // 步骤1：计算地址：x = y + z
                        new_bodies[i].push(ADD(x, y, z));
                        // 步骤2：从内存加载：x = [x]
                        new_bodies[i].push(LQ(x, x, 0));
                    }
                    
                    // 内存存储指令：分解为地址计算 + 存储 + 地址恢复
                    Operator::Store(x, y, z) => {
                        let (x, y, z) = get_regs!(x, y, z);
                        // 断言：地址寄存器不能与源寄存器相同
                        assert!(
                            x != z,
                            "store: address register may not alias original register"
                        );
                        // 步骤1：计算地址：z = z + y
                        new_bodies[i].push(ADD(z, z, y));
                        // 步骤2：存储到内存：[z] = x
                        new_bodies[i].push(SQ(x, z, 0));
                        // 步骤3：恢复地址：z = z - y
                        new_bodies[i].push(SUB(z, z, y));
                    }
                    
                    // 加载地址指令：映射到伪指令LA
                    Operator::La(x, y) => {
                        let x = get_regs!(x);
                        new_bodies[i].push(PSEUD_LA(x, y));
                    }
                    
                    // 分支指令：大于分支映射到BGE（大于等于）
                    Operator::Bgt(x, y, z, _) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(BGE(x, y, z));
                    }
                    
                    // 分支指令：小于分支映射到BL（小于）
                    Operator::Bl(x, y, z, _) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(BL(x, y, z));
                    }
                    
                    // 无条件跳转指令：映射到伪指令J
                    Operator::J(x) => {
                        new_bodies[i].push(PSEUD_J(x));
                    }
                    
                    // 相等分支指令：映射到BEQ（相等）
                    Operator::Beq(x, y, z, _) => {
                        let (x, y) = get_regs!(x, y);
                        new_bodies[i].push(BEQ(x, y, z));
                    }
                    
                    // 加载立即数指令：映射到伪指令LI
                    Operator::Li(x, y) => {
                        let x = get_regs!(x);
                        new_bodies[i].push(PSEUD_LI(x, y));
                    }
                    
                    // 小于比较指令：映射到SLT（小于设置）
                    Operator::Slt(x, y, z) => binary_op!(x, y, z, SLT),
                    
                    // 函数调用指令：映射到伪指令CALL
                    Operator::Call(_, y, z) => {
                        // 断言：参数数量不超过7个（RISC-V ABI限制）
                        debug_assert!(z.len() <= 7);
                        // 参数寄存器已在寄存器分配阶段处理
                        new_bodies[i].push(PSEUD_CALL(y));
                    }
                    
                    // 返回指令：映射到跳转到退出标签
                    Operator::Return(_) => {
                        // 返回值已在寄存器分配阶段固定到x10
                        new_bodies[i].push(PSEUD_J(Rc::clone(&exit_label)));
                    }
                    
                    // 标签指令：在CFG中不应出现
                    Operator::Label(_) => {
                        #[cfg(debug_assertions)]
                        unreachable!("label should be excluded in CFG");
                        #[cfg(not(debug_assertions))]
                        unsafe {
                            std::hint::unreachable_unchecked()
                        }
                    }
                    
                    // 获取参数指令：已在寄存器分配阶段处理
                    Operator::GetParameter(_, _) => {
                        // 参数已在寄存器分配阶段固定到正确寄存器
                    }
                    
                    // 存储到局部栈帧：映射到SQ指令
                    Operator::StoreLocal(x, y) => {
                        let x = get_regs!(x);
                        // 栈偏移量转换为字节：y * 8
                        new_bodies[i].push(SQ(x, RV64Reg::X2, (y * 8) as i16));
                    }
                    
                    // 从局部栈帧加载：映射到LQ指令
                    Operator::LoadLocal(x, y) => {
                        let x = get_regs!(x);
                        // 栈偏移量转换为字节：y * 8
                        new_bodies[i].push(LQ(x, RV64Reg::X2, (y * 8) as i16));
                    }
                    
                    // 空操作指令：忽略
                    Operator::Nop => {}
                }
            }
        }
        
        // 步骤4：创建新的基本块，包含转换后的指令
        let mut new_blocks: Vec<_> = std::mem::take(&mut cfg.blocks)
            .into_iter()
            .enumerate()
            .map(|(i, block)| block.into_other(std::mem::take(&mut new_bodies[i])))
            .collect();
        
        // 步骤5：生成函数序言代码（在入口块）
        // 5.1：保存返回地址到栈上
        new_blocks[cfg.get_entry()].body.insert(
            0,
            SQ(
                RV64Reg::X1,  // 返回地址寄存器（ra）
                RV64Reg::X2,  // 栈指针寄存器（sp）
                (*cfg.get_allocated_ars_mut() as i16) * 8,  // 栈偏移量（字节）
            ),
        );
        
        // 5.2：增加栈帧大小计数
        *cfg.get_allocated_ars_mut() += 1;
        
        // 5.3：调整栈指针（分配栈空间）
        new_blocks[cfg.get_entry()].body.insert(
            0,
            ADDI(
                RV64Reg::X2,  // 栈指针寄存器（sp）
                RV64Reg::X2,  // 源寄存器也是sp
                (*cfg.get_allocated_ars_mut() as i16) * -8,  // 负偏移，向下增长栈
            ),
        );
        
        // 步骤6：生成函数尾声代码（在退出块）
        new_blocks[cfg.get_exit()].body.extend([
            // 6.1：恢复返回地址
            LQ(
                RV64Reg::X1,  // 返回地址寄存器（ra）
                RV64Reg::X2,  // 栈指针寄存器（sp）
                (*cfg.get_allocated_ars_mut() as i16 - 1) * 8,  // 栈偏移量（字节）
            ),
            // 6.2：恢复栈指针（释放栈空间）
            ADDI(
                RV64Reg::X2,  // 栈指针寄存器（sp）
                RV64Reg::X2,  // 源寄存器也是sp
                (*cfg.get_allocated_ars_mut() as i16) * 8,  // 正偏移，向上收缩栈
            ),
            // 6.3：返回指令
            PSEUD_RET,
        ]);
        
        // 步骤7：返回转换后的控制流图
        cfg.into_other(new_blocks)
    }
```

## 算法流程详解

### 步骤1：数据结构初始化
1. **新指令体向量**：`new_bodies: Vec<Vec<RV64Operation>>`
   - 为每个基本块创建空的RISC-V指令序列
   - 长度与原始CFG相同

2. **退出标签**：`exit_label`
   - 获取退出块的标签
   - 用于返回指令的目标

### 步骤2：基本块遍历
- **遍历所有基本块**：`for (i, block) in cfg.get_blocks_mut().iter_mut().enumerate()`
- **指令体所有权转移**：`std::mem::take(&mut block.body)`
- **指令逐个处理**：`for op in body`

### 步骤3：指令选择映射

#### 算术运算指令
```
IR: Add(r1, r2, r3)  →  RISC-V: ADD(x10, x11, x12)
IR: Sub(r1, r2, r3)  →  RISC-V: SUB(x10, x11, x12)
IR: Mult(r1, r2, r3) →  RISC-V: MUL(x10, x11, x12)
IR: Div(r1, r2, r3)  →  RISC-V: DIV(x10, x11, x12)
```

#### 逻辑运算指令
```
IR: And(r1, r2, r3)  →  RISC-V: AND(x10, x11, x12)
IR: Or(r1, r2, r3)   →  RISC-V: OR(x10, x11, x12)
IR: Xor(r1, r2, r3)  →  RISC-V: XOR(x10, x11, x12)
```

#### 复制指令
```
IR: Mv(r1, r2)  →  RISC-V: ADDI(x10, x11, 0)
```

#### 内存访问指令
```
IR: Load(r1, r2, r3)  →  RISC-V: ADD(x10, x11, x12) + LQ(x10, x10, 0)
IR: Store(r1, r2, r3) →  RISC-V: ADD(x12, x12, x11) + SQ(x10, x12, 0) + SUB(x12, x12, x11)
```

#### 控制流指令
```
IR: J(label)      →  RISC-V: PSEUD_J(label)
IR: Bgt(r1, r2, label) → RISC-V: BGE(x10, x11, label)
IR: Bl(r1, r2, label)  → RISC-V: BL(x10, x11, label)
IR: Beq(r1, r2, label) → RISC-V: BEQ(x10, x11, label)
```

#### 立即数指令
```
IR: Li(r1, 42)    →  RISC-V: PSEUD_LI(x10, 42)
IR: La(r1, label) →  RISC-V: PSEUD_LA(x10, label)
```

#### 函数调用指令
```
IR: Call(r1, "func", [r2, r3]) → RISC-V: PSEUD_CALL("func")
```

#### 栈访问指令
```
IR: StoreLocal(r1, 3) → RISC-V: SQ(x10, x2, 24)  // 3 * 8 = 24字节
IR: LoadLocal(r1, 3)  → RISC-V: LQ(x10, x2, 24)
```

### 步骤4：函数序言生成

#### 栈帧布局
```
高地址
+----------------+
| 保存的寄存器   |  <- 被调用者保存区域
+----------------+
| 局部变量       |  <- 局部变量区域
+----------------+
| 返回地址       |  <- 栈指针指向这里
+----------------+
低地址
```

#### 序言代码
```assembly
# 函数入口
addi sp, sp, -32     # 分配32字节栈空间
sd   ra, 24(sp)      # 保存返回地址
```

#### 尾声代码
```assembly
# 函数出口
ld   ra, 24(sp)      # 恢复返回地址
addi sp, sp, 32      # 释放栈空间
ret                  # 返回
```

### 步骤5：寄存器映射

#### 寄存器分配表
```rust
// allocation: HashMap<VReg, RV64Reg>
// 示例：{1: X10, 2: X11, 3: X12, ...}
```

#### 物理寄存器使用
- **X1 (ra)**：返回地址
- **X2 (sp)**：栈指针
- **X10-X17 (a0-a7)**：参数/返回值寄存器
- **X8-X9, X18-X27 (s0-s11)**：被调用者保存寄存器
- **X5-X7, X28-X31 (t0-t6)**：调用者保存寄存器

## 举例说明

### 示例1：简单加法函数

```rust
// 原始IR控制流图
基本块0:                 // 入口块
  GetParameter(r1, 0)    // 获取参数
  Add(r2, r1, 1)         // r2 = r1 + 1
  Return(r2)             // 返回r2

// 寄存器分配：
// r1 -> X10 (a0)
// r2 -> X11 (a1)

// 调用 select_instructions 后：
基本块0:                 // 入口块（添加序言）
  ADDI(X2, X2, -16)      // 分配16字节栈空间
  SQ(X1, X2, 8)          // 保存返回地址
  ADDI(X11, X10, 1)      // X11 = X10 + 1 (原Add指令)
  PSEUD_J(".Lexit")      // 跳转到退出块

基本块1:                 // 退出块（添加尾声）
  LQ(X1, X2, 8)