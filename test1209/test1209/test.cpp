#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>



#if 0
class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}

	virtual void test()
	{
		func();
	}
};
/*
A的虚表：
A::func(int)
A::test()
*/

class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
/*
B的虚表：
D::func(int)
A::test()
*/

int main(int argc, char* argv[])
{
	B*p = new B; // 子类的指针
	p->test();
	delete p;
	return 0;
}
#endif




#if 0
class A
{
private:
	int _a;
	int _b;
public:
	int _c;
};

int main()
{
	A a;
	//a.
	return 0;
}
#endif




#if 1
#include "BSTree.hpp"

int main()
{
	TestBSTree();
	return 0;
}
#endif