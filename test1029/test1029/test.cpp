#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <string>


void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << "";
		++it;
	}
	cout << endl;

	string s("hello");
	vector<char> v4(s.begin(), s.end());

	vector<int> v5(v3);
	// vector<int>::reverse_iterator rit = v5.rbegin();
	auto rit = v5.rbegin();
	while (rit != v5.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<int> v6{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// e是对v6中每个元素的引用
	for (auto& e : v6)
		e *= 2;

	// e是v6中每个元素的一份拷贝
	// 注意：范围for的原理与采用正向迭代器的原理是完全相同的
	for (auto e : v6)
		cout << e << " ";
	cout << endl;
}


void TestVector2()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	if (v.empty())
	{
		cout << "v empty" << endl;
	}
	else
	{
		cout << "v not empty" << endl;
	}

	// 该方法只是将有效元素清空，并不会影响底层空间总的大小
	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


class A
{
public: 
	A(int a = 10) // 构造函数
 		: _a(a)
	{}

	A(const A& a) // 拷贝构造函数
		: _a(a._a)
	{
		cout << "A(const A& a)" << endl;
	}

private:
	int _a;
};

void TestVector3()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.resize(5);

	v.resize(7, 100);

	v.resize(9);

	v.resize(20, 50);

	vector<int> v1(10);
	vector<A> v2(10); // 调用无参或者全缺省的构造函数
}


void TestVector4()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.reserve(5);
	v.reserve(30);
	v.reserve(25);
	v.reserve(40);
}


void TestVector5()
{
	vector<int> v{ 1, 2, 3 };
	cout << v.front() << endl;
	cout << v.back() << endl;

	v.clear();

	// 注意：使用front和back访问vector中元素时，vector一定不能为空
	cout << v.front() << endl;
	cout << v.back() << endl;
}


// 内置类型元素的插入
void TestVector6()
{
	// 注意：push_back和insert在插入元素期间，可能需要扩容
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.pop_back(); // 尾删

	
	v.insert(v.begin(), 0);

	// 需求在元素2的位置插入10个值为5的元素
	v.insert(find(v.begin(), v.end(), 2), 10, 5);

	//将数组array中的元素插入到v的尾部
	int array[] = { 4, 5, 6, 7 };
	v.insert(v.end(), array, array + sizeof(array) / sizeof(array[0]));
}


// 插入自定义类型的元素：最终插入的是一份拷贝
void TestVector7()
{
	A a;
	vector<A> v;
	v.reserve(10);
	v.push_back(a);
	v.push_back(a);
}


void TestVector8()
{
	size_t sz;
	std::vector<int> foo;
	// foo.reserve(100);
	sz = foo.capacity();
	std::cout << "扩容机制:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i); // 插入期间需要扩容
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}


void TestVector9()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 3);
	//v.erase(v.begin(), v.end()); // v.clear();

	auto it = v.begin();
	while (it != v.end())
	{
		v.erase(it);
		it++;
	}
}


void TestVector10()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 4, 5, 6, 7, 8, 9 };

	// it1指向v1原来空间的起始位置
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	// v1底层的空间已经发生改变
	v1.swap(v2);

	// 没有失效
	cout << *it1 << endl;
	cout << *it2 << endl;

	it1 = v1.begin(); // 给迭代器重新赋值，否则迭代器会失效
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}


void TestVector11()
{
	vector<int> v{ 1, 2, 3 };
	auto it = v.begin(); // 迭代器

	//v.clear();
	//cout << *it << endl;

	while (it != v.end())
	{
		it = v.erase(it); // 接收erase的返回值
		// it++;  因为erase之后，it迭代器失效了
	}

	//cout << *it << endl;
}


void TestVector12()
{
	//vector<vector<int>> vv;
	//vector<int> v(5, 10);
	//for (size_t i = 0; i < 4; ++i)
	//    vv.push_back(v);
	
	vector<vector<int>> vv(4, vector<int>(5, 10));
}


// 杨辉三角
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

void TestVector13(size_t n)
{
	vector<vector<int>> vv;
	vv.resize(n);
	for (size_t i = 0; i < n; i++) // 先构造全为1的三角
	{
		vv[i].resize(i + 1, 1);
	}

	for (size_t i = 2; i < vv.size(); ++i)
	{
		for (size_t j = 1; j < vv[i].size() - 1; ++j) // 对于每一行
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
}


int main()
{
	//TestVector12();
	TestVector13(4);
	return 0;
}
