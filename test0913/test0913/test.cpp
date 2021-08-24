#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
	{
		cout << "Time(int,int,int)" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
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
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(0, 0, 0)   
		// ע�⣺����û�û����ʽ��_t���г�ʼ���������������Time���Ĭ�Ϲ��캯������ʼ��
		//, _count(0)
	{
		cout << "Date(int,int,int)" << endl;
		/*_year = year;
		_month = month;
		_day = day;*/
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;

public:
	static int _count;   // ������ֻ������
};

// ��̬��Ա�������룺��������������
// ��̬��Ա���������ⶨ��ʱ�����ܷ����޶���Լ��
int Date::_count = 0; // ֻ����ȫ���������ж���

// ��ʹ��ʱ����Ҫ�ܵ������޶�����Լ��
int g_a = Date::_count;

int main()
{
	// int Date::_count = 0; // ��ǰ��Χ�ڵĶ�������������Ƿ�

	Date d(2020, 9, 13);

	//Date::_count = 0;   // ����Date���еľ�̬��Ա����
	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
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
	}

	void SetDay(/*Date* const this,*/int day)
	{
		_day = day;
		//this->_day = day;
	}

	// ��̬��Ա�����ĺ��ı��ʣ���̬��Ա����û��thisָ��
	// ����Ҫͨ������������
	// ���ܷ��ʷǾ�̬�ĳ�Ա����
	// ���ܷ��ʷǾ�̬�ĳ�Ա����
	// ����ʹ��const����--->const���γ�Ա������ʵ����������thisָ��
	static int GetCount()//const
	{
		// ��Ϊ�Ǿ�̬�ĳ�Ա�����ǰ�����ĳ������Ķ�����
		// this->_day = 10;

		// SetDay(10);

		//cout << this << endl;
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;

//public:
private:
	static int _count;   // ������ֻ������
};

// ��̬��Ա��������������ȫ���������ж���
int Date::_count = 0;

void TestDate()
{
	Date d3(2020, 9, 13);
	Date d4(d3);
	//cout << Date::_count << endl;
	cout << Date::GetCount() << endl;
}

int main()
{
	//cout << Date::_count << endl;
	cout << Date::GetCount() << endl;

	Date d1(2020, 9, 13);
	Date d2(d1);

	//cout << Date::_count << endl;
	cout << d1.GetCount() << endl;

	TestDate();

	//d1._day = 14;  ˽�еĳ�Ա����������ֱ����������з���
	d1.SetDay(14);   // һ�㶼��ͨ���ṩpublic�ķ���������˽�еĳ�Ա����

	//Date::SetDay(14); //�о�������
	//cout << Date::_count << endl;

	//Date::_count = 100;
	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	Date()
		/*: _year(1900)
		, _month(1)
		, _day(1)*/
	{}

private:
	int _year = 1900;
	int _month = 1;
	int _day = 1;
};

int main()
{
	Date d1(2020, 9, 13);
	Date d2;

	return 0;
}
#endif




#if 0
// ��ʾ�����������������س���ĳ�Ա��������Ϊ�볣��ĵ����߼������
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	// ע�⣺����ڳ�Ա������һ������Գ�Ա�����޸�ʱ��Ϊ����ߴ���İ�ȫ�ԣ���ý��ó�Ա�������ó�const��Ա����
	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
		{
			return true;
		}
		return false;
	}

	// void operator<<(Date* const this, ostream& _cout)
	void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2020, 9, 13);
	Date d1(2020, 9, 11);
	d.PrintDate();

	// cout����ֱ�Ӵ�ӡ�������͵�����
	int a = 10;
	cout << a << endl;
	// cout����ֱ�Ӵ�ӡ�Զ������Ͷ���
	//cout << d << endl;

	// ������ӡ����
	//cout << d;
	d << cout;
	d.operator<<(cout);  // ===>Date::operator<<(&d, cout);

	if (d > d1)
	{
		cout << "d > d1" << endl;
	}
	else
	{
		cout << "d <= d1" << endl;
	}
	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

//private:
public:
	int _year;
	int _month;
	int _day;
};

// �����������أ�����Ҫ�з���ֵ���ͣ�����ostream&
// Ŀ�ģ�Ϊ��֧���������
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	Date d(2020, 9, 13);
	Date d1(2020, 9, 11);

	//cout << d;
	cout << d << "  " << d1 << endl;    // cout<<d; cout<<d1;
	// cout��ostream��Ķ���
	//operator<<(operator<<(cout, d), d1);

	cout << 10 << "  " << 20 << endl;
	//cout << endl; <===>cout<<"/n"; // �൱�ڻ���
	return 0;
}
#endif




#if 0
class Date
{
private:  // ��������
	// ��Ԫ����
	// ע��: ��Ԫ����������ĳ�Ա����
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend void TestFriend(); // ��Ԫ����
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	int GetYear()const
	{
		return _year;
	}

	int GetMonth()const
	{
		return _month;
	}

	int GetDay()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Time
{
	friend void TestFriend(); // ��Ԫ����
public:
	Time(int hour, int minute, int second)
	{
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	//_cout << d.GetYear() << "-" << d.GetMonth() << "-" << d.GetDay();
	return _cout;
}

// һ�����������Ƕ�������Ԫ����
void TestFriend()
{
	Time t(0, 0, 0);
	t._hour = 11;

	Date d(2020, 9, 13);
	d._day = 13;
}

int main()
{
	TestFriend();

	Date d(2020, 9, 13);
	cout << d << endl;
	return 0;
}
#endif




// const
//��C�����У����Ա���  �������κ����Ĳ���   �������κ����ķ���ֵ
//��C++�У�
// ���Ա���  
// ���κ����Ĳ���--->���ε����βΣ������ں����в��ܶ��βν����޸�
// ���κ����ķ���ֵ--->��������ֵ�����޸ģ������ⲿ���շ���ֵʱ��ֻ����const���͵�ָ�����
// ������ĳ�Ա����--->�����������γ�Ա������thisָ��,��thisָ��ָ������е����ݾͲ��ܱ��޸�
// ������ĳ�Ա����--->�ó�Ա���������޸ģ����ұ���Ҫ�ڹ��캯����ʼ���б��λ�÷���
#if 1
class Time
{
	friend class Date;// Date����Time�����Ԫ�࣬�������Date����ֱ�ӷ���Time���˽�г�Ա��
public:
	Time(int hour, int minute, int second)
	{
		_hour = 0;
		_minute = 0;
		_second = 0;
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
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(12, 15, 13)
	{}

	const Date* TestDate(const int& a)const
	{
		//_day = 10;
		return this;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << "-" << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d(2020, 9, 13);
	d.PrintDate();
	return 0;
}
#endif