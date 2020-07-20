//#include <iostream>
//using namespace std;


#if 0
#include <stdio.h>
// 在一个作用域中不能出现相同的名字

// C语言中总共有两个作用域：函数体中的局部作用域 以及 全局作用域


// 命名空间的概念以及定义
// N1是一个命名空间
// a和Add是N1命名空间中的成员
// 命名空间：实际就是一个带有名字的作用域
// 定义格式1
namespace N1
{
	int a = 10;

	int Add(int left, int right)
	{
		return left + right;
	}
}

int a = 20;

// 命名空间定义格式2--命名空间可以嵌套---即：在命名空间中还可以继续定义命名空间
// 命名空间可以嵌套：
// 学校可以看成是一个作用域，学校中又包含了多个院系，每个院系可以看成是命名空间
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

	// 有多个同名的a处在不同的作用域，在函数中直接访问时，是按照就近原则
	printf("%d\n", a);  // 访问的是函数体中的a
	printf("%d\n", ::a);  // 访问全局作用域中的a--->::作用域运算符

	printf("%d\n", N1::a);

	N1::Add(10, 20);

	printf("%d\n", N2::a);
	printf("%d\n", N2::N3::a);
	return 0;
}
#endif




#if 0
// 两个命名空间的名字相同的
// 在C++中，一个工程中可以出现相同名字的命名空间
// 编译器最终将相同名称命名空间合并成一个
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
// 命名空间使用方式：
// 1. 直接在成员前增加 N::
// 2. using N::a;   相当于是将a当成当前文件中的全局变量，注意：当前文件的全局作用域中不能有a，有的话就冲突了
// 3. using namespace N; 相当于将N命名空间中的所有成员当前当前文件的全局变量  缺陷：可能会产生冲突
//    如果产生冲突，按照方式1来进行访问

namespace N
{
	int a = 10;

	int Add(int left, int right)
	{
		return left + right;
	}
}



using N::a;


// int a = 100;

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
// C++要兼容C语言，而C语言中已经有了输入和输出：scanf和printf
// 为什么C++还需要重新搞一套输入和输出呢？
// 为了方便，为了简答
int main()
{
	// printf: 在输出时，需要记大量的格式控制，格式控制给错时，输出的结果会有问题
	printf("%d\n", 10);
	printf("%f\n", 10.0);
	printf("%c\n", 'a');

	// 输出的格式控制与输出的数据格式没有对应起来--C语言编译器不会进行释放匹配检测
	printf("%d", 10, 20, 30);
	printf("%d %d %d", 10);
	return 0;
}
#endif




#if 0
// 注意：在C++旧版本中 输出和输出的头文件是<iostream.h>， 比如vs6.0
// #include <iostream.h>  就版本中的头文件  vs6.0

// 现在新的编译器：<iostream> + std(标准命名空间)
// 因为标准库中的内容基本都是在std的命名空间中定义

#include <iostream>
using namespace std;
#endif




#if 0
int main()
{
	// 输出
	cout << 10 << endl;
	cout << 12.34 << endl;
	cout << "abcdef\n";
	cout << 888 << " " << "!!!" << endl;
	return 0;
}
#endif




#if 0
// 优势：使用起来方便，不需要记格式控制
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
// 函数不同的地方：
// C语言中定义如下的函数
// C语言编译器对于函数返回值类型以及参数类型检测不是很严格
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




#if 0
// C++编译器对于函数参数类型以及返回值类型检测更加严格
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
	test2(10, 20);
	//test2(10, 20, 30);
	return 0;
}
#endif




#if 0
#include <iostream>
using namespace std;



namespace N
{
	int a = 10;
	int Add(int left, int right)
	{
		return left + right;
	}
}


// 将N命名空间中a成员当前当前文件的全局变量来用
using N::a;


// 使用using N::a将a导出来之后，如果全局作用中也定义了a，则一定会发生冲突
// 如果出现该中情况，则不要直接使用，N::a
//int a = 100;

// N命名空间中的所有成员相当于是当前文件的全局变量，可以直接使用，产生冲突的概率可能会高一些
using namespace N;

int main()
{
	// N命名空间中的a频繁在当前文件中被访问，每次N::a太麻烦
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;
	cout << N::a << endl;

	cout << a << endl;

	cout << N::a << endl;
	cout << a << endl;
	cout << a << endl;
	cout << a << endl;
	cout << a << endl;
	cout << a << endl;
	N::Add(10, 20);
	N::Add(10, 20);
	N::Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);
	Add(10, 20);

	return 0;
}
#endif




#if 0
/*
缺省参数：在声明或定义函数时，给函数的参数待上默认值，在函数调用时，如果传递了实参了则使用实参
如果没有传递实参则使用默认值
*/
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc(100);
	TestFunc();
	return 0;
}

#endif




#if 0
// 缺省参数的分类
// 1. 全缺省参数：所有参数都带有默认值
// 2. 半缺省参数：部分参数带有默认值

// 全缺省参数
void TestFunc1(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}


// 半缺省参数
void TestFunc2(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc1();  // abc都是用默认值

	// 如果是全缺省参数，当实参没有传递够时，编译器会将缺的参数补充上来
	TestFunc1(10);      // TestFunc1(10,2,3)
	TestFunc1(10, 20);  // TestFunc1(10, 20, 3)
	TestFunc1(10, 20, 30); // a:10  b:20 c:30


	TestFunc2(10);   // TestFunc2实际有3个参数，编译器在调用时候会根据默认值将实参补全：TestFunc2(10, 2,3);
	TestFunc2(10, 20);     // TestFunc2(10,20,3);
	TestFunc2(10, 20, 30);
	return 0;
}
#endif




#if 0
// 缺省参数：不能在声明和定义时候同时给出

// 函数声明

int g_a = 100;

void TestFunc(int a = g_a);


// 函数定义
void TestFunc(int a)
{
	cout << a << endl;
}

// 为什么？ 因为两个位置同时给，万一给的默认值不一致，到底使用哪一个

// 缺省参数既可以在函数声明时给出，也可以在函数定义时给出，那在函数声明时给好还是在函数定义时给好？

// 在函数声明时给出好
int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
// 定义一个通用类型的加法函数----任意数据类型都要能够处理

// C 语言中：函数名字一定不能相同的，如果相同编译时报错：函数重定义
int AddII(int left, int right)
{
	return left + right;
}

double AddDD(double left, double right)
{
	return left + right;
}

char AddCC(char left, char right)
{
	return left + right;
}

int main()
{
	AddII(10, 20);
	AddDD(10.0, 20.0);
	AddCC('1', '2');
	return 0;
}
#endif




#if 0
// 同一个名字出现在不同的位置，出现的位置不同，含义就不一样--->一词多义
/*
你不"美"吗？
场景一：你和女朋友在逛街，看美女---生气了--->及时去哄---> 你不"美"吗？---漂亮
场景二：你和女朋友在逛街，突然之间女朋友表情非常痛苦---->身体不舒服--->你不"美"吗？---难受
*/
// 函数名字只有一个，编译器会根据所传递实参类确认应该调用那个函数

// 函数重载
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}


namespace N
{
	short Add(short left, short right)
	{
		return left + right;
	}
}

int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add('1', '2');
	return 0;
}
#endif




#if 0
// 参数列表必须要不同: 参数个数不同  参数类型不同  类型次序不同
void TestFunc()
{}

void TestFunc(int a)
{}

void TestFunc(double a)
{}

void TestFunc(int a, double b)
{}

void TestFunc(double a, int b)
{}

int TestFunc()
{
	return 0;
}

int main()
{
	// 为什么说仅仅返回值类型不同就不能构成重载？
	TestFunc();  // 该位置的函数调用就不知道调用带有返回值的还是没有返回值的TestFunc函数--会产生二义性
	return 0;
}
#endif




#if 0
// 函数重载调用原理
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

double Add(int left, double right)
{
	return left + right;
}

/*
在编译器编译阶段，会对传递实参的类型进行推演，然后根据推演的结果选择对应类型的函数进行调用
注意：
推演完成后，如果有合适的类型重载的函数则调用
否则会发生隐式类型转化---转化之后有合适类型则调用，否则则报错
*/
int main()
{
	Add(1, 2);      // int, int--->int类型的加法
	Add(1.0, 2.0);  // double, double--->double类型的加法函数

	// char,char--->找Add(char,char)函数，遗憾该函数没有，
	// 发现Add(int,int)函数，而char和int之间可以发生隐式类型转化
	Add('1', '2');

	/*
	double和int之间可以相互转换
	int,double---->Add(int,double), 没有该函数

	此时会发生隐式类型转化
	int,double--->Add(int,int)
	int,double--->Add(double, double)

	编译器生气了--->报错
	*/
	// Add(1, 2.0);
	// 解决方式一：用户自己进行强转
	Add(1, (int)2.0);  // --->Add(int,int)

	// 解决方式二：用户给出对应的函数重载
	Add(1, 2.0);

	// Add("hello", "world");  // char*  char* 没有合适的转换供调用，编译时报错
	return 0;
}
#endif




#if 0
// 函数重载：C语言不支持、C++支持----为什么C语言不支持函数重载呢？C++是如何支持函数重载？

// 为什么C语言不支持函数重载呢？--->因为：C语言编译器对函数名字修饰规则非常简单，仅仅只是在函数名之前增加了_
//int Add(int left, int right);   // C语言编译器最终将该函数名字修改:_Add
//{
//	return left + right;
//}

double Add(double left, double right);  // C语言编译器最终将该函数名字修改:_Add
//{
//	return left + right;
//}


/*
C/C++程序从编辑完到可以运行：
预处理：头文件展开、宏替换...
编译：编译器会按照该中语言的语法规则检测代码是否存在语法问题
汇编：翻译过程--->将汇编指令翻译成对应的二进制格式指令  mov:1010  push:1011   obj文件
链接: 组装--->将多个目标文件整合成一个文件 + 解决地址问题

可以生成一个可执行程序
*/
int main()
{
	/*
	push 14h
	push 0Ah
	call 函数的入口地址_Add
	*/
	//Add(10, 20);    // error LNK2019: 无法解析的外部符号 _Add，该符号在函数 _main 中被引用
	Add(1.0, 2.0);    // error LNK2019: 无法解析的外部符号 _Add，该符号在函数 _main 中被引用
	return 0;
}
#endif




//int Add(int left, int right);   // C++编译器最终将该函数名字修改:?Add@@YAHHH@Z
//{
//	return left + right;
//}

//double Add(double left, double right);  // C++编译器最终将该函数名字修改:?Add@@YANNN@Z
//{
//	return left + right;
//}

double Add(int left, double right);

/*
C++编译器对函数名字的修饰规则：
vs
?Add@@YAHHH@Z---->H:int
?Add@@YANNN@Z---->N:double
?Add@@YANHN@Z
?开头 之后就是函数的名字Add  第一个@符号表示函数名字结束  @YA之后跟函数返回值以及参数类型  @Z表示参数列表结束

C++编译器在对函数名字修饰时：最终将参数类型信息编译到名字中去了
*/
int main()
{
	//Add(1, 2);   // 无法解析的外部符号 "int __cdecl Add(int,int)" (?Add@@YAHHH@Z)
	//Add(1.0, 2.0); // 无法解析的外部符号 "double __cdecl Add(double,double)" (?Add@@YANNN@Z)
	Add(1, 2.0);   // 无法解析的外部符号 "double __cdecl Add(int,double)" (?Add@@YANHN@Z)
	return 0;
}