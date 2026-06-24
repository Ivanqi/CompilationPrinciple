# 虚拟寄存器生成器（`VRegGenerator`）
## 简单表达式翻译
源代码: `x = a + b`

翻译过程:
```rust
let mut gen = VRegGenerator::new();

// 为a分配寄存器
let reg_a = gen.next_reg(); // 0
// 为b分配寄存器  
let reg_b = gen.next_reg(); // 1
// 为结果x分配寄存器
let reg_x = gen.next_reg(); // 2

// 生成加法指令
// add rd2, rd0, rd1
```

## 条件语句翻译
源代码: `if (x > 0) then y = 1 else y = 0`

翻译过程:
```rust
let mut gen = VRegGenerator::new();

// 生成标签
let then_label = gen.next_label(); // "_LABEL_0"
let else_label = gen.next_label(); // "_LABEL_1"  
let merge_label = gen.next_label(); // "_LABEL_2"

// 生成条件分支指令
// beq rd_x, rd_0, @_LABEL_0, @_LABEL_1

// then分支
// Label: @_LABEL_0
// li rd_y, 1
// j @_LABEL_2

// else分支  
// Label: @_LABEL_1
// li rd_y, 0
// j @_LABEL_2

// 合并点
// Label: @_LABEL_2

```

## SSA 转换中的寄存器重命名
原始代码
```text
// 基本块0: x = 5
// 基本块1: x = x + 1
// 基本块2: y = x * 2
```
SSA 转换后
```rust
let mut gen = VRegGenerator::starting_at_reg(3); // 假设已有寄存器0,1,2

// 基本块0: x0 = 5
// 基本块1: x1 = φ(x0, x2)  // Phi函数需要新寄存器
let phi_reg = gen.next_reg(); // 3

// 基本块1: x2 = x1 + 1
let add_reg = gen.next_reg(); // 4

// 基本块2: y0 = x2 * 2  
let mul_reg = gen.next_reg(); // 5
```
## 循环结构翻译
源代码: `while (i < 10) { i = i + 1; }`

翻译过程:
```rust
let mut gen = VRegGenerator::new();

// 生成循环标签
let loop_head = gen.next_label(); // "_LABEL_0"
let loop_body = gen.next_label(); // "_LABEL_1"
let loop_exit = gen.next_label(); // "_LABEL_2"

// 跳转到循环头
// j @_LABEL_0

// 循环头标签
// Label: @_LABEL_0

// 条件检查
// slt rd_temp, rd_i, rd_10
// beq rd_temp, rd_0, @_LABEL_1, @_LABEL_2

// 循环体标签  
// Label: @_LABEL_1
// add rd_i, rd_i, rd_1
// j @_LABEL_0

// 退出标签
// Label: @_LABEL_2

```