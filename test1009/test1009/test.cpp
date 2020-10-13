#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;



#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

void TestFunc()
{
	// 需求：需要在堆上创建一个Test类型的对象
	Test* pt = (Test*)malloc(sizeof(Test));

	// ....

	free(pt);
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
int main()
{
	// 空间申请

	// 申请单个类型空间
	int* p1 = new int;
	// 申请单个类型空间---并且对空间中的内容进行初始化
	int* p2 = new int(10); // 对申请的空间进行初始化

	// 申请一段连续的空间
	int* p3 = new int[10];
	// 申请一段连续的空间并进行初始化
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	// 空间释放
	// 使用delete来释放单个类型的空间
	delete p1;
	delete p2;

	// 使用delete[]来释放连续的空间
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	Test* pt1 = new Test;
	Test* pt2 = new Test[10];

	delete pt1;
	delete[] pt2;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t, int a)
		: _t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	// 注意：如果类带有无参或者全缺省的构造函数时，new类类型对象时，可以不带参数
	//      如果类具有带有参数的构造函数时，new类类型对象时，必须要带T(参数)
	Test* pt1 = new Test(10, 20);
	Test* pt2 = new Test(20, 30);
	delete pt1;
	delete pt2;
	return 0;
}
#endif




#if 0
class Test
{
public:
	//Test(int t = 10) // 带上默认值，全缺省的构造函数，内置类型的空间，可以进行初始化
	Test(int t) // 自定义类型对象的连续空间，无法进行初始化
		: _t(t)
	{
		cout << "Test(int):" << this << endl;
	}
	
	Test() // 无参类型的构造函数
		: _t(100)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	// 注意：申请连续对象的空间时，类必须要具有无参的或者全缺省的构造函数
	//       如果是内置类型的空间，可以进行初始化
	//       如果是自定义类型对象的连续空间，无法进行初始化
	//Test* pt = new Test[10]{{ 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 }, { 0 }}; //编译失败
	//Test* pt = new Test[10]{1,2,3,4,5,6,7,8,9,0}; // 编译失败
	Test* pt = new Test[10];
	delete[] pt;

	// Test t();  
	//注意：此处不是创建了一个Test类型的对象t，而是声明了一个函数
	//函数的名字是t，该函数没有参数，返回值类型是Test

	Test();  // 创建了一个匿名对象
	Test* pt2 = new Test();
	delete pt2;

	Test* pt3 = new Test; // 调用无参类型的构造函数
	Test* pt4 = new Test(); // 调用无参类型的构造函数
	Test* pt5 = new Test(20); // 调用带有参数的构造函数

	return 0;
}
#endif




#if 0
void TestFunc()
{
	// 对于内置类型的空间，没有匹配起来使用，没有任何的影响
	// 但是：不建议这样子去写，一旦养成这种不好的习惯，那会很难改变
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;
	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;

	// 注意：在vs中可以使用该函数来简单的检测程序中是否存在内存泄漏
	_CrtDumpMemoryLeaks();
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
// 如果自定类型对象中涉及到资源管理时，一定匹配起来使用
// 如果自定义类型对象中未涉及到资源管理时，也 一定 要匹配起来使用
class Test
{
public:
	Test(int t = 10)// 全缺省的构造函数，内置类型的空间，可以进行初始化
		: _t(t)
	{
		p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete p;
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
	int* p;
};

void TestFunc()
{
	// 因为：malloc申请出来的不是一个Test类型的对象，而与Test类型大小相同的一段空间
	// 因此：在释放该空间时，也不能使用delete来进行释放，因为delete会调用析构函数
	// 而析构函数中需要对对象中p指针指向的空间进行释放，而malloc申请的空间没有调用构造函数
	// 对p1进行初始化，p1指向的空间中的内容是随机值
	Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;

	//Test* p2 = (Test*)malloc(sizeof(Test));
	//delete[] p2;

	//Test* p3 = new Test;
	//free(p3);  //没有使用delete来进行释放，p3对象中的p成员指向的int类型的堆空间就没有被释放掉，而存在内存泄漏
	//delete p3; // 可以
	//delete[] p3;// 代码崩溃
	//_CrtDumpMemoryLeaks();

	// 代码崩溃
	//Test* p4 = (Test*)malloc(sizeof(Test));
	//delete[] p4;

	// 代码崩溃
	//Test* p5 = new Test;
	//delete[] p5;
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 1
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt = new Test;
	delete pt;
	printf("hehe");
	return 0;
}
#endif
