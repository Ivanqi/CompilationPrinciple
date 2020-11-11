#ifndef DYARRAY_H
#define DYARRAY_H

#define DEFAULT_CAP 10

template<typename T>
class DyArray
{
    private:

        struct DArr
        {
            T *arr;
        };

        DArr **arr;     // 数组
        int capacity;   // 数组容量
        int curSize;    // 数组当前包含元素的个数

    private:
        bool initArray()
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

        bool resize();

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
            for (int i = 0; i < curSize; ++i) {
                delete arr[i];
            }

            delete [] arr;
        }

        void dump();

        bool insert(const T value)
        {
            if (curSize > capacity) {
                resize();
            }

            int hole = curSize++;
            arr[hole] = value;
            return true;
        }

        const T getIdx(int index)
        {
            if (index > curSize) {
                return nullptr;
            }

            return arr[index];
        }
};

template<typename T>
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

#endif