#include <iostream>
using namespace std;


#if 0
// 原因？
// 在底层：void Swap(int* left, int* right) // 指针
//        {
//           int temp = *left;
//           *left = *right;
//           *right = temp;
//        }

void Swap(int& left, int& right) // 引用
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
	// *pb = 100;    // 对空指针解引用，代码在执行期间崩溃了

	// 在传参时，看起来是按照值的方式传递的
	// 但编译器在编译代码时，检测到Swap的两个参数是引用类型的
	// 编译已经将Swap函数的两个引用类型的参数转换为指针
	// 因此：Swap(a, *pb)--->编译成：Swap(&a, pb);
	Swap(a, *pb);   //  但是该位置的空指针pb解引用时却没有崩溃
	return 0;
}
#endif




#if 0
// 注意：在C++中，被const修饰的已经是常量，而且具有宏替换的属性，但是替换实际在程序编译时
// 宏：是在预处理阶段发生替换--->代码还没有编译--->预处理器直接替换，不会进行类型检测--->安全性不高
// const修饰：是在编译阶段进行替换，会进行参数类型检测--->安全性高
// 在C++中，建议用const修饰常量代替宏常量

//宏常量：为了实现简单，会定义一些宏常量
//#define MAX_SIZE 100  在程序中所有用到100的位置都可以使用MAX_SIZE来代替，将来发现100不合适，一改全改
//#define PI 3.14  可以提高程序的可读性

//注意：宏常量是在预处理阶段来进行替换的，不会进行类型检测，安全性比较低

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
	//       即在C语言中，被const修饰的变量是：一个不能被修改的变量，不能将其称为常量
	const int a = 10;
	int array1[a];

	// 编译失败，因为b是一个变量，而定义数组时，需要一个常量来指定数组的大小
	//int b = 10;
	//int array2[b];
}

//1. 打印什么?  100 10
//2. 执行完成后a的值是多少？ 100
int main()
{
	const int a = 10;

	int* pa = (int*)&a;
	*pa = 100;

	cout << *pa << endl;   // *pa===a
	printf("%d\n", a);   // 编译器将该行代码最终编译成printf("%d\n", 10);  
	                    // 没有直接从a所在的空间中取数据，而是将a替换成10
	//cout << a << endl;

	TestFunc();
	return 0;
}
#endif




//宏常量
//优点：一改全改，降低出错率，提高代码可读性
//缺点：在预处理节点进行替换，不会进行类型检测，代码的安全性较低
//在C++中，提出建议：尽量使用const修饰的常量替换宏常量

//宏函数
//优点：
//1. 不是函数，少了函数调用的开销，可以提高程序的运行效率
//2. 少写一些代码：因为宏函数可以封装多条语句---注意：不是提高了代码的复用率，因为宏函数在预处理节点展开了
//3. 可以提高代码的可读性，方便修改
//缺点：
//1. 宏函数在预处理阶段被替换，不会进行类型检测，存在安全隐患
//2. 不能调试
//3. 容易出错，在写的时候每个部分都要加括号
//4. 每个使用宏函数的位置都会被展开，会造成代码膨胀
//5. 宏函数可能会有副作用
//在C++中，对于宏函数建议尽量使用内联函数进行代替


#if 0
#define MUL(a,b) ((a)*(b))

int Mul(int left, int right)
{
	return left*right;
}

#define MAX(a,b) (((a) > (b))? (a) : (b))

int main()
{
	// MUL是一个宏函数，不是函数，在预处理节点已经将MUL宏用宏题展开了
	// 因为MUL不是函数，则不会有函数调用的开销，可以提高程序的运行效率
	cout << MUL(2, 3) << endl; // cout << 2 * 3 << endl;
	
	// Mul是一个函数，在代码执行期间就有函数调用的一些开销：比如开辟栈环境、要进行参数压栈、请清零栈空间、要返回
	cout << Mul(2, 3) << endl;

	int x = 10;
	int y = 20;

	int z = MAX(x,++y);
	cout << z << endl;  // MAX求的较大值是22，而不是21，MAX宏产生了副作用
	return 0;
}
#endif




//内联函数
//优点：
//1. 因为是函数，参数有类型，因此在编译阶段会进行参数类型检测，代码安全性高
//2. 在Debug模式下默认不会展开，可以进行调试---> 也可以通过对编译器设置来验证是否到底展开
//3. 写时候期间不用向宏函数导出加括号，实现简单
//4. 不会有副作用
//5. 在编译阶段已经展开了，少了函数调用的开销，可以提高程序的运行效率
//缺点：每个使用内联函数的位置几乎都会被展开，会造成代码膨胀


#if 0
// 在C++中，被inline关键字修饰的函数称为内联函数
// 内联函数特性：在编译时，编译器会对内联函数进行展开，少了函数调用的开销，可以提高程序的运行效率
inline int Add(int left, int right)
{
	Add(left, right);
	return left + right;
}

inline int Max(int left, int right)
{
	return left > right ? left : right;
}

#include "InlineFunc.h"

int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;

	// 检测内联函数到底有么有展开？
	// 如果没有展开，sum = Add(a,b)；在该条语句中调用Add函数，有call Add
	// 如果展开，编译器已经用Add函数的函数体替换了函数调用

	// Debug模式下，默认是不会展开的---因为Debug为调试模式
	// Debug模式，调试模式，如果展开，就不能调试

	// Release模式，发布程序时所采用的模式，Release模式编译器会对代码进行大量的优化，让程序在运行时速度更快

	sum = Add(a, b);

	cout << Max(++b, a) << endl;

	// 因为Sub函数被inline修饰，而且定义和声明分离开
	// Sub具有文件作用域，只能在其定义的文件中使用，在其他的文件中不能使用
	// 使用时，会发生链接错误--->因为编译器在编译时，发现Sub是内联函数，并没有给Sub函数生成具体函数体
	Sub(a, b);
	return 0;
}
#endif




// C语言中有auto的关键字
// auto关键字专门用来修饰函数中定义的变量，表明：该变量为自动存储类型的变量，即该变量会被自动销毁掉

// 因此C++11中，废除了auto在C语言中的作用，给全新的含义:
// auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器
// auto声明的变量必须由编译器在编译时推导变量的类型

#if 0
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

	// 注意：auto不是类型，auto此时只是一个占位符
	// 在编译器编译时，编译器推演d的初始化表达式a+10的类型为int，最终用int替换d之前的auto
	auto d = a + 10;   // 编译器编译完成后  auto d = a + 10;--->int d = a + 10;
	// cout << sizeof(auto) << endl; // 不能将 sizeof 应用于包含“auto”的类型
	
	auto ret = Add(10, 20);

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(ret).name() << endl;

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

	//auto d = 12.34, e = 10;
	// 编译器在推演auto的实际类型时：
	// 12.34--->double，auto应该为double
	// 10--->int，auto应该为int类型
	// 就有歧义：编译器现在就不知道auto到底是应该给成int类型呢还是应该给成double类型，即存在二义性
}

// 注意：auto不能用来声明函数的参数
// 因为函数的参数在定义没有初始化，既然没有初始化，编译器也无法推演形参的实际类型
// 在用auto定义形参时，给了缺省值之后为什么也不行？
// 原因：因为不是所有函数的参数都有默认值

//void TestAutoParam(auto a = 10) // 参数不能为包含“auto”的类型
//{
//	a++;
//}

void TestAutoArray()
{
	int array1[10];
	int array2[] = { 1, 2, 3 };   // array2是一个整形的数组，里面包含3个元素
	int array3[10] = { 1, 2, 3 }; // array3是一个整形的数组，里面包含10个元素，前三个元素为1 2 3，其余元素为0

	// 注意：auto不能用来定义数组
	// auto array4[] = { 1, 2, 3 }; // 数组的元素类型不能是包含“auto”的类型
}

int main()
{
	TestAuto1();
	TestAuto2();
	TestAutoArray();
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

	// 打印数组中的元素，有一个不太好的点：
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
// 范围for循环 + 配合auto
int main()
{
	// [array, array+sizeof(array)/sizeof(array[0]))
	// 那么用户在访问整个数组或者对整个数组进行操作时，能否不用给范围，让编译器自己进行确定
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// 打印数组--e:实际就是array数组中每个元素的一份拷贝
	for (auto e : array)
	{
		e *= 2; //只是为了验证e改变之后，数组中的对应元素是否发生改变--->验证e是否为数组中每个元素的拷贝
		cout << e << " ";
	}
	cout << endl; // 换行

	// 对数组中每个元素乘2的操作，e就是数组中每个元素的别名
	for (auto& e : array)
		e *= 2;

	for (auto& e : array)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif




# if 0
// 错误
// 因为数组名作为函数的参数时，实际已经退还成一个指针了
void TestFor(int array[])  // void TestFor(int* array)
{
	for (auto e : array)   // array表示的空间的范围不确定
		cout << e << " ";
	cout << endl;
}
#endif




#if 1
void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int* pa)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	int a = 10;
	int* pa = &a;

	int* pb = NULL;

	TestFunc(0);
	// 理论上应该调用整形的TestFunc函数

	TestFunc(NULL);
	// NULL是一个空值指针，理论上应该调用指针类型的TestFunc函数            
	// 该位置实际调用的是整形类型的TestFunc函数
	// #define NULL 0
	// TestFunc(NULL)--->在预处理阶段--->TestFunc(0)
	// 逻辑不符合

	TestFunc(nullptr); // 不需要包含头文件

	cout << sizeof(nullptr) << endl;

	return 0;
}
#endif