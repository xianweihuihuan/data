#include"priority_queue.h"


int main(){
    me::priority_queue<int> st1;
    int m = 0;
    srand((unsigned)time(NULL));
    m = rand();
    st1.push(m);
    m = rand();
    st1.push(m);
    m = rand();
    st1.push(m);
    m = rand();
    st1.push(m);
    m = rand();
    st1.push(m);
    m = rand();
    st1.push(m);
    m = rand();
    st1.push(m);
    while(!st1.empty()){
        std::cout<<st1.top()<<std::endl;
        st1.pop();
    }
}