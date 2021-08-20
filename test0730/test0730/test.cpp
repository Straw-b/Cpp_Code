#include <iostream>
using namespace std;


#if 0
// Student将其看成是一个学生群体类型
struct Student
{
	// 属性：用来描述学生的基本信息的
	char _name[20];
	char _gender[3];
	int _age;
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
	// 吃饭、睡觉、上课、写作业、考试、编程--->功能一般都是通过函数体现的
	void Eat()
	{
		cout << "好好吃饭" << endl;
	}

	void Sleep()
	{
		cout << "睡觉~~~" << endl;
	}
};

int main()
{
	Student s1, s2, s3; // 对象
	s1.SetStudentInfo("熊大", "公", 5, "熊熊乐园");
	s2.SetStudentInfo("熊二", "母", 4, "熊熊乐园");
	s3.SetStudentInfo("强哥", "男", 28, "森林大学");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();

	s1.Eat();
	s1._age = 10;
	s1.PrintStudentInfo();
	return 0;
}
#endif




#if 0
class Student
{
private:
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

	void Eat()
	{
		cout << "好好饭吃" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}
};

int main()
{
	Student s1, s2;
	s1.SetStudentInfo("熊大", "公", 5, "熊熊乐园");
	s2.SetStudentInfo("熊二", "母", 4, "熊熊乐园");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	// s1._age = 10; // 无法访问 private 成员(在“Student”类中声明)
	return 0;
}
#endif




// C++中4个作用域：函数体中的局部作用域、全局作用域、命名空间、类
#if 0
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




// 类中的成员变量，只能在类成员函数中使用，成员变量相当于是类成员函数的全局变量
#if 0
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
	int _a;   
	// 该成员变量，既可以在SetTest函数中使用，也可以再PrintTest函数中使用
	// 因此：成员变量就可以看成是类成员函数的全局变量
};

// 注意：成员变量就可以看成是类成员函数的全局变量---但是和真正的全局变量还是有区别
//       全局变量在使用之前必须先要进行定义
int g_a = 10; // 提前定义

void TestFunc()
{
	cout << g_a << endl;
}

int main()
{
	Test t;
	t.SetTest(10);
	t.PrintTest();

	TestFunc();
	cout << g_a << endl;
	return 0;
}
#endif




// 定义了一个学生类
// 学生类代表的是学生的一个群体的类别，可以将学生类看成是一个新的类型，与学生对象不同
#if 0
class Student
{
public:
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
};

int main()
{
	//Student._age = 10;
	//该条语句编译失败，因为Student是一个学生类别，即类型
	//学生群体类别：就是类型--->类型没有属性
	//通过学生类型，定义出来的学生实体(学生对象：是真正的一个学生)，而一个真正的学生才有名字、性别、年龄

	Student s;  // s就是类实例化的结果，s就是一个真正的学生
	s._age = 10;

	return 0;
}
#endif




#if 1
class Student
{
public: // 成员函数
	void SetStudentInfo(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public: // 成员变量
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;

	// 要检测Student类对象有多大：至少要知道对象中都包含了那些成员
	s1.SetStudentInfo("熊大", "公", 5);
	s2.SetStudentInfo("熊二", "母", 4);
	s3.SetStudentInfo("强哥", "男", 28);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	cout << sizeof(s1) << endl;
	return 0;
}
#endif
