#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>


#if 1
class Base
{
public:
	void f0() // 普通函数
	{
		cout << "Base::f0()" << endl;
	}

	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	/*
	b1.f3();--->call Base::f3(&b1);
	b2.f3();--->call Base::f3(&b2);
	b3.f3();--->call Base::f3(&b3);

	virtual void f3(Base* const this)
	{
	    this->_b = 10;
	    cout << "Base::f3()" << endl;
	}
	*/

	virtual void f3()
	{
		_b = 10;
		cout << "Base::f3()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	void f0()  // 同名隐藏
	{
		cout << "Base::f0()" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	int _d;
};

typedef void(*PVF)();

void PrintVFT(Base& b, const string& str)
{
	cout << str << endl;
	// 获取对象前4个字节的内容--->(*(int*)&b)--->int类型的值
	// 必须将(*(int*)&b) 这个整形数值--->变成虚表地址
	// 虚表中--->放的虚函数的入口地址--->虚表中每个元素的类型其实就是每个虚函数的类型
	PVF* pVF = (PVF*)(*(int*)&b);   // &b--->Base*

	while (*pVF)
	{
		(*pVF)();
		++pVF;
	}
	cout << endl;
}

void TestVirtual(Base& b)
{
	b.f0();
	b.f1();
	b.f2();
	b.f3();
}

int main()
{
	int a = 10;
	a = 20; // a表示空间

	int b = 0;
	b = a; // a表示数值

	int* pa = &a;
	*pa = 30;

	Base bb;
	Derived dd;

	Base* pb = (Base*)&dd; // 没有生成新的对象，仍是子类的对象
	pb->f1();   // Derived

	pb = &(Base)dd; // 转化成基类对象，生成新的对象
	pb->f1();   // Base

	PrintVFT(bb, "Base vft:");
	PrintVFT(dd, "Derived vft: ");

	TestVirtual(bb);
	TestVirtual(dd);
	return 0;
}
#endif






#if 0
#include <vector>

int main()
{
	vector<vector<int>>  vv(5, vector<int>(6, 8)); // 5行6列
	for (auto& e : vv) // 用引用效率高
	{
		for (auto ee : e)
		{
			cout << ee << " ";
		}
		cout << endl;
	}

	int array[5][6] = { 0 };
	for (auto arr : array)
	{
		cout << typeid(arr).name() << endl; // int *
		//for (auto e : arr) // arr不是确定的范围
		//{
		//    cout << e << " ";
		//}
		cout << endl;
	}
	return 0;
}
#endif




// 多继承
#if 0
class B1
{
public:
	virtual void f1()
	{
		cout << "B1::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "B1::f2()" << endl;
	}

	int _b1;
};

class B2
{
public:
	virtual void f3()
	{
		cout << "B2::f3()" << endl;
	}

	virtual void f4()
	{
		cout << "B2::f4()" << endl;
	}

	int _b2;
};

class D : public B1, public B2 // 多继承
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "D::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "D::f5()" << endl;
	}

	int _d;
};

typedef void(*PVF)();

void PrintVFTB1(B1& b, const string& str)
{
	cout << str << endl;
	PVF* pVF = (PVF*)(*(int*)&b);
	while (*pVF)
	{
		(*pVF)();
		++pVF;
	}
	cout << endl;
}

void PrintVFTB2(B2& b, const string& str)
{
	cout << str << endl;
	PVF* pVF = (PVF*)(*(int*)&b);
	while (*pVF)
	{
		(*pVF)();
		++pVF;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFTB1(d, "B1 vft:");
	PrintVFTB2(d, "B2 vft:");
	return 0;
}
#endif




#if 0
class A
{
public:
	virtual void f1() = 0
	{
		cout << "f1()" << endl;
	}
};

class B
{
public:
	inline void f1()
	{}

	virtual inline void f2()
	{}

	virtual static void f3()
	{}
};
#endif




#if 0
class A{
public:
	A(char *s)
	{
		cout << s << endl;
	}

	~A(){}
};

class B :virtual public A
{
public:
	B(char *s1, char*s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};

class C :virtual public A
{
public:
	C(char *s1, char*s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};

class D :public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4)
		: B(s1, s2)
		, C(s1, s3)
		, A(s1)
	{
		cout << s4 << endl;
	}
};

int main() {
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
#endif




#if 0
class Base1 
{ 
public: 
	int _b1; 
};

class Base2 
{ 
public: 
	int _b2; 
};

class Derive : public Base1, public Base2
{
public: 
	int _d;
};

int main(){
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}
#endif




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

class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};

int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();

	delete p;
	return 0;
}
#endif