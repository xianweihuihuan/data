#include "stack.h"

using namespace std;
int main()
{
    stack st1;
    if (st1.emptystack())
    {
        cout << "null" << endl;
    }
    st1.push(1);
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.print();
    int top = st1.obtaintop();
    cout << top << endl;
    st1.pop();
    st1.print();
    st1.push(9999);
    st1.print();
    st1.pop();
    st1.pop();
    st1.pop();
    st1.pop();
    st1.print();
    st1.push(645456);
    st1.print();
    if (st1.emptystack())
    {
        cout << "error" << endl;
    }
}