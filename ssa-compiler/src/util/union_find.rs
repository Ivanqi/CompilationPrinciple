// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
use std::collections::HashMap;
use std::hash::Hash;

/// UnionFind 数据结构定义
/// V: 泛型参数，表示集合中的元素类型
pub struct UnionFind<V> {
    nodes: Vec<Node<V>>,        // 存储所有节点的向量
    indices: HashMap<V, Index>, // 元素到节点索引的映射
}

/// 类型别名：节点索引
type Index = usize;

/// 节点结构定义
struct Node<V> {
    content: V,         // 节点存储的实际内容
    p: Option<Index>,   // 父节点索引，None 表示根节点
    size: usize,        // 以该节点为根的集合大小（用于按秩合并）
}

/// Node 的实现
impl<V> Node<V> {
    /// 获取父节点引用（不可变）
    /// 生命周期注解：'b 必须至少和 'a 一样长
    fn parent<'a, 'b>(&'a self, nodes: &'b [Node<V>]) -> Option<&Node<V>>
    where
        'b: 'a,
    {
        if let Some(p) = self.p {
            Some(&nodes[p]) // 返回父节点引用
        } else {
            None    // 没有父节点（根节点）
        }
    }

    /// 获取父节点引用（可变）
    fn parent_mut<'a, 'b>(&'a self, nodes: &'b mut [Node<V>]) -> Option<&mut Node<V>>
    where
        'b: 'a,
    {
        if let Some(p) = self.p {
            Some(&mut nodes[p]) // 返回可变父节点引用
        } else {
            None
        }
    }
}

/// 从 V 类型到 Node<V> 的转换实现
impl<V> From<V> for Node<V> {
    fn from(v: V) -> Self {
        Self {
            content: v, // 存储内容
            p: None,    // 初始时没有父节点(自己是根)
            size: 1,    // 初始集合大小为1
        }
    }
}

/// UnionFind 的基本实现
impl<V> UnionFind<V> {
    /// 创建新的空 UnionFind
    pub fn new() -> Self {
        Self {
            nodes: Vec::new(),          // 空节点向量
            indices: HashMap::new(),    // 空索引映射
        }
    }
}

/// 默认实现，调用 new()
impl<V> Default for UnionFind<V> {
    fn default() -> Self {
        Self::new()
    }
}

/// 带约束的 UnionFind 实现
/// V 必须满足 Eq + Hash + Clone，因为要作为 HashMap 的键
impl<V> UnionFind<V>
where
    V: Eq + Hash + Clone,
{
    /// 创建新集合（添加新元素）
    pub fn new_set(&mut self, node: V) {
        // 如果元素已存在，直接返回
        if self.indices.contains_key(&node) {
            return;
        }

        // 创建新节点并添加到向量中
        self.nodes.push(Node::from(node.clone()));

        // 记录元素到索引的映射
        // self.nodes.len() - 1 是新节点的索引
        self.indices.insert(node, self.nodes.len() - 1);
    }

    /// 查找元素所属集合的代表元素（根节点）
    pub fn find(&mut self, node: &V) -> Option<&V> {
        // 获取元素的索引
        if let Some(&i) = self.indices.get(node) {
            // 递归查找根节点索引
            let res = self.find_rec(i);
            
            // 返回根节点的内容
            Some(&self.nodes[res].content)
        } else {
            // 元素不存在
            None
        }
    }

    /// 合并两个元素所在的集合
    pub fn union(&mut self, node1: &V, node2: &V) {
        // 获取两个元素的索引
        if let (Some(&n1), Some(&n2)) = (self.indices.get(node1), self.indices.get(node2)) {
            // 查找两个元素的根节点索引
            let p1_i = self.find_rec(n1);
            let p2_i = self.find_rec(n2);
            
            // 如果已经在同一个集合中，直接返回
            if p1_i == p2_i {
                return;
            }

            // 获取两个根节点的引用（用于比较大小）
            let p1 = &self.nodes[p1_i];
            let p2 = &self.nodes[p2_i];
            
            // 获取集合大小
            let p2_size = p2.size;
            let p1_size = p1.size;

            // 按秩合并：将较小的树合并到较大的树
            if p1.size > p2_size {
                // 将 p2 的父节点设为 p1
                self.nodes[p2_i].p = Some(p1_i);

                // 更新 p1 的集合大小
                self.nodes[p1_i].size += p2_size;
            } else {
                // 将 p1 的父节点设为 p2
                self.nodes[p1_i].p = Some(p2_i);

                // 更新 p2 的集合大小
                self.nodes[p2_i].size += p1_size;
            }
        }
    }
    
    /// 递归查找根节点（带路径压缩）
    fn find_rec(&mut self, index: Index) -> Index {
        let node = &self.nodes[index];
        let parent_index = node.p;
        
        if let Some(p) = parent_index {
            // 递归查找父节点的根节点
            let new_parent = Some(self.find_rec(p));

            // 路径压缩：将当前节点的父节点直接设为根节点
            let node: &mut Node<V> = &mut self.nodes[index];
            node.p = new_parent;
            
            // 返回根节点索引
            node.p.unwrap()
        } else {
            // 当前节点就是根节点
            index
        }
    }
}
