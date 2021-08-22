#define _CRT_SECURE_NO_WARNINGS 1
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

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// 以值的方式传递类类型对象，在传参期间编译器会调用拷贝构造函数构造一个临时的对象
// 缺陷：代码的运行效率低
void TestDate1(Date dd)
{}

// 一般情况下很少使用以值的方式传递类类型的参数，一般都是使用引用的方式作为参数类型
// 优点：参数效率非常高(少了一次拷贝构造调用)
// 缺点：如果修改形参就会修改外部实参
void TestDate2(Date& dd)
{}

// 加const
void TestDate3(const Date& dd)
{}

Date TestDate4()
{
	Date d;  // 栈上创建的对象
	return d;
}

// 在返回值期间，调用构造函数创建了一个匿名对象，因为该匿名对象没有名字，也不能拿到该对象的地址，
// 因此没有办法对该对象进行修改操作，因此编译器就将匿名对象当称一个临时对象用来进行返回了
Date TestDate5()
{
	// 构造函数不能直接调用，是编译器自动进行调用----怎么还可以直接调用构造函数？
	return Date(2020, 8, 8);   // Date(2020,8,8): 创建了一个没有名字的对象---匿名对象
}

int main()
{
	Date d(2020, 8, 8);
	//TestDate1(d);
	//TestDate3(d);

	//TestDate4();
	TestDate5();
	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year > 0 &&
			(month >= 1 && month <= 12) &&
			(day > 0 && day <= GetDaysOfMonth(year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 执行的是前置++的操作
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// 后置++
	// 注意：temp是函数栈上的对象，当函数退出时，temp就要被销毁了
	// 因此后置++的函数返回值不能使用引用的方式进行返回了，只能按照值的方式进行返回
	// 注意：语法为了区分后置++与前置++运算符重载的区别，最终在后置++的函数参数列表中多增加了一个int类型的参数
	//      前置++和后置++就可以形成函数重载了，但是该int类型参数在函数体中并不会使用，因此可以不用该名字
	//      虽然后置++在实现时多了一个int类型的参数，但是用户在调用时不用传递该int实参
	Date operator++(int) // 函数重载
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	// 前置--
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	// 后置--
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}

	// 对=进行重载，赋值运算符重载
	// 参数说明：Date d--->缺陷 在传参期间要创建一个临时对象来给this进行赋值，效率太低了
	//          Date& d---> 优点：在传参期间少创建一个临时对象，效率高了  
	//                      缺陷：在赋值期间不小心将d修改了，外部实参也被修改了
	//          const Date& d
	// 必须要有返回值：目的为了支持连续赋值
	Date& operator=(const Date& d) // 必须返回一个值
	{
		// 避免自己给自己赋值---如何区分：d和this就是同一个对象呢？
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

private:
	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
		{
			return true;
		}
		return false;
	}

	size_t GetDaysOfMonth(size_t year, int month)
	{
		int daysOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
		if (month == 2 && IsLeapYear(year))
			daysOfMonth[2] += 1;

		return daysOfMonth[month];
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 0;
	b = a++; // 内置类型

	int c = 10;
	a = b = c;

	Date d0(2020, 8, 100); // 保证合法性
	d0.PrintDate();

	Date d1(2020, 8, 8);
	Date d2;
	d1.PrintDate();
	d2.PrintDate();
	cout << endl;
	///////////////////////////////////////////////////////
    // 前置++
	d2 = ++d1;
	d2 = d1.operator++(); 
	d1.PrintDate();
	d2.PrintDate();

    // 后置++
	d2 = d1++;
	d2 = d1.operator++(0); 
	d1.PrintDate();
	d2.PrintDate();
	cout << endl;
	///////////////////////////////////////////////////////

	d1 = d2;

	Date d3;
	d3 = d2 = d1;
	d3.operator=(d2.operator=(d1));
	d1.PrintDate();
	d2.PrintDate();
	d3.PrintDate();

	d1 = d1;// 自己给自己进行赋值
	// d5是d1的别名，说明d5和d1是同一个对象
	Date& d5 = d1;
	d5 = d1;// 避免自己给自己进行赋值

	return 0;
}
#endif




// const修饰变量：
// 在C语言中，被const修饰的是一个不能被修改的变量
// 测试： const int a = 10;   int array[a];
//
// 在C++中，被const修饰的已经是一个常量，而且具有宏替换的属性
// void TestConst()
// {
// 	   const int a = 10;
// 	   int* pa = (int*)&a;
//
//	   *pa = 100;
//	   cout << a << endl;     // 10   但是a的值已经是100  原因：在编译阶段，编译器已经将a用10替换了
//	   cout << *pa << endl;   // 100
// }
// const修饰的常量的替换发生在编译阶段，会参与到参数类型检测，代码的安全性更高
// 建议：在C++中使用const修饰的常量代替宏常量


//在C++中，const也可以修饰类的成员
//1. const修饰类的成员变量，表明该成员变量不能被修改的
//2. const修饰类的成员函数---> 称为const类型的成员函数


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

	// 被const修饰的成员函数称为const类型的成员函数
	// const成员函数中不能修改类的"成员变量"
	// const本质修饰的是成员函数的隐藏的this指针
	// 表示：this指针指向的空间中的内容不能修改，即：this指向当前对象不能修改
	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//this->_day++; // 不能修改
		cout << typeid(this).name() << endl; // 打印class Date const *
	}

	// const在返回值类型之前，修饰的该函数的返回值类型
	// 普通成员函数中：可以修改this指向的当前对象的属性信息
	const Date& GetDate()
	{
		cout << typeid(this).name() << endl; // 打印class Date *
		_day++;
		return *this;
	}

	// 建议：如果在成员函数中不需要修改成员变量时，成员函数最好给成const成员函数，因为代码的安全性更高
	//      比如：get系列函数
	//      如果在成员函数中需要修改当前对象的成员，则一定不能使用const成员函数，否则编译失败
	//      比如：set系列函数

	// C++的人性化：
	// 理论上：被const修饰的成员函数中不能修改任何的"成员变量"，
	// 但是有些情况下，可能需要在const成员函数中修改个别成员变量
	void TestFunc()const
	{
		_day++;
		// _month++;
		// _year++;
	}

	// this的类型：Date* const this
	Date* operator&() // 返回地址
	{
		cout << "地址:" << this << endl;
		return this;
	}

	// const修饰成员函数，本质在修饰this指针，this的类型：const Date* const this
	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	mutable int _day;
	//mutable: 单词含义表示可变的，修饰成员变量时，表明该成员变量可以在const成员函数中被修改
};

int main()
{
	Date d1(2020, 8, 8);
	d1.PrintDate();
	d1.GetDate();
	cout << "d1:" << &d1 << endl;

	const Date d2(d1);
	cout << "d2:" << &d2 << endl;
	return 0;
}
#endif




#if 1
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date* operator&()
	{
		cout << this << endl;
		return this;
	}

	const Date* operator&()const
	{
		return this;
	}

	void SetDay(int day)
	{
		_day = day;
	}

	int GetDay()const
	{
		return _day;
	}

	// const类型的成员函数
	void TestFuncWithConst()const
	{
		// SetDay(10);
		// const成员函数中不能调用普通类型的成员函数
		// 因为：const成员函数this指针的类型是 const Date* const
		// 表明：this对象的成员是不能修改的
		// 如果将this传递SetDay，而SetDay在其内部可以对当前对象进行修改
		// 导致代码不安全
		PrintDate();
	}

	// 普通类型的成员函数
	// this指针的类型：Date* const，表明该对象中的成员可以修改也可以不修改
	void TestFuncWithoutConst()
	{
		SetDay(10);
		// SetDay：this指针的类型：Date* const，表明该对象中的成员可以修改也可以不修改
		// this指针的类型完全匹配，没有任何问题

		PrintDate();
		// 结论：普通成员函数中可以调用const成员函数
		// 因为：普通成员函数this指向的对象是可读写，既可以修改也可以不修改
		//       而const成员函数中的对象的成员是不能修改的
		// 在普通成员函数中调用const类型成员函数，将相当于将一个可读写的对象交给一个只读的函数来进行处理了
		// 代码本来就是安全的
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	const Date d1(2020, 8, 8);
	d1.PrintDate();
	// d1.SetDay(9);
	// d1是const类型的对象，表示该对象的成员是不允许被修改的
	// 但是const类型对象如果可以调用普通类型的成员函数，在普通类型的成员函数中可能会将const类型对象的成员修改掉
	// 代码不安全
	// 因此：const类型的对象只能调用const类型的成员函数，不能调用普通类型的成员函数


	Date d2(2020, 8, 8);
	d2.SetDay(9);
	// d2是普通类型的对象，该对象中的成员可以修改也可以不修改
	// 非const类型的对象对于普通成员函数和const类型的成员函数都可以进行调用
	cout << d2.GetDay() << endl;

	return 0;
}
#endif
