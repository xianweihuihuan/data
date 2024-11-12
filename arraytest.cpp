#include "arraylist.h"

using namespace std;
int main()
{
    arraylist arr;
    //arr.init();
    arr.insertback(1);
    arr.insertback(2);
    arr.insertback(3);
    arr.insertback(4);
    int tmp=arr.checkdata(1);
    arr.insertafterpos(tmp,5);
    arr.deletafterpos(0);
    arr.insertbeforepos(99,2);
    arr.deletpos(1);
    arr.deletpos(99);
    arr.print();
   
    return 0;
}