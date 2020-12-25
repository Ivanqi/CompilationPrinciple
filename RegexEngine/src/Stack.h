#ifndef STACK_H
#define STACK_H

#include <list>

template<typename T, class L = std::list<T>>
class Stack 
{
    private:
        L lt;

    public:
        typedef typename L::iterator iterator;
        typedef typename L::reverse_iterator reverse_iterator;
        iterator begin()
        {
            return lt.begin();    
        }

        iterator end()
        {
            return lt.end();
        }

        reverse_iterator rbegin()
        {
            return lt.rbegin();
        }

        reverse_iterator rend()
        {
            return lt.rend();
        }

        void push(const T& value)
        {
            lt.push_front(value);
        }

        void push_back(const T& value)
        {
            lt.push_back(value);
        }

        void pop()
        {
            lt.pop_front();
        }

        void pop_back()
        {
            lt.pop_back();
        }

        T top()
        {
            return lt.front();
        }

        T back()
        {
            return lt.back();
        }

        int size()
        {
            return lt.size();
        }
};
#endif