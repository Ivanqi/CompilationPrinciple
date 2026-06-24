# `InterferenceGraph` 数据结构分析报告

## 数据结构作用概述

`InterferenceGraph`（冲突图）是**寄存器分配**中的核心数据结构，用于表示虚拟寄存器之间的冲突关系。该数据结构的主要作用是：

1. **存储冲突关系**：记录哪些虚拟寄存器不能分配到同一个物理寄存器
2. **支持图着色算法**：为寄存器分配提供基础数据结构
3. **支持寄存器合并**：允许合并不冲突的寄存器对
4. **支持冲突查询**：快速检查两个寄存器是否冲突

## 每行代码详细注释

```rust
// 冲突图节点结构
struct InterferenceNode {
    live_range: VReg,      // 虚拟寄存器编号（活跃范围）
    edge_with: Vec<usize>, // 与该节点冲突的其他节点索引列表
}

// 冲突图数据结构
struct InterferenceGraph {
    nodes: Vec<InterferenceNode>,      // 所有节点的向量
    index: HashMap<VReg, usize>,       // 寄存器编号到节点索引的映射
}

impl InterferenceGraph {
    // 创建新的空冲突图
    fn new() -> Self {
        Self {
            nodes: Vec::new(),      // 空节点向量
            index: HashMap::new(),  // 空索引映射
        }
    }
    
    // 合并两个寄存器（将from合并到into）
    // 用于寄存器合并优化，减少寄存器数量
    fn merge(&mut self, into: VReg, from: VReg) {
        // 确保两个寄存器都在图中
        if !self.index.contains_key(&into) {
            self.maybe_insert(into);
        }
        if !self.index.contains_key(&from) {
            self.maybe_insert(from);
        }
        
        // 获取两个寄存器的节点索引
        let into_node = self.index[&into];
        let from_node = self.index[&from];
        
        // 遍历from节点的所有冲突边
        for edge in std::mem::take(&mut self.nodes[from_node].edge_with) {
            // 更新冲突节点的边列表：移除from节点，添加into节点
            self.nodes[edge].edge_with = std::mem::take(&mut self.nodes[edge].edge_with)
                .into_iter()
                .filter(|&n| n != from_node && n != into_node)  // 移除from和into节点
                .collect();
            self.nodes[edge].edge_with.push(into_node);  // 添加into节点
            
            // 将冲突边添加到into节点
            self.nodes[into_node].edge_with.push(edge);
        }
        
        // 对into节点的边列表进行排序和去重
        self.nodes[into_node].edge_with.sort();
        self.nodes[into_node].edge_with.dedup();
        
        // 移除from节点的索引（from节点成为垃圾数据）
        self.index.remove(&from); // garbage left
    }
    
    // 可能插入新节点（如果不存在则插入）
    fn maybe_insert(&mut self, vreg: VReg) -> Option<&InterferenceNode> {
        // 如果寄存器已存在，返回现有节点
        if let Some(&index) = self.index.get(&vreg) {
            return Some(&self.nodes[index]);
        }
        
        // 插入新节点
        self.index.insert(vreg, self.nodes.len());  // 记录索引映射
        self.nodes.push(InterferenceNode {
            live_range: vreg,      // 寄存器编号
            edge_with: Vec::new(), // 空冲突列表
        });
        None  // 返回None表示插入了新节点
    }
    
    // 获取节点的可变引用
    fn get_mut(&mut self, vreg: &VReg) -> Option<&mut InterferenceNode> {
        self.index
            .get(vreg)
            .and_then(|index| self.nodes.get_mut(*index))
    }
    
    // 获取节点的不可变引用
    fn get(&self, vreg: &VReg) -> Option<&InterferenceNode> {
        self.index
            .get(vreg)
            .and_then(|index| self.nodes.get(*index))
    }
    
    // 检查两个寄存器之间是否有冲突边
    fn check_edge(&self, vreg1: &VReg, vreg2: &VReg) -> bool {
        // 获取两个寄存器的索引
        if let (Some(index), Some(index2)) = (self.index.get(vreg1), self.index.get(vreg2)) {
            // 检查第一个节点的边列表是否包含第二个节点
            self.nodes[*index].edge_with.contains(index2)
        } else {
            false  // 任一寄存器不存在，返回false
        }
    }
    
    // 添加冲突边（表示两个寄存器冲突）
    fn add_edge(&mut self, vreg1: VReg, vreg2: VReg) {
        // 确保两个寄存器都在图中
        if !self.index.contains_key(&vreg1) {
            self.maybe_insert(vreg1);
        }
        if !self.index.contains_key(&vreg2) {
            self.maybe_insert(vreg2);
        }
        
        // 获取两个寄存器的索引
        let (&index1, &index2) = (
            self.index.get(&vreg1).unwrap(),
            self.index.get(&vreg2).unwrap(),
        );
        
        // 如果边不存在，则添加双向边
        if !self.nodes[index1].edge_with.contains(&index2) {
            self.nodes[index1].edge_with.push(index2);  // vreg1 -> vreg2
            self.nodes[index2].edge_with.push(index1);  // vreg2 -> vreg1
        }
    }
}
```

## 数据结构设计原理

### 1. 节点表示
- **`InterferenceNode`**：表示一个虚拟寄存器（活跃范围）
  - `live_range: VReg`：寄存器编号
  - `edge_with: Vec<usize>`：冲突节点索引列表

### 2. 图表示
- **`InterferenceGraph`**：整个冲突图
  - `nodes: Vec<InterferenceNode>`：所有节点的向量
  - `index: HashMap<VReg, usize>`：寄存器编号到节点索引的映射

### 3. 设计选择
- **向量存储节点**：提供O(1)的随机访问
- **哈希映射存储索引**：提供O(1)的寄存器查找
- **邻接列表存储边**：适合稀疏图，节省空间

## 举例说明

### 示例：构建冲突图

假设有以下冲突关系：
- `r1` 与 `r2` 冲突
- `r1` 与 `r3` 冲突
- `r2` 与 `r3` 冲突

#### 步骤1：创建空图
```rust
let mut graph = InterferenceGraph::new();
```

#### 步骤2：添加冲突边
```rust
graph.add_edge(r1, r2);  // r1 <-> r2
graph.add_edge(r1, r3);  // r1 <-> r3
graph.add_edge(r2, r3);  // r2 <-> r3
```

#### 步骤3：内部数据结构
```
nodes: [
    InterferenceNode { live_range: r1, edge_with: [1, 2] },  // 索引0
    InterferenceNode { live_range: r2, edge_with: [0, 2] },  // 索引1
    InterferenceNode { live_range: r3, edge_with: [0, 1] },  // 索引2
]

index: {
    r1: 0,
    r2: 1,
    r3: 2,
}
```

### 示例：寄存器合并

假设 `r1` 和 `r2` 可以合并（不冲突），将 `r2` 合并到 `r1`：

#### 合并前
```
r1: [r3]
r2: [r3]
r3: [r1, r2]
```

#### 执行合并
```rust
graph.merge(r1, r2);
```

#### 合并后
```
r1: [r3]  // r2的冲突边已合并到r1
r2: []    // r2的边列表被清空，索引被移除
r3: [r1]  // 移除r2，保留r1
```

## 在寄存器分配中的位置

`InterferenceGraph` 在寄存器分配流程中的位置：

1. **构建冲突图**：`build_interference_graph()` 构建初始冲突图
2. **图着色分配**：`find_coloring()` 使用冲突图进行寄存器分配
3. **寄存器合并**：`merge()` 合并不冲突的寄存器对
4. **冲突查询**：`check_edge()` 检查寄存器是否冲突

## 性能特点

### 时间复杂度
- **添加边**：O(1) 平均情况（哈希映射查找 + 向量追加）
- **检查边**：O(k) 其中k是节点的度数
- **合并节点**：O(m) 其中m是from节点的度数
- **插入节点**：O(1) 平均情况

### 空间复杂度
- **节点存储**：O(n) 其中n是寄存器数量
- **边存储**：O(m) 其中m是冲突边数量
- **索引映射**：O(n) 哈希映射存储

## 算法设计的核心思想

### 1. 冲突图表示
- **无向图**：冲突关系是对称的
- **邻接列表**：适合稀疏冲突图
- **双向边**：确保冲突关系的对称性

### 2. 寄存器合并
- **减少节点数量**：合并不冲突的寄存器
- **更新冲突关系**：正确传播合并后的冲突
- **垃圾数据**：合并后保留from节点但不使用

### 3. 高效查询
- **索引映射**：快速定位节点
- **向量存储**：快速访问节点
- **邻接列表**：快速遍历邻居

## 关键技术细节

### 1. 合并算法
1. **获取节点索引**：查找两个寄存器的节点索引
2. **转移冲突边**：将from节点的所有冲突边转移到into节点
3. **更新邻居**：更新所有邻居节点的边列表
4. **清理数据**：移除from节点的索引，保留节点数据

### 2. 边管理
1. **双向添加**：添加边时同时添加两个方向
2. **去重检查**：添加前检查边是否已存在
3. **排序去重**：合并后对边列表排序和去重

### 3. 节点管理
1. **惰性插入**：`maybe_insert` 只在需要时插入
2. **索引映射**：使用哈希映射快速查找
3. **向量存储**：使用向量连续存储节点

## 举例：复杂冲突图

### 原始代码
```
r1 = 10
r2 = r1 + 5
r3 = r2
r4 = r3 * 2
```

### 冲突关系
- `r1` 与 `r2` 冲突
- `r2` 与 `r3` 冲突（但可合并）
- `r3` 与 `r4` 冲突

### 构建冲突图
```rust
graph.add_edge(r1, r2);  // r1 <-> r2
graph.add_edge(r2, r3);  // r2 <-> r3
graph.add_edge(r3, r4);  // r3 <-> r4
```

### 合并寄存器
```rust
graph.merge(r2, r3);  // 合并r3到r2
```

### 合并后冲突图
- `r1` 与 `r2` 冲突
- `r2` 与 `r4` 冲突
- `r3` 被合并，不再存在

## 与图着色算法的关系

### 1. 冲突约束
- **节点**：虚拟寄存器
- **边**：冲突关系约束
- **着色**：为节点分配颜色（物理寄存器）
- **约束**：相邻节点不能有相同颜色

### 2. 合并优化
- **减少节点**：合并不冲突的寄存器
- **简化图**：减少图的复杂度
- **提高成功率**：增加着色成功率

### 3. 冲突检查
- **分配前检查**：确保分配不违反冲突约束
- **合并前检查**：确保合并的寄存器不冲突
- **溢出选择**：选择冲突最少的寄存器溢出

## 总结

`InterferenceGraph` 数据结构是寄存器分配算法的核心组件，它：

1. **高效存储冲突关系**：使用邻接列表表示稀疏冲突图
2. **支持寄存器合并**：允许合并不冲突的寄存器对
3. **提供快速查询**：支持高效的冲突检查和节点访问
4. **简化图着色**：为图着色算法提供基础数据结构

通过精心设计的数据结构和算法，`InterferenceGraph` 能够高效地支持寄存器分配过程中的各种操作，是实现高效编译器优化的关键组件。