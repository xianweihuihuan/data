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

void TestAVLTree3()
{
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}

	size_t begin2 = clock();
	AVLTree<int, int> t;
	for (auto e : v)
	{
		pair<int,int> tmp(e,e);
		t.insert(tmp);
	}
	size_t end2 = clock();

	cout << t.ISAVLTree() << endl;

	cout << "Insert:" << end2 - begin2 << endl;
	cout << "Height:" << t.Height() << endl;
	cout << "Size:" << t.Size() << endl;

	size_t begin1 = clock();
	for (size_t i = 0; i < N; i++)
	{
		t.Find((rand() + i));
	}

	size_t end1 = clock();
	cout << "Find:" << end1 - begin1 << endl;
}
int main()
{
    TestAVLTree1();
    cout<<endl;
    TestAVLTree2();
    cout<<endl;
	TestAVLTree3();
}