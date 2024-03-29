#include "util/map.hpp"
#include "runtime/universe.hpp"
#include "object/hiObject.hpp"
#include "memory/heap.hpp"
#include "memory/oopClosure.hpp"

template<typename K, typename V>
Map<K, V>::Map()
{
    _entries = new MapEntry<K, V>[8];
    _length = 8;
    _size = 0;
}

template<typename K, typename V>
MapEntry<K, V>::MapEntry(const MapEntry<K, V>& entry)
{
    _k = entry._k;
    _v = entry._v;
}

template<typename K, typename V>
void Map<K, V>::put(K k, V v)
{
    for (int i = 0; i < _size; i++) {
        if (_entries[i]._k->equal(k) == (HiObject*)Universe::HiTrue) {
            _entries[i]._v = v;
            return;
        }
    }

    expand();
    _entries[_size++] = MapEntry<K, V>(k, v);
}

template<typename K, typename V>
V Map<K, V>::get(K k)
{
    int i = index(k);
    if (i < 0) {
        return Universe::HiNone;
    } else {
        return _entries[i]._v;
    }
}

template<typename K, typename V>
bool Map<K, V>::has_key(K k)
{
    int i = index(k);
    return i >= 0;
}

template<typename K, typename V>
int Map<K, V>::index(K k)
{
    for (int i = 0; i < _size; i++) {
        if (_entries[i]._k->equal(k) == (HiObject*)Universe::HiTrue) {
            return i;
        }
    }

    return -1;
}

template<typename K, typename V>
void Map<K, V>::expand()
{
    if (_size >= _length) {
        MapEntry<K, V>* new_entries = new MapEntry<K, V>[_length << 1];
        for (int i = 0; i < _size; i++) {
            new_entries[i] = _entries[i];
        }
        _length <<= 1;
        _entries = new_entries;
    }
}

/**
 * @brief 哈希删除
 *  1. 由于map中的元素是没有先后顺序要求的，所有键值对可以任意排列
 *  2. 当要删除容器中的某一个元素的时，只需要将最后一个元素与待删除元素交换位置，这样待删除元素就会在最后一位
 *  3. 这样删除最后一位就可以了
 * 
 * @tparam K 
 * @tparam V 
 * @param k 
 * @return V 
 */
template<typename K, typename V>
V Map<K, V>::remove(K k)
{
    int i = index(k);

    if (i < 0) {
        return 0;
    }

    V v = _entries[i]._v;
    _entries[i] = _entries[--_size];
    return v;
}

template<typename K, typename V>
K Map<K, V>::get_key(int index)
{
    return _entries[index]._k;
}

template<typename K, typename V>
V Map<K, V>::get_value(int index)
{
    return _entries[index]._v;
}

template<typename K, typename V>
void* MapEntry<K, V>::operator new[](size_t size)
{
    return Universe::heap->allocate(size);
}

template<typename K, typename V>
void Map<K, V>::oops_do(OopClosure* closure)
{
    closure->do_raw_mem((char**)(&_entries), _length * sizeof(MapEntry<K, V>));

    for (int i = 0; i < _size; i++) {
        closure->do_oop(&(_entries[i]._k));
        closure->do_oop(&(_entries[i]._v));
    }
}

template <typename K, typename V>
void* Map<K, V>::operator new(size_t size) 
{
    return Universe::heap->allocate(size);
}

template class Map<HiObject*, HiObject*>;