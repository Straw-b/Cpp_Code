#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
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




#if 0
// Add����ģ��
// ģ������б���������
template<typename T>   

T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	// �Ժ���ģ���ڽ���ʵ����
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

// �������͵�����
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




// ģ���ʵ������Ҳ���ǽ�����ģ��������廯
// ����ģ�����ԭ��---��ʽʵ����
// ����ģ�岻��һ������������һ��������ģ��
#if 0
template<typename T>

T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	// ��ʽʵ����
	// �������ڱ���׶Σ��û��Ժ���ģ��ʵ����֮�󣬱��������ʵ�����ͽ������ݣ�
	// �������ݵĽ����ȷ��ģ������б���T��ʵ������
	// ����ȷ����T�ľ������������ɴ���������͵ĺ���
	// ע�⣺����ʽʵ�����У������������ɴ���ʱ���������ʽ����ת��
	Add(10, 20);  // int
	Add(1, 2);    // int

	Add(1.0, 2.0);  // double

	// int �� double ֮������໥ת��
	Add(1, (int)2.0);  // int   double


	// ��ʽʵ����
	// �������ڱ�������ڼ䣬�����Ժ���ģ�������ʾʵ����֮��
	// ֱ�Ӹ�����ʽʵ������T�ľ�������ֱ�����ɴ��룬�ھ������ʱ���ܻ������ʽ����ת��
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

// ����ģ�壺���Ա�ʵ���������Ͳ�ͬ�Ĳ���
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




#if 1
#include <assert.h>

// ģ�����͵Ķ�̬˳���
template<class T>

class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

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

	// ��������[]
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

// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template<class T>

void SeqList<T>::PushBack(const T& data)
{
	if (_size == _capacity)
	{
		// ����
	}

	// β��
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

	cout << s1[2] << endl;   // []--->�±������

	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;

	const SeqList<int> s0;
	//s0[1];  // s0.operator[](1);

	SeqList<double> s2;

	// ʵ��������������
	SeqList<Date> s3;
	return 0;
}
#endif
