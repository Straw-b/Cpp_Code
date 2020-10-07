#include <iostream>
using namespace std;



#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		// 注意：构造函数体中是赋值,而不是初始化
		_year = year;
		_month = month;
		_day = day;
		_day = 2020;
		// ra = year;
	}

	void SetYear(int year)
	{
		_year = year;
	}

	// 该方法本质：获取当前日期中的年份
	// 在获取期间是不能对当前对象中成员进行修改
	// 代码不安全

	// 为了保证代码的安全性，禁止this指向指向的对象被修改
	// 如何禁止？  用const修饰this指针指向的对象
	// const修饰的成员函数：称为const成员函数
	// const本质：修饰this指针指向的对象，表明const成员函数中不能修改类成员变量的
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




#if 0
// 构造函数与其他成员函数最主要的区别：构造函数具有初始化列表
// 初始化列表作用：完成对类成员变量的初始化工作

class Time
{
public:
	// 注意：如果一个类没有显式定义任何构造函数，则编译器会生成一个默认的构造函数(无参的构造函数)
	// 一旦用户显式定义，则编译器不再生成
	// Time类不存在默认的构造函数
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

// 如果一个类A中包含有类B的对象，类B具有无参构造函数时，
// 类A必须将其内部包含的类B的对象 放在类A构造函数初始化列表的位置 进行初始化
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(0, 0, 0) //显式初始化
		, ra(_day) // 引用类型成员变量
		, ca(10) // const类型成员变量
		// , _day(day)
	{ } // {}是Date类构造函数的函数体，我们暂时没有在构造函数体中写任何有效的代码

private:
	int _year;
	int _month;
	int _day;
	Time _t;

	int& ra; // 引用类型成员变量
	const int ca; // const类型成员变量
};

int main()
{   
	// 被const修饰的变量，在C++中已经是一个常量了，而且在定义时候必须对其进行初始化
    const int a = 10;
	//a = 10; 
	int array[a];
	
	Date d(2020, 9, 11);
	return 0;
}
#endif




#if 0
// Time类：具有带有参数的构造函数
// 注意：用户已经显式定义了带有参数的构造函数，则编译器不会再生成默认的构造函数了
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

// 如果一个类A中包含有类B的对象，类B具有无参构造函数时，类A必须将其内部包含的类B的对象放在类A构造函数
// 初始化列表的位置进行初始化
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(0, 0, 0)  // 调用Time类的构造函数对Time类的对象_t进行初始化
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
	// 无参的构造函数
	Time(/*int hour, int minute, int second*/)
	{
		// 注意：构造函数体中是赋值
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
// 注意：成员变量在初始化列表中出现的先后次序不是其真正初始化的次序
//      真正的初始化次序与其在类中的声明次序一致
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)   
		// 注意：在_day初始化_month时，_day还没有初始化，即暂时还是随机值，因此_day初始化_month,_month中肯定就是随机值
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
	// 单参类型构造函数具有类型转换的作用
	// 想要禁止单参类型构造函数的转换作用
	explicit Date(int year)
	// Date(int year)
		: _year(year)
		, _month(1)
		, _day(1)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	Date& operator=(const Date& d) // 赋值运算符的重载
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

	// 代码可以通过编译
	d = 2021;
	// 问题：d是一个日期类型的对象，2021只是一个整形类型的数据
	// 将一个整形数据赋值给一个日期类型的对象？！

	// 1. 使用2021调用单参类型的构造函数，构造一个匿名对象(没有名字的对象)
	// 2. 使用该匿名对象给d来进行赋值
	// 3. 销毁该匿名对象
}

int main()
{
	TestDate();
	return 0;
}
#endif




#if 0
// 创建一个普通类之后，该类可以创建许多个对象
// 统计：该类现在创建了多少个对象了？

int _count = 0;

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		// , _count(0) // 每次都初始化为0
	{
		cout << "Date(int,int,int):" << this << endl;
		_count++; // 统计
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++; // 拷贝也统计
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
	// int _count;   // count是类的成员变量
};

// 如果想要知道Date类到底创建了多少个对象？
// 必须要有一个计数变量：该变量来统计Date类创建了多少个对象

/*
方式一：采用普通的成员变量来进行计数
结果：不行
原因：普通类型的成员变量，每个对象中都存在，而在构造函数中需要对计数来进行初始化，每次都是将_count初始化成一个值

提示：用来统计对象个数的计数：应该要与对象没有任何关系，需要一个共享的计数

方式二：采用全局变量---->C语言中，一旦定义一个全局变量，该全局变量可以再当前工程中任何函数中使用
表面上看：可以采用全局变量来统计对象的个数
但实际上不行：因为全局变量任何代码都可以对其进行修改
不行

计数：所有对象都要共享 + 不能被外部随意修改(变成类的"成员变量",因为成员变量可以被访问限定符修改)
*/

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
	// 静态成员变量在类中只是声明，必须要在类外来进行定义
	static int _count;  // 静态成员变量的声明
};

int Date::_count = 0; // 静态成员变量的定义

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

	cout << &(d1._count) << " " << &(d2._count) << endl;
}

/*
静态成员变量和普通类型成员变量之间的区别：
1. 静态成员变量必须要放在类外来进行初始化
2. 静态成员变量没有包含在对象中，每个对象都可以使用(所有类对象共享)，是类的属性
3. 静态成员变量不会影响一个类的大小
4. 静态成员变量可以通过对象.访问，也可以通过类名::方式访问
5. 静态成员变量不能在构造函数初始化列表的位置初始化，因为：构造函数初始化列表位置初始化的都是包含在对象中的成员
*/

int main()
{
	cout << "sizeof(Date):" << sizeof(Date) << endl;

	// 在调用TestDate()函数之前，现在想要知道Date类到底创建了多少个对象
	// 打印_count

	// 临时创建了一个对象d来访问_count
	// Date d(2020,9,11);
	// cout << d._count << endl;
	// 计数多了一个

	cout << "Date::_count:" << Date::_count << endl;

	TestDate();
	return 0;
}
#endif