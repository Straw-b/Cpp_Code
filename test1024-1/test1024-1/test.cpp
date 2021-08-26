#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>


#if 0
// c_str ����C��ʽ�ַ���
int main()
{
	string s("12345"); // �ַ������ַ���
	int value = atoi(s.c_str()); // ת��������
	// s.c_str()����ת��C���Եĸ�ʽ
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

	//getline(cin, s); // ���Խ���һ��
	//cout << s << endl;

	while (getline(cin, s))
	{
		cout << s << endl;
	}
	return 0;
}
#endif



#if 0
#include <algorithm> //�㷨��ͷ�ļ�

int main()
{
	string s("hello");
	reverse(s.begin(), s.end()); //����
	cout << s << endl;

	sort(s.begin(), s.end()); //����
	cout << s << endl;
	return 0;
}
#endif




#if 0
int main()
{
	string s("hello");

	// ������ʽ1--ʹ�÷ǳ�Ƶ��
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	// ������ʽ2
	for (auto e : s)
		cout << e << " ";
	cout << endl;

	// ���õ����������б���
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ���÷�������������б���
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




// ��ת�ַ���
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
			// ��ǰ��������Ч�ַ�
			// 'a'-'z' || 'A'~'Z'
			while (begin < end)
			{
				if (isalpha(S[begin]))
				{
					break;
				}

				++begin;
			}

			// �Ӻ���ǰ��һ����Ч�ַ�
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



//���ַ����е�һ��ֻ����һ�ε��ַ�
class Solution {
public:
	int firstUniqChar(string s)
	{
		// 1.ͳ��ÿ���ַ����ֵĴ���
		size_t count[256] = { 0 };
		for (auto e : s)
		{
			count[e]++;
		}

		// 2.�ҵ���һ������һ�ε��ַ�
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



//��֤һ���ַ����Ƿ��ǻ���
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

		// ��дתСд
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
			// ��ǰ������һ��Сд�ַ����������ַ�
			while (begin < end)
			{
				if (IsVailaChar(s[begin]))
					break;

				begin++;
			}
			// �Ӻ���ǰ��һ��Сд�ַ����������ַ�
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
//�ַ������
class Solution {
public:
	// num1��"0", num2��"0"
	string addStrings(string num1, string num2) 
	{
		if(num1.size() < num2.size())
		{
			num1.swap(num2); //��������
		}

		string strRet(num1.size() + 1, '0'); //������
		char step = 0; //�����λ
		// 999 + 99

		for(int Lindex = num1.size()-1, Rindex = num2.size()-1; Lindex >= 0; --Lindex, --Rindex)
		{
			char ch = num1[Lindex] - '0' + step;

			//�̵����ַ�
			if(Rindex >= 0)
			{
				ch += num2[Rindex] - '0'; //�ַ�0�������
			}

			step = 0;
			if(ch >= 10)
			{
				step = 1;
				ch -= 10;
			}

			strRet[Lindex + 1] += ch; //strRet��num1��1λ
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





// �����string�����⣬����ʾ��
#if 0
class String
{
public:
	String(const char* str = "") // ���캯��
	{
		//if (nullptr == str)
		//{
		//	_str = new char[1]; //new[]��newһ���ַ�
		//	*_str = '\0';
		//}
		//else
		//{
		//	_str = new char[strlen(str) + 1];
		//	strcpy(_str, str);
		//}

		if (nullptr == str) // ��strΪ�չ����һ����Ч�ַ���
			str = "";

		_str = new char[strlen(str) + 1]; //����ռ�
		strcpy(_str, str);
	}

	// ���������ɵ�Ĭ�Ͽ������캯��---ǳ����
	String(const String& s)
		: _str(s._str)
	{}

	// ���������ɵ�Ĭ�ϸ�ֵ���������---ǳ����
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
	s1 = s3; // ��ֵҲ����һ�ֿ���
	return 0;
}
#endif




// ע�⣺ �������漰����Դ(���ڴ�ռ䡢�ļ�ָ���)����ʱ
//        �û�����Ҫ��ʽʵ�ֿ������캯������ֵ��������ء���������---three big

// ���ǳ����
// ��ʽһ�����---��ͳ��
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

	String(const String& s) // ������캯��
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s) // �����ֵ���������
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
