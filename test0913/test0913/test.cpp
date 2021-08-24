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
		// 注意：如果用户没有显式对_t进行初始化，则编译器调用Time类的默认构造函数来初始化
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
	static int _count;   // 在类中只是声明
};

// 静态成员变量必须：放在类外来定义
// 静态成员变量在类外定义时，不受访问限定符约束
int Date::_count = 0; // 只能在全局作用域中定义

// 在使用时必须要受到访问限定符的约束
int g_a = Date::_count;

int main()
{
	// int Date::_count = 0; // 当前范围内的定义或重新声明非法

	Date d(2020, 9, 13);

	//Date::_count = 0;   // 访问Date类中的静态成员变量
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

	// 静态成员函数的核心本质：静态成员函数没有this指针
	// 不需要通过对象来访问
	// 不能访问非静态的成员变量
	// 不能访问非静态的成员函数
	// 不能使用const修饰--->const修饰成员函数：实际是在修饰this指针
	static int GetCount()//const
	{
		// 因为非静态的成员变量是包含在某个具体的对象中
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
	static int _count;   // 在类中只是声明
};

// 静态成员变量必须在类外全局作用域中定义
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

	//d1._day = 14;  私有的成员变量不允许直接在类外进行访问
	d1.SetDay(14);   // 一般都是通过提供public的方法来操作私有的成员变量

	//Date::SetDay(14); //有具体日期
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
// 演示：输出运算符不能重载成类的成员函数，因为与常规的调用逻辑不相符
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	// 注意：如果在成员函数中一定不会对成员变量修改时，为了提高代码的安全性，最好将该成员函数设置成const成员函数
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

	// cout可以直接打印内置类型的数据
	int a = 10;
	cout << a << endl;
	// cout不能直接打印自定义类型对象
	//cout << d << endl;

	// 这样打印出来
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

// 输出运算符重载：必须要有返回值类型，返回ostream&
// 目的：为了支持连续输出
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
	// cout是ostream类的对象
	//operator<<(operator<<(cout, d), d1);

	cout << 10 << "  " << 20 << endl;
	//cout << endl; <===>cout<<"/n"; // 相当于换行
	return 0;
}
#endif




#if 0
class Date
{
private:  // 不受限制
	// 友元函数
	// 注意: 友元函数不是类的成员函数
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend void TestFriend(); // 友元函数
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
	friend void TestFriend(); // 友元函数
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

// 一个函数可以是多个类的友元函数
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
//在C语言中：可以变量  可以修饰函数的参数   可以修饰函数的返回值
//在C++中：
// 可以变量  
// 修饰函数的参数--->修饰的是形参，表明在函数中不能对形参进行修改
// 修饰函数的返回值--->表明返回值不能修改，即在外部接收返回值时，只能以const类型的指针接受
// 修饰类的成员函数--->本质是在修饰成员函数的this指针,即this指针指向对象中的内容就不能被修改
// 修饰类的成员变量--->该成员变量不能修改，而且必须要在构造函数初始化列表的位置访问
#if 1
class Time
{
	friend class Date;// Date类是Time类的友元类，则可以在Date类中直接访问Time类的私有成员了
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