#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// �������ʵ��
// ������������ã�Ϊ����ߴ���Ŀɶ���
// �������أ�һЩ��������ͬ�����򡢺���������ͬ�������б�ͬ���뺯������ֵ�����Ƿ���ͬ�޹�
// ע�⣺��Щ������������أ�
#if 0
class Date
{
public:
	// ȫȱʡ�Ĺ��캯��
	// ��������Ƿ������ڣ��������ڹ���Ĭ�ϵ�����
	Date(int year = 1900, int month = 1, int day = 1)// ����Ĭ�ϲ���
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

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			// �������Ƿ�Ϊ����
			if (isLeapYear(year))
				days[2] += 1;
		}
		return days[month];
	}

	bool isLeapYear(int year)const
	{
		// ����һ����겻��ÿ�İ�����һ��
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}

	// �������캯��
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	// ��ֵ���������
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

	// ��������
	~Date()
	{}

	friend ostream& operator<<(ostream& _cout, const Date& d);


	////////////////////////////////////////////////////////////////////////////////////////////
	// ע�⣺����֮ǰ���ص�������������ô���ʵ���������ӵļ�
	// >���������
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

	// ==���������
	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	// ע�⣺==��!=��ͬʱ���ֵ�
	// !=���������
	bool operator != (const Date& d)const
	{
		return !(*this == d);
	}

	// >=���������
	bool operator >= (const Date& d)
	{
		if (*this > d || *this == d)
			return true;
		return false;
	}

	// <���������
	bool operator < (const Date& d)const
	{
		if (!(*this > d || *this == d))
			return true;
		return false;
	}

	// <=���������
	bool operator <= (const Date& d)const
	{
		if (*this < d || *this == d)
			return true;
		return false;
	}


	///////////////////////////////////////////////////////////////////////////////////////
	// ����+����
	Date operator+(int days)
	{
		// ����Ҫ��days�ӵ���ǰ������
		//_day += days;
		//return *this;
		// ע�⣺���ܽ������ӵ���ǰ�����ϣ���Ϊ+����������ͱ��޸���
		// ������+�Ĺ���

		if (days < 0)
		{
			return *this - (0 - days);
		}

		Date temp(*this);
		temp._day += days;

		// temp���ڿ��ܻ�Ƿ������_day�������걾�µ����������ڿ϶����ǷǷ���
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

	// ����-����
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date temp(*this);
		temp._day -= days;

		// temp���ڷǷ�
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

	// ǰ��++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	// ǰ��--
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	// ����--
	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	// ����-���� ��������
	// *this��d֮��Ĳ�ֵ
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

// <<������
// 1.����Ҫ���س�ȫ�ֺ���---��Ϊ���ĵ�һ������������ostream&
// 2.������سɳ�Ա�����������һ����������thisָ�룬�����Ƿ��� d<<cout;
// 3.����Ҫ�з���ֵ��Ϊ��֧���������
// 4.�ں����������ʱ����������һЩ��ʽ���Ĳ��������绻��
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




// 1.��1 + 2 + 3 + ... + n��
// Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж����
#if 0
class Sum
{
public:
	Sum() // �������Զ��������캯��
	{
		count++;
		sum += count;
	}

	static void Reset() //����Ҫ����ֵ
	{
		count = 0;
		sum = 0;
	}

	static int GetSum()
	{
		return sum;
	}

private:
	// ��̬���͵ĳ�Ա����
	static int count; // ������ʾ�ӵ�ÿһ��
	static int sum; // �����ۼ����ӵĽ��
};

// ��̬���͵ĳ�Ա�����������ʼ��
int Sum::count = 0; // ����
int Sum::sum = 0;

// static��Ա���������ж�����ģ������ж����������
class Solution 
{
public:
	int Sum_Solution(int n) 
	{
		Sum::Reset(); //ÿ�μ���֮ǰ��0
		Sum s[n]; //�����Լ�
		return Sum::GetSum();
	}
};
#endif




// 2.�������ڵ�������ת��
// ������������ڣ���������һ��ĵڼ���

// ���裺2020,9,20	
// 1. ֻ�轫ǰ8����ÿ���µ�����������	
// 2. ������9�·ݵ�20��	
// 3. ע������
#if 0
#include <iostream>
using namespace std;

int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;

	// ѭ�����ն����������
	while (cin >> year >> month >> day)
	{
		// ÿ�ν��ܵ�һ�����������Ȼ��������������ͳ��month-1ÿ���µ�����
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




// ��Ŀ��һ���ж������
// ��������һ�������һ������
#if 0
int main()
{
	char sz[1024] = { 0 };

	// ע�⣺�����Ҫ����һ�����ַ���������£�����ֱ��ʹ��scanf��cin
	// ��Ϊscanf��cin�����ո��ֹͣ���գ��ո�֮������ݽ��ղ���
	//cin >> sz;
	//scanf("%s", sz);

	while (gets_s(sz))
	{
		// ʵ�ʴӺ���ǰ�ң��ҵ���һ���ո�
		int i = strlen(sz);
		for (; i >= 0; i--)
		{
			if (sz[i] == ' ')
				break;
		}

		// ����һ��ֻ��һ�����ʣ����о�û�пո�
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




// 3.���ڲ�ֵ
// ���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
// ˼·��
// 1. �ֱ����ÿһ��������0000��0��1�վ��������
// 2. ������������������ɵõ�����������������
#if 0
#include <iostream>
using namespace std;

//ƽ���1�µ�n�µ�����
int mon[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

//���������գ��������0000��0��1�յ�������
int CountDay(int y, int m, int d)
{
	// ����0-y�������
	int yearDay = y * 365 + y / 4 - y / 100 + y / 400;

	// ���㵽0-m�µ�����
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




// 4.��ӡ����
// �������m��һ���еĵ�n�죬�����n���Ǽ��¼���
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




// 5.�ۼ�����
// �����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�����
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
					if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) // ���ж���һ���Ƿ�������
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
