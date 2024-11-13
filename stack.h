#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

class stack
{
public:
    stack()
    {
        arr = nullptr;
        alloc = top = 0;
    }
    void buyalloc();
    void push(int n);
    void pop();
    int obtaintop();
    bool emptystack();
    void print();
    ~stack()
    {
        free(arr);
        arr = nullptr;
        alloc = top = 0;
    }

protected:
    int *arr;
    int top;
    int alloc;
};