#include <iostream>
using namespace std;


#if 0
// ע�⣺�����÷�ʽ��Ϊ�����ķ���ֵʱ��һ�����ܷ���ջ�ϵĿռ䣺���纯���еľֲ�����
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}

int main()
{
	int& sum = Add(1, 2);
	cout << sum << endl;
	Add(3, 4);
	cout << sum << endl;
	Add(5, 6);
	cout << sum << endl;
	return 0;
}
#endif




#if 0
// ע�⣺����ʵ�����������ֻҪ���溯���Ľ�������������
// ����������ȫ�ֱ�������
int g_a = 0;// ȫ�ֱ���

int& Add(int left, int right)
{
	g_a = left + right;
	return g_a;
}

int main()
{
	int& sum = Add(1, 2);
	cout << sum << endl;
	Add(3, 4);
	cout << sum << endl;
	Add(5, 6);
	cout << sum << endl;
	return 0;
}
#endif




#if 0
// ע�⣺����ʵ�����������ֻҪ���溯���Ľ�������������
// ����������ȫ�ֱ�������
int& Add(int left, int right, int& ret)
{
	ret = left + right;
	return ret;
}

int main()
{
	int r = 0;// �������͵Ĳ���
	int& sum = Add(1, 2, r);
	cout << sum << endl;
	Add(3, 4, r);
	cout << sum << endl;
	Add(5, 6, r);
	cout << sum << endl;
	return 0;
}
#endif




#if 0
// ���⣬һ��������ز������
void test(int a)
{}

void test(int& a)
{}

int main()
{
	test(10);

	int r = 10;
	test(r);// �������������Ե��ã������غ����ĵ��ò���ȷ
	return 0;
}
#endif




#if 0
int main()
{
	int a = 10;   // a�ڶ���ʱ��������Ҫ��a�������ٿռ�
	int& ra = a;  // ra���������͵ı������ڶ���ʱ���������Ͳ����ra���ٿռ�

	cout << typeid(a).name() << endl; // ��֤����
	cout << typeid(ra).name() << endl;
	return 0;
}
#endif




#if 0
#include <ctime> // clock ��ͷ�ļ�

struct A
{
	int array[100000];
};

void TestValue(A a) // ��ֵ
{}
void TestRef(A& a) // ������
{}
void TestPtr(A* a) // ��ָ��
{}

void TestFunc()
{
	A a;

	// ��ֵ���ڴ����ڼ���Ҫ����ʵ�ε�һ�ݿ���
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
		TestValue(a);
	size_t end1 = clock();

	// �����Ǳ������ڴ����ڼ䲻��Ҫ���п���
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end2 = clock();

	// ��ָ�룬�ڴ����ڼ䲻��Ҫ���ж���Ŀ���---�������Ƕ���ĵ�ַ---32ƽ̨�¾���4���ֽ�
	size_t begin3 = clock();
	for (int i = 0; i < 100000; i++)
		TestPtr(&a);
	size_t end3 = clock();

	cout << "��ֵ���ܣ�" << end1 - begin1 << " ms" << endl;
	cout << "���������ܣ�" << end2 - begin2 << " ms" << endl;
	cout << "��ָ�����ܣ�" << end3 - begin3 << " ms" << endl;

	// ����1��������Ч�ʱȴ�ֵЧ�ʸ�
	// ע�⣺��C++�У������Զ������͵Ĳ���һ�㶼�ǰ������õķ�ʽ�����ݵ�T&   const T&

	// ����2�������úʹ�ָ���Ч�ʲ��
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
// ���ÿ��Դﵽ��ָ�����Ƶ�Ч�������磺������ͨ���β����ı��ⲿ��ʵ��
// ���⣺ָ���������ʲô�����أ�
// �ڵײ�ʵ���ϣ����þ��ǰ���ָ�뷽ʽʵ�ֵ�
int main()
{
	int a = 10;

	int* pa = &a;
	*pa = 100;

	// ������Ϊ�˴�Һ���⣬���þ��Ǳ����������������õ�ʵ�干��ͬһ���ڴ�ռ䣬
	// ��������������ñ������¿����ڴ�ռ�

	// ʵ�ָ��м������������ڵײ��ǰ���ָ��ķ�ʽ��ʵ��

	// �û�д�Ĵ��룺���ձ����ڴ����е�ĳ���ļ���
	// ϵͳִ�еĴ��룺����Ԥ�������롢��ࡢ����--->���ɿ�ִ�г���(exe)
	// ���б���---�����������﷨�������룬���Ƿ��в������﷨��������ڣ����û���д������з���
	// ������ʹ�õ�������
	// �������ڷ����ʱ�򣬽����ð���ָ��ķ�ʽ������
	// ��������������֮��Ĵ��룬������û������
	int& ra = a;
	ra = 100;

	return 0;
}
#endif




#if 0
void Swap(int& left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	Swap(&a, &b);
	Swap(a, b);

	return 0;
}
#endif




#if 1
int main()
{
	int* p;

	int a = 10;
	int& ra = a;
	ra++;   // ע�⣺�ڵײ㴦���ϣ����������ra�������ҵ�a

	int b = 20;

	p = &a;
	p++;   // ָ��ֻ��ָ��һ�������Ŀռ䣬++/--��������

	p = &b;

	int* const cp = &a;
	// pc = &b;

	char c = 'a';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;  // 4  ��32ƽ̨�£��κ�ָ�붼ռ��4���ֽ�
	cout << sizeof(rc) << endl;  // 1  ��������ʵ�ʾ���������ʵ�����͵Ĵ�С

	// �ж༶ָ��
	int* p1 = NULL;
	int** p2 = NULL;
	int*** p3 = NULL;

	// û�ж༶����--->��ʵ��û�ж༶�����������
	int d = 10;
	int& rd = d;

	//int&& rrd = d;
	// ��ֵ����--->C++11
	int&& rrd = 10; // ������д��
	return 0;
}
#endif




#if 0
// ԭ��
void Swap(int& left, int& right) // ����
{
	int temp = left;
	left = right;   // �������
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int* pb = NULL;
	// *pb = 100;    // �Կ�ָ������ã�������ִ���ڼ������

	// �ڴ���ʱ���������ǰ���ֵ�ķ�ʽ���ݵ�
	// ���������ڱ������ʱ����⵽Swap�������������������͵�
	// �����Ѿ���Swap�����������������͵Ĳ���ת��Ϊָ��
	// ��ˣ�Swap(a, *pb)--->����ɣ�Swap(&a, pb);
	Swap(a, *pb);   //  ���Ǹ�λ�õĿ�ָ��pb������ʱȴû�б���
	return 0;
}
#endif