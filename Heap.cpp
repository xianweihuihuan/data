#include"Heap.h"

void swap(int&a,int&b){
    int tmp = a;
    a = b;
    b = tmp;
}
void heap::_realloc(){
    int newn = 2*alloc;
    int* tmp = (int*)realloc(arr,newn*sizeof(int));
    if(tmp==nullptr){
        perror("realloc failed");
        exit(1);
    }
    arr = tmp;
    alloc = newn;
}

bool heap::empty()const{
    return len==0;
}

void heap::adjustup(int kid){
    int parent = (kid-1)/2;
    while(kid>0){
        if(arr[kid]<arr[parent]){//此处为小堆，大堆应为>
            swap(arr[kid],arr[parent]);
            kid = parent;
            parent = (kid-1)/2;
        }else{
            break;
        }
    }
}
void heap::adjustdown(int parent){
    int kid = 2*parent+1;
    while(kid<len){
        if(kid+1<len&&arr[kid]>arr[kid+1]){
            kid++;
        }
        if(arr[parent]>arr[kid]){
            swap(arr[parent],arr[kid]);
            parent = kid;
            kid = parent*2+1;
        }else{
            break;
        }
    }
}

void heap::insert(int n){
    if(len==alloc){
        _realloc();
    }
    arr[len] = n;
    adjustup(len);
    len++; 
}

void heap::delet(){
    swap(arr[0],arr[len-1]);
    len--;
    adjustdown(0);
}

int heap::obtaintop()const{
    return arr[0];
}
int heap::obtainsize()const{
    return len;
}

void heap::print()const{
    for(int i =0;i<len;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}