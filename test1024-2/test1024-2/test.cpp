#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>


// ���ʵ�ַ�ʽ��������/�ִ���
#if 0
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

	String(const String& s)
		: _str(nullptr)
	{
		// ���ù��캯������һ���¶���
		String strTemp(s._str); // ����һ����ʱ����
		swap(_str, strTemp._str); // ����ʱ���󽻸�_str������ָ��
	}

	// �ڴ����ڼ䣬����������ÿ������캯��������һ����ʱ����s
	String& operator=(String s)
	{
		swap(_str, s._str);
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
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif




// ��������¼ͬһ����Դ��ʹ�õĶ���ĸ���
// ��������static��Ա��������ͨ���͵ĳ�Ա����-->������
#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_count = 1;
	}

	String(const String& s)
		: _str(s._str)
	{
		++_count;
		cout << _count << endl;
	}

	~String()
	{
		if (--_count == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
	//size_t _count;
	static size_t _count; // ��̬��Ա����
};

size_t String::_count = 0;

void TestString()
{
	String s1("hello");
	String s2(s1);
	String s3("world");	//_count = 1;
}

int main()
{
	TestString();
	return 0;
}
#endif




#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_pcount = new int(1); // �¿���һ�������ļ���
	}

	String(const String& s)
		: _str(s._str)
		, _pcount(s._pcount) // ��������
	{
		++*_pcount;
		cout << *_pcount << endl;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			// ����0
			if (--*_pcount == 0 && _str)
			{
				delete[] _str;
				delete _pcount;
			}

			_str = s._str;
			_pcount = s._pcount;

			++ *_pcount;
		}
		return *this;
	}

	~String()
	{
		if (--*_pcount == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;

			delete _pcount;
			_pcount = nullptr;
		}
	}

private:
	char* _str;
	int* _pcount;
};

void TestString()
{
	// s1��s2�ڵײ㹲ͬͬһ����Դ--->2
	String s1("hello");
	String s2(s1);

	// s3��s4�ڵײ㹲ͬͬһ����Դ--->2
	String s3("world");
	String s4(s3);

	// �����ֵ�ɹ���s1�ͻ��s3��ͬͬһ����Դ
	s1 = s3;
	s2 = s3;
}

int main()
{
	TestString();
	return 0;
}
#endif




// ǳ���� + ���ü���--->�����ǳ�������´�������ĺ��
// ע�⣺���ַ�ʽ��������ʵ��String��
// ����������ʽʵ��String��--->����String���ж�����д����ʱ��
// ����ö�����������������Դ�ˣ���Ӧ�ø��ö������һ����Դ
// copy on write--->COW:дʱ����

#if 0
// ���߳��£��̲߳���ȫ
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_pcount = new int(1);
	}

	String(const String& s) // ��������
		: _str(s._str)
		, _pcount(s._pcount)
	{
		AddRef();
	}

	String& operator=(const String& s) // ��ֵ���������
	{
		if (this != &s)
		{
			Release();

			_str = s._str;
			_pcount = s._pcount;

			AddRef();
		}

		return *this;
	}

	~String()
	{
		Release();
	}

	char& operator[](size_t index) // �±��������ʵ��
	{
		// �����ǰ������������������Դ��
		// �ͱ������ǰ���󵥶�һ����Դ
		if (GetRef() > 1)
		{
			SubRef();
			char* temp = new char[strlen(_str) + 1];
			strcpy(temp, _str);

			_pcount = new int(1);
			_str = temp;
		}

		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		return _str[index];
	}

private:
	void AddRef()
	{
		++*_pcount;
	}

	int& SubRef()
	{
		--*_pcount;
		return *_pcount;
	}

	int& GetRef()
	{
		return *_pcount;
	}

	void Release()
	{
		if (SubRef() == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;

			delete _pcount;
			_pcount = nullptr;
		}
	}

private:
	char* _str;
	int* _pcount;
};

int main()
{
	String s1("hello");
	String s2(s1);
	String s3(s2);

	// ��Ϊs1��s2��s3���������ڵײ㹲�õ���ͬһ���ڴ�ռ�
	// ���s1��0��λ�õ��ַ��޸�֮��s2��s3Ҳ�ᱻ�޸�
	// ����s1��s2��s3��������ͬ�Ķ���
	// ����������s1����ȥ����һ����Դ
	s1[0] = 'H';
	cout << s1[0] << s2[0] << s3[0] << endl;

	return 0;
}
#endif




// ��֤��vs�е�string���ǰ�������ķ�ʽʵ�ֵ�
#if 0
int main()
{
	string s1(20, 'a');
	string s2(s1);

	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());
	return 0;
}
#endif




// string���ģ��ʵ��
#if 1
#include <assert.h>

namespace bite
{
	class string
	{
	public:
		typedef char* iterator;

	public:
		string(const char* str = "") // string��Ĺ���
		{
			if (nullptr == str)
				str = "";

			_capacity = strlen(str);
			_size = _capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s) // ��������
			: _str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string strTemp(s._str);
			this->swap(strTemp);
		}

		string(size_t n, char ch = char()) // ��n��ֵΪch���ַ�
			: _str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, ch, n);
			_str[n] = '\0';
		}

		string& operator=(string& s) // ��ֵ���������
		{
			swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}

		////////////////////////////////////////////������
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + size();
		}

		///////////////////////////////////////////////����
		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const // �п�
		{
			return 0 == _size;
		}

		void clear() // ����
		{
			_str[0] = '\0';
			_size = 0;
		}

		void resize(size_t newsize, char ch)
		{
			size_t oldsize = _size;
			if (newsize > oldsize)
			{
				if (newsize > _capacity)
				{
					reserve(_capacity * 2);
				}

				// �����λ����Ҫʹ��ch�������
				memset(_str + oldsize, ch, newsize - oldsize);
			}

			_str[newsize] = '\0';
			_size = newsize;
		}

		void reserve(size_t newcapacity) // ����
		{
			if (newcapacity > capacity())
			{
				char* temp = new char[newcapacity + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = newcapacity;
			}
		}

		///////////////////////////////////////////////////Ԫ�ط���
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		//////////////////////////////////////////////////�޸�
		string& operator+=(char ch)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);

			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}

		string& operator+=(const char* str)
		{
			return *this;
		}

		string& operator+=(const string& s)
		{
			*this += s._str;
			return *this;
		}

		void push_back(char ch) // β��
		{
			*this += ch;
		}

		string& append(const string& s) // ׷��
		{
			*this += s;
			return *this;
		}

		//////////////////////////////////////////////////
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		////////////////////////////////////////////////////
		const char* c_str()const
		{
			return _str;
		}

		///////////////////////////////////////////////////����
		size_t find(char ch, size_t pos = 0)
		{
			if (pos >= _size)
				return npos;

			for (size_t index = pos; index < _size; ++index)
			{
				if (_str[index] == ch)
					return index;
			}

			return npos;
		}

		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos == npos)
				pos = _size - 1;

			for (int index = pos; index >= 0; --index)
			{
				if (_str[index] == ch)
					return index;
			}

			return npos;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static size_t npos;

		friend ostream& operator<<(ostream& _cout, const bite::string& s);
		friend istream& operator>>(istream& _cin, bite::string& s);
	};

	size_t string::npos = -1;
}

ostream& bite::operator<<(ostream& _cout, const bite::string& s)
{
	// ����ʹ�����
	//cout << s._str;
	for (size_t i = 0; i < s.size(); ++i)
	{
		_cout << s[i];
	}
	return _cout;
}

//���Զ����string����в���
void TestBitstring()
{
	bite::string s1("hello");
	s1.push_back(' ');
	s1.push_back('a');
	s1 += 'b';

	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	// ֧�ַ�Χfor
	for (auto ch : s1)
		cout << ch << " ";
	cout << endl;
}

int main()
{
	TestBitstring();
	return 0;
}
#endif
