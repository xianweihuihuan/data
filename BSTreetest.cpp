#include"BSTree.h"

int main(){
    me::BSTree<int> s1;
    for(int j = 0;j<10;j++){
        s1.insert(j);
    }
    s1.Print();
    for(int j = 0;j<10;j++){
        s1.earse(j);
        s1.Print();
    }
}