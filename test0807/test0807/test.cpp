#include <iostream>
using namespace std;


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯����
	// ����Ĺ��캯����һ���ǵ��εģ����������������Ͷ��������(һ������»��ڲ���ǰconst)
	// ��ʹ���Ѿ����ڵĶ��󴴽��¶���ʱ���ɱ������Զ����е���
	// ע�⣺����û�û����ʽʵ�֣������������һ�ݣ����һ���ɿ����Ĺ���
	// һ�㿽������Ҫͨ���β�d�ı��ⲿ��ʵ�Σ������const��d�����޸�
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << this << ":" << &d << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		// ����Date����������д��д������ν��һ����������Ƕ�����д
		// ��Ϊ����������һ������ǰ������Դ����Date�������û���漰����Դ����
		// �������������Ը���Ҳ���Բ��ø��������û��Ƿ���Ҫ
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	//int b = a;
	int b(a);

	Date d1(2020, 8, 7);
	d1.PrintDate();

	// ����d2�����ڴ�����֮����d1�����е�����һ��
	// Date d2(2020,8,7);

	// ���Ѿ����ڵ�d1������һ���¶���d2
	// d2���´����Ķ��󣬼�Ȼ�´����˶��󣬿϶�Ҫ���ù��캯��
	// Date d2 = d1; // Ҳ����
	Date d2(d1);// ��Ϊ�����Ѿ����ڵ�d1�ڴ����¶���d2---->�������캯��(���ƹ��캯��)
	d2.PrintDate();
	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
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
	Date d1(2020, 8, 7);
	d1.PrintDate();

	// ����ÿ������캯����Date��û����ʽ�ṩ�������캯��
	Date d2(d1);
	d2.PrintDate();

	// ����d2���󴴽��ɹ��󣬷���d2�����е�������d1�����е�������ȫ��ͬ
	// ���Ѿ����ڶ���d1���������¶���d2--->���õľ��Ǳ��������ɵ�Ĭ�ϵĿ������캯��
	// ��������Date�����ɵ�Ĭ�ϵĿ������캯���Ѿ��ܹ���ɿ����Ĺ���
	// ����������Ĭ�Ͽ������캯����ֵ�Ŀ���(�ڴ�Ŀ���)����һ�������е�����ԭ�ⲻ���Ŀ�������һ���¶�����

	// ����Date����ԣ�ʹ�ñ��������ɵ�Ĭ�Ͽ������캯��û���κ�����
	// Date�Ŀ������캯��д��д�����ԣ����д�˾�ʹ���û����ṩ�Ŀ������캯��
	// ���û���ṩ����ʹ�ñ��������ɵ�Ĭ�ϵĿ������캯��
	return 0;
}
#endif




// ���֣�Date�࿽�������Ƿ��ṩû���κ�Ӱ��
// ���⣺�Ƿ��κ���Ŀ������캯�������Բ����ṩ����Ϊ������������һ��Ĭ�ϵĿ������캯��
#if 0
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

	size_t Size()
	{
		return strlen(_str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");

	// ��s1��������s2���϶�Ҫ���ÿ������캯��
	// ��ΪString��û����ʽ�ṩ�������캯������ʹ�õ��Ǳ��������ɵ�Ĭ�ϵĿ������캯��
	// ��Ĭ�ϵĿ������캯���ǰ���ֵ�ķ�ʽ���п�����������s1�����е�����ԭ�ⲻ���Ŀ������¶�����
	//String s2(s1); //�ͷ�ʱ�������
}

int main()
{
	TestString();
	return 0;
}
#endif




// ��ֵ���������
#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// isLess��������ĳ�Ա��������Ա��������Ҫͨ�����������е��ã���Ҫһ���������͵Ĳ���
	// ע�⣺isLess��������Ҳ������ֵ�ķ�ʽ��ֻ��������ֵ�ķ�ʽ���Σ�
	//       �ڴ���ʱҪ����һ����ʱ���󣬻�Ӱ����������Ч�ʣ����ʹ�����õķ�ʽ����
	//       ���þ���ʵ�εı���������Ҫ����һ����ʱ���󣬴��ε�Ч�ʾ͸�
	// һ������£���������Ϊ�����Ĳ���ʱ���������ǰ������õķ�ʽ���ݵģ�
	// �������Ҫͨ���βθı��ⲿ��ʵ�Σ���ü���const����������
	bool isLess(const Date& d) // Ҳ����ֵ����
	{
		cout << "d1����this��" << this << endl;
		cout << "d��d2�����һ�ݿ���" << &d << endl;
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

	// <�������������
	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	// �����������͵ı���������ֱ��֧�ֱȴ�С
	// ��Ϊ������������������Դ������ͣ��������϶�֪���������з��õ�������������бȽ�
	int a = 10;
	int b = 20;
	if (a > b)
	{
		cout << "a > b" << endl;
	}
	else if (a == b)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a < b" << endl;
	}
	cout << endl;

	Date d1(2020, 8, 7);
	Date d2(2020, 8, 8);
	//if (d1 < d2)
	//	cout << "d1 < d2" << endl;
	// ���ճ�ʶ��˵���������͵Ķ���϶����Աȴ�С�����Ǵ������ʧ��
	// ��������֧���������͵Ķ���ֱ�ӱȴ�С
	// Date���û��Զ�������ͣ����Զ���������п��ܻ���������Ա��������������������װ���ʲô���������бȽ���

	// �ṩһ�����еĺ��������бȽ�
	// ��Ȼ���Խ����������Ͷ���֮��ıȽϣ�����d1.isLess(d2) û�� d1 < d2����ֱ��
	cout << "d1:" << &d1 << endl;
	cout << "d2:" << &d2 << endl;
	if (d1.isLess(d2))
	{
		cout << "d1 < d2" << endl;
	}
	cout << endl;

	// ���߱�������ζ��������͵Ķ�����бȽ�----��<���Ž�������
	if (d1 < d2)
		cout << "d1 < d2" << endl;

	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// <�������������
	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

	// ==����
	// ==������������������д����ʱʵ��ֻ���ṩһ���������ɣ���Ϊ��Ա��������һ�����ص�thisָ��
	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	Date d1(2020, 8, 7);
	Date d2(d1);

	if (d1 != d2)
	{
		cout << "d1 != d2" << endl;
	}
	else
	{
		cout << "d1 == d2" << endl;
	}
	return 0;
}
#endif




//void operator@(const Date& d)// �ú�������ʧ�ܣ�@�����������û��
//{}

// +���м�������������������Ҫ�ṩ����������
// ����ʧ�ܣ�+���������������int���͵����ݣ�������������֧�֣�������ʱ��Ͷ��һ��
// ���һ��γ������޵ݹ�
// ע�⣺�ڽ������������ʱ��������һ�������ͻ���ö�����͵Ĳ���
//int operator+(int left, int right)
//{
//	return left + right;
//}

//enum DATA{ONE, TWO, TRHEE}; // ö��
//
//int operator+(DATA op1, int op2)
//{
//	return op1 + op2; // ��ݹ����пؼ�·������������������ʱ��ջ���
//}




#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 8, 7);
	Date d2(2020, 8, 8);

	d2 = d1;
	// ע�⣺ d2 = d1��Ӧ�õ��ø�ֵ��������أ�����Date����û���ṩ��ֵ���������
	// ����ͨ������
	// ��Ϊ����ֵ���������--->�û�û����ʽʵ��ʱ�����������Զ�����һ��
	// ����Date��ʹ�ñ��������ɵ�Ĭ�ϵĸ�ֵ���������û���κ�����

	return 0;
}
#endif




#if 1
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
		}
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2("world");

	//s2 = s1; //�����ڴ�й¶
}

int main()
{
	TestString();
	return 0;
}
#endif