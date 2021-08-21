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

// ���н��г�Ա����
class A2
{
public:
	void f2() 
	{}
};

// ����ʲô��û��---����
// �﷨֧�ָ����࣬���Ǹ���û��ʵ������
// ע�⣺����Ҳ��һ���࣬���Զ��������
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
	cout << sizeof(A2) << endl;   // ��Ϊ����û�г�Ա�����������ϴ�СӦ����0�Ŷ�-->����ʵ�ʽ����С��1
	cout << sizeof(A3) << endl;   // ���࣬�����ϴ�СӦ����0�Ŷ�-->����ʵ�ʽ����С��1

	A3 a1, a2, a3;
	cout << &a1 << " " << &a2 << " " << &a3 << endl;

	cout << offsetof(A, b) << endl; // ����ƫ����
	cout << offsetof(A, c) << endl; // ����ƫ����
	cout << offsetof(A, d) << endl; // ����ƫ����
	return 0;
}
#endif




// ��C�����У����Ǵ�����ôд������������ô������������Դ�������κ��޸�
// �㿴���ľ��Ǳ�����ִ�еģ���C������ģ��ʱ����������
#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

// Ҫ��name��gender��age�������õ�psָ���ѧ����Ϣ��
void SetStudentInfo(Student* ps, char name[], char gender[], int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

// ��ӡpsָ���ѧ��
void PrintSutdentInfo(Student* ps)
{
	printf("%s %s %d", ps->_name, ps->_gender, ps->_age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "�ܴ�", "��", 5);
	SetStudentInfo(&s2, "�ܶ�", "ĸ", 4);
	SetStudentInfo(&s3, "ǿ��", "��", 28);

	PrintSutdentInfo(&s1);
	PrintSutdentInfo(&s2);
	PrintSutdentInfo(&s3);
	return 0;
}
#endif




// ע�⣺��C++�У��۾������Ĳ�һ���������----���������ڴ����͵͵�����޸�
// ÿ����"��Ա����"����һ��Ĭ�ϵĲ������ò���ʱʱ�̿�ָ����øó�Ա�����Ķ��󣬽��ò�����Ϊthisָ��
// ע�⣺�����ص�thisָ���Ǳ������ڱ�������ڼ��Զ����ϵģ�����û�����Ҫ��ӣ�Ҳ����Ҫ����
#if 1
class Student
{
public:
	void SetStudentInfo(/*Student* const this,*/char name[], char gender[], int age)
	{
		// this = nullptr;  thisָ��ָ�����޸ĵ�
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudentInfo(/*Student* const this*/)
	{
		cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	}

public:
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;

	// thisָ��û�а����ڶ����У���Ӱ�����Ĵ�С�����Ǳ���������Ա�������ӵ�һ���������ֲ�ͬ�����ָ�����
	cout << sizeof(s1) << endl;

	// �������thisֻ����"��Ա������ʹ��"
	// ��Ϊthisָ���Ǳ����������"��Ա����"���ӵ�һ��ָ�룬�ø�ָ�������ֲ�ͬ�Ķ���
	// cout << this << endl;

	cout << &s1 << endl;
	s1.SetStudentInfo(/*&s1,*/"�ܴ�", "��", 5);

	cout << &s2 << endl;
	s2.SetStudentInfo(/*&s2,*/"�ܶ�", "ĸ", 4);

	cout << &s3 << endl;
	s3.SetStudentInfo(/*&s3,*/"ǿ��", "��", 28);
	
	// thisָ��Ĵ��ݷ�ʽ��
	// 1. �ò������ɱ��������ݵ�
	// 2. һ������ò�����ͨ��ecx�Ĵ��������ݵ�
	// ע�⣺һ������³�Ա�������Ǳ�this_call����Լ�����Σ�
	//      ����this_call����Լ�����εĳ�Ա������thisָ����ͨ��ecx�Ĵ�������, 
	//      ����_cdecl����Լ�����εĳ�Ա������this��ͨ������ѹջ�ķ�ʽ����
    // 3. ���������ͨ������ѹջ�ķ�ʽ����

	s1.PrintStudentInfo(/*&s1*/);
	s2.PrintStudentInfo(/*&s2*/);
	s3.PrintStudentInfo(/*&s3*/);
	return 0;
}
#endif




//��Ա�������Կ����ǳ�Ա������ȫ�ֱ���
//���⣺����ǰ֪ʶ--->ȫ�ֱ���������������ʹ�ã��������Ա�����������£�Ϊʲô��������֮ǰ�ĳ�Ա������ʹ���أ�

//��������δ����ࣿ
//1. ʶ������
//2. ʶ�����г�Ա����
//3. ʶ�����еĳ�Ա����&�Գ�Ա�������и�д

#if 0
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
#endif