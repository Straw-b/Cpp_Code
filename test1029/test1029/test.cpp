#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <string>


#if 0
void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	vector<int>::iterator it = v3.begin();

	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string s("hello");
	vector<char> v4(s.begin(), s.end());

	vector<int> v5(v3);
	// vector<int>::reverse_iterator rit = v5.rbegin();
	auto rit = v5.rbegin();
	while (rit != v5.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<int> v6{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// e�Ƕ�v6��ÿ��Ԫ�ص�����
	for (auto& e : v6)
		e *= 2;

	// e��v6��ÿ��Ԫ�ص�һ�ݿ���
	// ע�⣺��Χfor��ԭ������������������ԭ������ȫ��ͬ��
	for (auto e : v6)
		cout << e << " ";
	cout << endl;
}

int main()
{
	TestVector1();
	return 0;
}
#endif




#if 0
void TestVector2()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	if (v.empty())
	{
		cout << "v empty" << endl;
	}
	else
	{
		cout << "v not empty" << endl;
	}

	// �÷���ֻ�ǽ���ЧԪ����գ�������Ӱ��ײ�ռ��ܵĴ�С
	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	TestVector2();
	return 0;
}
#endif




#if 0
class A
{
public: 
	A(int a = 10) // ���캯��
 		: _a(a)
	{}

	A(const A& a) // �������캯��
		: _a(a._a)
	{
		cout << "A(const A& a)" << endl;
	}

private:
	int _a;
};

void TestVector3()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.resize(5);

	v.resize(7, 100); // ���Ԫ����100���

	v.resize(9);

	v.resize(20, 50);

	vector<int> v1(10);
	vector<A> v2(10); // �����޲λ���ȫȱʡ�Ĺ��캯��
}

int main()
{
	TestVector3();
	return 0;
}
#endif




#if 0
void TestVector4()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.reserve(5);
	v.reserve(30);
	v.reserve(25);
	v.reserve(40);
}

int main()
{
	TestVector4();
	return 0;
}
#endif




#if 0
void TestVector5()
{
	vector<int> v{ 1, 2, 3 };
	cout << v.front() << endl;
	cout << v.back() << endl;

	v.clear();

	// ע�⣺ʹ��front��back����vector��Ԫ��ʱ��vectorһ������Ϊ��
	cout << v.front() << endl;
	cout << v.back() << endl;
}

int main()
{
	TestVector5();
	return 0;
}
#endif




#if 0
// ��������Ԫ�صĲ���
void TestVector6()
{
	// ע�⣺push_back��insert�ڲ���Ԫ���ڼ䣬������Ҫ����
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.pop_back(); // βɾ

	v.insert(v.begin(), 0);
	// ������Ԫ��2��λ�ò���10��ֵΪ5��Ԫ��
	v.insert(find(v.begin(), v.end(), 2), 10, 5);
	//������array�е�Ԫ�ز��뵽v��β��
	int array[] = { 4, 5, 6, 7 };
	v.insert(v.end(), array, array + sizeof(array) / sizeof(array[0]));
}

int main()
{
	TestVector6();
	return 0;
}
#endif




#if 0
class A
{
public:
	A(int a = 1) // ���캯��
		: _a(a)
	{}

	A(const A& a) // �������캯��
		: _a(a._a)
	{
		cout << "A(const A& a)" << endl;
	}

private:
	int _a;
};

// �����Զ������͵�Ԫ�أ����ղ������һ�ݿ���
void TestVector7()
{
	A a; //����һ���ṹ�����

	vector<A> v;
	v.reserve(10); // ���ݵ�10��
	v.push_back(a);
	v.push_back(a);
}

int main()
{
	TestVector7();
	return 0;
}
#endif




#if 0
void TestVector8()
{
	size_t sz;
	std::vector<int> foo;
	// foo.reserve(100);
	sz = foo.capacity();
	std::cout << "���ݻ���:\n";
	for (int i = 0; i < 100; ++i)
	{
		// �����ڼ���Ҫ����
		foo.push_back(i); 

		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	TestVector8();
	return 0;
}
#endif




#if 0
void TestVector9()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 3);

	//v.erase(v.begin(), v.end()); 
	//v.clear();
	auto it = v.begin();
	while (it != v.end())
	{
		v.erase(it); // ���ڵ�����ʧЧ������
		it++;
	}
}

int main()
{
	TestVector9();
	return 0;
}
#endif




#if 0
void TestVector10()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 4, 5, 6, 7, 8, 9 };

	// it1ָ��v1ԭ���ռ����ʼλ��
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	// v1�ײ�Ŀռ��Ѿ������ı�
	v1.swap(v2);

	// û��ʧЧ
	cout << *it1 << endl;
	cout << *it2 << endl;


    // �����������¸�ֵ�������������ʧЧ
	it1 = v1.begin(); 
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

int main()
{
	TestVector10();
	return 0;
}
#endif




#if 0
void TestVector11()
{
	vector<int> v{ 1, 2, 3 };
	auto it = v.begin(); // ������
	//v.clear();
	//cout << *it << endl;

	while (it != v.end())
	{
		it = v.erase(it); // ����erase�ķ���ֵ
		// it++;  //��Ϊerase֮��it������ʧЧ��
	}
	//cout << *it << endl;
}

int main()
{
	TestVector11();
	return 0;
}
#endif




#if 0
void TestVector12()
{
	vector<vector<int>> vv;

	vector<int> v(5, 10);
	for (size_t i = 0; i < 4; ++i)
	    vv.push_back(v); // ����v


	vector<vector<int>> vv1(4, vector<int>(5, 10));
}

int main()
{
	TestVector12();
	return 0;
}
#endif




// �������
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
#if 1
void TestVector13(size_t n)
{
	vector<vector<int>> vv;
	vv.resize(n); // n��Ԫ��
	for (size_t i = 0; i < n; i++) // �ȹ���ȫΪ1������
	{
		vv[i].resize(i + 1, 1); //ÿһ�ж�һ��1
	}

	for (size_t i = 2; i < vv.size(); ++i)
	{
		for (size_t j = 1; j < vv[i].size() - 1; ++j) // ����ÿһ��
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
}

int main()
{
	TestVector13(5);
	return 0;
}
#endif
