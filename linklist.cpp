#include "linklist.h"

using namespace std;
node *linklist::buynode(int n)
{
    node *tmp = (node *)malloc(sizeof(node));
    if (tmp == nullptr)
    {
        perror("malloc failed");
        exit(1);
    }
    tmp->val = n;
    tmp->next =nullptr;
    return tmp;
}
void linklist::pushback(int n)
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
void linklist::pushhead(int n)
{
    node *tmp = buynode(n);
    if (head == nullptr)
    {
        head = tail = tmp;
        return;
    }
    tmp->next = head;
    head = tmp;
}
void linklist::delethead()
{
    assert(head);
    node *pcur = head->next;
    free(head);
    head = pcur;
}
void linklist::deletback()
{
    assert(head);
    if (head == tail)
    {
        free(tail);
        head = tail = nullptr;
        return;
    }
    node *pcur = head;
    while (pcur->next->next != nullptr)
    {
        pcur = pcur->next;
    }
    free(tail);
    tail = pcur;
    tail->next =nullptr;
}
int linklist::finddata(int n)
{
    assert(head);
    int sz = 0;
    node *pcur = head;
    while (pcur->val != n && pcur != nullptr)
    {
        sz++;
        pcur = pcur->next;
    }
    if (pcur == nullptr)
    {
        return -1;
    }
    return sz;
}
void linklist::print()
{   
    if(tail==NULL){
        cout<<"nuulptr"<<endl;
        return;
    }
    node*pcur = head;
    while(pcur!=tail){
        cout<<pcur->val<<"->";
        pcur=pcur->next;
    }
    cout<<pcur->val<<"->";
    cout<<"nullptr"<<endl;
}
void linklist::deletpos(int pos){
    if(pos==0){
        this->delethead();
    }
    int  i = pos;
    node*pcur = head;
    node*prev = nullptr;
    while(i--){
        prev =pcur;
        pcur= pcur->next;
    }
    prev->next = pcur->next;
    free(pcur);
    pcur = nullptr;
}