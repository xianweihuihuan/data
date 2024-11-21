#include"Heap.h"

int main(){
    heap st1;
    st1.insert(1);
    st1.insert(7);
    st1.insert(2);
    st1.insert(4);
    st1.insert(0);
    st1.insert(78);
    st1.insert(77);
    st1.insert(56);
    st1.insert(4);
    st1.insert(55);
    st1.insert(22);
    st1.insert(99);
    heap st2 = st1;
    int n = st1.obtainsize();
    st1.print();
    st2.print();
    st2.insert(999);
    st2.insert(945);
    st2.print();
    st2.insert(6);
    st2.insert(12);
    st2.insert(10);
    st2.print();
    
}