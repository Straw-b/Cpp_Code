#include "InlineFunc.h"

// 如果编译器将Sub当成内联函数来处理
// 将来编译时，并不会生成真正的Sub函数
int Sub(int left, int right)
{
	return left - right;
}

void TestFunc()
{
	int a = 10;
	int b = 20;

	// Sub(a, b);  // a - b
}