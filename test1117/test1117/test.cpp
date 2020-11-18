#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 全特化：对于所有类型参数都具体化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};


// 偏特化
// 1. 部分特化
template<class T>
class Data<T, int>
{
public:
	Data() { cout << "Data<T, int>" << endl; }
private:
	T _d1;
	int _d2;
};


// 2. 让参数的限制更加的严格
// 在对Data模板进行实例化期间，如果两个参数都是指针类型的
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1* _d1;
	T2* _d2;
};


#include <string>

int  main()
{
	// 使用的是模板
	Data<int, int> d1;
	Data<char, char> d2;

	// 使用特化版本
	Data<int, char> d3;

	Data<string, int> d4;

	Data<string*, int*> d5;
	Data<char*, char*> d6;
	return 0;
}
#endif





// 假设：实现一个通用的拷贝函数
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	// O(1)
//	//memcpy(dst, src, sizeof(T)*size);
//
//	// O(N)
//	for (size_t i = 0; i < size; ++i)
//		dst[i] = src[i]; // 赋值，调用赋值运算符重载，深拷贝
//}


// 类型萃取---类模板特化的应用
#if 0
// 表示内置类型
struct True
{
	static bool Get()
	{
		return true;
	}
};

// 表示自定义类型
struct False
{
	static bool Get()
	{
		return false;
	}
};


// 用该模板来检测T到底是什么类型---自定义类型
template<class T>
struct TypeTraits
{
	typedef False POD_TYPE;
};

// 所有内置类型全部进行特化
template<>
struct TypeTraits<int>
{
	typedef True POD_TYPE;
};

template<>
struct TypeTraits<char>
{
	typedef True POD_TYPE;
};

template<>
struct TypeTraits<double>
{
	typedef True POD_TYPE;
};

//....

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::POD_TYPE::Get())
	{
		// 如果是内置类型元素之间的拷贝
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// 如果是自定义类型元素之间的拷贝
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}


class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str; // 释放当前空间
			_str = temp;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};


void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5 };
	int array2[5];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));

	String s1[] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);

	char* p1 = new char[5];
	char* p2 = new char[5];
	Copy(p1, p2, 5);
	delete[] p1;
	delete[] p2;
}

int main()
{
	TestCopy();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif




// 类型萃取---类模板特化的应用---优化
#if 0
// 表示内置类型
struct True
{};

// 表示自定义类型
struct False
{};


// 用该模板来检测T到底是什么类型---自定义类型
template<class T>
struct TypeTraits
{
	typedef False POD_TYPE;
};


// 所有内置类型全部进行特化
template<>
struct TypeTraits<int>
{
	typedef True POD_TYPE;
};

template<>
struct TypeTraits<char>
{
	typedef True POD_TYPE;
};

template<>
struct TypeTraits<double>
{
	typedef True POD_TYPE;
};

//....

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::POD_TYPE());
}

template<class T>
void Copy(T* dst, const T* src, size_t size, True)
{
	// 如果是内置类型元素之间的拷贝
	memcpy(dst, src, sizeof(T)*size);
}

template<class T>
void Copy(T* dst, const T* src, size_t size, False)
{
	// 如果是自定义类型元素之间的拷贝
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5 };
	int array2[5];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));

	String s1[] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);

	char* p1 = new char[5];
	char* p2 = new char[5];
	Copy(p1, p2, 5);
	delete[] p1;
	delete[] p2;
}

int main()
{
	TestCopy();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif




#if 0
#include "a.h"

/*
void TestFunc();

template<class T>
T Add(const T& left, const T& right);
*/

#include "a.hpp"

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add('1', '2');
	TestFunc();
	return 0;
}
#endif




#if 0
int main()
{
	int a = 10;
	int b = 20;
	//int ret = scanf("%d", &a, b);

	printf("%d", printf("1234\n"));

	cin >> a;
	cout << a << endl;
	return 0;
}
#endif




#if 0
#include <string>

int main()
{
	char ch;
	//cin >> ch;
	ch = getchar();
	cout << ch << endl;

	//string s;
	//cin >> s;
	//getline(cin, s);
	//cout << s << endl;
	return 0;
}
#endif