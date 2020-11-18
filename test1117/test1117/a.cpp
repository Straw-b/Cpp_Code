#define _CRT_SECURE_NO_WARNINGS 1
#include "a.h"
#include <iostream>
using namespace std;



template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

/*
double Add<double>(const double& left, const double& right)
{
return left + right;
}
*/

void TestFunc()
{
	Add(1.0, 2.0);
	Add(3, 4);
	Add('1', '2');
	cout << "TestFunc()" << endl;
}