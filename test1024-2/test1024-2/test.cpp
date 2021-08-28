#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>


// 深拷贝实现方式二：简洁版/现代版
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
		// 调用构造函数创建一个新对象
		String strTemp(s._str); // 构造一个临时对象
		swap(_str, strTemp._str); // 将临时对象交给_str，交换指针
	}

	// 在传参期间，编译器会调用拷贝构造函数，构造一个临时对象s
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




// 计数：记录同一份资源被使用的对象的个数
// 计数给成static成员变量、普通类型的成员变量-->都不行
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
	static size_t _count; // 静态成员变量
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
		_pcount = new int(1); // 新开辟一个独立的计数
	}

	String(const String& s)
		: _str(s._str)
		, _pcount(s._pcount) // 共享起来
	{
		++*_pcount;
		cout << *_pcount << endl;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			// 减成0
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
	// s1和s2在底层共同同一份资源--->2
	String s1("hello");
	String s2(s1);

	// s3和s4在底层共同同一份资源--->2
	String s3("world");
	String s4(s3);

	// 如果赋值成功，s1就会和s3共同同一份资源
	s1 = s3;
	s2 = s3;
}

int main()
{
	TestString();
	return 0;
}
#endif




// 浅拷贝 + 引用计数--->来解决浅拷贝导致代码崩溃的后果
// 注意：该种方式不能用来实现String类
// 借助上述方式实现String类--->当向String类中对象中写内容时，
// 如果该对象与其他对象共享资源了，就应该给该对象独立一份资源
// copy on write--->COW:写时拷贝

#if 0
// 多线程下：线程不安全
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

	String(const String& s) // 拷贝构造
		: _str(s._str)
		, _pcount(s._pcount)
	{
		AddRef();
	}

	String& operator=(const String& s) // 赋值运算符重载
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

	char& operator[](size_t index) // 下标运算符的实现
	{
		// 如果当前对象与其他对象共享资源了
		// 就必须给当前对象单独一份资源
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

	// 因为s1、s2、s3三个对象在底层共用的是同一块内存空间
	// 因此s1将0号位置的字符修改之后，s2、s3也会被修改
	// 但是s1、s2、s3是三个不同的对象
	// 问题解决：让s1单独去管理一份资源
	s1[0] = 'H';
	cout << s1[0] << s2[0] << s3[0] << endl;

	return 0;
}
#endif




// 验证：vs中的string类是按照深拷贝的方式实现的
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




// string类的模拟实现
#if 1
#include <assert.h>

namespace bite
{
	class string
	{
	public:
		typedef char* iterator;

	public:
		string(const char* str = "") // string类的构造
		{
			if (nullptr == str)
				str = "";

			_capacity = strlen(str);
			_size = _capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s) // 拷贝构造
			: _str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string strTemp(s._str);
			this->swap(strTemp);
		}

		string(size_t n, char ch = char()) // 放n个值为ch的字符
			: _str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, ch, n);
			_str[n] = '\0';
		}

		string& operator=(string& s) // 赋值运算符重载
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

		////////////////////////////////////////////迭代器
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + size();
		}

		///////////////////////////////////////////////容量
		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const // 判空
		{
			return 0 == _size;
		}

		void clear() // 清理
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

				// 多出的位置需要使用ch进行填充
				memset(_str + oldsize, ch, newsize - oldsize);
			}

			_str[newsize] = '\0';
			_size = newsize;
		}

		void reserve(size_t newcapacity) // 扩容
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

		///////////////////////////////////////////////////元素访问
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

		//////////////////////////////////////////////////修改
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

		void push_back(char ch) // 尾插
		{
			*this += ch;
		}

		string& append(const string& s) // 追加
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

		///////////////////////////////////////////////////查找
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
	// 不能使用这个
	//cout << s._str;
	for (size_t i = 0; i < s.size(); ++i)
	{
		_cout << s[i];
	}
	return _cout;
}

//对自定义的string类进行测试
void TestBitstring()
{
	bite::string s1("hello");
	s1.push_back(' ');
	s1.push_back('a');
	s1 += 'b';

	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	// 支持范围for
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
