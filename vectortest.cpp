#include"vector.h"

using namespace me;
int main(){
    vector<int> st1;
    st1.push_back(1);
    st1.push_back(1);
    st1.push_back(2);
    st1.push_back(3);
    st1.push_back(4);
    st1.insert(st1.begin(),90);
    st1.insert(st1.begin(),90);
    st1.insert(st1.begin(),90);
    st1.insert(st1.begin(),90);
    st1.insert(st1.begin(),90);
    st1.insert(st1.begin(),90);
    for(auto i : st1){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    vector<std::string> st2;
    st2.push_back("dwadaw");
    st2.push_back("dwadaw");
    st2.push_back("dwadaw");
    st2.push_back("dwadaw");
    st2.push_back("dwadaw");
    for(auto i: st2){
        std::cout<<i<<" ";
    }
}