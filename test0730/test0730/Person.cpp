#if 0

#include "Person.h"
#include <string.h>
#include <iostream>
using namespace std;

// ע�⣺���еĳ�Ա���������ⶨ��ʱ���ڳ�Ա��������ǰ��Person::���ƣ������ó�Ա������ĳ����ĳ�Ա����
// ���û�м�����::�������ú�����һ��ȫ�ֵĺ����������Ա���������
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
	cout << "�Է�" << endl;
}

void Person::Sleep()
{
	cout << "˯��" << endl;
}

void Person::Work()
{
	cout << "����" << endl;
}

int main()
{
	return 0;
}
#endif