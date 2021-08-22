#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// ������
class Complex
{
public:
	Complex(double real, double image)
	{
		_real = real;
		_image = image;
	}

	Complex& operator=(const Complex& c);
	bool operator>(const Complex& c);
	bool operator<(const Complex& c);
	bool operator==(const Complex& c);
	bool operator!=(const Complex& c);
	bool operator+(const Complex& c);
	bool operator-(const Complex& c);
	bool operator*(const Complex& c);
	bool operator/(const Complex& c);

	// ������Ĺ��캯�� + �������캯�� + ��ֵ���������--->�����������Բ���ʵ��
	// �漰��Դ����ʱ��Ҫʵ��
private:
	double _real; // ʵ��
	double _image; // �鲿
};
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

		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;

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

	// operator&
	Date* GetAddr()
	{
		return this;
	}

	Date* operator&()
	{
		return this;
	}

	const Date* operator&()const
	{
		cout << this << endl;
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date TestDate1(Date d)
{
	Date temp(d);
	temp = d;
	return temp;
}
void Test1()
{
	Date d1(2020, 8, 8);
	Date d2(2020, 8, 9);
	d1 = TestDate1(d2);
}

Date& TestDate2(Date& d)
{
	Date temp(d);
	temp = d;
	return d;
}
void Test2()
{
	Date d1(2020, 8, 8);
	Date d2(2020, 8, 9);
	d1 = TestDate2(d2);

	cout << &d1 << endl;
	cout << &d2 << endl;
}

int main()
{
	Date d1(2020, 9, 9); 
	const Date d2(2020, 9, 9); 
	cout << &d1 << endl;// ����Date* operator&()
	cout << &d2 << endl;// ����const Date* operator&()const

	//Test1();
	//Test2();
	return 0;
}
#endif




#if 1
class Date
{
public:
	Date(int year, int month, int day)
	{
		// ע�⣺���캯�������Ǹ�ֵ�����ǳ�ʼ��
		_year = year;
		_month = month;
		_day = day;
		// _day = 2020;
		// ra = year;
	}

	void SetYear(int year)
	{
		_year = year;
	}

	// �÷����ı��ʣ���ȡ��ǰ�����е���ݣ��ڻ�ȡ�ڼ��ǲ��ܶԵ�ǰ�����г�Ա�����޸ģ����벻��ȫ
	// Ϊ�˱�֤��ȫ�ԣ���ֹthisָ��ָ��Ķ����޸ģ���const����
	// const���εĳ�Ա��������Ϊconst��Ա����
	// const���ʣ�����thisָ��ָ��Ķ��󣬱���const��Ա�����в����޸����Ա����
	int GetYear()const
	{
		//++_year;
		return _year;
	}

private:
	int _year;
	int _month;
	int _day;
	// int& ra;
};

int main()
{
	Date d(2020, 9, 9);
	cout << d.GetYear() << endl;
	return 0;
}
#endif