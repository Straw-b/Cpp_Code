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
	// C语言定义变量方式
	int a1;
	int a2 = 10;
	int a3(10);

	// 需求：当Date类将对象创建好，该对象中就要有初始值
	Date d1; // 对象已经被创建好 
	d1.SetDate(2020, 8, 1); // ---> Date::SetDate(&d, 2020, 8, 1)，进行赋值
	d1.PrintDate();

	//Date d2(2020, 8, 1);  // 定义d2对象并对其进行初始化--构造函数就是完成对对象的初始化工作
	//d2.PrintDate();

	return 0;
}
#endif




// 构造函数是一个特殊的成员函数，特殊：
// 1.构造函数的名字必须与类名相同
// 2.构造函数没有返回值类型，即使加void也不行
// 3.构造函数是在创建对象时由编译器自动进行调用，并且在对象的生命周期内只调用一次
// 作用：主要是创建对象时，完成对当前对象的初始化工作
// 初始化：给对象开辟空间，给对象中放置初始值

#if 0
class Date
{
public:
    // 构造函数，一般是用户自己写，不能给返回参数	
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		// return 0; // 不能返回
		// return; //可以，该种写法表示：并没有返回一个实际的内容，表明函数从该位置退出

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
	// d对象是函数中的一个局部的对象，在函数退出时该对象就要被销毁
	// d的声明周期随着函数的结束而结束
	Date d(2020, 8, 2);
	d.PrintDate();
}

int main()
{
	TestDate();

	Date d1(2020, 8, 1);  // 我们并没有显式(用户没有写出调用构造函数的语句)调用构造函数
	d1.PrintDate();

	// Date d2;
	return 0;
}
#endif




#if 0
// 构造函数可以重载
class Date
{
public:
	// 该构造函数只能创建带有三个参数的对象，不能创建无参的对象
	Date(int year, int month, int day) // 带参构造函数
	{
		/*this->*/_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date() // 无参构造函数
	{
		_year = 1900; // 默认日期
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




// 如果一个类没有显式定义(用户写出)任何构造函数，编译器会生成一个默认的构造函数，
// 注意：编译器生成的构造函数一定是无参的，用户一旦给出构造函数，编译器就不会生成了
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

	Date d2(2020, 8, 1);  // 在创建对象时，要调用Date(int,int,int)
	d2.PrintDate();
	return 0;
}
#endif




// 全缺省的构造函数 和 无参的构造函数统称为 默认的构造函数
// 并且：全缺省的构造函数 和 无参的构造函数不能同时存在
#if 0
class Date
{
public:
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	//// 无参的构造函数
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




// 用户没有定义构造函数时，编译器生成无参的构造函数，那么它给对象初始化成什么值？还会是随机值吗？
// 编译器生成的默认构造函数中：
// 将对象中内置类型定义的成员变量初始化为随机值
// 将对象中包含的类类型对象成员---调用成员对应类的默认构造函数来初始化
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
	// 如果用户没有显式定义构造函数，编译器才会生成一个默认的构造函数
	// 注意：编译器生成的构造函数一定是无参的

	// 自己写构造函数，编译器对函数也进行修改了
	// 在Date类构造函数执行时，先跳转到Time类构造函数位置执行，将日期类中的_t的对象初始化完整
	// 然后再执行Date类的构造函数体给_year\_month\_day来进行赋值
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

	Time _t; // 对象里面包含对象
};

int main()
{
	// 编译器给日期类生成了一个默认的构造函数
	// 在生成的默认的构造函数中调用了Time类的构造函数，目的：将日期类中包含的Time类的对象初始化完成
	Date d;  // 会调用编译器生成的默认构造函数(无参)   call Date()
	d.PrintDate();

	Date dd(2020, 8, 1);
	dd.PrintDate();
	// dd对象在创建时，需要调用带有三个int类型参数的构造函数
	// 而该构造函数用户并没有提供，编译器只能生成无参的默认构造函数
	// 表示该类没有带有三个int类型的构造函数---dd对象没有办法创建--->编译失败
	return 0;
}
#endif




#if 0
#include <malloc.h>
typedef int DataType;

class SeqList
{
public:
	// 对象在创建时，给对象中放数据(资源)
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		_capacity = capacity;
		_size = 0;
	}
	
	// 析构函数
	// 在对象销毁时，必须要将对象中的资源清理掉
	// 在对象被销毁时，由编译器自动进行调用，完整对象中资源清理工作
	// 析构函数一定是无参的，不能带有任何类型的参数，不能有返回值
	// 一个类只能有一个析构函数

	~SeqList() // 无参数无返回值
	{
		if (_array)// 看有无空间
		{
			free(_array);
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(DataType data)
	{
		// 扩容
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
	// 在构造Person对象p时，从汇编代码中看到，编译器给Person类生成了一个默认的构造函数，
	// 而生成的默认构造函数中，主要调用了String类的构造函数，目的就是对p对象中所包含的String类型的name来进行初始化
	// 注意：在Person p行不能直接调用call String(), 因为在Person p行创建的是一个Person类型的对象，就要调用Person的构造函数，
	// 来完成Person对象中所包含的String类型的name的初始化工作，因此编译器给Person类生成一个默认的构造函数

	// 在P对象销毁时，因为p对象中包含有String类型的name，name中管理了资源，
	// 因此必须要调用String类的析构函数，完成p对象中所包含的String类型的name的资源清理工作
	// 但是在函数退出时，不能直接调用String类的析构函数，因为现在析构的是Person类的对象，直接调用String类的析构函数讲不通

	// 析构哪个类的对象，调用哪个类的析构函数
	// 因此：编译器给Person类生成了一个默认的析构函数，在默认的析构函数中调用String类的析构函数
	// 完成p对象中所包含的String类型name的资源清理工作

	//编译器给Person类生成的析构函数
	//~Person()
	//{
	//    call ~String();  // 清理Person类对象中包含的String类型成员name中的资源
	//}
}

int main()
{
	TestPerson();
	TestString();
	return 0;
}
#endif