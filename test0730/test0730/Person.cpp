#if 0

#include "Person.h"
#include <string.h>
#include <iostream>
using namespace std;

// 注意：类中的成员函数在类外定义时，在成员函数名字前加Person::限制，表明该成员函数是某个类的成员函数
// 如果没有加类名::，表明该函数是一个全局的函数，与类成员函数不相干
void Person::SetPersonInfo(char name[], char gender[], int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void Person::PrintStudentInfo()
{
	cout << _name << "-" << _gender << "-" << _age << endl;
}

void Person::Eat()
{
	cout << "吃饭" << endl;
}

void Person::Sleep()
{
	cout << "睡觉" << endl;
}

void Person::Work()
{
	cout << "工作" << endl;
}

int main()
{
	return 0;
}
#endif