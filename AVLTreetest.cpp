#include"AVLTree.h"
#include<iostream>

using namespace std;
void TestAVLTree1()
{
	AVLTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };//不需要双旋的数组
	for (auto e : a)
	{
		pair<int,int> tmp(e,e);
        t.insert(tmp);
		cout << "Insert:" << e<<"->";
	}
	t.Print();
}
void TestAVLTree2()
{
	AVLTree<int, int> t;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };//需要双旋的数组
	for (auto e : a)
	{
		pair<int,int> tmp(e,e);
        t.insert(tmp);
		cout << "Insert:" << e<<"->";
	}
	t.Print();
}


int main()
{
    TestAVLTree1();
    cout<<endl;
    TestAVLTree2();
    cout<<endl;
}