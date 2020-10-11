#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// 内部类
class A
{
private:
	static int k;
	int h;
public:
	// 注意：B类只是在A类中定义了，但是并不是A类的一部分，两个实际还是独立的
	// 外部类是内部类的友元类，说明：可以在内部类中直接访问外部类的私有的成员

	// 如果内部类需要在全局作用域中创建对象时，该类在外部类中定义时，就使用public来修饰
	// 如果内部类需要在全局作用域中不需要创建对象时，该类在外部类中定义时，就使用private来修饰
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK // 随机值

			// cout << h << endl; // 编译失败，因为h是外部类的普通成员变量，必须要通过外部类的对象来进行访问
		}
		int b;
	};
};

int A::k = 1;

int main()
{
	cout << sizeof(A) << endl;

	A::B b;
	b.foo(A());
	return 0;
}
#endif




#if 0
// 比如说：现在要实现一个带头节点的双向循环链表
class List
{
	// 如果内部类需要在全局作用域中创建对象时，该类在外部类中定义时，就使用public来修饰
	// 如果内部类需要在全局作用域中不需要创建对象时，该类在外部类中定义时，就使用private来修饰
private:
public:
	struct ListNode
	{
		ListNode* _next;
		ListNode* _prev;
		int _data;
		ListNode(int data = 0)
			: _next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};

public:
	List()
		:head(nullptr)
	{}

	void PushBack(int data)
	{}

	void PopBack()
	{}

	size_t size() const
	{
		return 0;
	}

private:
	ListNode* head;
};

int main()
{
	List::ListNode node(10);
	return 0;
}
#endif




#include <malloc.h>

int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	// ...可以一直采用下标的方式来进行操作
	// 从程序的角度来看，malloc申请的空间就是连续的

	*(p + 1) = 10; // 等价于p[1]=10
	*((int*)&p + 1) = 10;

	free(p);
	return 0;
}