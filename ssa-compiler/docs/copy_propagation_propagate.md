# 代码
```rust
/// `propagate` 函数复制传播优化（Copy Propagation）的核心实现部分，位于 `copy_propagation` 模块中
    /// 该函数的主要作用将控制图(CFG) 中所有冗余的寄存器复制操作进行传播和消除
    /// `cfg: &mut CFG<SSAOperator>` - 要优化的控制流图
    /// `set: &HashMap<VReg, VReg>` - 复制关系映射表，表示哪些寄存器是其他寄存器的复制
    /// 核心功能:
    ///     1. __删除冗余的复制指令__：如果一个寄存器的值只是另一个寄存器的复制，并且这个复制关系在 
    ///     `set` 中，那么删除产生这个复制结果的指令
    ///     2. __替换寄存器引用__：将所有使用被复制寄存器的地方替换为使用原始寄存器
    fn propagate(cfg: &mut CFG<SSAOperator>, set: &HashMap<VReg, VReg>) {
        /// 遍历控制流图中的所有基本块
        for block in cfg.get_blocks_mut() {
            /// 使用 std::mem::swap 交换 block.body 和空向量，获取原始指令体
            /// 这是一种高效获取所有权的方式，避免额外的复制
            let mut old = Vec::new();
            std::mem::swap(&mut old, &mut block.body);
            
            /// 对原始指令体进行转换处理
            block.body = old
                .into_iter() // 获取所有权迭代器，消耗原始向量
                .filter_map(|op| { // 使用 filter_map 同时进行过滤和映射
                    /// 检查当前指令是否有结果寄存器（receiver）
                    if let Some(receiver) = op.receiver() {
                        /// 如果结果寄存器在复制关系映射表中（即它是冗余的复制）
                        if set.contains_key(&receiver) {
                            /// 返回 None，表示删除这条指令
                            /// 因为这条指令只是产生一个冗余的复制值
                            return None;
                        }
                    }

                    /// 如果指令没有被删除，创建一个可变的副本用于修改
                    let mut res = op;
                    
                    /// 遍历复制关系映射表中的所有条目
                    for (&k, &v) in set {
                        /// 将指令中所有使用被复制寄存器 k 的地方替换为使用原始寄存器 v
                        /// replace_reg 方法会递归地替换指令中所有出现的寄存器 k
                        res.replace_reg(k, v);
                    }

                    /// 返回修改后的指令
                    Some(res)
                })
                .collect(); /// 将迭代器结果收集回向量
        }
    }
```

# 例子
假设有以下复制关系映射表
```rust
set = {
    3: 1,  // 寄存器3是寄存器1的复制
    4: 2,  // 寄存器4是寄存器2的复制
}
```

原始指令序列:
```llvm
add r5, r3, r4  // r5 = r3 + r4
mv r6, r3       // r6 = r3
sub r7, r6, r4  // r7 = r6 - r4
```
经过 `propagate` 函数处理后:

**删除冗余指令**:
`mv r6, r3` 被删除，因为 r6 是 r3 的复制（假设 r6 在 set 中）

**替换寄存器引用**
`add r5, r3, r4` → `add r5, r1, r2`（r3 替换为 r1，r4 替换为 r2）

`sub r7, r6, r4` → `sub r7, r1, r2`（r6 替换为 r1，r4 替换为 r2）

最后指令序列
```rust
add r5, r1, r2
sub r7, r1, r2
```