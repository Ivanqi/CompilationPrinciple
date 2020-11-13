#ifndef DYARRAY_H
#define DYARRAY_H

#include <iostream>
#define DEFAULT_CAP 10

template<typename T>
class DyArray
{
    private:

        T *arr;         // 数组
        int capacity;   // 数组容量
        int curSize;    // 数组当前包含元素的个数
    
    private:
        bool initArray()
        {
            arr = new T[capacity];

            return arr != nullptr;
        }

        void reSize()
        {
            T* newdata = new T[2 * capacity];
            for (int i = 0; i < curSize; i++) {
                newdata[i] = arr[i];
            }

            capacity = 2 * capacity;

            delete [] arr;
            arr = newdata;
        }

    public:

        DyArray(int cap):capacity(cap), curSize(0)
        {
            initArray();
        }

        DyArray() : capacity(DEFAULT_CAP), curSize(0)
        {
            initArray();
        }

        ~DyArray()
        {
            delete [] arr;
        }

        void insert(int index, T e)
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

        void push_back(T e)
        {
            insert(curSize, e);
        }

        T& operator[](int i) 
        {
            if (i < 0 || i > curSize) {
                throw "get::index < 0 || index > curSize";
            }
		    return arr[i];
	    }

        T operator [] (int i) const
        {
            if (i < 0 || i > curSize) {
                throw "get::index < 0 || index > curSize";
            }
            return arr[i];
        }

        T& get(int index)
        {
            if (index < 0 || index > curSize) {
                throw "get::index < 0 || index > curSize";
            }

            return arr[index];
        }

        void set(int index, T e)
        {
            if (index < 0 || index > curSize) {
                throw "set::index < 0 || index > curSize";
            }

            arr[index] = e;
        }

        bool contains(T e)
        {
            for (int i = 0; i < curSize; i++) {
                if (arr[i] == e) {
                    return true;
                }
            }
            return false;
        }

        //删除并返回
        T remove(int index)
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

        int size() 
        {
        	return curSize;
        }

        int length()
        {
            return curSize;
        }

        bool IsEmpty() {
        	return curSize == 0;
        }

        void toString()
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
};

#endif