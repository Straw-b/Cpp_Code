#include <iostream>
using namespace std;


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
	//test2(10, 20);
	//test2(10, 20, 30);
	return 0;
}
#endif
