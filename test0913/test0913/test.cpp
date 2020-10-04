#define _CRT_SECURE_NO_WARNINGS 1




/*
const:
在C语言中：可以变量  可以修饰函数的参数   可以修饰函数的返回值
在C++中：
const修饰类成员变量----该成员变量不能修改，而且必须要在构造函数初始化列表的位置访问
const修饰类成员函数
*/

/*
Date类是Time类的友元类，则可以再Date类中直接访问Time类的私有成员了
*/
class Time
{
	friend class Date;
public:
	Time(int hour, int minute, int second)
	{
		cout << "Time()" << endl;
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


	/*
	const修饰非静态成员函数：本质是在修饰成员函数的this指针
	即：this指针指向对象中的内容就不能被修改
	*/
	const Date* TestDate(const int& a)const
	{
		//_day = 10;
		return this;
	}


	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << "  " << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};


int main()
{


	return 0;
}