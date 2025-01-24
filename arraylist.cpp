#include "arraylist.h"

using namespace std;
void arraylist::buyalloc()
{
    int news = (alloc == 0) ? 4 : alloc * 2;
    int *tmp = (int *)realloc(arr, news);
    if (tmp == NULL)
    {
        perror("realloc failed");
        exit(1);
    }
    arr = tmp;
    alloc = news;
}
/*void arraylist::init(){
    arr = NULL;
    alloc = size = 0;
}*/
void arraylist::print()
{
    assert(arr);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void arraylist::insertback(int n)
{
    if (size == alloc)
    {
        buyalloc();
    }
    arr[size] = n;
    size++;
}
void arraylist::deletback()
{
    assert(size);
    size--;
}
void arraylist::inserthead(int n)
{
    if (size == alloc)
    {
        buyalloc();
    }
    for (int i = size; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = n;
    size++;
}
void arraylist::delethead()
{
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
int arraylist::checkdata(int n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            return i;
        }
    }
    return -1;
}
void arraylist::insertafterpos(int pos, int n)
{
    if (size == alloc)
    {
        buyalloc();
    }
    for (int i = size; i > pos + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos + 1] = n;
    size++;
}
void arraylist::deletafterpos(int pos)
{
    if (pos >= size - 1)
    {
        pos = size - 2;
    }
    if (pos >= size - 1)
    {
        pos = size - 2;
    }
    for (int i = pos + 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
void arraylist::insertbeforepos(int pos, int n)
{
    if (pos == 0)
    {
        inserthead(n);
        return;
    }
    if (pos >= size)
    {
        insertback(n);
        return;
    }
    if (size == alloc)
    {
        buyalloc();
    }
    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = n;
    size++;
}

void arraylist::deletpos(int pos)
{
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}