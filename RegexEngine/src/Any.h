#ifndef ANY_H
#define ANY_H

#include <type_traits>
#include <utility>
#include <typeinfo>
#include <iostream>

template <class T> 
    using StorageType = typename std::decay<T>::type;

struct Any
{
    private:
        struct Base
        {
            virtual ~Base()
            {

            };

            virtual Base* clone() const = 0;
        };

        template <typename T>
        struct Derived: Base
        {
            public:
                template <typename U> Derived(U&& value_): value(std::forward<U>(value_))
                {
                }

                T value;

                Base *clone() const
                {
                    return clone<>();
                }
            
            private:
                template <int N = 0, typename std::enable_if < N == N && std::is_nothrow_copy_constructible<T>::value, int>::type = 0>
                Base *clone() const 
                {
                    return new Derived<T>(value);
                }

                template<int N = 0, typename std::enable_if<N == N && !std::is_nothrow_copy_constructible<T>::value, int>::type = 0>
                Base *clone() const
                {
                    return nullptr;
                }
        };

        Base *clone() const
        {
            if (_ptr) {
                return _ptr->clone();
            } else {
                return nullptr;
            }
        }

        template <class U>
        Derived<StorageType<U>> *getDerived(bool checkCast) const
        {
            typedef StorageType<U> T;

            auto derived = dynamic_cast<Derived<T>*>(_ptr);

            if (checkCast && !derived) {
                throw std::bad_cast();
            }

            return derived;
        }

        Base *_ptr;

    public:
        bool isNull() const
        {
            return _ptr == nullptr;
        }

        bool isNotNULL() const
        {
            return _ptr != nullptr;
        }

        Any() : _ptr(nullptr)
        {
        }

        Any(Any& that): _ptr(that.clone())
        {
        }

        Any(Any&& that): _ptr(that._ptr)
        {
            that._ptr = nullptr;
        }

        Any(const Any& that): _ptr(that.clone())
        {
        }

        Any(const Any&& that): _ptr(that.clone())
        {
        }

        // 右值
        template<typename U>
        Any(U&& value): _ptr(new Derived<StorageType<U>>(std::forward<U>(value)))
        {
        }

        template<class U>
        bool is () const
        {
            auto derived = getDerived<U>(false);

            return derived != nullptr;
        }

        template <class U>
        StorageType<U>& as() 
        {
            auto derived = getDerived<U>(true);

            return derived->value;
        }

        template <class U>
        const StorageType<U>& as() const
        {
            auto derived = getDerived<U>(true);

            return derived->value;
        }

        template <class U>
        operator U ()
        {
            return as<StorageType<U>>();
        }

        template <class U>
        operator const U() const
        {
            return as<const StorageType<U>>();
        }

        Any& operator = (const Any& a)
        {
            if (_ptr == a._ptr) {
                return *this;
            }

            auto old_ptr = _ptr;
            _ptr = a.clone();

            if (old_ptr) {
                delete old_ptr;
            }

            return *this;
        }

        Any& operator = (Any&& a)
        {
            if (_ptr == a._ptr) {
                return *this;
            }

            std::swap(_ptr, a._ptr);

            return *this;
        }

        virtual ~Any();

        virtual bool equals (Any other) const
        {
            return _ptr == other._ptr;
        }
};

template<> inline
Any::Any(std::nullptr_t&& ) : _ptr(nullptr) 
{
}

Any::~Any()
{
    delete _ptr;
}

#endif