// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
use std::borrow::Borrow;
use std::collections::hash_map::RandomState;

use std::collections::HashMap;
use std::hash::BuildHasher;
use std::hash::Hash;

// /**
//  * 嵌套作用域: 支持作用域嵌套，通过 parent 字段实现
//  * 层次查找: 在当前作用域找不到时，会自动向上查找父作用域
//  * 作用域管理: 支持 push() 和 pop() 操作来管理作用域层次
//  */
pub struct SheafTable<K, V, S = RandomState> {
    parent: Option<Box<SheafTable<K, V, S>>>, // 父作用域
    current: HashMap<K, V, S>,  // 当前作用域
}

impl<K, V> SheafTable<K, V, RandomState> {
    pub fn new() -> Self {
        Self {
            parent: None,
            current: HashMap::<K, V>::new(),
        }
    }
    pub fn push(&mut self) {
        let mut new = Self::new();
        std::mem::swap(self, &mut new);
        self.parent = Some(Box::new(new));
    }
    pub fn pop(&mut self) {
        if let Some(parent) = self.parent.take() {
            *self = *parent;
        }
    }
}

impl<K, V> Default for SheafTable<K, V> {
    fn default() -> Self {
        Self::new()
    }
}

impl<K, V, S> SheafTable<K, V, S>
where
    K: Eq + Hash,
    S: BuildHasher,
{
    pub fn insert(&mut self, k: K, v: V) -> Option<V> {
        self.current.insert(k, v)
    }
    pub fn get<Q>(&self, k: &Q) -> Option<&V>
    where
        K: Borrow<Q>,
        Q: Hash + Eq + ?Sized,
    {
        self.current
            .get(k)
            .or_else(|| self.parent.as_deref().and_then(|p| p.get(k)))
    }
    pub fn get_mut<Q>(&mut self, k: &Q) -> Option<&mut V>
    where
        K: Borrow<Q>,
        Q: Hash + Eq + ?Sized,
    {
        self.current
            .get_mut(k)
            .or_else(|| self.parent.as_deref_mut().and_then(|p| p.get_mut(k)))
    }
    pub fn remove<Q>(&mut self, k: &Q) -> Option<V>
    where
        K: Borrow<Q>,
        Q: Hash + Eq + ?Sized,
    {
        self.current
            .remove(k)
            .or_else(|| self.parent.as_deref_mut().and_then(|p| p.remove(k)))
    }
    pub fn get_key_value<Q>(&self, k: &Q) -> Option<(&K, &V)>
    where
        K: Borrow<Q>,
        Q: Hash + Eq + ?Sized,
    {
        self.current
            .get_key_value(k)
            .or_else(|| self.parent.as_deref().and_then(|p| p.get_key_value(k)))
    }
}
