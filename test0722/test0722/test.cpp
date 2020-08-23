#include <iostream>
using namespace std;



#if 0
// 注意：以引用方式作为函数的返回值时，一定不能返回栈上的空间：比如函数中的局部变量
// 对函数调用原理是否清楚？
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}

int main()
{
	int& sum = Add(1, 2);
	Add(3, 4);
	Add(5, 6);
	return 0;
}
#endif




#if 0
// 注意：返回实体的声明周期只要不随函数的结束而结束即可
int g_a = 0;// 全局变量

//int& Add(int left, int right)
//{
//	g_a = left + right;
//	return g_a;
//}
//int main()
//{
//	int& sum = Add(1, 2);
//	Add(3, 4);
//	Add(5, 6);
//	return 0;
//}


int& Add(int left, int right, int& ret)
{
	g_a = left + right;
	return ret;
}
int main()
{
	int r = 0;
	int& sum = Add(1, 2, r);
	Add(3, 4, r);
	Add(5, 6, r);
	return 0;
}
#endif




#if 0
// 问题
// 一般该种重载不会出现
void test(int a)
{}

void test(int& a)
{}

int main()
{
	test(10);

	int r = 10;
	test(r);// 两个方法都可以调用
	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;   // a在定义时，编译器要给a变量开辟空间
	int& ra = a;  // ra是引用类型的变量，在定义时，编译器就不会给ra开辟空间

	cout << typeid(a).name() << endl; // 验证类型
	cout << typeid(ra).name() << endl;
	return 0;
}
#endif




#if 0
#include <ctime> // clock 的头文件

struct A
{
	int array[100000];
};

void TestValue(A a) // 传值
{}
void TestRef(A& a) // 传引用
{}
void TestPtr(A* a) // 传指针
{}

void TestFunc()
{
	A a;

	// 传值，在传参期间需要进行实参的一份拷贝
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
		TestValue(a);
	size_t end1 = clock();

	// 引用是别名，在传参期间不需要进行拷贝
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end2 = clock();

	// 传指针，在传参期间不需要进行对象的拷贝---拷贝的是对象的地址---32平台下就是4个字节
	size_t begin3 = clock();
	for (int i = 0; i < 100000; i++)
		TestPtr(&a);
	size_t end3 = clock();

	cout << "传值性能：" << end1 - begin1 << " ms" << endl;
	cout << "传引用性能：" << end2 - begin2 << " ms" << endl;
	cout << "传指针性能：" << end3 - begin3 << " ms" << endl;

	// 结论1：传引用效率比传值效率高
	// ---注意：在C++中，对于自定义类型的参数一般都是按照引用的方式来传递的T&  constT&

	// 结论2：传引用和传指针的效率差不多
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
// 引用可以达到和指针类似的效果，比如：都可以通过形参来改变外部的实参
// 问题：指针和引用有什么区别呢？
// 在底层实现上：引用就是按照指针方式实现的
int main()
{
	int a = 10;

	int* pa = &a;
	*pa = 100;

	// 概念上为了大家好理解，引用就是别名，引用与其引用的实体共用同一块内存空间，
	// 编译器不会给引用变量重新开辟内存空间

	// 实现该中技术：编译器在底层是按照指针的方式来实现

	// 用户写的代码：最终保存在磁盘中的某个文件中
	// 系统执行的代码：首先预处理、编译、汇编、链接--->生成可执行程序(exe)
	// 其中编译---编译器按照语法来检测代码，看是否有不满足语法的问题存在
	//          对用户所写代码进行翻译
	// 程序中使用到了引用
	// 编译器在翻译的时候，将引用按照指针的方式翻译了
	// 经过编译器编译之后的代码，根本就没有引用
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




#if 0
int main()
{
	int* p;

	int a = 10;
	int& ra = a;
	ra++;   // 注意：在底层处理上，编译器会对ra解引用找到a


	int b = 20;

	p = &a;
	p++;   // 指针只有指向一段连续的空间，++/--才有意义

	p = &b;

	int* const cp = &a;
	// pc = &b;

	char c = 'a';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;  // 4  在32平台下，任何指针都占有4个字节
	cout << sizeof(rc) << endl;  // 1  引用类型实际就是其引用实体类型的大小


	// 有多级指针
	int* p1 = NULL;
	int** p2 = NULL;
	int*** p3 = NULL;


	// 没有多级引用--->其实就没有多级引用这个名词
	int d = 10;
	int& rd = d;

	//int&& rrd = d;
	// 右值引用--->C++11
	int&& rrd = 10; // 有这种写法
	return 0;
}
#endif




#if 0
// 原因？
// 在底层：void Swap(int* left, int* right)
//        {
//           int temp = *left;
//           *left = *right;
//           *right = temp;
//        }

void Swap(int& left, int &right)
{
	int temp = left;
	left = right;   // 代码崩溃
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int* pb = NULL;
	// *pb = 100;     // 对空指针解引用，代码在执行期间崩溃了

	// 在传参时，看起来是按照值的方式传递的
	// 但编译器在编译代码时，检测到Swap的两个参数是引用类型的
	// 编译已经将Swap函数的两个引用类型的参数转换为指针
	// 因此：Swap(a, *pb)--->编译成：Swap(&a, pb);

	Swap(a, *pb);   //  但是该位置的空指针pb解引用时却没有崩溃
	return 0;
}
#endif




#if 1
//1. 打印什么100 10
//2. 执行完成后a的值是多少？  100

// 注意：在C++中，被const修饰的已经是常量，而且具有宏替换的属性，但是替换实际在程序编译时
// 宏：是在预处理阶段发生替换---代码还没有编译---预处理器直接替换，不会进行类型检测---安全性不高
// const修饰：是在编译阶段进行替换---会进行参数类型检测---安全性高

// 在C++中，建议用const修饰常量代替宏常量--- 

/*
宏常量：为了实现简单，会定义一些宏常量
#define MAX_SIZE 100  在程序中所有用到100的位置都可以使用MAX_SIZE来代替，将来发现不100不合适，一改全改
#define PI 3.14  可以提高程序的可读性

注意：宏常量是在预处理阶段来进行替换的  不会进行类型检测  安全比较低
*/

#define PI "3.1415"

const double pi = 3.14;//"3.14";

void TestFunc()
{
	int r = 2;
	//double s = PI * r * r;   // double s = "3.1415" * r * r;

	double s = pi * r * r;
	cout << s << endl;


	// 要验证被const修饰的a是否为常量，借助定义数组来测试
	// 因为：定义数组时必须要给出数组的大小，而数组的大小必须是常量
	// 编译成功，因为a被const修饰，a是一个常量
	// 注意：在C语言中，被const修饰的变量不能将其称为常量，仍旧是一个变量，只不过该变量不能够被修改
	//      即在C语言中，被const修饰的变量是：一个不能被修改的变量，不能将其称为常量
	const int a = 10;
	int array1[a];

	// 编译失败，因为b是一个变量，而定义数组时，需要一个常量来指定数组的大小
	//int b = 10;
	//int array2[b];
}


int main()
{
	const int a = 10;

	int* pa = (int*)&a;
	*pa = 100;

	cout << *pa << endl;   // *pa===a
	printf("%d\n", 10/*a*/);  // 编译器将该行代码最终编译成printf("%d\n", 10);  没有直接从a所在的空间中取数据，而是将a替换成10
	cout << a << endl;
	return 0;
}
#endif

