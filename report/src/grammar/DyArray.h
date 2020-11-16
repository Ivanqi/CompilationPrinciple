#ifndef DYARRAY_H
#define DYARRAY_H

#include <iostream>
#include <functional>

#define DEFAULT_CAP 10

template<typename T>
class DyArray
{
    private:

        T *arr;         // 数组
        int capacity;   // 数组容量
        int curSize;    // 数组当前包含元素的个数
        std::function<bool(T,T)> compareFunc;
        T *sortArr;    // 排序数组
    
    private:
        bool initArray()
        {
            arr = new T[capacity];

            return arr != nullptr;
        }

        T* createSortArr()
        {
            sortArr = new T[capacity];
            for (int i = 0; i < curSize; i++) {
                sortArr[i] = arr[i];
            }
            return sortArr;
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

        void quickSort(T *sortArr, int p, int r)
        {
            int q;

            if (p >= r) {
                return ;
            }

            q = partition(sortArr, p, r);
            quickSort(sortArr, p, q - 1);
            quickSort(sortArr, q + 1, r);
        }

        int partition(T *sortArr, int p, int r)
        {
            int i, j;

            i = j = p;

            for (; j < r; j++) {
                if (compareFunc(sortArr[j], sortArr[r])) {
                    if (i != j) {
                        std::swap(sortArr[i], sortArr[j]);
                    }
                    i++;
                }
            }

            std::swap(sortArr[i], sortArr[r]);
            return i;
        }

        static bool defaultCompare(T a, T b)
        {
            return (a < b) ? true : false;
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

        T* sort(bool (*compare)(T, T))
        {
            T *sortArr = createSortArr();
            compareFunc = compare;
            quickSort(sortArr, 0, curSize - 1);
            return sortArr;
        }

        T* sort()
        {
            T *sortArr = createSortArr();
            compareFunc = DyArray::defaultCompare;
            quickSort(sortArr, 0, curSize - 1);
            return sortArr;
        }

        T max_element(bool (*compare)(T, T))
        {
            T *sArr = sort(compare);

            return sArr[0];
        }
};

#endif