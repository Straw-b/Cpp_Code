#include <iostream>
using namespace std;

#if 0
// 工程是C++工程，但是想要按照C语言的方式来编译代码

extern "C" int Add(int left, int right);

int main()
{
	Add(1, 2);
	return 0;
}
#endif




#if 0
#if defined(__cplusplus)

extern "C" 
{
	int Add(int left, int right);
	int Sub(int left, int right);
	int Mul(int left, int right);
	int Div(int left, int right);
#endif
	// 在这里写标准C程序，例如dll导出函数的定义
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
// 全缺省的函数与同名的无参函数只能存在一个
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
// C语言传参有几种方式？
// 传值
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
//传地址
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// 之间有什么区别？
// 1. 传值：形参将接收到的是实参的一份拷贝,在函数中如果对形参进行改变，不会影响外部的实参
// 2. 传址：形参将放置的是实参的地址，通过对形参解引用拿到实参，对形参解引用进行修改，实际修改的就是外部的实参
//          可以通过形参来改变外部的实参
// 3. 传址比传值的效率高：传值需要的是实参本身的一份拷贝，如果实参类型比较大，将来拷贝的副本就比较大
//                       传址需要的是实参地址的一份拷贝，形参只占4个字节(32位)
//                       传址不仅效率高，而且节省空间
// 4. 传值比传地址更安全---指针必须要判空
// 5. 传值比传址代码的可读性高

// 有什么优缺点？
//传值：
//优点： 1. 代码可读性高、较安全  2. 不想通过形参改变外部的实参时，即使将形参改了也不会影响外部的实参
//缺点： 1. 传参效率低，浪费空间(传递的是实参的副本)  2. 如果想要通过形参改变外部实参时，做不到
//
//传地址：
//优点：1. 传参效率高，节省空间(传递的是实参的地址--32位平台4字节) 2. 可以通过形参改变外部的实参
//缺点：1. 安全性低，可读性低  2. 如果不想通过形参改变外部的实参时，可能会产生副作用

// 问题：能否有种类型，按值的方式进行操作，但是可以达到指针类似的效果？
//       传值，在函数中也是按照值的方式来操作的，但是可以通过形参改变外部的实参

// C++提出的引用---->就是一个别名
// 类型& 引用变量名(对象名) = 引用实体；
void TestRef()
{
	int a = 10;
	// ra就是a的别名
	int& ra = a;
	//double& rra = a;
	ra = 20;
	a = 30;
	// 因为ra是a的别名，因此ra和a在底层就共用同一个实体，即共用同一个块内存空间
	cout << &a << " " << &ra << endl;
	cout << a << " " << ra << endl;
}

int main()
{
	TestRef();//引用

	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;

	// 传值方式进行交换
	Swap(a, b);
	cout << a << " " << b << endl;

	// 传地址方式进行交换
	Swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}
#endif




#if 0
// 发现：引用可以达到指针类似的效果

void SetNULLPtr(int*& p)
{
	p = NULL;
}

// 虽然二级指针可以通过形参指针达到对外部实参指针指向的修改，但是理解起来比较麻烦
void SetNULLPtr(int** p)
{
	// *p就是实参本身
	*p = NULL;
}

// 如果需要一级指针，可以直接用引用来代替
// 如果需要二级指针，可以直接使用一级指针的引用来代替
int main()
{
	int a = 10;
	int* pa = &a;// 指针
	*pa = 20;

	int& ra = a;// 引用
	ra = 30;

	// 通过SetNULLPtr将pa指针指向空
	// 需要在SetNULLPtr函数中改变pa指针的指向
	SetNULLPtr(pa);
	SetNULLPtr(&pa);
	return 0;
}
#endif




#if 0
int main()
{
	int a = 10;
	// 引用类型的变量在定义是必须要初始化
	int& ra = a;

	// int& rb; 取的别名是给谁取的？
	// 一个变量可以有多个别名
	int& rb = a;
	int& rc = a;

	cout << &ra << " " << &rb << " " << &rc << " " << &a << endl;
	cout << ra << " " << rb << " " << rc << " " << a << endl;

	// ra已经是a的别名了
	int b = 20;

	ra = b;   // 该条语句不是让ra去引用b，而是给ra来进行赋值
	cout << &ra << " " << &b << endl;
	cout << ra << " " << b << endl;

	// &ra = b;  编译失败  &ra:对ra取地址  &在类型之后表示引用的标记  &在变量之前表示对该变量取地址

	// 引用变量非常死心眼，一辈子在一块

	// 问题：引用变量的声明周期长还是实体的生命周期长？
	if (true)
	{
		// 注意：rb只能在if的范围之内使用
		int& rrb = b;
		rrb = 30;
	}

	// cout << rrb << endl;
	return 0;
}
#endif




#if 0
// 常引用--->const类型的引用
int main()
{
	const int a = 10;   // a是不能被修改的
	//int& ra = a;      // 如果普通类型的引用变量ra去引用a，可以修改ra，如果修改ra则就会把a修改掉
	const int& ra = a;
	cout << &ra << " " << &a << endl;

	const int& rb = 100;  // 100是一个常量---也不能修改

	//正确的引用
	//double d = 12.34;
	//double& rd = d;
	//rd = 23.34;

	double d = 12.34;
	const int& rd = d; // 地址不一样，rd就不是d的别名，修改d不会对rd产生任何影响
	// 编译器创建了一个临时的int类型的变量
	d = 23.34;

	cout << &rd << " " << &d << endl;
	return 0;
}
#endif




#if 1
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