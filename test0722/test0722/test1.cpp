#include <iostream>
using namespace std;




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
	int&& rrd = 10;
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

#if 0
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
	//cout << a << endl;
	return 0;
}
#endif

