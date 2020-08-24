#include <iostream>
using namespace std;







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