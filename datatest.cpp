#include "data.h"
using namespace std;
int main()
{
    data1 st1(2038, 7, 28);
    data1 st2 = st1 - 5000;
    st1.print();
    st2.print();
    st2 += 10;
    st2.print();
    st2 += 5000;
    st2.print();
    if (st1 != st2)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    data1 st3 = st2++;
    st3.print();
    st2.print();
    data1 st4 = ++st2;
    st4.print();
    st2.print();
    data1 st6(2024, 11, 18);
    st6.print();
    data1 st7 = st6 + 5000;
    st7.print();
    int i = st7 - st6;
    cout << i << endl;
    st7--;
    st7.print();
    data1 st8 = --st7;
    cout << st8 - st7 << endl;
}