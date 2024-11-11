#include <stdlib.h>
typedef struct stack
{
    int *arr;
    int size;
    int neicun;
} stack;

void kuorong(stack *a)
{
    int new = (a->neicun == 0) ? 4 : 2 * a->neicun;
    a->arr = (stack *)realloc(a->arr, sizeof(int) * new);
    a->neicun = new;
}
void chushihua(stack *a)
{
    a->neicun = 0;
    a->size = 0;
    a->arr = NULL;
}
void stackpush(stack *a, int x)
{
    if (a->size == a->neicun)
    {
        kuorong(a);
    }
    a->arr[a->size] = x;
    a->size++;
}
void stackpup(stack *a)
{
    a->size--;
}