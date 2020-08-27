#include <iostream>
using namespace std;


#if 0
class A1
{
public:
	void f1()
	{}
private:
	int _a;
	char _b;
};

// 类中仅有成员函数
class A2
{
public:
	void f2() 
	{}
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
	cout << sizeof(A3) << endl;   // 空类，理论上大小应该是0才对-->但是实际结果大小是1

	A3 a1, a2, a3;
	cout << &a1 << " " << &a2 << " " << &a3 << endl;

	cout << offsetof(A, b) << endl; // 计算偏移量
	cout << offsetof(A, c) << endl; // 计算偏移量
	cout << offsetof(A, d) << endl; // 计算偏移量
	return 0;
}
#endif




// 在C语言中，我们代码怎么写，编译器就怎么做，几乎不会对代码进行任何修改
// 你看到的就是编译器执行的
// 用C语言来模拟时间上述代码

#if 0
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




// 注意：在C++中，眼睛看到的不一定就是真的----编译器对于代码会偷偷进行修改
// 导致：感觉C++比较难学、C++学不深

// 每个类"成员函数"都有一个默认的参数，该参数时时刻刻指向调用该成员函数的对象，将该参数称为this指针
// 注意：该隐藏的this指针是编译器在编译类的期间自动加上的,因此用户不需要添加，也不需要传递

#if 0
class Student
{
public:
	void SetStudentInfo(/*Student* const this,*/char name[], char gender[], int age)
	{
		// this = nullptr;  this指针指向不能修改的
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

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

	// 编译出错：this只能在"成员函数中使用"
	// 因为this指针是编译器给类的"成员函数"增加的一个指针，用该指针来区分不同的对象
	// cout << this << endl;


	cout << &s1 << endl;
	s1.SetStudentInfo(/*&s1,*/"熊大", "公", 5);

	cout << &s2 << endl;
	s2.SetStudentInfo(/*&s2,*/"熊二", "母", 4);

	cout << &s3 << endl;
	s3.SetStudentInfo(/*&s3,*/"强哥", "男", 28);
	
	
	// this指针的传递方式：
	// 1. 该参数是有编译器传递的
	// 2. 一般情况该参数是通过ecx寄存器来传递的
	// 注意：一般情况下成员函数都是被this_call调用约定修饰，
	//      即被this_call调用约定修饰的成员函数，this指针是通过ecx寄存器传递, 
	//      而被_cdecl调用约定修饰的成员函数，this是通过参数压栈的方式传递
    // 3. 二般情况是通过参数压栈的方式传递
	// s3.TestFunc();


	s1.PrintStudentInfo(/*&s1*/);
	s2.PrintStudentInfo(/*&s2*/);
	s3.PrintStudentInfo(/*&s3*/);

	return 0;
}

// 上述是用户写的代码，经过编译器器修改之后，代码就变成

//struct Student
//{
//	char name[20];
//	char gender[3];
//	int age;
//};
//
//// 要将name、gender、age数据设置到this指向的学生信息中
//void SetStudentInfo(Student* this, char name[], char gender[], int age)
//{
//	strcpy(this->name, name);
//	strcpy(this->gender, gender);
//	this->age = age;
//}
//
//// 打印this指向的学生
//void PrintSutdentInfo(Student* this)
//{
//	printf("%s %s %d", this->name, this->gender, this->age);
//}
//
//int main()
//{
//	Student s1, s2, s3;
//	SetStudentInfo(&s1, "熊大", "公", 5);
//	SetStudentInfo(&s2, "熊二", "母", 4);
//	SetStudentInfo(&s3, "强哥", "男", 28);
//
//	PrintSutdentInfo(&s1);
//	PrintSutdentInfo(&s2);
//	PrintSutdentInfo(&s3);
//	return 0;
//}
#endif




//成员变量可以看成是成员函数的全局变量
//问题：据以前知识--->全局变量必须声明才能使用，但是类成员变量声明在下，为什么还可以在之前的成员函数中使用呢？

//编译器大概是怎么处理类？
//1. 识别类名
//2. 识别类中成员变量
//3. 识别类中的成员函数&对成员函数进行改写

#if 1
class Student
{
public:
	//void SetStudentInfo(Student* const this, char name[], char gender[], int age)
	//{
	//	strcpy(this->_name, name);
	//	strcpy(this->_gender, gender);
	//	this->_age = age;
	//}
	
	void SetStudentInfo(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	//void PrintStudentInfo()
	//{
	//	cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	//}
	
	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public:
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	return 0;
}
#endif