# 具体示例分析
## 示例1: 简单线性控制流
```
// 基本块0 → 基本块1 → 基本块2
// 假设：
// exp_gen[0]: [(10, Immediate(3)), (11, Immediate(5)), (12, Plus(10, 11))]
// exp_gen[1]: []
// exp_gen[2]: []

// 处理过程：
// 1. 处理基本块2：antic_out[2] = {} (无后继)
// 2. 处理基本块1：antic_out[1] = phi_translate(antic_in[2])
// 3. 处理基本块0：antic_out[0] = phi_translate(antic_in[1])

// 结果：
// antic_in[0]: [10, 11, 12]  // 所有表达式都可用
// antic_in[1]: [10, 11, 12]  // 从基本块0传播
// antic_in[2]: [10, 11, 12]  // 从基本块1传播
```

## 示例2： 分支控制流
```
// 基本块0 → 基本块1
//          ↘ 基本块2
// 假设：
// antic_in[1]: [(10, Immediate(3)), (12, Plus(10, 11))]
// antic_in[2]: [(10, Immediate(3)), (13, Sub(10, 11))]

// 处理过程：
// 基本块0是分支节点，取antic_in[1]和antic_in[2]的交集
// 交集：[(10, Immediate(3))]  // 只有值编号10在两个分支中都可用

// 结果：
// antic_out[0]: [(10, Immediate(3))]
// antic_in[0]: exp_gen[0] ∪ antic_out[0]  // 加上基本块0生成的表达式
```

## 示例3：包含kill 指令
```
// 基本块0包含：
// li r1, 3     // 值编号10
// load r4, [r1] // kill r4
// add r5, r4, r2 // 依赖r4，被kill

// 处理过程：
// tmp_gen[0]: {r4}
// exp_gen[0]: [(10, Immediate(3))]
// antic_out[0]: [(10, Immediate(3))]

// 计算antic_in[0]:
// 表达式(10, Immediate(3)): 无依赖，不被kill → 保留
// 表达式add r5, r4, r2: 依赖r4，r4被kill → 过滤

// 结果：
// antic_in[0]: [(10, Immediate(3))]
```