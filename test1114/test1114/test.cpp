#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <queue>
#include <vector>



#if 0
#include "PriorityQueue.h"
#include <functional> //greater()的头文件

class Greater // 类型
{
public:
	bool operator()(int left, int right)
	{
		return left > right;
	}
};


bool compare(int left, int right)
{
	return left > right;
}

typedef bool (*CMP) (int left, int right); // 函数指针的类型


#include <stack>
#include <vector>

int main()
{
	stack<int, vector<int>> s; // 默认用deque，可以改成vector

	vector<int> v{ 3, 2, 5, 1, 4 };
	bite::priority_queue<int> q1{ v.begin(), v.end() };
	q1.push(0);

	//bite::priority_queue<int, vector<int>, greater<int>> q2{ v.begin(), v.end() };
	bite::priority_queue<int, vector<int>, CMP> q2{ v.begin(), v.end(), compare }; // 传函数指针
	q2.push(0);

	bite::priority_queue<int, vector<int>, Greater> q3{ v.begin(), v.end() }; // 仿函数对象
	q3.push(0);

	return 0;
}
#endif





#if 0
size_t g_a = 10;
size_t g_b = 20;

namespace bite
{
	// T : 类型参数
	// N : 非类型参数，具有const属性-->是一个常量
	template<class T, size_t N = 10>
	// template<class T, size_t N = g_a + g_b> // 错误，未在编译期确认结果
	class array // 数组
	{
	public:
		array()
			: _size(0)
		{
			//N = 10;
		}

		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < _size);
			return _array[index];
		}

		size_t size()const
		{
			return _size;
		}

		bool empty()const
		{
			return 0 == _size;
		}

	private:
		T _array[N];
		size_t _size;
	};
}

int main()
{
	bite::array<int> a1;
	return 0;
}
#endif




// 函数模板可能对于某些特殊类型不能处理，或者处理的逻辑是有问题的
// 因此：需要将该模板针对于该种类型来进行特殊处理
// 特化

// 如果要对模板进行特化：
// 1. 先要有模板的代码
// 2. 该份模板类型的代码对于那种类型不能处理
// 3. 用该类型去特化该模板

#if 1
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

// 专门针对的是char*，特化
//template<>
//const char*& Max<const char*&>(const char*& left, const char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return left;
//
//	return right;
//}

// 将该函数直接给出
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

int main()
{
	cout << Max(10, 20) << endl;
	cout << Max(1.2, 3.4) << endl;

	const char* p1 = "hello";
	const char* p2 = "World";
	cout << Max(p1, p2) << endl;
	return 0;
}
#endif