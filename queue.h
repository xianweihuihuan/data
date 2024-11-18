#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node
{
    int val;
    node *next;
};
class queue
{
protected:
    node *head;
    node *tail;

public:
    queue()
    {
        head = tail = nullptr;
    }
    void insert(int n);
    void delet();
    bool judgeempty();
    int obtainheaddata();
    int checkcount();
    node *buynode(int n);
    void print();
    ~queue()
    {
        if (head == nullptr)
        {
            return;
        }
        node *pcur = head;
        while (pcur != tail)
        {
            node *prev = pcur->next;
            free(pcur);
            pcur = prev;
        }
        free(tail);
        tail = head = nullptr;
    }
};