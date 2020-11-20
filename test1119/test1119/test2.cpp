#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
#include <string>

// 基类/父类
class Person
{
public:
	void Eat()
	{
		cout << "吃饭" << endl;
	}

	void Sleep()
	{
		cout << "睡觉" << endl;
	}

private:
	string _name;
	string _gender;
	int _age;
};

// 派生类/子类
class Student : public Person
{
public:
	void Study()
	{
		cout << "学习" << endl;
	}

private:
	int _stuid;
};

int main()
{
	Student s;
	s.Eat();
	s.Sleep();
	s.Study();

	cout << sizeof(Student) << endl; // 28+28+4+4=64
	return 0;
}
#endif





#if 0
#include <string>

class Person
{
public:
	void Eat()
	{
		cout << "吃饭" << endl;
	}

	void Sleep()
	{
		cout << "睡觉" << endl;
	}

private:
	// 既不能再类外直接使用
	// 也不允许再子类中直接使用
	string _name;
	string _gender;

protected:
	// 不能再类外直接使用
	// 但是可以再子类中使用
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		// 基类中protected成员在子类中可以直接使用，权限：protected
		_age = 18;

		// 基类中private修饰的成员在子类中不可见(不能直接使用)
		//_name = "lily";
		cout << "学习" << endl;
	}

private:
	int _stuid;
};

class A : public Student
{
public:
	void Test()
	{
		_age = 10;
	}
};

int main()
{
	Student s;

	// 基类public成员在子类中的访问权限也是public
	s.Eat();
	s.Sleep();

	//s._age = 10;
	cout << sizeof(Student) << endl;
	return 0;
}
#endif





#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : protected Base
{
public:
	void test()
	{
		// 基类中public修饰成员在子类中的权限变成protected
		_pub = 10;

		// 基类中protected修饰的成员在子类中的权限也是protected
		_pro = 10;

		// 基类中privage修饰的成员在子类中不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}
#endif





#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : private Base
{
public:
	void test()
	{
		// 基类中public修饰成员在子类中的权限变成private
		_pub = 10;

		// 基类中protected修饰的成员在子类中的权限也是private
		_pro = 10;

		// 基类中privage修饰的成员在子类中不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		//_pub = 20;
		//_pro = 30;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}
#endif





#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

// class默认继承方式：private
// struct默认继承方式：struct
struct Derive : Base
{
public:
	void test()
	{
		_pub = 10;
		_pro = 20;
		//_pri = 30;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	d._pub = 1;
	return 0;
}
#endif





// 赋值兼容规则---前提：必须是public继承方式
// 1. 子类对象可以给基类对象赋值，反过来不行
// 2. 基类值指针或者引用可以直接指向子类的对象
// 3. 子类的指针不能直接指向基类的对象

//如果是public的继承方式：
//子类和基类的关系：is-a(是一个) 可以将子类对象看成是一个基类对象
//对象模型：对象中成员在内存中的分布形式
#if 0
class Person
{
public:
	void Eat()
	{
		cout << "吃饭" << endl;
	}

	void Sleep()
	{
		cout << "睡觉" << endl;
	}

	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "学习" << endl;
	}

	int _stuid;
};

int main()
{
	// 1. 子类对象可以给基类对象赋值，反过来不行
	Person p;
	Student s;
	p = s;
	// s = p;

	// 2. 基类值指针或者引用可以直接指向子类的对象
	Person* pp = &s;
	Person& rp = s;

	// 3. 子类的指针不能直接指向基类的对象,但是强转可以---不安全
	// Student* ps = &p;
	Student* ps = (Student*)&p;
	ps->_name = "lily";
	ps->_gender = "男";
	ps->_age = 18;
	//ps->_stuid = 100; // 崩溃，越界访问
	return 0;
}
#endif





#if 1
class Base
{
public:
	void Set(int b) //都继承下来
	{
		_b = 10;
	}

private:
	int _b;
};

class Derive : public Base
{
public:
	void Set() //都继承下来
	{
		Base::Set(10);
		__super::Set(10);
		_d = 100;
	}
private:
	int _d;
};

int main()
{
	Derive d;
	d.Base::Set(10);
	return 0;
}
#endif