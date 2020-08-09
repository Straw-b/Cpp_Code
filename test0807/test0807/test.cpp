#include <iostream>
using namespace std;


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数：
	//   特殊的构造函数，一定是单参的，参数必须是类类型对象的引用(一般情况下会在参数前const)
	//   在使用已经存在的对象创建新对象时，由编译器自动进行调用
	// 注意：如果用户没有显式实现，则编译器生成一份，并且会完成拷贝的工作

	// 一般拷贝不需要通过形参d改变外部的实参，最好用const对d进行修改
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	cout << this << ":" << &d << endl;
	//}

	~Date()
	{
		// 对于Date类析构函数写不写都无所谓，一般情况下我们都不会写
		// 因为析构函数中一般清理当前对象资源，而Date类对象中没有涉及到资源管理
		// 该析构函数可以给出也可以不用给出，看用户是否需要
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	int a = 10;
	//int b = a;
	int b(a);

	Date d1(2020, 8, 7);

	// 需求：d2对象在创建好之后与d1对象中的数据一样
	//Date d2(2020,8,7);

	// 用已经存在的d1来创建一个新对象d2
	// d2是新创建的对象，既然新创建了对象，肯定要调用构造函数
	//Date d2 = d1;

	// 因为是用已经存在的d1在创建新对象d2---->拷贝构造函数(复制构造函数)
	Date d2(d1);
	return 0;
}
