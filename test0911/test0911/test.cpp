#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;



#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)

	{

	}

private:
	int _hour;
	int _minute;
	int _second;
};


// 如果一个类A中包含有类B的对象
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(0,0,0)
		, ra(day)
		, ca(10)
		//, _day(day)

	{
		//_year = year;

	}

private:
	int _year;
	int _month;
	int _day;

	int& ra;
	const int ca;
	Time _t;
};

int main()
{
	const int a = 10;  // 被const修饰的变量，在C++中已经是一个常量了

	int array[10];
	//a = 10;
	Date d(2020, 9, 11);
	return 0;
}
#endif




class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)

	{
		cout << "Date(int,int,int):" << this << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

int main()
{

}