#include <iostream>
using namespace std;


#if 0
class Test
{
public:
	Test(int t)
		: _t(t)
	{}

	Test& operator=(const Test& t)
	{
		if (this != &t)
		{
			_t = t._t;
		}
		return *this;
	}

	int _t;
};

// ע�⣺����˵���е���������ض�Ҫд����ĳ�Ա���������磺���ص���������
// ��ֵ��������ر���д����ĳ�Ա����
//Test& operator=( Test& t)
//{
//	return t;
//}

int main()
{
	Test t1(10);
	Test t2(20);

	t1 = t2;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " " << _t << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << " " << _t << endl;
	}

	int _t;
};

Test t1(10);

void TestStatic()
{
	static Test t4(40);
}

int main()
{
	Test t2(20);
	Test t3(30);
	TestStatic();
	TestStatic();
	TestStatic();

	//Test t4(t2);
	return 0;
}
#endif




#if 0
// ���캯���﷨��˵�����캯��û�з���ֵ����
// ���캯�������з���ֵ��
// �﷨����:û�У�����������д
// ��෽��:�У����ص�ǰ���������
class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " " << _t << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << " " << _t << endl;
	}

	int _t;
};

int test1()
{
	return 10;
}
void test2()
{}

int main()
{
	int a = 10;
	a = test1();   //test1()�����з���ֵ����˿��Է���=���Ҳ�
	// a = test2();  test2()����û�з���ֵ����Ȼû�з���ֵ���䲻�ܳ�����=���Ҳ�

	Test t1(10);

	// ��Ȼ���캯���Ϳ������캯�����Է���=���Ҳ࣬��֤������Ϳ������캯�����з���ֵ��
	// ���캯���Ϳ������캯�����ص��Ƕ��������
	t1 = Test(20);  // ���ù��캯������
	t1 = Test(t1);  // ���ÿ�������

	return 0;
}
#endif




// �ڲ�������ⲿ�����Ԫ��
// 1.�ڲ�����Զ������ⲿ���public��protected��private���ǿ��Եġ�
// 2.ע���ڲ������ֱ�ӷ����ⲿ���е�static��ö�ٳ�Ա������Ҫ�ⲿ��Ķ��� / ������
// 3.sizeof(�ⲿ��) = �ⲿ�࣬���ڲ���û���κι�ϵ��
#if 1
class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};

int A::k = 1;

int main()
{
	A::B b;
	b.foo(A());
	return 0;
}
#endif