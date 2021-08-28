#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>


#if 0
// 构造
void TestString1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(10, 'a');
	string s5(50, 'b');
	string s6("hello", 3);	// 放前3个hello进去，为hel
	string s7("hello", 10);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;

	cin >> s1;
	cout << s1 << endl;
}

int main()
{
	TestString1();
	return 0;
}
#endif




#if 0
// 容量
void TestString2()
{
	string s1("hello");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}

	// s1 = "";
	s1.clear();
	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}
}

int main()
{
	TestString2();
	return 0;
}
#endif




#if 0
//void resize(size_t n, char c)
//void resize(size_t n)

//s1.resize(20, '!');
//假设s1中有效字符为size 容量为capacity
//size > 20 将有效字符个数减少到20个，第二个参数不起作用
//size < 20 将s1中有效字符个数增多到20个，多出的20-size个字符使用!(第二个参数)进行填充
//如果第二个参数没有提供，则使用0进行填充----很少使用
//capacity > 20  底层不需要扩容
//capacity < 20 再将字符个数增多时，需要进行扩容
//当使用resize将字符有效个数减少时，resize方法不会缩小底层容量的大小

void TestString3()
{
	string s1("hello");

	// 将s1中有效字符增加到10个，多出的5个字符使用'!'来进行填充
	s1.resize(10, '!');

	s1.resize(15);

	// 将s1中有效字符增加到32个，多出的22个字符使用'$'来进行填充
	// 在增加字符期间会进行扩容
	s1.resize(32, '$');
	cout << s1 << endl;

	// 当resize将有效元素个数减少时，只修改有效元素个数，而不会缩小底层空间的大小
	s1.resize(28, '*');
	s1 += "world";
	cout << s1 << endl;

	s1.resize(20);
	s1.resize(16);
	s1.resize(8);	
	cout << s1 << endl;
}

int main()
{
	TestString3();
	
	return 0;
}
#endif




#if 0
//  void reserve(size_t newcapacity)

//假设：string类型对象原来的容量为oldcapacity
//newcapacity > oldcapacity： 将string类型对象底层的容量增大
//    实际增加到多大，newcapacity只是一个参考
//newcapacity <= oldcapacity 将string类型对象底层的容量缩小
//    当newcapacity > 15时，底层容量不会发生改变
//    当newcapacity <= 15时，string类会将底层动态开辟的空间释放掉，使用内部的静态数组

void TestString4()
{
	string s1("hello");
	cout << sizeof(s1) << endl;

	// 将容量增大
	s1.reserve(10);   // 15
	s1.reserve(21);   // 31
	s1.reserve(28);   // 31
	s1.reserve(40);   // 47

	// 将容量缩小
	s1.reserve(32);   // 47
	s1.reserve(20);   // 47
	s1.reserve(13);   // 15
	cout << s1.capacity() << endl;
}

int main()
{
	TestString4();
	return 0;
}
#endif




#if 0
// 元素访问
void TestString5()
{
	string s1("hello");
	cout << s1[0] << endl;
	s1[0] = 'H';
	//cout << s1[8] << endl; // 越界，assert断言

	cout << s1.at(0) << endl;
	s1.at(0) = 'h';
	cout << s1[0] << endl;

	// s1.at(8); // 越界，抛异常
}

int main()
{
	TestString5();
	return 0;
}
#endif




#if 0
// 修改
void TestString6()
{
	string s1("hello");
	cout << s1 << endl;
	s1.push_back(',');
	s1 += "world";
	cout << s1 << endl;

	string s2("!!!");
	s1 += s2;
	s1 += '$';
	cout << s1 << endl;
	cout << s2 << endl;

	s1.append(1, '%');
	cout << s1 << endl;
	// 从s1的第2个位置开始，追加3个字符
	s1.append(s1, 2, 3); //继续追加
	cout << s1 << endl;
}

int main()
{
	TestString6();
	return 0;
}
#endif




#if 0
// 插入
void TestString7()
{
	string s1("hello world !!!");
	s1.insert(s1.find(' '), "@@@");
	cout << s1 << endl;
	s1.insert(s1.rfind(' '), "@@@"); //rfind是从后往前找
	cout << s1 << endl;
	s1.insert(s1.find(' ', 10), "$$$"); //从第10个位置开始找
	cout << s1 << endl;
}

int main()
{
	TestString7();
	return 0;
}
#endif




#if 1
// 给定一个文件 || 文件全路径 获取该文件的后缀
// 给一行单词(该行可能有多个单词，单词和单词之间使用空格隔开，求最后一个单词的长度)
void TestString8()
{
	string s;
	//cin >> s;  hello  world
	getline(cin, s);
	cout << s << endl;
	cout << s.substr(s.rfind(' ') + 1) << endl;
	cout << s.substr( s.rfind(' ') + 1 ).size() << endl; //求最后一个单词的长度
}

int main()
{
	TestString8();
	return 0;
}
#endif
