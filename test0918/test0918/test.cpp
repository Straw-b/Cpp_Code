#include <iostream>
using namespace std;


#if 0
class Test
{
public:
	Test(int t)
		: _t(t)
	{}

	/*Test& operator=(const Test& t)
	{
		if (this != &t)
		{
			_t = t._t;
		}
		return *this;
	}*/

	int _t;
};

//Test& operator=( Test& t)// 赋值运算符重载必须写成类的成员函数
//{
//	return t;
//}
// 注意：不是说所有的运算符重载都要写成类的成员函数，比如：重载的输出运算符

int main()
{
	Test t1(10);
	Test t2(20);

	t1 = t2;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " " << _t << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << " " << _t << endl;
	}

	int _t;
};

Test t1(10);

void TestStatic()
{
	static Test t4(40);
}

int main()
{
	Test t2(20);
	Test t3(30);
	TestStatic();
	TestStatic();
	TestStatic();

	//Test t4(t2);
	return 0;
}
#endif




#if 0
// 构造函数语法中说：构造函数没有返回值类型
// 构造函数到底有返回值吗？
class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " " << _t << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << " " << _t << endl;
	}

	int _t;
};

int test1()
{
	return 10;
}
void test2()
{}

int main()
{
	int a = 10;
	a = test1();   //test1()函数有返回值，因此可以放在=的右侧
	// a = test2();  test2()方法没有返回值，既然没有返回值则其不能出现在=的右侧

	Test t1(10);

	// 既然构造函数和拷贝构造函数可以放在=的右侧，则证明构造和拷贝构造函数是有返回值的
	// 构造函数和拷贝构造函数返回的是对象的引用
	t1 = Test(20);  // 调用构造函数函数
	t1 = Test(t1);  // 调用拷贝函数

	return 0;
}
#endif

