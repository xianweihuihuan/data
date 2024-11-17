#pragma once
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

struct node{
    int val;
    node*next;
};

class linklist{
protected:
    node*head;
    node*tail;
public:
    linklist(){
        head = nullptr;
        tail = nullptr;
    }
    node* buynode(int n);
    void pushback(int n );
    void pushhead(int n );  
    void deletback();
    void delethead();
    int finddata(int n );
    void print();
    void deletpos(int pos);
    void pushafterpos(int pos,int n);
    void pushbeforepos(int pos,int n);
    int checkdatapos(int pos);
};