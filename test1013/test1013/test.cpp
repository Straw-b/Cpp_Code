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

// ����new int��
// ��Ҫ֪��new�����Ǹ��ļ��е��Ǹ������е���һ�������˶��ٸ��ֽڣ�
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

int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	free(p);

	// ����ڴ��ʹ��
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt)Test(100);
	//void* operator new(size_t size, void* p)
	//{
	//    return p;
	//}


	Test* pt2 = new Test(100);
	//void* operator new(size_t size)
	//{
	//    //��Ҫѭ������malloc������ռ���
	//}

	pt->~Test();
	free(pt);
	return 0;
}
#endif




#if 1
#include <windows.h>
void TestMerroyLeaks()
{
	while (true)
	{
		new int[10];
		Sleep(1);
	}
}

int main()
{
	//TestMerroyLeaks();

    // 32λϵͳ������ܴ�С���ó���0x7fffffff�ֽ�
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif
