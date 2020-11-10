#include <iostream>
using namespace std;

#include <list>
#include <vector>



#if 0

void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);
	for (auto e : L2)
		cout << e << " ";
	cout << endl;

	// 采用正向迭代器遍历
	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> L3(v.begin(), v.end());
	list<int>::iterator it = L3.begin();
	while (it != L3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 采用反向迭代器遍历
	list<int> L4(L3);
	// list<int>::reverse_iterator rit = L4.rbegin();
	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> L5{ 1, 2, 3, 4, 5 };
}

void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	cout << L.front() << endl;
	cout << L.back() << endl;
	cout << L.size() << endl;

	L.push_front(0);
	cout << L.front() << endl;

	L.pop_back();
	L.pop_front();
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.insert(find(L.begin(), L.end(), 3), 5);

	L.erase(find(L.begin(), L.end(), 5));

	L.erase(L.begin(), L.end());
}

bool Greater(int left, int right)
{
	return left > right;
}

bool Lesser(int left, int right)
{
	return left < right;
}

void TestList3()
{
	list<int> L{ 2, 5, 3, 7, 1, 1, 3, 7, 6, 2, 5 };
	L.sort();
	// 注意：在使用unique对list中重复的数字去重时，先排序
	L.unique(); // 去除相邻重复的

	L.sort(Greater); // 降序
	L.sort(Lesser); // 升序
}

bool IsEven(int data)
{
	return 0 == data % 2;
}

void TestList4()
{
	list<int> L1{ 2, 5, 3, 7 };
	list<int> L2{ 4, 9, 6, 1, 0 };

	L1.sort();
	L2.sort();
	L1.merge(L2); // 归并到L1

	L1.reverse(); // 逆置

	L1.remove(3); // 删除3

	L1.remove_if(IsEven); // 满足什么条件，然后删除
}

int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	TestList4();

	return 0;
}
#endif




#if 0
// erase / pop_back （迭代器在最后一个节点会失效）
// pop_front （迭代器在第一个节点会失效）
// clear() 
int main()
{
	list<int> L{ 1, 2, 3, 4, 5 };
	auto it = L.begin();
	//L.pop_back();
	L.pop_front();
	cout << *it << endl;
	while (it != L.end())
	{
		it = L.erase(it);
		//++it;
	}
	return 0;
}
#endif




#include "List.h"

int main()
{
	TestMyList1();
	return 0;
}