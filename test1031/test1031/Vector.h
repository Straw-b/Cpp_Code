#pragma once

#include <assert.h>

namespace bite // 命名空间
{
	template<class T> // 模板类型
	class vector
	{
	public:
		typedef T* iterator;

	public:
		vector() // 构造
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}

		vector(int n, const T& data = T())
			: start(new T[n])
			, finish(start + n)
			, endofstorage(finish)
		{
			for (int i = 0; i < n; ++i)
			{
				start[i] = data;
			}
		}

		template<class Iterator> // 重新声明迭代器

		vector(Iterator first, Iterator last)
		{
			// 确定该区间中有多少个元素
			Iterator it = first;
			size_t count = 0;
			while (it != last)
			{
				count++; // 内置类型
				++it; // 自定义类型，前置++返回引用，效率高
			}

			// 给当前对象开辟空间，并初始化成员变量
			start = new T[count];
			finish = start;
			endofstorage = start + count;

			// 赋值
			while (first != last)
			{
				*finish++ = *first++;
			}
		}

		vector(const vector<T>& v) // 拷贝构造
		{
			size_t vsize = v.size();
			start = new T[vsize];
			finish = endofstorage = start + vsize;
			for (size_t i = 0; i < vsize; ++i)
				start[i] = v[i]; // 赋值
		}

		vector<T>& operator=(vector<T> v) // 赋值运算符重载
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = endofstorage = nullptr;
			}
		}

		///////////////////////////////////
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		//////////////////////////////////
		// capacity
		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return endofstorage - start;
		}

		bool empty()const
		{
			return start == finish;
		}


		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				finish = start + newsize;
			}
			else
			{
				if (newsize > capacity())
					reserve(newsize);

				for (size_t i = oldsize; i < newsize; ++i)
					start[i] = data;

				finish = start + newsize;
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			size_t oldsize = size();
			if (newcapacity > oldcapacity)
			{
				// 开辟新空间
				T* temp = new T[newcapacity];

				// 拷贝元素
				//memcpy(temp, start, oldsize*sizeof(T));
				for (size_t i = 0; i < oldsize; ++i)
					temp[i] = start[i];

				// 释放旧空间
				delete[] start;

				start = temp;
				finish = start + oldsize;
				endofstorage = start + newcapacity;
			}
		}

		/////////////////////////////////////
		// access
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}
		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return start[0];
		}
		const T& front()const
		{
			return start[0];
		}

		T& back()
		{
			return start[size() - 1];
		}
		const T& back()const
		{
			return start[size() - 1];
		}

		//////////////////////////////////////////////
		// modify
		void push_back(const T& data)
		{
			if (size() == capacity())
				reserve(capacity() * 2 + 3);

			*finish++ = data;
		}

		void pop_back()
		{
			if (empty())
				return;

			--finish;
		}

		iterator insert(iterator pos, const T& data)
		{
			assert(pos <= end());
			if (size() == capacity())
				reserve(capacity() * 2);

			auto it = end();
			while (it > pos)
			{
				*it = *(it - 1); // 将前一个位置搬到后一个位置
				--it;
			}

			*pos = data;
			++finish;

			return pos;
		}

		iterator erase(iterator pos) // 删除
		{
			assert(pos < end());
			if (size() == 1)
			{
				pop_back();
				return end();
			}

			auto it = pos;
			while (it < end())
			{
				*it = *(it + 1);
				++it;
			}

			--finish;
			return pos;
		}

		void clear()
		{
			finish = start;
		}

		void swap(const vector<T>& v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(endofstorage, v.endofstorage);
		}

	private:
		iterator start;
		iterator finish;
		iterator endofstorage;
	};
}





#include <iostream>
using namespace std;

#include <string>

void TestMyVector1()
{
	bite::vector<int> v1;

	bite::vector<int> v2(10, 5);
	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v3(array, array + 5);	
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	std::string s("hello");
	bite::vector<char> vc(s.begin(), s.end());
	for (size_t i = 0; i < vc.size(); ++i)
		cout << vc[i] << " ";
	cout << endl;

	bite::vector<int> v4(v3);
	for (auto e : v4)
		cout << e << " ";
	cout << endl;
}

void TestMyVector2()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.begin(), 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.begin());
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void TestMyVector3()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	// capacity:9  size: 4
	v.resize(8, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(15, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(20, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(12);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}
