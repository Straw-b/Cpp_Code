#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// 复数类
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

	// 复数类的构造函数 + 拷贝构造函数 + 赋值运算符函数--->三个函数可以不用实现
	// 涉及资源管理时需要实现
private:
	double _real; // 实部
	double _image; // 虚部
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
	cout << &d1 << endl;// 调用Date* operator&()
	cout << &d2 << endl;// 调用const Date* operator&()const

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
		// 注意：构造函数体中是赋值而不是初始化
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

	// 该方法的本质：获取当前日期中的年份，在获取期间是不能对当前对象中成员进行修改，代码不安全
	// 为了保证安全性，禁止this指针指向的对象被修改，用const修饰
	// const修饰的成员函数：称为const成员函数
	// const本质：修饰this指针指向的对象，表明const成员函数中不能修改类成员变量
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