#include "DyArray.h"
#include <iostream>

template<typename T>
void DyArray<T>::reSize()
{
    T* newdata = new T[2 * capacity];
    for (int i = 0; i < curSize; i++) {
        newdata[i] = arr[i];
    }

    capacity = 2 * capacity;

    delete [] arr;
    arr = newdata;
}

template<typename T>
void DyArray<T>::insert(int index, T e) 
{
    if (curSize >= capacity) {
        reSize();
    }

    if (index < 0 || index > curSize) {
        throw "add::index < 0 || index > size";
    }

    for (int i = curSize - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = e;
    curSize++;
}

template<typename T>
int DyArray<T>::get(int index) 
{
    if (index < 0 || index > curSize) {
        throw "get::index < 0 || index > curSize";
    }

    return arr[index];
}

template<typename T>
void DyArray<T>::set(int index, T e) 
{
    if (index < 0 || index > curSize) {
        throw "set::index < 0 || index > curSize";
    }

    arr[index] = e;
}

template<typename T>
bool DyArray<T>::contains(T e) 
{
    for (int i = 0; i < curSize; i++) {
        if (arr[i] == e) {
            return true;
        }
    }
    return false;
}

//删除并返回
template<typename T>
T DyArray<T>::remove(int index) 
{
    if (index < 0 || index > curSize) {
        throw "remove::index < 0 || index > curSize";
    }

    int ret = arr[index];
    for (int i = index + 1; i < curSize; i++) {
        arr[i - 1] = arr[i];
    }

    curSize--;
    return ret;
}

template<typename T>
void DyArray<T>::toString() 
{
    std::cout << "Array Size =" << curSize << "，Capacity=" << capacity << std::endl;

    for (int i = 0; i < curSize; i++) {
        std::cout << *(arr + i);
        if (i != curSize - 1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
}