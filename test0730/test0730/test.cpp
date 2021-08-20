#include <iostream>
using namespace std;


#if 0
// Student���俴����һ��ѧ��Ⱥ������
struct Student
{
	// ���ԣ���������ѧ���Ļ�����Ϣ��
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

	// ��Ϊ��ѧ������ɶ
	// �Է���˯�����ϿΡ�д��ҵ�����ԡ����--->����һ�㶼��ͨ���������ֵ�
	void Eat()
	{
		cout << "�úóԷ�" << endl;
	}

	void Sleep()
	{
		cout << "˯��~~~" << endl;
	}
};

int main()
{
	Student s1, s2, s3; // ����
	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
	s3.SetStudentInfo("ǿ��", "��", 28, "ɭ�ִ�ѧ");

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
		cout << "�ú÷���" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}
};

int main()
{
	Student s1, s2;
	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	// s1._age = 10; // �޷����� private ��Ա(�ڡ�Student����������)
	return 0;
}
#endif




// C++��4�������򣺺������еľֲ�������ȫ�������������ռ䡢��
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




// ���еĳ�Ա������ֻ�������Ա������ʹ�ã���Ա�����൱�������Ա������ȫ�ֱ���
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
	// �ó�Ա�������ȿ�����SetTest������ʹ�ã�Ҳ������PrintTest������ʹ��
	// ��ˣ���Ա�����Ϳ��Կ��������Ա������ȫ�ֱ���
};

// ע�⣺��Ա�����Ϳ��Կ��������Ա������ȫ�ֱ���---���Ǻ�������ȫ�ֱ�������������
//       ȫ�ֱ�����ʹ��֮ǰ������Ҫ���ж���
int g_a = 10; // ��ǰ����

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




// ������һ��ѧ����
// ѧ����������ѧ����һ��Ⱥ�����𣬿��Խ�ѧ���࿴����һ���µ����ͣ���ѧ������ͬ
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
	//����������ʧ�ܣ���ΪStudent��һ��ѧ����𣬼�����
	//ѧ��Ⱥ����𣺾�������--->����û������
	//ͨ��ѧ�����ͣ����������ѧ��ʵ��(ѧ��������������һ��ѧ��)����һ��������ѧ���������֡��Ա�����

	Student s;  // s������ʵ�����Ľ����s����һ��������ѧ��
	s._age = 10;

	return 0;
}
#endif




#if 1
class Student
{
public: // ��Ա����
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

public: // ��Ա����
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;

	// Ҫ���Student������ж������Ҫ֪�������ж���������Щ��Ա
	s1.SetStudentInfo("�ܴ�", "��", 5);
	s2.SetStudentInfo("�ܶ�", "ĸ", 4);
	s3.SetStudentInfo("ǿ��", "��", 28);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	cout << sizeof(s1) << endl;
	return 0;
}
#endif
