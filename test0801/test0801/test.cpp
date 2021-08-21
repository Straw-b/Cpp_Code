#include <iostream>
using namespace std;


#if 0
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	// C���Զ��������ʽ
	int a1;
	int a2 = 10;
	int a3(10);

	// ���󣺵�Date�ཫ���󴴽��ã��ö����о�Ҫ�г�ʼֵ
	Date d1; // �����Ѿ��������� 
	d1.SetDate(2020, 8, 1); // ---> Date::SetDate(&d, 2020, 8, 1)�����и�ֵ
	d1.PrintDate();

	//Date d2(2020, 8, 1);  // ����d2���󲢶�����г�ʼ��--���캯��������ɶԶ���ĳ�ʼ������
	//d2.PrintDate();

	return 0;
}
#endif




// ���캯����һ������ĳ�Ա���������⣺
// 1.���캯�������ֱ�����������ͬ
// 2.���캯��û�з���ֵ���ͣ���ʹ��voidҲ����
// 3.���캯�����ڴ�������ʱ�ɱ������Զ����е��ã������ڶ��������������ֻ����һ��
// ���ã���Ҫ�Ǵ�������ʱ����ɶԵ�ǰ����ĳ�ʼ������
// ��ʼ���������󿪱ٿռ䣬�������з��ó�ʼֵ

#if 0
class Date
{
public:
    // ���캯����һ�����û��Լ�д�����ܸ����ز���	
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		// return 0; // ���ܷ���
		// return; //���ԣ�����д����ʾ����û�з���һ��ʵ�ʵ����ݣ����������Ӹ�λ���˳�

		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	// d�����Ǻ����е�һ���ֲ��Ķ����ں����˳�ʱ�ö����Ҫ������
	// d�������������ź����Ľ���������
	Date d(2020, 8, 2);
	d.PrintDate();
}

int main()
{
	TestDate();

	Date d1(2020, 8, 1);  // ���ǲ�û����ʽ(�û�û��д�����ù��캯�������)���ù��캯��
	d1.PrintDate();

	// Date d2;
	return 0;
}
#endif




#if 0
// ���캯����������
class Date
{
public:
	// �ù��캯��ֻ�ܴ����������������Ķ��󣬲��ܴ����޲εĶ���
	Date(int year, int month, int day) // ���ι��캯��
	{
		/*this->*/_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date() // �޲ι��캯��
	{
		_year = 1900; // Ĭ������
		_month = 1;
		_day = 1;
		cout << "Date():" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 8, 1);   // call Date(2020, 8, 1)
	d1.PrintDate();
	Date d2(2020, 8, 2);
	d2.PrintDate();

	Date d3;              // call Date()
	d3.PrintDate();
	Date d4;
	d4.PrintDate();

	return 0;
}
#endif




// ���һ����û����ʽ����(�û�д��)�κι��캯����������������һ��Ĭ�ϵĹ��캯����
// ע�⣺���������ɵĹ��캯��һ�����޲εģ��û�һ���������캯�����������Ͳ���������
#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	//Date()
	//{
	//	_year = 1900;
	//	_month = 1;
	//	_day = 1;
	//}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Date d1;
	//d1.PrintDate();

	Date d2(2020, 8, 1);  // �ڴ�������ʱ��Ҫ����Date(int,int,int)
	d2.PrintDate();
	return 0;
}
#endif




// ȫȱʡ�Ĺ��캯�� �� �޲εĹ��캯��ͳ��Ϊ Ĭ�ϵĹ��캯��
// ���ң�ȫȱʡ�Ĺ��캯�� �� �޲εĹ��캯������ͬʱ����
#if 0
class Date
{
public:
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	//// �޲εĹ��캯��
	//Date()
	//{
	//	_year = 1900;
	//	_month = 1;
	//	_day = 1;
	//}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2(2020, 8, 1);
	return 0;
}
#endif




// �û�û�ж��幹�캯��ʱ�������������޲εĹ��캯������ô���������ʼ����ʲôֵ�����������ֵ��
// ���������ɵ�Ĭ�Ϲ��캯���У�
// ���������������Ͷ���ĳ�Ա������ʼ��Ϊ���ֵ
// �������а����������Ͷ����Ա---���ó�Ա��Ӧ���Ĭ�Ϲ��캯������ʼ��
#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;

		cout << "Time(int,int,int):" << this << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	// ����û�û����ʽ���幹�캯�����������Ż�����һ��Ĭ�ϵĹ��캯��
	// ע�⣺���������ɵĹ��캯��һ�����޲ε�

	// �Լ�д���캯�����������Ժ���Ҳ�����޸���
	// ��Date�๹�캯��ִ��ʱ������ת��Time�๹�캯��λ��ִ�У����������е�_t�Ķ����ʼ������
	// Ȼ����ִ��Date��Ĺ��캯�����_year\_month\_day�����и�ֵ
	Date(int year = 1900, int month = 1, int day = 1) // call Time() 
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

	Time _t; // ���������������
};

int main()
{
	// ��������������������һ��Ĭ�ϵĹ��캯��
	// �����ɵ�Ĭ�ϵĹ��캯���е�����Time��Ĺ��캯����Ŀ�ģ����������а�����Time��Ķ����ʼ�����
	Date d;  // ����ñ��������ɵ�Ĭ�Ϲ��캯��(�޲�)   call Date()
	d.PrintDate();

	Date dd(2020, 8, 1);
	dd.PrintDate();
	// dd�����ڴ���ʱ����Ҫ���ô�������int���Ͳ����Ĺ��캯��
	// ���ù��캯���û���û���ṩ��������ֻ�������޲ε�Ĭ�Ϲ��캯��
	// ��ʾ����û�д�������int���͵Ĺ��캯��---dd����û�а취����--->����ʧ��
	return 0;
}
#endif




#if 0
#include <malloc.h>
typedef int DataType;

class SeqList
{
public:
	// �����ڴ���ʱ���������з�����(��Դ)
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		_capacity = capacity;
		_size = 0;
	}
	
	// ��������
	// �ڶ�������ʱ������Ҫ�������е���Դ�����
	// �ڶ�������ʱ���ɱ������Զ����е��ã�������������Դ������
	// ��������һ�����޲εģ����ܴ����κ����͵Ĳ����������з���ֵ
	// һ����ֻ����һ����������

	~SeqList() // �޲����޷���ֵ
	{
		if (_array)// �����޿ռ�
		{
			free(_array);
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(DataType data)
	{
		// ����
		_array[_size++] = data;
	}

	void PopBack()
	{
		if (Empty())
			return;

		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return _size == 0;
	}

private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void TestSeqList()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
}

int main()
{
	TestSeqList();
	return 0;
}
#endif




#if 1
#include <malloc.h>
#include <string.h>

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1;
	String s2("hello");
}


class Person
{
private:
	String _name;
	int _age;
};

void TestPerson()
{
	Person p;
	// �ڹ���Person����pʱ���ӻ������п�������������Person��������һ��Ĭ�ϵĹ��캯����
	// �����ɵ�Ĭ�Ϲ��캯���У���Ҫ������String��Ĺ��캯����Ŀ�ľ��Ƕ�p��������������String���͵�name�����г�ʼ��
	// ע�⣺��Person p�в���ֱ�ӵ���call String(), ��Ϊ��Person p�д�������һ��Person���͵Ķ��󣬾�Ҫ����Person�Ĺ��캯����
	// �����Person��������������String���͵�name�ĳ�ʼ����������˱�������Person������һ��Ĭ�ϵĹ��캯��

	// ��P��������ʱ����Ϊp�����а�����String���͵�name��name�й�������Դ��
	// ��˱���Ҫ����String����������������p��������������String���͵�name����Դ������
	// �����ں����˳�ʱ������ֱ�ӵ���String���������������Ϊ������������Person��Ķ���ֱ�ӵ���String���������������ͨ

	// �����ĸ���Ķ��󣬵����ĸ������������
	// ��ˣ���������Person��������һ��Ĭ�ϵ�������������Ĭ�ϵ����������е���String�����������
	// ���p��������������String����name����Դ������

	//��������Person�����ɵ���������
	//~Person()
	//{
	//    call ~String();  // ����Person������а�����String���ͳ�Աname�е���Դ
	//}
}

int main()
{
	TestPerson();
	TestString();
	return 0;
}
#endif