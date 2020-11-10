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
        bool initArray();

        bool resize();

    public:

        DyArray(int cap);

        DyArray();

        ~DyArray()
        {
            for (int i = 0; i < curSize; ++i) {
                delete arr[i];
            }

            delete [] arr;
        }

        void dump();

        bool insert(const T& value);

        const T& getIdx(int index);
};

#endif