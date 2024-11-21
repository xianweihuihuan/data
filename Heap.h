#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

using namespace std;
class heap{
public:
    heap(int n=4)
    :alloc(4)
    ,len(0)
    ,arr(nullptr)
    {
        int*tmp = (int*)malloc(n*sizeof(int));
        if(tmp == nullptr){
            perror("malloc failed");
            alloc = 0;
            exit(1);
        }
        arr = tmp;
    }
    heap(const heap&n){
        int* tmp = (int*)malloc(sizeof(int)*n.alloc);
        if(tmp==nullptr){
            perror("malloc failed");
            exit(1);
        }
        arr = tmp;
        alloc = n.alloc;
        memcpy(arr,n.arr,4*n.len);
        len = n.len;
    }
    void insert(int n );
    void adjustup(int kid);
    void _realloc();
    void adjustdown(int parent);
    void delet();
    bool empty()const;
    int obtaintop()const;
    int obtainsize()const;
    void print()const;
    ~heap(){
        free(arr);
        alloc = len =0;
        arr = nullptr;
    }
    int* operator&(){
        return arr;
    }
protected:
    int* arr;
    int alloc ;
    int len;
};