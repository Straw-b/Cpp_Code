#include <iostream>
using namespace std;




#if 0

// 一般该种重载不会出现
void test(int a)
{}

void test(int& a)
{}

int main()
{
	test(10);

	int r = 10;
	test(r);
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;   // a在定义时，编译器要给a变量开辟空间
	int& ra = a;  // ra是引用类型的变量，在定义时，编译器就不会给ra开辟空间

	cout << typeid(a).name() << endl;
	cout << typeid(ra).name() << endl;
	return 0;
}
#endif

#if 0
#include <ctime>

struct A
{
	int array[10000];
};

void TestValue(A a)
{}

void TestRef(A& a)
{}

void TestPtr(A* a)
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

	cout << "传值性能：" << end1 - begin1 << endl;
	cout << "传引用性能：" << end2 - begin2 << endl;
	cout << "传指针性能：" << end3 - begin3 << endl;

	// 结论1：传引用效率比传值效率高---注意：在C++中，对于自定义类型的参数一般都是按照引用的方式来传递的T&  constT&
	// 结论2：传引用和传指针的效率差不多
}

int main()
{
	TestFunc();
	return 0;
}

#endif




// 引用可以达到和指针类似的效果，比如：都可以通过形参来改变外部的实参

// 问题：指针和引用有什么区别呢？

#if 0
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

#if 0
// 宏和内联函数的区别？
// 在C++中，有什么方式可以替代宏？
// 说说宏的优缺点
/*
宏常量
优点：一改全改、降低出错概率、提高代码可读性
缺点：在预处理节点进行替换，不会进行类型检测，代码的安全性较低
在C++中，提出建议：尽量使用const修饰的常量替换宏常量
宏函数
优点：
1. 不是函数，少了函数调用的开销，可以提高程序的运行效率
2. 少写一些代码：因为宏函数可以封装多条语句---注意：不是提高了代码的复用率，因为宏函数在预处理节点展开了
3. 可以提高代码的可读性

缺陷：
1. 宏函数在预处理阶段被替换，不会进行类型检测，代码的可读性比较低
2. 不能调试
3. 容易出错，在写的时候每个部分都要加括号
4. 每个使用宏函数的位置都会被展开，会造成代码膨胀
5. 宏函数可能会有副作用

在C++中，对于宏函数建议尽量使用内联函数进行代替
优点：
1. 因为是函数，参数有类型，因此在编译阶段会进行参数类型检测，代码安全性高
2. 在Debug模式下默认不会展开，可以进行调试---也可以通过对编译器设置来验证到底是否展开
3. 写时候期间不用向宏函数导出加括号，实现简单
4. 不会有副作用
5. 在编译阶段已经展开了，少了函数调用的开销，可以提高程序的运行效率


缺陷：每个使用内联函数的位置几乎都会被展开，会造成代码膨胀
*/


#define MUL(a,b) ((a)*(b))

int Mul(int left, int right)
{
	return left*right;
}


#define MAX(a,b) (((a) > (b))? (a) : (b))

int main()
{
	// Mul是一个函数，在代码执行期间就有函数调用的一些开销：比如开辟栈环境、要进行参数压栈、请清零栈空间、要返回
	cout << Mul(2, 3) << endl;

	// MUL是一个宏函数，不是函数，在预处理节点已经将MUL宏用宏题展开了
	// 因为MUL不是函数，则不会有函数调用的开销，可以提高程序的运行效率
	// 
	cout << MUL(2, 3) << endl;
	cout << 2 * 3 << endl;

	int x = 10;
	int y = 20;

	int z = MAX(++y, x);
	cout << z << endl;  // MAX求的较大值是22，而不是21，MAX宏产生了副作用
	return 0;
}
#endif



#if 0
// 在C++中，被inline关键字修饰的函数称为内联函数
// 内联函数特性：在编译期，编译器会对内联函数进行展开，少了函数调用的开销，可以提高程序的运行效率

inline int Add(int left, int right)
{
	Add(left, right);
	return left + right;
}

inline int Max(int left, int right)
{
	return left > right ? left : right;
}


/*
release模式下，main函数相当于称为了以下的代码
int main()
{
return 0;
}

*/

#include "InlineFunc.h"

int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;

	// 检测内联函数到底有么有展开？
	// 如果没有展开，sum = Add(a,b);在该条语句中调用Add函数，有call Add
	// 如果展开，编译器已经用Add函数的函数体替换了函数调用

	// Debug模式，调试模式，Debug模式下情况下，默认是不会展开的---因为Debug为调试模式
	// 如果展开，就不能调试

	// Release模式，发布程序时所采用的模式，Release模式编译器会对代码进行大量的优化，让程序在运行时速度更快

	// Debug模式来摸索：
	// 需要对编译器来设置，具体参考课件
	sum = Add(a, b);

	cout << Max(++b, a) << endl;

	// 因为Sub函数被inline修饰，而且定义和声明分离开
	// Sub具有文件作用域，只能在其定义文件中使用
	// 在其他文件中不能使用
	// 使用时，会发生链接错误---因为编译器在编译时，发现Sub是内联函数，并没有给Sub函数生成具体函数体
	Sub(a, b);
	return 0;
}
#endif


#if 0
// C语言中有auto的关键字
// auto关键字专门用来修饰函数中定义的变量，表明：该变量为自动存储类型的变量，即该变量会被自动销毁掉

// 因此C++11中，废除了auto在C语言中的作用，给全新的含义:
//   auto不再是一个存储类型指示符，而是作为一个新的类型
//   指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导变量的类型


int Add(int left, int right)
{
	return left + right;
}

int main()
{
	// auto int a = 10;  // 局部变量，而局部变量在函数结束时本来就会自动销毁

	auto a = 10;
	auto b = "1234";
	auto c = 12.34;

	// 注意：auto不是类型
	// auto此时只是一个占位符
	// 在编译器编译时，编译器推演d的初始化表达式a+10的类型为int，最终用int替换d之前的auto
	auto d = a + 10;   // 编译器编译完成后  auto d = a + 10;--->int d = a+10;
	// cout << sizeof(auto) << endl;

	auto ret = Add(10, 20);
	cout << typeid(ret).name() << endl;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;


	// 在用auto定义变量时，必须对变量进行初始化
	// 因为：编译器在编译期间，要根据变量的初始化表达式来推演该变量的实际类型
	// 将该实际类型推演出来之后替换auto
	// auto e;
	return 0;
}
#endif


#if 0
void TestAuto1()
{
	auto a = 10;

	// 使用auto定义指针类型变量时，加不加*都无所谓
	auto pa = &a;   // auto---> 替换为int*
	auto *pb = &a;  // auto---> 替换为int
	cout << typeid(pa).name() << endl;
	cout << typeid(pb).name() << endl;

	// 注意：auto定义引用类型变量时，auto之后必须要&
	auto& ra = a;   // 让ra引用a
	auto rra = a;   // 注意：rra并不是a的引用，只是定义了一个rra的变量，该变量使用a来进行初始阿化

	cout << &a << endl;
	cout << &ra << endl;
	cout << &rra << endl;
}

void TestAuto2()
{
	// 使用auto在一行定义多个变量时，每个变量的初始化表达式的类型必须一致
	auto a = 1, b = 2, c = a + b;

	// 编译器在推演auto的实际类型时：
	// 12.34--->double auto 应该为double
	// 10--->int  auto应该为int类型
	// 就有歧义：编译器现在就不知道auto到底是应该给成int类型呢还是应该给成double类型，即存在二义性
	//auto d = 12.34, e = 10;

}


// 注意：auto不能用来声明函数的参数
// 因为函数的参数在定义没有初始化，既然没有初始化，编译器也无法推演形参的实际类型
// 在用auto定义形参时，给了缺省值之后为什么也不行？
// 原因：因为不是所有函数的参数都有默认值
void TestAutoParam(auto a = 10)
{
	a++;
}

void TestAutoArray()
{
	int array0[10];
	int array1[] = { 1, 2, 3 };   // array1是一个整形的数组，里面包含3个元素
	int array2[10] = { 1, 2, 3 }; // array2是一个整形的数组，里面包含10个元素，前三个元素为1 2 3，其余元素为0


	// 注意：auto不能用来定义数组
	auto array4[] = { 1, 2, 3 };
}

int main()
{
	TestAuto1();
	return 0;
}
#endif

#if 0
int main()
{
	// [array, array+sizeof(array)/sizeof(array[0]))
	// 问题：既然数组定义好了之后，数组的范围是确定的
	// 那么用户在访问整个数组或者对整个数组进行操作时，能否不用给范围，让编译器自己进行确定
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// 打印数组中的元素
	// 有一个不太好的点：
	// 在对数组操作时，必须要依靠用户来确定数组的范围
	// 但是：数组定义好了之后，范围就是确定的
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";
	cout << endl;

	// 对数组中每个元素*2
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	cout << endl;

	// 打印数组的元素
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << " ";
	cout << endl;

	return 0;
}
#endif



#if 0
// 因为数组名作为函数的参数时，实际已经退还成一个指针了
void TestFor(int array[])  // void TestFor(int* array)
{
	for (auto e : array)   // array表示的空间的范围不确定
		cout << e << " ";
	cout << endl;
}

// 范围for循环 + 配合auto
int main()
{
	// [array, array+sizeof(array)/sizeof(array[0]))
	// 那么用户在访问整个数组或者对整个数组进行操作时，能否不用给范围，让编译器自己进行确定
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// 打印数组--e:实际就是array数组中每个元素的一份拷贝
	for (auto e : array)
	{
		// e *= 2; 只是为了验证e改变之后，数组中的对应元素是否发生改变--->验证e是否为数组中每个元素的拷贝
		cout << e << " ";
	}
	cout << endl;

	// 对数组中每个元素乘2的操作
	// e就是数组中每个元素的别名
	for (auto& e : array)
		e *= 2;
	cout << endl;

	for (auto& e : array)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif