#include <iostream>
using namespace std;


#if 0
#include <stdio.h>
// ��һ���������в��ܳ�����ͬ������

// C�������ܹ������������򣺺������еľֲ������� �Լ� ȫ��������

// �����ռ�ĸ����Լ�����
// N1��һ�������ռ�
// a��Add��N1�����ռ��еĳ�Ա
// �����ռ䣺ʵ�ʾ���һ���������ֵ�������
// �����ʽ1
namespace N1
{
	int a = 10;

	int Add(int left, int right)
	{
		return left + right;
	}
}

int a = 20;

// �����ռ䶨���ʽ2--�����ռ����Ƕ��---�����������ռ��л����Լ������������ռ�
// �����ռ����Ƕ�ף�
// ѧУ���Կ�����һ��������ѧУ���ְ����˶��Ժϵ��ÿ��Ժϵ���Կ����������ռ�
namespace N2
{
	int a = 40;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 50;

		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}

namespace N3
{
	//��ǰ��û�й���
	//namespace N1{}

	int Div(int left, int right)
	{
		printf("%d\n", N1::a);
		return left / right;
	}
}

int main()
{
	int a = 30;

	// �ж��ͬ����a���ڲ�ͬ���������ں�����ֱ�ӷ���ʱ���ǰ��վͽ�ԭ��
	printf("%d\n", a);  // ���ʵ��Ǻ������е�a
	printf("%d\n", ::a);  // ����ȫ���������е�a--->::�����������
	printf("%d\n", N1::a);

	N1::Add(10, 20);

	printf("%d\n", N2::a);
	printf("%d\n", N2::N3::a);
	return 0;
}
#endif




#if 0
// ���������ռ��������ͬ��
// ��C++�У�һ�������п��Գ�����ͬ���ֵ������ռ�
// ���������ս���ͬ���������ռ�ϲ���һ��
namespace N
{
	int a = 10;

	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N
{
	int b = 20;

	int Sub(int left, int right)
	{
		return left - right;
	}
}

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::b);
	return 0;
}
#endif





#if 0
// �����ռ�ʹ�÷�ʽ��
// 1. ֱ���ڳ�Աǰ���� N::
// 2. using N::a;   �൱���ǽ�a���ɵ�ǰ�ļ��е�ȫ�ֱ�����ע�⣺��ǰ�ļ���ȫ���������в�����a���еĻ��ͳ�ͻ��
// 3. using namespace N; �൱�ڽ�N�����ռ��е����г�Ա���ɵ�ǰ�ļ���ȫ�ֱ���  ȱ�ݣ����ܻ������ͻ
//    ���������ͻ�����շ�ʽ1�����з���

namespace N
{
	int a = 10;

	int Add(int left, int right)
	{
		return left + right;
	}
}

using N::a;
// int a = 100;  // ��ͻ

using namespace N;

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	printf("%d\n", a);

	Add(10, 20);
	return 0;
}
#endif




#if 0
// C++Ҫ����C���ԣ���C�������Ѿ���������������scanf��printf
// ΪʲôC++����Ҫ���¸�һ�����������أ�
// Ϊ�˷��㣬Ϊ�˼��
int main()
{
	// printf: �����ʱ����Ҫ�Ǵ����ĸ�ʽ���ƣ���ʽ���Ƹ���ʱ������Ľ����������
	printf("%d\n", 10);
	printf("%f\n", 10.0);
	printf("%c\n", 'a');

	// ����ĸ�ʽ��������������ݸ�ʽû�ж�Ӧ����--C���Ա�������������ͷ�ƥ����
	printf("%d", 10, 20, 30);
	printf("%d %d %d", 10);
	return 0;
}
#endif




#if 0
// ע�⣺��C++�ɰ汾�� ����������ͷ�ļ���<iostream.h>�� ����vs6.0
// #include <iostream.h>  �Ͱ汾�е�ͷ�ļ�  vs6.0

// �����µı�������<iostream> + std(��׼�����ռ�)
// ��Ϊ��׼���е����ݻ���������std�������ռ��ж���

#include <iostream>
using namespace std;

int main()
{
	// ���
	cout << 10 << endl;
	cout << 12.34 << endl;
	cout << "abcdef\n";
	cout << 888 << " " << "!!!" << endl;
	return 0;
}
#endif




#if 0
// ���ƣ�ʹ���������㣬����Ҫ�Ǹ�ʽ����
int main()
{
	int a, b;
	float c;
	char d;

	cin >> a;
	cout << a << endl;

	cin >> a >> b;
	cout << a << " " << b << endl;

	cin >> a >> c >> d;
	cout << a << " " << c << " " << d << endl;
	return 0;
}
#endif




#if 0
// ������ͬ�ĵط���
// C�����ж������µĺ���
// C���Ա��������ں�������ֵ�����Լ��������ͼ�ⲻ�Ǻ��ϸ�
#include <stdio.h>
test1()
{
	printf("test1()\n");
}

void test2(int a)
{
	printf("test2(): %d\n", a);
}

int main()
{
	int a = test1();
	printf("%d\n", a);

	test2(10);
	test2(10, 20);
	test2(10, 20, 30);
	return 0;
}
#endif




#if 1
// C++���������ں������������Լ�����ֵ���ͼ������ϸ�
void test1()
{
	printf("test1()\n");
}

void test2(int a)
{
	printf("test2(): %d\n", a);
}

int main()
{
	test1();

	test2(10);
	//test2(10, 20);
	//test2(10, 20, 30);
	return 0;
}
#endif
