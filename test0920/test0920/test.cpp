#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// 日期类的实现
// 运算符重载作用：为了提高代码的可读性
// 函数重载：一些函数在相同作用域、函数名字相同、参数列表不同，与函数返回值类型是否相同无关
// 注意：哪些运算符不能重载？
#if 0
class Date
{
public:
	// 全缺省的构造函数
	// 如果遇到非法的日期，将该日期构成默认的日期
	Date(int year = 1900, int month = 1, int day = 1)// 带上默认参数
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!((year > 0) &&
			(month >= 1 && month <= 12) &&
			(day >= 1 && day <= GetMonthDay(year, month))))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			// 检测该年是否为闰年
			if (isLeapYear(year))
				days[2] += 1;
		}
		return days[month];
	}

	bool isLeapYear(int year)const
	{
		// 四年一润百年不润，每四百年再一润
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}

	// 拷贝构造函数
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	// 赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 析构函数
	~Date()
	{}

	friend ostream& operator<<(ostream& _cout, const Date& d);


	////////////////////////////////////////////////////////////////////////////////////////////
	// 注意：复用之前重载的运算符，可以让代码实现起来更加的简单
	// >运算符重载
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

	// ==运算符重载
	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	// 注意：==和!=是同时出现的
	// !=运算符重载
	bool operator != (const Date& d)const
	{
		return !(*this == d);
	}

	// >=运算符重载
	bool operator >= (const Date& d)
	{
		if (*this > d || *this == d)
			return true;
		return false;
	}

	// <运算符重载
	bool operator < (const Date& d)const
	{
		if (!(*this > d || *this == d))
			return true;
		return false;
	}

	// <=运算符重载
	bool operator <= (const Date& d)const
	{
		if (*this < d || *this == d)
			return true;
		return false;
	}


	///////////////////////////////////////////////////////////////////////////////////////
	// 日期+天数
	Date operator+(int days)
	{
		// 必须要将days加到当前对象上
		//_day += days;
		//return *this;
		// 注意：不能将天数加到当前对象上，因为+的左操作数就被修改了
		// 不符合+的规则

		if (days < 0)
		{
			return *this - (0 - days);
		}

		Date temp(*this);
		temp._day += days;

		// temp日期可能会非法：如果_day超过本年本月的天数，日期肯定会是非法的
		int daysOfMonths = 0;
		while (temp._day >(daysOfMonths = temp.GetMonthDay(temp._year, temp._month)))
		{
			temp._month += 1;
			if ((temp._month > 12))
			{
				temp._year += 1;
				temp._month = 1;
			}
			temp._day -= daysOfMonths;
		}
		return temp;
	}

	// 日期-天数
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date temp(*this);
		temp._day -= days;

		// temp日期非法
		while (temp._day <= 0)
		{
			temp._month -= 1;
			if (temp._month == 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += temp.GetMonthDay(temp._year, temp._month);
		}
		return temp;
	}

	// 前置++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	// 前置--
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	// 后置--
	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	// 日期-日期 返回天数
	// *this和d之间的差值
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);
		if (minDate > maxDate)
		{
			minDate = d;
			maxDate = *this;
		}

		int count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}

		return count;
	}

private:
	int _year;
	int _month;
	int _day;
};

// <<的重载
// 1.必须要重载成全局函数---因为它的第一个参数必须是ostream&
// 2.如果重载成成员函数，则其第一个参数就是this指针，调用是反的 d<<cout;
// 3.必须要有返回值，为了支持连续输出
// 4.在函数体中输出时，尽量避免一些格式化的操作，比如换行
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	Date d1(2020, 9, 20);
	Date d2;
	//d2 = d1 + 999;
	d2 = d1 - 999;
	cout << d1 << endl;
	cout << d2 << endl;

	Date d3(2020, 9, 100);
	cout << d3 << endl;

	Date d4(2020, 9, 20);
	Date d5;
	d5 = d4 + 999;
	cout << d5 << endl;
	Date d6;
	d6 = d4 - 999;
	cout << d6 << endl;

	Date d7(2021, 1, 1);
	cout << d1 - d7 << endl;
	return 0;
}
#endif




// 1.求1 + 2 + 3 + ... + n，
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句
#if 0
class Sum
{
public:
	Sum() // 编译器自动创建构造函数
	{
		count++;
		sum += count;
	}

	static void Reset() //不需要返回值
	{
		count = 0;
		sum = 0;
	}

	static int GetSum()
	{
		return sum;
	}

private:
	// 静态类型的成员变量
	static int count; // 用来表示加的每一项
	static int sum; // 用来累计最后加的结果
};

// 静态类型的成员变量在类外初始化
int Sum::count = 0; // 定义
int Sum::sum = 0;

// static成员变量是所有对象共享的，并且有多组测试用例
class Solution 
{
public:
	int Sum_Solution(int n) 
	{
		Sum::Reset(); //每次计算之前清0
		Sum s[n]; //构造自加
		return Sum::GetSum();
	}
};
#endif




// 2.计算日期到天数的转换
// 根据输入的日期，计算是这一年的第几天

// 假设：2020,9,20	
// 1. 只需将前8个月每个月的天数加起来	
// 2. 最后加上9月份的20天	
// 3. 注意闰年
#if 0
#include <iostream>
using namespace std;

int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;

	// 循环接收多组测试用例
	while (cin >> year >> month >> day)
	{
		// 每次接受到一组测试用例，然后计算该组用例，统计month-1每个月的天数
		int totalDays = 0;
		for (int i = 0; i < month; ++i)
		{
			totalDays += days[i];
		}

		if ((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
		{
			if (month>2)
				totalDays += 1;
		}

		totalDays += day;
		cout << totalDays << endl;
	}
	return 0;
}
#endif




// 题目：一行有多个单词
// 需求：输入一行中最后一个单词
#if 0
int main()
{
	char sz[1024] = { 0 };

	// 注意：如果需要接收一整行字符串的情况下，不能直接使用scanf和cin
	// 因为scanf和cin遇到空格就停止接收，空格之后的内容接收不了
	//cin >> sz;
	//scanf("%s", sz);

	while (gets_s(sz))
	{
		// 实际从后往前找，找到第一个空格
		int i = strlen(sz);
		for (; i >= 0; i--)
		{
			if (sz[i] == ' ')
				break;
		}

		// 处理一行只有一个单词，该行就没有空格
		if (i < 0)
		{
			i = 0;
			cout << sz + i << endl;
		}

		else
			cout << sz + i + 1 << endl;
	}
	return 0;
}
#endif




// 3.日期差值
// 有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
// 思路：
// 1. 分别求出每一个日期与0000年0月1日距离的天数
// 2. 两个距离天数相减即可得到两个日期相差的天数
#if 0
#include <iostream>
using namespace std;

//平年从1月到n月的天数
int mon[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

//给出年月日，计算距离0000年0月1日的天数和
int CountDay(int y, int m, int d)
{
	// 计算0-y年的天数
	int yearDay = y * 365 + y / 4 - y / 100 + y / 400;

	// 计算到0-m月的天数
	int monthDay = mon[m - 1];
	if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		monthDay += 1;

	return yearDay + monthDay + d;
}

int main()
{
	int year1, month1, day1;
	scanf("%4d%2d%2d", &year1, &month1, &day1);
	int n1 = CountDay(year1, month1, day1);

	int year2, month2, day2;
	scanf("%4d%2d%2d", &year2, &month2, &day2);
	int n2 = CountDay(year2, month2, day2);

	cout << abs(n1 - n2) + 1 << endl;
}
#endif




// 4.打印日期
// 给出年分m和一年中的第n天，算出第n天是几月几号
#if 0
#include <iostream>
using namespace std;

int main()
{
	int year;
	int day;

	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year >> day)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			mon[1] = 29;
		else
			mon[1] = 28;

		for (int i = 0; i < 12; i++)
		{
			if (day <= mon[i])
			{
				printf("%04d-%02d-%02d\n", year, i + 1, day);
				break;
			}
			else
			{
				day = day - mon[i];
			}
		}
	}
	return 0;
}
#endif




// 5.累加天数
// 输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数
#if 0
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			int y, m, d, num;
			int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			cin >> y >> m >> d >> num;

			while (num > 0)
			{
				if (num > days[m - 1] - d)
				{
					if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) // 来判断这一年是否是闰年
						days[1] = 29;
					else
						days[1] = 28;

					num -= days[m - 1] - d;
					d = 0;
					m++;
					if (m == 13)
					{
						y++;
						m = 1;
					}
				}
				else
				{
					d += num;
					break;
				}
			}
			printf("%4d-%02d-%02d\n", y, m, d);
		}
	}
	return 0;
}
#endif
