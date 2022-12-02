#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <stdio.h>
class OopClosure;

template<typename T>
class ArrayList {
    private:
        int _length; // 元素数组大小
        T* _array; // 元素数组指针 
        int _size; // 有效元素

        void expand();
    
    public:
        ArrayList(int n = 8);

        void add(T t);
        void insert(int index, T t);
        T get(int index);
        void set(int index, T t);
        int size();
        int length();
        int index(T t);
        T* value() { return _array;}
        T pop();
        void delete_index(int index);

        void* operator new(size_t size);

        void oops_do(OopClosure* closure); 
};

class HiObject;
typename ArrayList<HiObject*>* ObjList;

#endif