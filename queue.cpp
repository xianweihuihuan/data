#include "queue.h"

using namespace std;

node *queue::buynode(int n)
{
    node *tmp = (node *)malloc(sizeof(node));
    if (tmp == nullptr)
    {
        perror("malloc failed");
        exit(1);
    }
    tmp->val = n;
    tmp->next = nullptr;
    return tmp;
}

void queue::insert(int n)
{
    node *tmp = buynode(n);
    if (head == nullptr)
    {
        head = tail = tmp;
        return;
    }
    tail->next = tmp;
    tail = tmp;
}
void queue::delet()
{
    assert(head);
    if (tail == head)
    {
        free(head);
        head = tail = nullptr;
        return;
    }
    node *pcur = head->next;
    free(head);
    head = pcur;
}
bool queue::judgeempty()
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}
int queue::obtainheaddata()
{
    assert(head);
    return head->val;
}

int queue::checkcount()
{
    if (head == nullptr)
    {
        return 0;
    }
    int i = 1;
    node *pcur = head;
    while (pcur != tail)
    {
        i++;
        pcur = pcur->next;
    }
    return i;
}
void queue::print()
{
    node *pcur = head;
    while (pcur != nullptr)
    {
        cout << pcur->val << "->";
        pcur = pcur->next;
    }
    cout << "nullptr" << endl;
}