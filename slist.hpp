#include <iostream>

class my_list
{
public:
    my_list()
        : _head(0), _id(0), _size(0)
    {
    }

    void push_front(int x)
    {
        _id++;
        _value[_id] = x;
        _next[_id] = _next[_head];
        _next[_head] = _id;
        _size++;
    }

    void print()
    {
        for (int i = _next[_head]; i != 0; i = _next[i])
        {
            std::cout << _value[i] << "->";
        }

        std::cout << "end" << std::endl;
    }

    int find(int x)
    {
        for (int i = _next[_head]; i; i = _next[i])
        {
            if (_value[i] == x)
            {
                return i;
            }
        }
        return 0;
    }

    void insert(int pos, int x)
    {
        if (pos < 0)
        {
            return;
        }
        else if (pos == 0)
        {
            push_front(x);
            return;
        }
        if (pos > _size)
        {
            pos = _size;
        }
        int pp = 0;
        for (int i = 0; i < pos; i++)
        {
            pp = _next[pp];
        }
        _id++;
        _value[_id] = x;
        _next[_id] = _next[pp];
        _next[pp] = _id;
        _size++;
    }

    void erase(int pos)
    {
        if (pos < 0)
        {
            return;
        }
        int ppos = 0;
        if (pos >= _size)
        {
            pos = _size - 1;
        }
        for (int i = 0; i < pos; i++)
        {
            ppos = _next[ppos];
        }
        _next[ppos] = _next[_next[ppos]];
        _size--;
    }
    
    bool empty()
    {
        return _size == 0;
    }

private:
    int _value[1000] = {0};
    int _next[1000] = {0};
    int _head;
    int _id;
    int _size;
};