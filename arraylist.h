#include<iostream>
#include<stdlib.h>
#include<assert.h>

class arraylist{
protected:
    int * arr;
    int size;
    int alloc;
public:
    arraylist(){
        arr=NULL;
        size = alloc=0;
    }
    void buyalloc();
    //void init();
    void print();
    void insertback(int n);
    void deletback();
    void inserthead(int n);
    void delethead();
    int checkdata(int n);
    void insertafterpos(int pos,int n);
    void deletafterpos(int pos);
    void deletpos(int pos);
    void insertbeforepos(int pos,int n);
    ~arraylist(){
        arr = NULL;
        size = alloc = 0;
    }
};