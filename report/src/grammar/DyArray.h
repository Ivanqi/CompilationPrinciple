#ifndef DYARRAY_H
#define DYARRAY_H

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

        void reSize();

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

        void insert(int index, T e);

        void push_back(T e)
        {
            insert(curSize, e);
        }

        T& operator[](int i) {
		    return arr[i];
	    }

        int get(int index);

        void set(int index, T e);

        bool contains(T e);

        //删除并返回
        T remove(int index);

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

        void toString();
};

#endif