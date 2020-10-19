#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// int
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(10, 20);
	Add(1.2, 3.4);
	Add('1', '2');
	return 0;
}
#endif




#if 1
// Add函数模板
template<typename T>       // 模板参数列表：声明类型
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	// 对函数模板在进行实例化
	Add(10, 20);     // 10,20--->int
	Add(1.2, 2.3);  // 1.2,2.3--->double
	Add('1', '2');  // '1' '2'--->char
	return 0;
}
#endif




#if 0
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

// 各种类型的数组
template<class T>

void PrintArray(T array[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

int main()
{
	int array1[] = { 1, 2, 3, 4, 5 };
	PrintArray(array1, sizeof(array1) / sizeof(int));

	double array2[] = { 1.1, 2.2, 3.3 };
	PrintArray(array2, sizeof(array2) / sizeof(double));

	return 0;
}
#endif




#if 0
// 函数模板不是一个函数，而是一个函数的模具
template<typename T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

// 模板的实例化：也就是将函数模板参数具体化

// 函数模板调用原理---隐式实例化
//  编译器在编译阶段，用户对函数模板实例化之后，
//  编译器会对实参类型进行推演，
//  根据推演的结果来确定模板参数列表中T的实际类型
//  根据确定的T的具体类型来生成处理具体类型的函数
// 注意：在隐式实例化中，编译器在生成代码时不会进行隐式类型转化
int main()
{
	// 隐式实例化
	Add(10, 20);  // int
	Add(1, 2);    // int
	/*
	int Add<int>(int left, int right)
	{
	cout << typeid(int).name() << endl;
	return left + right;
	}
	*/

	Add(1.0, 2.0);  // double
	/*
	double Add<double>(double left, double right)
	{
	cout << typeid(double).name() << endl;
	return left + right;
	}
	*/


	// int 和 double 之间可以相互转换
	Add(1, (int)2.0);  // int   double


	// 显式实例化
	// 编译器在编译代码期间，看到对函数模板进行显示实例化之后，
	// 直接根据显式实例化的T的具体类型直接生成代码，
	// 在具体调用时可能会进行隐式类型转化
	Add<int>(1, 2.0);
	Add<double>(1, 2.0);

	// Add<int>(1, "hello");
	return 0;
}
#endif




#if 0
// decltype
// auto
template<class T, class U>
T Add(T left, U right)
{
	return left + right;
}

// Add(1, 2.0)--->double
// Add(1.0, 2)--->double

int main()
{
	Add(1, 2.0);  // int double
	/*
	int Add<int,duoble>(int left, double right)
	{
	return left + right;
	}
	*/

	Add(1.0, 2);

	Add(1, 2);
	return 0;
}
#endif




#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add<>(1, 2);
	Add<int>(1, 2);

	Add(1.0, 2.0);
	return 0;
}
#endif




#if 0
int Add(int left, int right)
{
	return left + right;
}

// 函数模板：可以被实例化成类型不同的参数
template<class T1, class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1, 2.0);
	return 0;
}
#endif




#if 0
int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1, 2.0);
	return 0;
}
#endif




#if 0
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add<int>(1, 2.0);
	return 0;
}
#endif




#if 0
#include <assert.h>

// 模板类型的动态顺序表
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	void PushBack(const T& data);

	void PopBack()
	{
		if (!Empty())
		{
			--_size;
		}
	}

	bool Empty()const
	{
		return _size == 0;
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	// 函数重载
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::PushBack(const T& data)
{
	if (_size == _capacity)
	{
		// 扩容
	}

	// 尾插
	_array[_size++] = data;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << array[2] << endl;
	array[2] = 10;

	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	cout << s1[2] << endl;   // []--->下标运算符

	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;

	const SeqList<int> s0;
	s0[1];  // s0.operator[](1);

	SeqList<double> s2;

	SeqList<Date> s3;
	return 0;
}
#endif

