#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <list>
#include <vector>




#if 0
// 迭代器失效
// erase / pop_back （迭代器在最后一个节点会失效）
// pop_front （迭代器在第一个节点会失效）
// clear() 
int main()
{
	list<int> L{ 1, 2, 3, 4, 5 };
	auto rit = L.rbegin();
	while (rit != L.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	auto it = L.begin();
	//L.pop_back();
	//L.pop_front();
	cout << *it << endl;
	while (it != L.end())
	{
		it = L.erase(it);
		//++it;
	}
	return 0;
}
#endif




#if 0
//#include "abc.h"
#include "List.h"

int main()
{
	//TestMyList1();
	//TestMyList2();
	//TestMyList3();
	TestMyList4();
	return 0;
}
#endif




#if 0
#include<stack>

int main()
{
	stack<int> s;
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





// 逆波兰表达式求值
// 根据逆波兰表示法，求表达式的值。
// 有效的运算符包括 + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		for (auto& e : tokens) // e就是RPN中的每一项
		{
			// 该项可能是数字，也可能是符号
			if (!(e == "+" || e == "-" || e == "*" || e == "/"))
			{
				s.push(atoi(e.c_str())); // atoi把参数 str 所指向的字符串转换为一个整数
			}
			else
			{
				// e是一个操作符
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();

				switch (e[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};




// 栈的弹出压入序列
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。
// 例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
			return false;

		stack<int> s;
		int outIdx = 0;
		int inIdx = 0;
		while (outIdx < popV.size())
		{
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx >= pushV.size())
					return false;
				else
					s.push(pushV[inIdx++]);
			}

			s.pop();
			++outIdx;
		}
		return true;
	}
};




// 最小栈
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈

class MinStack 
{
public:
	MinStack() 
	{}

	void push(int x) 
	{
		dataStack.push(x);
		if (minStack.empty() || x <= minStack.top())
			minStack.push(x);
	}

	void pop() 
	{
		if (dataStack.top() == minStack.top())
			minStack.pop();

		dataStack.pop();
	}

	int top() 
	{
		return dataStack.top();
	}

	int getMin() 
	{
		return minStack.top();
	}

private:
	stack<int> dataStack;
	stack<int> minStack;
};