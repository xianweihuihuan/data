#include <iostream>
#include <string>
#include <functional>

template <class T>
class shared_ptr
{
public:
    shared_ptr(T *ptr)
        : _ptr(ptr), _count(new int(1)), _del([](T *ptr)
                                              { delete ptr; })
    {
    }

    template <class D>
    shared_ptr(T *ptr, D del)
        : _ptr(ptr), _count(new int(1)), _del(del)
    {
    }

    void release()
    {
        if (--(*_count) == 0)
        {
            _del(_ptr);
            delete _count;
            _ptr = nullptr;
            _count = nullptr;
        }
    }

    ~shared_ptr()
    {
        release();
        std::cout<<"~shared_ptr"<<std::endl;
    }

    shared_ptr<T> &operator=(const shared_ptr<T> &sp)
    {
        if (this != &sp)
        {
            release();
            _ptr = sp._ptr;
            _count = sp._count;
            _del = sp._del;
            ++(*_count);
        }
        return *this;
    }

    shared_ptr(const shared_ptr<T> &sp)
        : _ptr(sp._ptr), _count(sp._count), _del(sp._del)
    {
        (*_count)++;
    }

    T &operator*()
    {
        return *_ptr;
    }

    T *operator->()
    {
        return _ptr;
    }

    T *get() const
    {
        return _ptr;
    }

    int use_count() const
    {
        return *_count;
    }

    operator bool()
    {
        return _ptr != nullptr;
    }

protected:
    T *_ptr;
    int *_count;
    std::function<void(T *)> _del;
};