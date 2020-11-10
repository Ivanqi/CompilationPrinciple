#include "DyArray.h"

template<class T>
DyArray<T>::DyArray(int cap) :capacity(cap), curSize(0)
{
    initArray();
}

template<class T>
DyArray<T>::DyArray(): capacity(DEFAULT_CAP), curSize(0)
{

}



template<class T>
bool DyArray<T>::initArray()
{
    arr = new DArr*[capacity];

    if (!arr) {
        return false;
    }

    for (int i = 0; i < capacity; ++i) {
        arr[i] = nullptr;
    }
    return true;
}

template<class T>
bool DyArray<T>::insert(const T& value)
{
    if (curSize > capacity) {
        resize();
    }

    int hole = curSize++;
    arr[hole] = value;
    return true;
}

template<class T>
const T& DyArray<T>::getIdx(int index)
{
    if (index > curSize) {
        return nullptr;
    }

    return arr[index];
}

template<class T>
bool DyArray<T>::resize()
{
    DArr **temp = new DArr* [2 * capacity];
    for (int i = 0; i < 2 * capacity; i++) {
        temp[i] = nullptr;
    }

    if (!temp) {
        return false;
    }

    capacity = 2 * capacity;

    for (int i = 0; i < curSize; ++i) {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}