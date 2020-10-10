#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// 1.求1 + 2 + 3 + ... + n，
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句
class Sum
{
public:
	Sum() // 编译器自动创建构造函数
	{
		count++;
		sum += count;
	}

	static void Reset()
	{
		count = 0;
		sum = 0;
	}

	static int GetSum() // 声明
	{
		return sum;
	}

private:
	// 静态类型的成员变量
	static int count; // 用来表示加的每一项
	static int sum; // 用来累计最后加的结果
};

int Sum::count = 0; // 定义
int Sum::sum = 0;

class Solution 
{
public:
	int Sum_Solution(int n) 
	{
		Sum::Reset();
		Sum s[n];
		return Sum::GetSum();
	}
};

//int main()
//{
//	Sum s1[3];
//	cout << Sum::GetSum() << endl; // 1+2+3=6
//
//	// 将上一次的结果清零
//	Sum::Reset();
//
//	Sum s2[5];
//	cout << Sum::GetSum() << endl; // 1+2+3+4+5=15
//	
//	return 0;
//}
#endif





#if 0
// 日期类的实现
// 运算符重载作用：为了提高代码的可读性
// 函数重载：一些函数在相同作用域、函数名字相同、参数列表不同，与函数返回值类型是否相同无关
// 注意：哪些运算符不能重载？
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


	//////////////////////////////////////////////////////////////////////////////
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


	//////////////////////////////////////////////////////////////////////////////
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

	Date d4(2021, 1, 1);
	cout << d1 - d4 << endl;
	return 0;
}
#endif





#if 0
// 2.计算日期到天数的转换
// 根据输入的日期，计算是这一年的第几天
// 详细描述：
// 输入某年某月某日，判断这一天是这一年的第几天？

int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;

	// 假设：2020,9,20
	// 1. 只需将前8个月每个月的天数加起来
	// 2. 最后加上9月份的20天
	// 3. 注意闰年

	// 循环接收多组测试用例
	while (cin >> year >> month >> day)
	{
		// 每次接受到一组测试用例，然后计算该组用例
		// 统计month-1每个月的天数
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

int main()
{
	char sz[1024] = { 0 };

	// 注意：如果需要接收一整行字符串的情况下，不能直接使用scanf和cin
	// 因为scanf和cin遇到空格就停止接收，空格之后的内容接收不了
	//cin >> sz;
	//scanf("%s", sz);

	while (gets(sz))
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

