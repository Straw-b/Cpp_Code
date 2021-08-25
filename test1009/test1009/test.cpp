#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

void TestFunc()
{
	// ������Ҫ�ڶ��ϴ���һ��Test���͵Ķ���
	Test* pt = (Test*)malloc(sizeof(Test));

	// ....

	free(pt);
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
int main()
{
	// �ռ�����
	// ���뵥�����Ϳռ�
	int* p1 = new int;
	// ���뵥�����Ϳռ�---���ҶԿռ��е����ݽ��г�ʼ��
	int* p2 = new int(10); // ������Ŀռ���г�ʼ��

	// ����һ�������Ŀռ�
	int* p3 = new int[10];
	// ����һ�������Ŀռ䲢���г�ʼ��
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	// �ռ��ͷ�
	// ʹ��delete���ͷŵ������͵Ŀռ�
	delete p1;
	delete p2;

	// ʹ��delete[]���ͷ������Ŀռ�
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	Test* pt1 = new Test;
	Test* pt2 = new Test[10];

	delete pt1;
	delete[] pt2;
	return 0;
}
#endif




#if 0
class Test
{
public:
	Test(int t, int a)
		: _t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	// ע�⣺���������޲λ���ȫȱʡ�Ĺ��캯��ʱ��new�����Ͷ���ʱ�����Բ�������
	//      �������д��в����Ĺ��캯��ʱ��new�����Ͷ���ʱ������Ҫ��T(����)
	Test* pt1 = new Test(10, 20);
	Test* pt2 = new Test(20, 30);
	delete pt1;
	delete pt2;
	return 0;
}
#endif




#if 0
class Test
{
public:
	//Test(int t = 10) // ����Ĭ��ֵ��ȫȱʡ�Ĺ��캯�����������͵Ŀռ䣬���Խ��г�ʼ��
	Test(int t) // �Զ������Ͷ���������ռ䣬�޷����г�ʼ��
		: _t(t)
	{
		cout << "Test(int):" << this << endl;
	}
	
	Test() // �޲����͵Ĺ��캯��
		: _t(100)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	// ע�⣺������������Ŀռ�ʱ�������Ҫ�����޲εĻ���ȫȱʡ�Ĺ��캯��
	//       ������������͵Ŀռ䣬���Խ��г�ʼ��
	//       ������Զ������Ͷ���������ռ䣬�޷����г�ʼ��
	//Test* pt = new Test[10]{{ 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 }, { 0 }}; //����ʧ��
	//Test* pt = new Test[10]{1,2,3,4,5,6,7,8,9,0}; // ����ʧ��
	Test* pt = new Test[10];
	delete[] pt;

	// Test t();  
	//ע�⣺�˴����Ǵ�����һ��Test���͵Ķ���t������������һ������
	//������������t���ú���û�в���������ֵ������Test

	Test();  // ������һ����������
	Test* pt2 = new Test();
	delete pt2;

	Test* pt3 = new Test; // �����޲����͵Ĺ��캯��
	Test* pt4 = new Test(); // �����޲����͵Ĺ��캯��
	Test* pt5 = new Test(20); // ���ô��в����Ĺ��캯��

	return 0;
}
#endif




#if 0
void TestFunc()
{
	// �����������͵Ŀռ䣬û��ƥ������ʹ�ã�û���κε�Ӱ��
	// ���ǣ�������������ȥд��һ���������ֲ��õ�ϰ�ߣ��ǻ���Ѹı�
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;
	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;

	// ע�⣺��vs�п���ʹ�øú������򵥵ļ��������Ƿ�����ڴ�й©
	_CrtDumpMemoryLeaks();
}

int main()
{
	TestFunc();
	return 0;
}
#endif




// ����Զ������Ͷ������漰����Դ����ʱ��һ��ƥ������ʹ��
// ����Զ������Ͷ�����δ�漰����Դ����ʱ��Ҳ һ�� Ҫƥ������ʹ��
#if 0
class Test
{
public:
	Test(int t = 10)// ȫȱʡ�Ĺ��캯�����������͵Ŀռ䣬���Խ��г�ʼ��
		: _t(t)
	{
		p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete p;
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
	int* p;
};

void TestFunc()
{
	// ��Ϊ��malloc��������Ĳ���һ��Test���͵Ķ��󣬶���Test���ʹ�С��ͬ��һ�οռ�
	// ��ˣ����ͷŸÿռ�ʱ��Ҳ����ʹ��delete�������ͷţ���Ϊdelete�������������
	// ��������������Ҫ�Զ�����pָ��ָ��Ŀռ�����ͷţ���malloc����Ŀռ�û�е��ù��캯��
	// ��p1���г�ʼ����p1ָ��Ŀռ��е����������ֵ
	//Test* p1 = (Test*)malloc(sizeof(Test));
	//delete p1;

	//Test* p2 = (Test*)malloc(sizeof(Test));
	//delete[] p2;

	//Test* p3 = new Test;
	//free(p3);  //û��ʹ��delete�������ͷţ�p3�����е�p��Աָ���int���͵Ķѿռ��û�б��ͷŵ����������ڴ�й©
	//delete p3; // ����
	//delete[] p3;// �������
	//_CrtDumpMemoryLeaks();

	// �������
	//Test* p4 = (Test*)malloc(sizeof(Test));
	//delete[] p4;

	// �������
	//Test* p5 = new Test;
	//delete[] p5;
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 1
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}
#endif
