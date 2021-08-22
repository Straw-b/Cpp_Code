#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// ��ֵ�ķ�ʽ���������Ͷ����ڴ����ڼ����������ÿ������캯������һ����ʱ�Ķ���
// ȱ�ݣ����������Ч�ʵ�
void TestDate1(Date dd)
{}

// һ������º���ʹ����ֵ�ķ�ʽ���������͵Ĳ�����һ�㶼��ʹ�����õķ�ʽ��Ϊ��������
// �ŵ㣺����Ч�ʷǳ���(����һ�ο����������)
// ȱ�㣺����޸��βξͻ��޸��ⲿʵ��
void TestDate2(Date& dd)
{}

// ��const
void TestDate3(const Date& dd)
{}

Date TestDate4()
{
	Date d;  // ջ�ϴ����Ķ���
	return d;
}

// �ڷ���ֵ�ڼ䣬���ù��캯��������һ������������Ϊ����������û�����֣�Ҳ�����õ��ö���ĵ�ַ��
// ���û�а취�Ըö�������޸Ĳ�������˱������ͽ��������󵱳�һ����ʱ�����������з�����
Date TestDate5()
{
	// ���캯������ֱ�ӵ��ã��Ǳ������Զ����е���----��ô������ֱ�ӵ��ù��캯����
	return Date(2020, 8, 8);   // Date(2020,8,8): ������һ��û�����ֵĶ���---��������
}

int main()
{
	Date d(2020, 8, 8);
	//TestDate1(d);
	//TestDate3(d);

	//TestDate4();
	TestDate5();
	return 0;
}
#endif




#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year > 0 &&
			(month >= 1 && month <= 12) &&
			(day > 0 && day <= GetDaysOfMonth(year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// ִ�е���ǰ��++�Ĳ���
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// ����++
	// ע�⣺temp�Ǻ���ջ�ϵĶ��󣬵������˳�ʱ��temp��Ҫ��������
	// ��˺���++�ĺ�������ֵ����ʹ�����õķ�ʽ���з����ˣ�ֻ�ܰ���ֵ�ķ�ʽ���з���
	// ע�⣺�﷨Ϊ�����ֺ���++��ǰ��++��������ص����������ں���++�ĺ��������б��ж�������һ��int���͵Ĳ���
	//      ǰ��++�ͺ���++�Ϳ����γɺ��������ˣ����Ǹ�int���Ͳ����ں������в�����ʹ�ã���˿��Բ��ø�����
	//      ��Ȼ����++��ʵ��ʱ����һ��int���͵Ĳ����������û��ڵ���ʱ���ô��ݸ�intʵ��
	Date operator++(int) // ��������
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	// ǰ��--
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	// ����--
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}

	// ��=�������أ���ֵ���������
	// ����˵����Date d--->ȱ�� �ڴ����ڼ�Ҫ����һ����ʱ��������this���и�ֵ��Ч��̫����
	//          Date& d---> �ŵ㣺�ڴ����ڼ��ٴ���һ����ʱ����Ч�ʸ���  
	//                      ȱ�ݣ��ڸ�ֵ�ڼ䲻С�Ľ�d�޸��ˣ��ⲿʵ��Ҳ���޸���
	//          const Date& d
	// ����Ҫ�з���ֵ��Ŀ��Ϊ��֧��������ֵ
	Date& operator=(const Date& d) // ���뷵��һ��ֵ
	{
		// �����Լ����Լ���ֵ---������֣�d��this����ͬһ�������أ�
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

private:
	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
		{
			return true;
		}
		return false;
	}

	size_t GetDaysOfMonth(size_t year, int month)
	{
		int daysOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
		if (month == 2 && IsLeapYear(year))
			daysOfMonth[2] += 1;

		return daysOfMonth[month];
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 0;
	b = a++; // ��������

	int c = 10;
	a = b = c;

	Date d0(2020, 8, 100); // ��֤�Ϸ���
	d0.PrintDate();

	Date d1(2020, 8, 8);
	Date d2;
	d1.PrintDate();
	d2.PrintDate();
	cout << endl;
	///////////////////////////////////////////////////////
    // ǰ��++
	d2 = ++d1;
	d2 = d1.operator++(); 
	d1.PrintDate();
	d2.PrintDate();

    // ����++
	d2 = d1++;
	d2 = d1.operator++(0); 
	d1.PrintDate();
	d2.PrintDate();
	cout << endl;
	///////////////////////////////////////////////////////

	d1 = d2;

	Date d3;
	d3 = d2 = d1;
	d3.operator=(d2.operator=(d1));
	d1.PrintDate();
	d2.PrintDate();
	d3.PrintDate();

	d1 = d1;// �Լ����Լ����и�ֵ
	// d5��d1�ı�����˵��d5��d1��ͬһ������
	Date& d5 = d1;
	d5 = d1;// �����Լ����Լ����и�ֵ

	return 0;
}
#endif




// const���α�����
// ��C�����У���const���ε���һ�����ܱ��޸ĵı���
// ���ԣ� const int a = 10;   int array[a];
//
// ��C++�У���const���ε��Ѿ���һ�����������Ҿ��к��滻������
// void TestConst()
// {
// 	   const int a = 10;
// 	   int* pa = (int*)&a;
//
//	   *pa = 100;
//	   cout << a << endl;     // 10   ����a��ֵ�Ѿ���100  ԭ���ڱ���׶Σ��������Ѿ���a��10�滻��
//	   cout << *pa << endl;   // 100
// }
// const���εĳ������滻�����ڱ���׶Σ�����뵽�������ͼ�⣬����İ�ȫ�Ը���
// ���飺��C++��ʹ��const���εĳ�������곣��


//��C++�У�constҲ����������ĳ�Ա
//1. const������ĳ�Ա�����������ó�Ա�������ܱ��޸ĵ�
//2. const������ĳ�Ա����---> ��Ϊconst���͵ĳ�Ա����


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// ��const���εĳ�Ա������Ϊconst���͵ĳ�Ա����
	// const��Ա�����в����޸����"��Ա����"
	// const�������ε��ǳ�Ա���������ص�thisָ��
	// ��ʾ��thisָ��ָ��Ŀռ��е����ݲ����޸ģ�����thisָ��ǰ�������޸�
	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//this->_day++; // �����޸�
		cout << typeid(this).name() << endl; // ��ӡclass Date const *
	}

	// const�ڷ���ֵ����֮ǰ�����εĸú����ķ���ֵ����
	// ��ͨ��Ա�����У������޸�thisָ��ĵ�ǰ�����������Ϣ
	const Date& GetDate()
	{
		cout << typeid(this).name() << endl; // ��ӡclass Date *
		_day++;
		return *this;
	}

	// ���飺����ڳ�Ա�����в���Ҫ�޸ĳ�Ա����ʱ����Ա������ø���const��Ա��������Ϊ����İ�ȫ�Ը���
	//      ���磺getϵ�к���
	//      ����ڳ�Ա��������Ҫ�޸ĵ�ǰ����ĳ�Ա����һ������ʹ��const��Ա�������������ʧ��
	//      ���磺setϵ�к���

	// C++�����Ի���
	// �����ϣ���const���εĳ�Ա�����в����޸��κε�"��Ա����"��
	// ������Щ����£�������Ҫ��const��Ա�������޸ĸ����Ա����
	void TestFunc()const
	{
		_day++;
		// _month++;
		// _year++;
	}

	// this�����ͣ�Date* const this
	Date* operator&() // ���ص�ַ
	{
		cout << "��ַ:" << this << endl;
		return this;
	}

	// const���γ�Ա����������������thisָ�룬this�����ͣ�const Date* const this
	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	mutable int _day;
	//mutable: ���ʺ����ʾ�ɱ�ģ����γ�Ա����ʱ�������ó�Ա����������const��Ա�����б��޸�
};

int main()
{
	Date d1(2020, 8, 8);
	d1.PrintDate();
	d1.GetDate();
	cout << "d1:" << &d1 << endl;

	const Date d2(d1);
	cout << "d2:" << &d2 << endl;
	return 0;
}
#endif




#if 1
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date* operator&()
	{
		cout << this << endl;
		return this;
	}

	const Date* operator&()const
	{
		return this;
	}

	void SetDay(int day)
	{
		_day = day;
	}

	int GetDay()const
	{
		return _day;
	}

	// const���͵ĳ�Ա����
	void TestFuncWithConst()const
	{
		// SetDay(10);
		// const��Ա�����в��ܵ�����ͨ���͵ĳ�Ա����
		// ��Ϊ��const��Ա����thisָ��������� const Date* const
		// ������this����ĳ�Ա�ǲ����޸ĵ�
		// �����this����SetDay����SetDay�����ڲ����ԶԵ�ǰ��������޸�
		// ���´��벻��ȫ
		PrintDate();
	}

	// ��ͨ���͵ĳ�Ա����
	// thisָ������ͣ�Date* const�������ö����еĳ�Ա�����޸�Ҳ���Բ��޸�
	void TestFuncWithoutConst()
	{
		SetDay(10);
		// SetDay��thisָ������ͣ�Date* const�������ö����еĳ�Ա�����޸�Ҳ���Բ��޸�
		// thisָ���������ȫƥ�䣬û���κ�����

		PrintDate();
		// ���ۣ���ͨ��Ա�����п��Ե���const��Ա����
		// ��Ϊ����ͨ��Ա����thisָ��Ķ����ǿɶ�д���ȿ����޸�Ҳ���Բ��޸�
		//       ��const��Ա�����еĶ���ĳ�Ա�ǲ����޸ĵ�
		// ����ͨ��Ա�����е���const���ͳ�Ա���������൱�ڽ�һ���ɶ�д�Ķ��󽻸�һ��ֻ���ĺ��������д�����
		// ���뱾�����ǰ�ȫ��
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	const Date d1(2020, 8, 8);
	d1.PrintDate();
	// d1.SetDay(9);
	// d1��const���͵Ķ��󣬱�ʾ�ö���ĳ�Ա�ǲ������޸ĵ�
	// ����const���Ͷ���������Ե�����ͨ���͵ĳ�Ա����������ͨ���͵ĳ�Ա�����п��ܻὫconst���Ͷ���ĳ�Ա�޸ĵ�
	// ���벻��ȫ
	// ��ˣ�const���͵Ķ���ֻ�ܵ���const���͵ĳ�Ա���������ܵ�����ͨ���͵ĳ�Ա����


	Date d2(2020, 8, 8);
	d2.SetDay(9);
	// d2����ͨ���͵Ķ��󣬸ö����еĳ�Ա�����޸�Ҳ���Բ��޸�
	// ��const���͵Ķ��������ͨ��Ա������const���͵ĳ�Ա���������Խ��е���
	cout << d2.GetDay() << endl;

	return 0;
}
#endif
