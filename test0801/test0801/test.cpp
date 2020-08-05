#define _CRT_SECURE_NO_WARNINGS 1



//8月1日，11:40开始
class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		_capacity = capacity;
		_size = 0;
	}


	~SeqList()//析构函数
	{
		if (_array)
		{
			free(_array);
			_capacity = 0;
			_size = 0;
		}
	}


	void PushBack(DataType data)
	{

	}


private:
	DataType* _array;

};

void 
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);

}

int main()
{
	
	return 0;
}





class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

private:

};

void TestString()
{
	String s1;
	String s2("hello");
}

class Person
{
private:
	String _name;
	int _age;
};

int main()
{
	TestSring();
	return 0;
}