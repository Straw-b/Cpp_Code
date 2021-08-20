#include <iostream>
using namespace std;

#if 0
// ������C++���̣�������Ҫ����C���Եķ�ʽ���������

extern "C" int Add(int left, int right);

int main()
{
	Add(1, 2);
	return 0;
}
#endif




#if 0
#if defined(__cplusplus) // ��⹤���ǲ���C++����

extern "C" 
{
	int Add(int left, int right);
	int Sub(int left, int right);
	int Mul(int left, int right);
	int Div(int left, int right);
#endif
	// ������д��׼C��������dll���������Ķ���
#ifdef __cplusplus
}

#endif

int main()
{
	Add(1, 2);
	Sub(1, 2);
	Mul(1, 2);
	Div(1, 2);
	return 0;
}
#endif




#if 0
// ȫȱʡ�ĺ�����ͬ�����޲κ���ֻ�ܴ���һ��
void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}

void TestFunc()
{
	cout << "void TestFunc()" << endl;
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
// C���Դ����м��ַ�ʽ��
// ��ֵ
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
//����ַ
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// ֮����ʲô����
// 1. ��ֵ���βν����յ�����ʵ�ε�һ�ݿ���,�ں�����������βν��иı䣬����Ӱ���ⲿ��ʵ��
// 2. ��ַ���βν����õ���ʵ�εĵ�ַ��ͨ�����βν������õ�ʵ�Σ����βν����ý����޸ģ�ʵ���޸ĵľ����ⲿ��ʵ��
//          ����ͨ���β����ı��ⲿ��ʵ��
// 3. ��ַ�ȴ�ֵ��Ч�ʸߣ���ֵ��Ҫ����ʵ�α����һ�ݿ��������ʵ�����ͱȽϴ󣬽��������ĸ����ͱȽϴ�
//                       ��ַ��Ҫ����ʵ�ε�ַ��һ�ݿ������β�ֻռ4���ֽ�(32λ)
//                       ��ַ����Ч�ʸߣ����ҽ�ʡ�ռ�
// 4. ��ֵ�ȴ���ַ����ȫ---ָ�����Ҫ�п�
// 5. ��ֵ�ȴ�ַ����Ŀɶ��Ը�

// ��ʲô��ȱ�㣿
//��ֵ��
//�ŵ㣺 1. ����ɶ��Ըߡ��ϰ�ȫ  2. ����ͨ���βθı��ⲿ��ʵ��ʱ����ʹ���βθ���Ҳ����Ӱ���ⲿ��ʵ��
//ȱ�㣺 1. ����Ч�ʵͣ��˷ѿռ�(���ݵ���ʵ�εĸ���)  2. �����Ҫͨ���βθı��ⲿʵ��ʱ��������
//
//����ַ��
//�ŵ㣺1. ����Ч�ʸߣ���ʡ�ռ�(���ݵ���ʵ�εĵ�ַ--32λƽ̨4�ֽ�) 2. ����ͨ���βθı��ⲿ��ʵ��
//ȱ�㣺1. ��ȫ�Եͣ��ɶ��Ե�  2. �������ͨ���βθı��ⲿ��ʵ��ʱ�����ܻ����������

// ���⣺�ܷ��������ͣ���ֵ�ķ�ʽ���в��������ǿ��Դﵽָ�����Ƶ�Ч����
//       ��ֵ���ں�����Ҳ�ǰ���ֵ�ķ�ʽ�������ģ����ǿ���ͨ���βθı��ⲿ��ʵ��

// C++���������---->����һ������
// ����& ���ñ�����(������) = ����ʵ�壻
void TestRef()
{
	int a = 10;
	// ra����a�ı���
	int& ra = a;
	//double& rra = a;
	ra = 20;
	a = 30;
	// ��Ϊra��a�ı��������ra��a�ڵײ�͹���ͬһ��ʵ�壬������ͬһ�����ڴ�ռ�
	cout << &a << " " << &ra << endl;
	cout << a << " " << ra << endl;
}

int main()
{
	TestRef();//����

	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;

	// ��ֵ��ʽ���н���
	Swap(a, b);
	cout << a << " " << b << endl;

	// ����ַ��ʽ���н���
	Swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}
#endif




#if 0
// ���֣����ÿ��Դﵽָ�����Ƶ�Ч��
void SetNULLPtr(int*& p)
{
	p = NULL;
}

// ��Ȼ����ָ�����ͨ���β�ָ��ﵽ���ⲿʵ��ָ��ָ����޸ģ�������������Ƚ��鷳
void SetNULLPtr(int** p)
{
	// *p����ʵ�α���
	*p = NULL;
}

// �����Ҫһ��ָ�룬����ֱ��������������
// �����Ҫ����ָ�룬����ֱ��ʹ��һ��ָ�������������
int main()
{
	int a = 10;
	int* pa = &a;// ָ��
	*pa = 20;

	int& ra = a;// ����
	ra = 30;

	// ͨ��SetNULLPtr��paָ��ָ���
	// ��Ҫ��SetNULLPtr�����иı�paָ���ָ��
	SetNULLPtr(pa);
	SetNULLPtr(&pa);
	return 0;
}
#endif




#if 0
int main()
{
	int a = 10;
	// �������͵ı����ڶ����Ǳ���Ҫ��ʼ��
	int& ra = a;

	// int& rb; ȡ�ı����Ǹ�˭ȡ�ģ�
	// һ�����������ж������
	int& rb = a;
	int& rc = a;

	cout << &ra << " " << &rb << " " << &rc << " " << &a << endl;
	cout << ra << " " << rb << " " << rc << " " << a << endl;

	// ra�Ѿ���a�ı�����
	int b = 20;

	ra = b;   // ������䲻����raȥ����b�����Ǹ�ra�����и�ֵ
	cout << &ra << " " << &b << endl;
	cout << ra << " " << b << endl;

	// &ra = b;  ����ʧ��  &ra:��raȡ��ַ  &������֮���ʾ���õı��  &�ڱ���֮ǰ��ʾ�Ըñ���ȡ��ַ

	// ����ͬһ������ʵ����������ڳ�
	if (true)
	{
		// ע�⣺rbֻ����if�ķ�Χ֮��ʹ��
		int& rrb = b;
		rrb = 30;
	}

	// cout << rrb << endl;
	return 0;
}
#endif




#if 0
// ������--->const���͵�����
int main()
{
	const int a = 10;   // a�ǲ��ܱ��޸ĵ�
	//int& ra = a;      // �����ͨ���͵����ñ���raȥ����a�������޸�ra������޸�ra��ͻ��a�޸ĵ�
	const int& ra = a;
	cout << &ra << " " << &a << endl;

	//int& rb = 100;  // 100��һ������---Ҳ�����޸�
	const int& rb = 100;

	//��ȷ������
	//double d = 12.34;
	//double& rd = d;
	//rd = 23.34;

	double d = 12.34;
	const int& rd = d; // ��ַ��һ����rd�Ͳ���d�ı������޸�d�����rd�����κ�Ӱ��
	// ������������һ����ʱ��int���͵ı���
	d = 23.34;

	cout << &rd << " " << &d << endl;
	return 0;
}
#endif




#if 1
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