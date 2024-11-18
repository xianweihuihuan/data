#include "queue.h"

using namespace std;
int main()
{
    queue st1;
    st1.insert(1);
    st1.insert(2);
    st1.insert(3);
    st1.insert(4);
    st1.insert(5);
    st1.insert(6);
    st1.print();
    st1.delet();
    st1.print();
    st1.delet();
    st1.print();
    st1.delet();
    st1.print();
    int i = st1.obtainheaddata();
    cout << i << endl;
    int k = st1.checkcount();
    cout << k << endl;
    st1.delet();
    st1.delet();
    st1.delet();
    st1.print();
    if (st1.judgeempty())
    {
        cout << "This queue is already empty" << endl;
    }
    st1.insert(555);
    st1.print();
    if (!(st1.judgeempty()))
    {
        cout << "This queue hasn't empty" << endl;
    }
}