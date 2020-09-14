#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 1
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1) // 构造函数
	{
		_year = year;
		_month = month;
		_day = day;

		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d) // 拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d) // 赋值运算符重载
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

	~Date() // 析构函数
	{
		cout << "~Date():" << this << endl;
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
}

int main()
{
	// Test1();
	Test2();
	return 0;
}
#endif




// 复数类
class Complex
{
public:
	Complex(double real, double image)
	{
		_real = real;
		_image = image;
	}

	Complex& operator=(const Complex& C);
	bool operator>(const Complex& C);
	bool operator<(const Complex& C);
	bool operator==(const Complex& C);
	bool operator!=(const Complex& C);
	bool operator+(const Complex& C);
	bool operator-(const Complex& C);
	bool operator*(const Complex& C);
	bool operator/(const Complex& C);

	// 复数类的构造函数 + 拷贝构造函数 + 赋值运算符函数--->三个函数可以不用实现
private:
	double _real; // 实部
	double _image; // 虚部

};