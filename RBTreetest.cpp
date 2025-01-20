#include "RBTree.h"

using namespace std;
void TestRBTree1()
{
    RBTree<int, int> t;
    int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    for (auto e : a)
    {
        pair<int, int> tmp(e, e);

        t.insert(tmp);
        cout << "Insert:" << e << "->";
        // cout << t.IsBalanceTree() << endl;
    }
    t.Print();
}

void TestRBTree2()
{
    RBTree<int, int> t;
    int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    for (auto e : a)
    {
        pair<int, int> tmp(e, e);

        t.insert(tmp);
        cout << "Insert:" << e << "->";
        // cout << t.IsBalanceTree() << endl;
    }
    t.Print();
}
int main()
{
    TestRBTree1();
    cout << endl;
    TestRBTree2();
    cout << endl;
}