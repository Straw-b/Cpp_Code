#include <iostream>
using namespace std;


#if 0
class Test
{
public:
	Test(int t)
		: _t(t)
	{}

	Test& operator=(const Test& t)
	{
		if (this != &t)
		{
			_t = t._t;
		}
		return *this;
	}

	int _t;
};

// 注意：不是说所有的运算符重载都要写成类的成员函数，比如：重载的输出运算符
// 赋值运算符重载必须写成类的成员函数
//Test& operator=( Test& t)
//{
//	return t;
//}

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
// 语法方面:没有，编译器不让写
// 汇编方面:有，返回当前对象的引用
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




// 内部类就是外部类的友元类
// 1.内部类可以定义在外部类的public、protected、private都是可以的。
// 2.注意内部类可以直接访问外部类中的static、枚举成员，不需要外部类的对象 / 类名。
// 3.sizeof(外部类) = 外部类，和内部类没有任何关系。
#if 1
class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};

int A::k = 1;

int main()
{
	A::B b;
	b.foo(A());
	return 0;
}
#endif