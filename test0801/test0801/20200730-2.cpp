#include <iostream>
using namespace std;


#if 0
// Student将其看成是一个学生群体类型
struct Student
{
	// 属性：用来描述学生的基本信息的
	char _name[20];
	char _gender[3];
	int  _age;
	char _school[20];

	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
		strcpy(_school, school);
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
	}

	// 行为：学生都会啥
	// 吃饭、睡觉、上课、写作业、考试、编程---功能一般都是通过函数体现的
	void Eat()
	{
		cout << "好好饭吃长肉肉" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}

	void Exam()
	{
		cout << "考试" << endl;
	}
};

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("熊大", "公", 5, "熊熊乐园");
	s2.SetStudentInfo("熊二", "母", 4, "熊熊乐园");
	s3.SetStudentInfo("强哥", "男", 28, "森林大学");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	return 0;
}
#endif

#if 0
class Student
{
protected:
	// 属性：用来描述学生的基本信息的
	char _name[20];
	char _gender[3];
	int  _age;
	char _school[20];

public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
		strcpy(_school, school);
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
	}

	// 行为：学生都会啥
	// 吃饭、睡觉、上课、写作业、考试、编程---功能一般都是通过函数体现的
	void Eat()
	{
		cout << "好好饭吃长肉肉" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}

	void Exam()
	{
		cout << "考试" << endl;
	}
};

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("熊大", "公", 5, "熊熊乐园");
	s2.SetStudentInfo("熊二", "母", 4, "熊熊乐园");
	s3.SetStudentInfo("强哥", "男", 28, "森林大学");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	s1._age = 10;
	return 0;
}
#endif

#if 0
// C++中4个作用域：函数体中的局部作用域、全局作用域、命名空间、类
void TestFunc()
{}

namespace N
{
	void TestFunc(int a)
	{}
}

class Test
{
public:
	void TestFunc(double d)
	{}
};
#endif


#if 0
// 类中的成员变量，只能在类成员函数中使用，成员变量相当于是类成员函数的全局变量

class Test
{
public:
	void SetTest(int a)
	{
		_a = a;
		cout << &_a << endl;
	}

	void PrintTest()
	{
		cout << _a << endl;
		cout << &_a << endl;
	}

private:
	int _a;   // 该成员变量，既可以在SetTest函数中使用，也可以再PrintTest函数中使用
	          // 因此：成员变量就可以看成是类成员函数的全局变量
};


// 注意：成员变量就可以看成是类成员函数的全局变量---但是和真正的全局变量还是有区别
//      全局在使用之前必须先要进行定义



void TestFunc()
{
	cout << g_a << endl;
}

int g_a = 10;

int main()
{
	Test t;
	t.SetTest(10);
	t.PrintTest();

	cout << g_a << endl;
	return 0;
}
#endif


#if 0
// 定义了一个学生类
// 注意区分：学生类代表的是学生的一个群体的类别，可以将学生类看成是一个新的类型，与学生对象不同
//          类   对象
//         int   a
class Student
{
public:
	// 属性：用来描述学生的基本信息的
	char _name[20];
	char _gender[3];
	int  _age;
	char _school[20];

public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
		strcpy(_school, school);
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
	}

	// 行为：学生都会啥
	// 吃饭、睡觉、上课、写作业、考试、编程---功能一般都是通过函数体现的
	void Eat()
	{
		cout << "好好饭吃长肉肉" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}

	void Exam()
	{
		cout << "考试" << endl;
	}
};

int main()
{
	/*
	该条语句编译失败，因为Student是一个学生类别即类型
	学生群体类别：就是类型---类型没有属性一说
	通过学生类型 定义出来的学生实体(学生对象：是真正的一个学生)，而一个真正的学生才有名字、性别、年龄
	*/
	//Student._age = 10;

	Student s;  // s就是类实例化的结果，s就是一个真正的学生
	s._age = 10;

	return 0;
}
#endif


#if 0
class Student
{
public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public:
	// 属性：用来描述学生的基本信息的
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1,s2,s3;

	// 要检测Student类对象有多大：至少要知道对象中都包含了那些成员
	s1.SetStudentInfo("熊大", "公", 5, "熊熊乐园");
	s2.SetStudentInfo("熊二", "母", 4, "熊熊乐园");
	s3.SetStudentInfo("强哥", "男", 28, "森林大学");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	cout << sizeof(s1) << endl;
	return 0;
}
#endif

#if 0
class A1 
{
public:
	void f1(){}
private:
	int _a;
	char _b;
};

// 类中仅有成员函数
class A2 
{
public:
	void f2() {}
};


// 类中什么都没有---空类
// 语法支持该中类，但是该类没有实际意义
// 注意：空类也是一个类，可以定义其对象
class A3
{};

struct A
{
	int a;
	char b;
	double c;
	char d;
};

int main()
{
	cout << sizeof(A1) << endl;

	cout << sizeof(A2) << endl;   // 因为类中没有成员变量，理论上大小应该是0才对-->但是实际结果大小是1
	cout << sizeof(A3) << endl;   // 因为类中没有成员变量，理论上大小应该是0才对-->但是实际结果大小是1

	A3 a1, a2, a3;
	cout << &a1 << " " << &a2 << " " <<&a3<< endl;

	cout << offsetof(A, b) << endl;
	cout << offsetof(A, c) << endl;
	return 0;
}
#endif

#if 0

// 注意：在C++中，眼睛看到的不一定就是真的----编译器对于代码会偷偷进行修改
// 导致：感觉C++比较难学、C++学不深

// 每个类"成员函数"都有一个默认的参数，该参数时时刻刻指向调用该成员函数的对象，将该参数称为this指针
// 注意：该隐藏的this指针是编译器在编译类的期间自动加上的,因此用户不需要添加，也不需要传递

class Student
{
public:
	void SetStudentInfo(/*Student* const this,*/char name[], char gender[], int age);
// 	{
// 		// this = nullptr;  this指针指向不能修改的
// 		cout << this << endl;
// 		strcpy(this->_name, name);
// 		strcpy(this->_gender, gender);
// 		this->_age = age;
// 	}

	void PrintStudentInfo(/*Student* const this*/)
	{
		cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	}

	void TestFunc(...);   // ...表示不定参数
	//{}

public:
	// 属性：用来描述学生的基本信息的
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;

	// this指针没有包含在对象中，不影响对象的大小，它是编译器给成员函数增加的一个用来区分不同对象的指针参数
	cout << sizeof(s1) << endl;

	// 编译出错：this只能在"成员函数中使用"，因为this指针是编译器给类的"成员函数"增加的一个指针，用该指针来区分不同的对象呢
	// cout << this << endl;

	// 要检测Student类对象有多大：至少要知道对象中都包含了那些成员
	cout << &s1 << endl;
	s1.SetStudentInfo(/*&s1,*/"熊大", "公", 5);

	cout << &s2 << endl;
	s2.SetStudentInfo(/*&s2,*/"熊二", "母", 4);

	// this指针的传递方式：
	// 1. 该参数是有编译器传递的
	// 2. 一般情况该参数是通过ecx寄存器来传递的
	// 注意：一般情况下成员函数都是被this_call调用约定修饰，即被this_call调用约定修饰的成员函数
	//      this指针是通过ecx寄存器传递, 被_cdecl调用约定修饰的成员函数，this是通过参数压栈的方式传递
	cout << &s3 << endl;
	s3.SetStudentInfo(/*&s3,*/"强哥", "男", 28);
	// 3. 二般情况是通过参数压栈的方式传递
	s3.TestFunc();

	s1.PrintStudentInfo(/*&s1,*/);
	s2.PrintStudentInfo(/*&s2,*/);

	cout << sizeof(s1) << endl;
	return 0;
}

/*
上述是用户写的代码，经过编译器器修改之后，代码就变成
// 在C语言中，我们代码怎么写，编译器就怎么做，几乎不对代码进行任何修改--你看到的就是编译器执行的
// 用C语言来模拟时间上述代码
struct Student
{
	char name[20];
	char gender[3];
	int age;
};


// 要将name、gender、age数据设置到ps指向的学生信息中
void SetStudentInfo(Student* this, char name[], char gender[], int age)
{
	strcpy(this->name, name);
	strcpy(this->gender, gender);
	this->age = age;
}

// 打印ps指向的学生
void PrintSutdentInfo(Student* this)
{
	printf("%s %s %d", this->name, this->gender, this->age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "熊大", "公", 5);
	SetStudentInfo(&s2, "熊二", "母", 4);
	SetStudentInfo(&s3, "强哥", "男", 28);

	PrintSutdentInfo(&s1);
	PrintSutdentInfo(&s2);
	PrintSutdentInfo(&s3);
	return 0;
}
*/
#endif


#if 0
// 在C语言中，我们代码怎么写，编译器就怎么做，几乎不对代码进行任何修改--你看到的就是编译器执行的
// 用C语言来模拟时间上述代码
struct Student
{
	char name[20];
	char gender[3];
	int age;
};


// 要将name、gender、age数据设置到ps指向的学生信息中
void SetStudentInfo(Student* ps, char name[], char gender[], int age)
{
	strcpy(ps->name, name);
	strcpy(ps->gender, gender);
	ps->age = age;
}

// 打印ps指向的学生
void PrintSutdentInfo(Student* ps)
{
	printf("%s %s %d", ps->name, ps->gender, ps->age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "熊大", "公", 5);
	SetStudentInfo(&s2, "熊二", "母", 4);
	SetStudentInfo(&s3, "强哥", "男", 28);

	PrintSutdentInfo(&s1);
	PrintSutdentInfo(&s2);
	PrintSutdentInfo(&s3);
	return 0;
}
#endif

#if 0
/*
成员变量可以看成是成员函数的全局变量
问题：具以前知识--->全局变量必须声明才能使用，但是类成员变量声明在下，为什么还可以在之前的成员函数中使用呢？


编译器大概是怎么处理类？-----单身18年了，你央求你的同学/朋友给我介绍一个女朋友
1. 识别类名
2. 识别类中成员变量
3. 识别类中的成员函数&对成员函数进行改写
*/
class Student
{
public:
	/*
	void SetStudentInfo(Student* const this, char name[], char gender[], int age)
	{
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	*/
	void SetStudentInfo(char name[], char gender[], int age)
	{
	    strcpy(_name, name);
	 	strcpy(_gender, gender);
	 	_age = age;
	}

	/*
	void PrintStudentInfo()
	{
	    cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	}
	*/
	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public:
	char _name[20];
	char _gender[3];
	int  _age;
};
#endif

#if 0
// 空类
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
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a1;
	int a2 = 10;
	int a3(10);


	// 需求：当Date类将对象创建好，该对象中就要有初始值
	Date d1;
	d1.SetDate(2020, 8, 1);  // Date::SetDate(&d, 2020,8,1)
	d1.PrintDate();

	Date d2(2020, 8, 1);   // 定义d2对象并对其进行初始化--构造函数就是完成对对象的初始化工作
	d2.PrintDate();
	return 0;
}

#endif


#if 0
class Date
{
public:
	// 构造函数是一个特殊的成员函数，特殊：
	// 构造函数的名字必须与类名相同
	// 构造函数没有返回值类型，即使加void也不行
	// 构造函数是在创建对象时由编译器自动进行调用，并且在对象的生命周期内只调用一次
	// 作用：主要是创建对象时完成对当前对象的初始化工作
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		//return;   // return;该中写法表示：并没有返回一个实际的内容，表明函数从该位置退出

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
	Date d(2020, 8, 1);
	d.PrintDate();
}

int main()
{
	TestDate();

	Date d1(2020, 8, 1);  // 我们并没有显式(用户没有写出调用构造函数的语句)调用构造函数
	d1.PrintDate();
	return 0;
}
#endif

#if 0
// 构造函数可以重载
class Date
{
public:
	// 该构造函数只能创建带有三个参数的对象，不能创建无参的对象
	Date(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
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

int main()
{
	Date d1(2020, 8, 1);   // call Date(2020, 8, 1)
	d1.PrintDate();

	Date d2(2020, 8, 2);

	Date d3;              // call Date()
	Date d4;
	Date d5;
	return 0;
}
#endif


#if 0
// 如果一个类没有显式定义(用户写出)任何构造函数，编译器会生成一个默认的构造函数，
// 注意：编译器生成的构造函数一定是无参的，用户一旦给出构造函数，编译器就不会生成了
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


int main()
{
	Date d1;
	Date d2(2020, 8, 1);  // 在创建对象时，要调用Date(int,int,int)
	return 0;
}
#endif


#if 0
// 全缺省的构造函数 和 无参的构造函数统称为 默认的构造函数
// 并且：全缺省的构造函数 和 无参的构造函数不能同时存在
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

	// 无参的构造函数
	//Date()
	//{
	//	_year = 1900;
	//	_month = 1;
	//	_day = 1;
	//}

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


int main()
{
	Date d1;
	Date d2(2020, 8, 1);
	return 0;
}
#endif


#if 0
// 用户没有定义构造函数时，编译器生成无参的构造函数，那么它给对象初始化成什么值？还会是随机值吗？
// 编译器生成的默认构造函数中：
// 将对象中内置类型定义的成员变量初始化为随机值
// 将对象中包含的类型类型对象成员---调用成员对应类的默认构造函数来初始阿化
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;

		cout << "Time(int,int,int)" << endl;
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
	// 在Date类构造函数执行时，先跳转到Time类构造函数位置执行，将日期类中中的_t的对象初始化完整
	// 然后再执行Date类的构造函数体给_year\_month\_day来进行赋值
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		year = year;
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

	Time _t;
};


int main()
{
	// 编译器给日期类生成了一个默认的构造函数
	// 在生成的默认的构造函数中调用了Time类的构造函数，目的：将日期类中包含的Time类的对象初始化完成
	Date d;   // call Time() // 会调用编译器生成的默认构造函数(无参)   call Date()
	
	// Date dd(2020, 8, 1);  dd对象在创建时，需要调用带有三个int类型参数的构造函数
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

	// 在对象销毁时，必须要将对象中的资源清理掉
	// 析构函数
	// 在对象被销毁时，由编译器自动进行调用，完整对象中资源清理工作
	// 析构函数一定是无参的，不能带有任何类型的参数
	// 析构函数不能有返回值
	// 一个类只能有一个析构函数
	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_capacity = 0;
			_size = 0;
		}

		// return 0;
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

	// ....
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
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
	// 在构造Person对象p时，从汇编代码中看到，编译器给Person类生成了一个默认的构造函数
	// 而生成的默认构造函数中，主要调用了String类的构造函数，目的就是对p对象中所包含的String类型的name
	// 来进行初始化
	// 注意：在989行不能直接调用call String(), 因为在989行创建的是一个Person类型的对象，就要调用Person
	// 的构造函数，来完成Person对象中所包含的String类型的name的初始化工作，因此编译器给Person类生成一个默认的构造函数


	// 在P对象销毁时，因为p对象中包含有String类型的name，name中管理资源，因此必须要调用String类的析构函数
	// 完成p对象中所包含的String类型的name的资源清理工作
	// 但是在函数退出时，不能直接调用String类的析构函数，因为现在析构的是Person类的对象，直接调用String类的析构函数讲不通
	// 析构那个类的对象，调用那个类的析构函数
	// 因此：编译器给Person类生成了一个默认的析构函数，在默认的析构函数中调用String类的析构函数，完成p对象中所包含的String类型name的资源清理工作
	/*
	编译器给Person类生成的析构函数
	~Person()
	{
	    call ~String();  // 清理Person类对象中包含的String类型成员name中的资源
	}
	*/
}

int main()
{
	TestPerson();
	TestString();
	return 0;
}