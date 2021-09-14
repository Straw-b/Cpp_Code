#include <iostream>
using namespace std;
#include <vector>
#include <list>


#if 0
void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);
	for (auto e : L2)
		cout << e << " ";
	cout << endl;

	// �����������������
	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> L3(v.begin(), v.end());
	list<int>::iterator it = L3.begin();
	while (it != L3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ���÷������������
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

int main()
{
	TestList1();
	return 0;
}
#endif




#if 0
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

int main()
{
	TestList2();
	return 0;
}
#endif




#if 0
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
	L.sort(); //Ĭ������
	// ע�⣺��ʹ��unique��list���ظ�������ȥ��ʱ��������
	L.unique(); // ȥ�������ظ���

	L.sort(Greater); // ����
	L.sort(Lesser); // ����
}

int main()
{
	TestList3();
	return 0;
}
#endif




#if 0
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
	L1.merge(L2); // �鲢��L1

	L1.reverse(); // ����

	L1.remove(3); // ɾ��3

	L1.remove_if(IsEven); // ����ʲô������Ȼ��ɾ��
}

int main()
{
	TestList4();
	return 0;
}
#endif




#if 0
// erase / pop_back �������������һ���ڵ��ʧЧ��
// pop_front ���������ڵ�һ���ڵ��ʧЧ��
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
		it = L.erase(it); //���¸�ֵ
		//++it;
	}
	return 0;
}
#endif




#if 1
#include "List.h"

int main()
{
	TestMyList1();
	return 0;
}
#endif