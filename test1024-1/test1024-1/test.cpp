#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>


#if 0
// c_str 返回C格式字符串
int main()
{
	string s("12345"); // 字符类型字符串
	int value = atoi(s.c_str()); // 转整形数字
	// s.c_str()，先转成C语言的格式
	cout << value << endl;

	string s1("hello");
	char* p = (char*)s1.c_str();
	*p = 'H';
	cout << p << endl;

	cout << sizeof(string) << endl;
	return 0;
}
#endif




#if 0
int main()
{
	string s1("hello");
	string s2("world");

	if (s1 < s2)
	{
		cout << "s1 < s2" << endl;
	}
	else
	{
		cout << "s1 >= s2";
	}

	return 0;
}
#endif




#if 0
int main()
{
	string s;
	//cin >> s;
	//cout << s << endl;

	//getline(cin, s); // 可以接收一行
	//cout << s << endl;

	while (getline(cin, s))
	{
		cout << s << endl;
	}
	return 0;
}
#endif



#if 0
#include <algorithm> //算法的头文件

int main()
{
	string s("hello");
	reverse(s.begin(), s.end()); //逆置
	cout << s << endl;

	sort(s.begin(), s.end()); //排序
	cout << s << endl;
	return 0;
}
#endif




#if 0
int main()
{
	string s("hello");

	// 遍历方式1--使用非常频繁
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	// 遍历方式2
	for (auto e : s)
		cout << e << " ";
	cout << endl;

	// 采用迭代器来进行遍历
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 采用反向迭代器来进行遍历
	//string::reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;
}
#endif




// 反转字符串
#if 0
class Solution {
public:
	string reverseOnlyLetters(string S)
	{
		if (S.empty())
			return S;

		size_t begin = 0, end = S.size() - 1;

		while (begin < end)
		{
			// 从前往后找有效字符
			// 'a'-'z' || 'A'~'Z'
			while (begin < end)
			{
				if (isalpha(S[begin]))
				{
					break;
				}

				++begin;
			}

			// 从后往前找一个有效字符
			while (begin < end)
			{
				if (isalpha(S[end]))
				{
					break;
				}

				--end;
			}

			if (begin != end)
			{
				swap(S[begin], S[end]);
				begin++;
				end--;
			}
		}
		return S;
	}
};



//找字符串中第一个只出现一次的字符
class Solution {
public:
	int firstUniqChar(string s)
	{
		// 1.统计每个字符出现的次数
		size_t count[256] = { 0 };
		for (auto e : s)
		{
			count[e]++;
		}

		// 2.找到第一个出现一次的字符
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[s[i]] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};



//验证一个字符串是否是回文
class Solution {
public:
	bool IsVailaChar(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') ||
			(ch >= '0' && ch <= '9'))
		{
			return true;
		}
		return false;
	}

	bool isPalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}

		// 大写转小写
		for (auto& e : s)
		{
			if (e >= 'A' && e <= 'Z')
			{
				e += 32;
			}
		}

		size_t begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			// 从前往后找一个小写字符或者数字字符
			while (begin < end)
			{
				if (IsVailaChar(s[begin]))
					break;

				begin++;
			}
			// 从后往前找一个小写字符或者数字字符
			while (begin < end)
			{
				if (IsVailaChar(s[end]))
					break;

				end--;
			}

			if (begin != end)
			{
				if (s[begin] != s[end])
					return false;

				begin++;
				end--;
			}
		}
		return true;
	}
};
#endif




#if 0
//字符串相加
class Solution {
public:
	// num1："0", num2："0"
	string addStrings(string num1, string num2) 
	{
		if(num1.size() < num2.size())
		{
			num1.swap(num2); //交换数组
		}

		string strRet(num1.size() + 1, '0'); //保存结果
		char step = 0; //保存进位
		// 999 + 99

		for(int Lindex = num1.size()-1, Rindex = num2.size()-1; Lindex >= 0; --Lindex, --Rindex)
		{
			char ch = num1[Lindex] - '0' + step;

			//短的有字符
			if(Rindex >= 0)
			{
				ch += num2[Rindex] - '0'; //字符0变成数字
			}

			step = 0;
			if(ch >= 10)
			{
				step = 1;
				ch -= 10;
			}

			strRet[Lindex + 1] += ch; //strRet比num1多1位
		}

		if(step == 1)
		{
			strRet[0] += 1;
		}
		else
		{
			strRet.erase(strRet.begin());
		}
		return strRet;
	}
};

int main()
{
	string s1("8");
	string s2("19");
	Solution s;
	string strRet = s.addStrings(s1, s2);

	cout << strRet << endl;
	return 0;
}
#endif





// 经典的string类问题，错误示例
#if 0
class String
{
public:
	String(const char* str = "") // 构造函数
	{
		//if (nullptr == str)
		//{
		//	_str = new char[1]; //new[]，new一个字符
		//	*_str = '\0';
		//}
		//else
		//{
		//	_str = new char[strlen(str) + 1];
		//	strcpy(_str, str);
		//}

		if (nullptr == str) // 将str为空构造成一个有效字符串
			str = "";

		_str = new char[strlen(str) + 1]; //分配空间
		strcpy(_str, str);
	}

	// 编译器生成的默认拷贝构造函数---浅拷贝
	String(const String& s)
		: _str(s._str)
	{}

	// 编译器生成的默认赋值运算符重载---浅拷贝
	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	//String s2(s1);
	String s3("hello");
	s1 = s3; // 赋值也算是一种拷贝
	return 0;
}
#endif




// 注意： 当类中涉及到资源(堆内存空间、文件指针等)管理时
//        用户必须要显式实现拷贝构造函数、赋值运算符重载、析构函数---three big

// 解决浅拷贝
// 方式一：深拷贝---传统版
#if 1
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s) // 深拷贝构造函数
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s) // 深拷贝赋值运算符重载
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2(s1);

	String s3("world");
	s1 = s3;
}

int main()
{
	TestString();
	return 0;
}
#endif
