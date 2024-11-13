#include "stack.h"

using namespace std;
void stack::buyalloc()
{
    int newn = (alloc == 0) ? 4 : alloc * 2;
    int *tmp = (int *)realloc(arr, newn);
    if (tmp == nullptr)
    {
        perror("realloc failed");
        exit(1);
    }
    arr = tmp;
    alloc = newn;
}

void stack::push(int n)
{
    if (alloc == top)
    {
        buyalloc();
    }
    arr[top++] = n;
}

int stack::obtaintop()
{
    assert(top > 0);
    return arr[top - 1];
}

bool stack::emptystack()
{
    if (top == 0)
    {
        return true;
    }
    return false;
}

void stack::pop()
{
    assert(top > 0);
    top--;
}

void stack::print()
{
    for (int i = 0; i < top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}