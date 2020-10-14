#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
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
	Test t(100);

	int* p = new int;
	Test* pt1 = new Test;
	Test* pt2 = new Test();
	Test* pt3 = new Test(20);

	delete pt1;
	delete pt2;
	delete pt3;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
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
	Test* pt = new Test[10];

	delete[] pt;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _t;
};

// 需求：new int；
// 需要知道new是在那个文件中的那个函数中的哪一行申请了多少个字节？
void* operator new(size_t size, char* fileName, char* funcName, size_t lineNo)
{
	cout << fileName << "-" << funcName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__) 

int main()
{
	int* p = new int;
	Test* pt = new Test;

	delete p;
	delete pt;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _t;
};

void TestMerroyLeaks()
{
	while (true)
	{
		new int[10];
		Sleep(3000);
	}
}

int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	free(p);

	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt)Test(100);
	/*
	void* operator new(size_t size, void* p)
	{
	return p;
	}
	*/

	Test* pt2 = new Test(100);
	/*
	void* operator new(size_t size)
	{
	需要循环调用malloc来申请空间呢
	}
	*/

	pt->~Test();
	free(pt);
	return 0;
}
#endif




#if 0
#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

