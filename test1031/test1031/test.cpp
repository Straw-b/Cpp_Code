#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>


#if 0
// 创建二维数组
int** Create(int row, int col)
{
	int** p = new int*[row];
	for (int i = 0; i < row; ++i)
		p[i] = new int[col];

	return p;
}
#endif




#if 0
void TestVector(size_t n)
{
	//vector<int> v;
	//v.reserve(10); // 扩容，无元素
	//v.resize(10); // 扩容，放置元素
	//cout << v[0] << endl;

	vector<vector<int>> vv;

	// 开辟保存每行vector元素的空间
	vv.resize(n);

	// 开辟每行的空间
	for (size_t i = 0; i < n; ++i)
	{
		// 每行放置元素
		vv[i].resize(i + 1, 1);
	}

	// 计算杨辉三角除第0列和对角线之外的元素
	for (size_t i = 2; i < n; ++i)
	{
		for (size_t j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			printf("%3d", vv[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	TestVector(5);
	return 0;
}
#endif




#if 0
int main()
{
	vector<int> v;
	v.push_back(1);

	auto it = v.erase(v.begin());
	if (it == v.end())
		cout << "it == end" << endl;
	else
		cout << "it != end" << endl;
	return 0;
}
#endif




#if 0
#include "Vector.h"

int main()
{
	//TestMyVector1();
	//TestMyVector2();
	TestMyVector3();
	return 0;
}
#endif




#if 1
#include "Vector.h"

// 下标运算符成对给出
int main()
{
	// 普通类型的对象
	bite::vector<int> v1(10, 5);
	// v1[0]--->v1.operator[](0)--->t
	v1[0] = 6; // 返回引用
	cout << v1[0] << endl;

	const bite::vector<int> v2(10, 5); // const类型的对象
	cout << v2[0] << endl; // 元素访问
	return 0;
}
#endif
