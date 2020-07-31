#include <iostream>
using namespace std;



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




#if 0
// 注意：返回实体的声明周期只要不随函数的结束而结束即可
int g_a = 0;
int& Add(int left, int right, int& ret)
{
	g_a = left + right;
	// return g_a;

	return ret;
}

int main()
{
	int r = 0;
	int& sum = Add(1, 2, r);
	Add(3, 4);
	Add(5, 6);
	return 0;
}
#endif
