#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <queue>
#include <vector>
#include <functional> //greater()的头文件



#if 0
#include "Stack.h"

int main()
{
	bite::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.top() = 5;
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	return 0;
}
#endif




#if 0
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;
	q.front() = 0;
	cout << q.front() << endl;

	cout << q.back() << endl;
	q.back() = 50;
	cout << q.back() << endl;

	cout << q.size() << endl;

	q.pop();
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;

	return 0;
}
#endif





#if 0
#include "Queue.h"
int main()
{
	bite::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;
	q.front() = 0;
	cout << q.front() << endl;

	cout << q.back() << endl;
	q.back() = 50;
	cout << q.back() << endl;

	cout << q.size() << endl;

	q.pop();
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;

	return 0;
}
#endif





// 优先队列（堆）
#if 0
int main()
{
	// 注意：默认按照小于进行比较，大堆
	priority_queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	q1.pop();
	cout << q1.top() << endl;


	vector<int> v{ 1, 2, 3, 4, 5 };
	priority_queue<int, vector<int>, greater<int>>  q2(v.begin(), v.end()); //小堆

	cout << q2.top() << endl;
	return 0;
}
#endif




#if 0
class Date // 自定义类型类
{
public:
	Date(int year = 1900, int month = 1, int day = 1) 
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}

	int _year;
	int _month;
	int _day;
};


void TestPriorityQueue1()
{
	Date d1(2020, 11, 12);
	Date d2(2020, 11, 11);
	Date d3(2020, 11, 13);

	priority_queue<Date> q1;
	q1.push(d1);
	q1.push(d2);
	q1.push(d3);
}


//  仿函数/函数对象---可以像函数一样使用的对象
//  原理：只需要在类中将()重载一下
//  ()称为函数调用运算符
//  作用：定制算法功能
class Greater
{
public:
	bool operator()(const Date* left, const Date* right)
	{
		return left->_day > right->_day;
	}
};

bool gg(const Date* left, const Date* right)
{
	return left->_day > right->_day;
}


int main()
{
	Date* p1 = new Date(2020, 11, 12);
	Date* p2 = new Date(2020, 11, 11);
	Date* p3 = new Date(2020, 11, 13);

	// q1不是一个堆，问题不在于传递less还是greater
	// 是因为priority_queue内部 按照指针的值 直接进行比较---直接拿地址比较
	priority_queue<Date*> q1; // 大堆
	//priority_queue<Date*, vector<Date*>, Greater> q1; // 小堆
	q1.push(p1);
	q1.push(p2);
	q1.push(p3);


	Greater g;
	g(p1, p2);    // 函数调用，g是一个对象
	gg(p1, p2);   // 函数调用，gg是一个函数名

	return 0;
}
#endif




#if 0
struct Goods
{
	Goods(const string& name, double price)
	: _name(name)
	, _price(price)
	{}

	bool operator<(const Goods& g)const
	{
		return _price < g._price;
	}

	bool operator>(const Goods& g)const
	{
		return _price > g._price;
	}

	string _name;
	double _price;
};

struct Greater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};


#include <algorithm>

int main()
{
	// 默认按照小于比较--->升序
	vector<int> v{ 2, 5, 0, 8, 1, 7, 6, 4, 3, 9 };
	sort(v.begin(), v.end());

	// 按照greater进行比较--->降序
	//greater<int>()创建一个greater<int>类型的匿名对象
	sort(v.begin(), v.end(), greater<int>());


	Goods gs[] = { { "apple", 2.5 }, { "banana", 1.8 }, { "orange", 3.2 } };

	sort(gs, gs + sizeof(gs) / sizeof(gs[0])); //升序
	//sort(gs, gs + sizeof(gs) / sizeof(gs[0]), greater<Goods>());
	sort(gs, gs + sizeof(gs) / sizeof(gs[0]), Greater()); //降序

	return 0;
}
#endif




#if 1
#include "PriorityQueue.h"

int main()
{
	vector<int> v{ 3, 2, 5, 1, 4 };
	bite::priority_queue<int> q1{ v.begin(), v.end() };
	q1.push(0);
	bite::priority_queue<int, vector<int>, greater<int>> q2{ v.begin(), v.end() };
	q2.push(0);
	return 0;
}
#endif