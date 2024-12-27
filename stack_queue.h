#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

namespace me
{
    template <class T, class al = std::vector<T>>
    class stack
    {
    private:
        al _data;

    public:
        void push(const T &x)
        {
            _data.push_back(x);
        }
        void pop(){
            _data.pop_back();
        }
        T top(){
            return _data[_data.size()-1];
        }
        size_t size(){
            return _data.size();
        }
        bool empty(){
            return _data.empty();
        }
    };
    template <class T, class al = std::vector<T>>
    class queue{
    private:
        al _data;
    public:
        void push(const T& x){
            _data.push_back(x);
        }
        void pop(){
            _data.erase(_data.begin());
        }
        T top(){
            return _data[0];
        }
        bool empty(){
            return _data.empty();
        }
        size_t size(){
            return _data.size();
        }
    };
}