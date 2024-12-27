#include"stack_queue.h"

int main(){
    me::queue<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    while(!st1.empty()){
        std::cout<<st1.top()<<std::endl;
        st1.pop();
    }
    std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
    me::stack<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    while(!st2.empty()){
        std::cout<<st2.top()<<std::endl;
        st2.pop();
    }
}