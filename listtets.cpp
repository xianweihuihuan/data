#include"list.h"

int main(){
    me::list<int> ls;
    ls.insert(ls.begin(),1);
    ls.insert(ls.begin(),1);
    ls.insert(ls.begin(),1);
    ls.insert(ls.begin(),1);
    ls.insert(ls.begin(),1);
    ls.insert(ls.begin(),1);
    ls.insert(ls.begin(),1);
    ls.erase(ls.begin());
    int i = 0;
    for(auto& tmp: ls){
        tmp+=i;
        std::cout<<tmp<<std::endl;
        i++;
    }
}