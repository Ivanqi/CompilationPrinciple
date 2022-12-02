#include "util/arrayList.hpp"
#include "runtime/interpreter.hpp"
#include "runtime/universe.hpp"
#include "memory/heap.hpp"
#include "memory/oopClosure.hpp"
#include <new>
#include <stdio.h>

template<typename T>
ArrayList<T>::ArrayList(int n)
{
    _length = n;
    _size = 0;
    void* temp = Universe::heap->allocate(sizeof(T) * n);
    _array = new(temp)T[n];
}

template<typename T>
void ArrayList<T>::add(T t)
{
    if (_size >= _length) {
        expand();
    }

    _array[_size++] = t;
}

template<typename T>
void ArrayList<T>::insert(int index, T t)
{
    add(NULL);

    for (int i = _size - 1; i > index; i--) {
        _array[i] = _array[i - 1];
    }

    _array[index] = t;
}

/**
 * @brief 内存扩展
 *  1. 当内存不足时，增加一倍内存
 *  2. 并把旧内存复制新内存指针中
 *  3. 时间复杂度: O(n)
 * 
 * @tparam T 
 */
template<typename T>
void ArrayList<T>::expand()
{
    void* temp = Universe::heap->allocate(sizeof(T) * (_length << 1));
    T* new_array = new(temp)T[_length << 1]; // 增加一倍
    for (int i = 0; i < _length; i++) {
        new_array[i] = _array[i];
    }

    _array = new_array;

    _length <<= 1;  // 长度增加一倍
    printf("expand an array to %d, size is %d\n", _length, _size);
}

template<typename T>
int ArrayList<T>::size()
{
    return _size;
}

template<typename T>
int ArrayList<T>::length()
{
    return _length;
}

template<typename T>
T ArrayList<T>::get(int index)
{
    return _array[index];
}

template<typename T>
void ArrayList<T>::set(int index, T t)
{
    if (_size <= index) {
        _size = index + 1;
    }

    while (_size > _length) {
        expand();
    }

    _array[index] = t;
}

template<typename T>
T ArrayList<T>::pop()
{
    return _array[--_size];
}

template<typename T>
void ArrayList<T>::delete_index(int index)
{
    for (int i = index; i + 1 < _size; i++) {
        _array[i] = _array[i + 1];
    }
    _size--;
}

template<typename T>
void ArrayList<T>::oops_do(OopClosure* closure)
{
    closure->do_raw_mem((char **)(&_array), _length * sizeof(T));
}

template<>
void ArrayList<Klass*>::oops_do(OopClosure* closure)
{
    closure->do_raw_mem((char **)(*_array), _length * sizeof(Klass));

    for (int i = 0; i < size(); i++) {
        closure->do_klass((Klass**)&_array[i]);
    }

    return;
}

template<>
void ArrayList<HiObject*>::oops_do(OopClosure* closure)
{
    closure->do_raw_mem((char **)(&_array), _length * sizeof(HiObject*));

    for (int i = 0; i < size(); i++) {
        closure->do_oop((HiObject**)&_array[i]);
    }
}

template <typename T>
int ArrayList<T>::index(T t) {
    return 0;
}

template <>
int ArrayList<HiObject*>::index(HiObject* t) {
    for (int i = 0; i < _size; i++) {
        if (_array[i]->equal(t) == Universe::HiTrue) {
            return i;
        }
    }

    return -1;
}

class HiObject;
template class ArrayList<HiObject*>;

class HiString;
template class ArrayList<HiString*>;

class Block;
template class ArrayList<Block*>;

class Klass;
template class ArrayList<Klass*>;