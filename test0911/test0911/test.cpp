#include <iostream>
using namespace std;


// ���캯����������Ա��������Ҫ�����𣺹��캯�����г�ʼ���б�
// ��ʼ���б����ã���ɶ����Ա�����ĳ�ʼ������
#if 0
class Time
{
public:
	// ע�⣺���һ����û����ʽ�����κι��캯�����������������һ��Ĭ�ϵĹ��캯��(�޲εĹ��캯��)
	// һ���û���ʽ���壬��������������ɣ�Time�಻����Ĭ�ϵĹ��캯��
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{ }

private:
	int _hour;
	int _minute;
	int _second;
};

// ���һ����A�а�������B�Ķ�����B�����޲ι��캯��ʱ��
// ��A���뽫���ڲ���������B�Ķ��󣬷�����A���캯����ʼ���б��λ�ã����г�ʼ��
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(0, 0, 0) //��ʽ��ʼ��
		, ra(_day) // �������ͳ�Ա����
		, ca(10) // const���ͳ�Ա����
		// , _day(day)
	{ } // {}��Date�๹�캯���ĺ����壬������ʱû���ڹ��캯������д�κ���Ч�Ĵ���

private:
	int _year;
	int _month;
	int _day;
	Time _t;

	int& ra; // �������ͳ�Ա����
	const int ca; // const���ͳ�Ա����
};

int main()
{   
	// ��const���εı�������C++���Ѿ���һ�������ˣ������ڶ���ʱ����������г�ʼ��
    const int a = 10;
	//a = 10; 
	int array[a];
	
	Date d(2020, 9, 11);
	return 0;
}
#endif




// Time�ࣺ���д��в����Ĺ��캯��
// ע�⣺�û��Ѿ���ʽ�����˴��в����Ĺ��캯���������������������Ĭ�ϵĹ��캯����
#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int):" << this << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

// ���һ����A�а�������B�Ķ�����B�����޲ι��캯��ʱ����A���뽫���ڲ���������B�Ķ��������A���캯��
// ��ʼ���б��λ�ý��г�ʼ��
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(0, 0, 0)  // ����Time��Ĺ��캯����Time��Ķ���_t���г�ʼ��
	{
		cout << "Date(int,int,int):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d(2020, 9, 11);
	return 0;
}
#endif




#if 0
class Time
{
public:
	// �޲εĹ��캯��
	Time(/*int hour, int minute, int second*/)
	{
		// ע�⣺���캯�������Ǹ�ֵ
		_hour = 0;
		_minute = 0;
		_second = 0;
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
	Date(int year, int month, int day)
		//: _t(0, 0, 0)
		// �������Ĺ��캯����Ҫ�ڹ��캯���ĳ�ʼ���б����
	{
		cout << "Date(int,int,int):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d(2020, 9, 11);
	return 0;
}
#endif




#if 0
// ע�⣺��Ա�����ڳ�ʼ���б��г��ֵ��Ⱥ��������������ʼ���Ĵ���
//      �����ĳ�ʼ���������������е���������һ��
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)   
		// ע�⣺��_day��ʼ��_monthʱ��_day��û�г�ʼ��������ʱ�������ֵ�����_day��ʼ��_month,_month�п϶��������ֵ
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2020, 9, 11);
	return 0;
}
#endif




#if 0
class Date
{
public:
	// �������͹��캯����������ת�������ã���Ҫ��ֹ�������͹��캯����ת������
	//explicit Date(int year)
	Date(int year)
		: _year(year)
		, _month(1)
		, _day(1)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << " = " << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d(2020);

	// �������ͨ������
	d = 2021;
	// ���⣺d��һ���������͵Ķ���2021ֻ��һ���������͵�����
	// ��һ���������ݸ�ֵ��һ���������͵Ķ��󣿣�

	// 1. ʹ��2021���õ������͵Ĺ��캯��������һ����������(û�����ֵĶ���)
	// 2. ʹ�ø����������d�����и�ֵ
	// 3. ���ٸ���������
}

int main()
{
	TestDate();
	return 0;
}
#endif




#if 0
// ����һ����ͨ��֮�󣬸�����Դ�����������
// ͳ�ƣ��������ڴ����˶��ٸ������ˣ�
int _count = 0;

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		// , _count(0) // ÿ�ζ���ʼ��Ϊ0
	{
		cout << "Date(int,int,int):" << this << endl;
		_count++; // ͳ��
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++; // ����Ҳͳ��
	}

	~Date()
	{
		--_count;
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	// int _count;   // count����ĳ�Ա����
};

// �����Ҫ֪��Date�ൽ�״����˶��ٸ�����
// ����Ҫ��һ�������������ñ�����ͳ��Date�ഴ���˶��ٸ�����

//��ʽһ��������ͨ�ĳ�Ա���������м���
//���������
//ԭ����ͨ���͵ĳ�Ա������ÿ�������ж����ڣ����ڹ��캯������Ҫ�Լ��������г�ʼ����ÿ�ζ��ǽ�_count��ʼ����һ��ֵ
//��ʾ������ͳ�ƶ�������ļ�����Ӧ��Ҫ�����û���κι�ϵ����Ҫһ������ļ���

//��ʽ��������ȫ�ֱ���---->C�����У�һ������һ��ȫ�ֱ�������ȫ�ֱ��������ٵ�ǰ�������κκ�����ʹ��
//�����Ͽ������Բ���ȫ�ֱ�����ͳ�ƶ���ĸ���
//��ʵ���ϲ��У���Ϊȫ�ֱ����κδ��붼���Զ�������޸�
//���������ж���Ҫ���� + ���ܱ��ⲿ�����޸�(������"��Ա����",��Ϊ��Ա�������Ա������޶����޸�)

int main()
{
	Date d(2020, 9, 11);
	return 0;
}
#endif




#if 1
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
		_count++;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		--_count;
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;

public:
	// ��̬��Ա����������ֻ������������Ҫ�����������ж���
	static int _count;  // ��̬��Ա����������
};

int Date::_count = 0; // ��̬��Ա�����Ķ���

void TestDate()
{
	Date d1(2020, 9, 11);
	Date d2(2020, 9, 11);
	Date d3(2020, 9, 11);
	Date d4(2020, 9, 11);

	Date d5(d1);

	cout << d1._count << endl;
	cout << d2._count << endl;
	cout << d3._count << endl;
	cout << d4._count << endl;
	cout << d5._count << endl;

	// d1��d2���ʵ���ͬһ��count
	cout << &(d1._count) << " " << &(d2._count) << endl;
}

//��̬��Ա��������ͨ���ͳ�Ա����֮�������
//1. ��̬��Ա��������Ҫ�������������г�ʼ��
//2. ��̬��Ա����û�а����ڶ����У�ÿ�����󶼿���ʹ��(�����������)�����������
//3. ��̬��Ա��������Ӱ��һ����Ĵ�С
//4. ��̬��Ա��������ͨ������.���ʣ�Ҳ����ͨ������::��ʽ����
//5. ��̬��Ա���������ڹ��캯����ʼ���б��λ�ó�ʼ������Ϊ�����캯����ʼ���б�λ�ó�ʼ���Ķ��ǰ����ڶ����еĳ�Ա

int main()
{
	cout << "sizeof(Date):" << sizeof(Date) << endl;

	// �ڵ���TestDate()����֮ǰ��������Ҫ֪��Date�ൽ�״����˶��ٸ�����
	// ��ӡ_count

	// ��ʱ������һ������d������_count	����������һ��
	Date d(2020,9,11);
    cout << d._count << endl; 
	cout << "Date::_count:" << Date::_count << endl;

	TestDate();
	return 0;
}
#endif