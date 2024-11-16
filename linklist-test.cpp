#include"linklist.h"

using namespace std;
int main(){
    linklist st1;
    st1.pushback(1);
    st1.pushback(2);
    st1.pushback(3);
    st1.pushback(4);
    st1.print();
    st1.pushhead(10);
    st1.pushhead(11);
    st1.pushhead(12);
    st1.pushhead(13);
    st1.print();
    st1.delethead();
    st1.delethead();
    st1.delethead();
    st1.print();
    st1.deletback();
    st1.deletback();
    st1.deletback();
    st1.print();
    st1.deletback();
    st1.deletback();
    st1.print();
    st1.pushback(1);
    st1.pushback(3);
    st1.pushback(5);
    st1.pushback(99);
    st1.pushback(4);
    int i = st1.finddata(99);
    cout<<i<<endl;
    int j = st1.finddata(3);
    cout<<j<<endl;
    st1.deletpos(j);
    st1.print();

    int k = st1.finddata(4);
    cout<<k<<endl;
    st1.deletpos(k);
    st1.print();
}