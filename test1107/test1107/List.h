#pragma once


namespace bite
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& value = T())
		: next(nullptr)
		, prev(nullptr)
		, data(value)
		{}

		ListNode<T>* next;
		ListNode<T>* prev;
		T data;
	};




	// 正向迭代器
	template<class T>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> Self;

	public:
		ListIterator(Node* ptr = nullptr)
			: _ptr(ptr)
		{}

		/////////////////////////////////// 具有指针类似的操作
		T& operator*()
		{
			return _ptr->data;
		}

		T* operator->()
		{
			return &_ptr->data;
		}

		//////////////////////////////////// 迭代器要能够移动
		Self& operator++()
		{
			_ptr = _ptr->next;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_ptr = _ptr->next;
			return temp;
		}

		Self& operator--()
		{
			_ptr = _ptr->prev;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_ptr = _ptr->prev;
			return temp;
		}

		////////////////////////////////// 迭代器要能够进行比较
		bool operator!=(const Self& s)const
		{
			return _ptr != s._ptr;
		}

		bool operator==(const Self& s)const
		{
			return _ptr == s._ptr;
		}

		Node* _ptr;
	};




	// 反向迭代器：直接将正向迭代器进行封装
	//        反向迭代器的++就是正向迭代器的--
	//        反向迭代器的--就是正向迭代器的++
	template<class T, class Iterator>
	struct ListReverseIterator
	{
		typedef ListNode<T> Node;
		typedef ListReverseIterator<T, Iterator> Self;
	
	public:
		ListReverseIterator(Node* pNode = nullptr)
			: _it(pNode)
		{}

		ListReverseIterator(Iterator it) // 拷贝构造
			: _it(it)
		{}

		T& operator*()
		{
			Iterator temp(_it);
			--temp; // 副本向前走一步
			return *temp;
		}

		T* operator->()
		{
			return &(*_it);
		}

		Self& operator++() // 前置++
		{
			--_it;
			return *this;
		}

		Self operator++(int) // 后置++
		{
			_it--;
			return *this;
		}

		Self& operator--() // 前置--
		{
			++_it;
			return *this;
		}

		Self operator--(int) // 后置--
		{
			_it++;
			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

	private:
		Iterator _it;
	};




	template<class T>
	class list
	{
		typedef ListNode<T> Node;

	public:
		typedef ListIterator<T> iterator;
		typedef ListReverseIterator<T,iterator> reverse_iterator; // 反向迭代器

	public:
		//////////////////////////////////////////////构造
		list()
		{
			CreatHead();
		}

		list(int n, const T& data)
		{
			CreatHead();
			for (int i = 0; i < n; ++i)
				push_back(data);
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreatHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(list<T>& L) // 拷贝构造函数
		{
			CreatHead();
			auto it = L.begin();
			while (it != L.end())
			{
				push_back(*it);
				++it;
			}
		}

		~list()
		{
			clear();
			delete head;
			head = nullptr;
		}

		///////////////////////////////////////// iterator
		iterator begin()
		{
			// 构造一个匿名对象返回了
			return iterator(head->next);
		}

		iterator end()
		{
			return iterator(head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		////////////////////////////////////////// capacity
		size_t size() const
		{
			size_t count = 0;
			Node* pCur = head->next;
			while (pCur != head)
			{
				++count;
				pCur = pCur->next;
			}

			return count;
		}

		bool empty()const
		{
			return head->next == head;
		}


		// T()
		// 如果T是内置类型，比如int，int()--->0 ，该默认值都是0
		// 如果T是自定义类型，比如Date，Date()调用无参构造函数或者全缺省的构造函数
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
			else
			{
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
			}
		}

		//////////////////////////////////////// access
		T& front()
		{
			return *begin();
		}

		const T& front()const
		{
			return *begin();
		}

		T& back()
		{
			return head->prev->data;
		}

		const T& back()const
		{
			return head->prev->data;
		}

		//////////////////////////////////////////////modify
		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			erase(--end());
		}


		iterator insert(iterator pos, const T& data) // 插入
		{
			Node* newNode = new Node(data);
			newNode->next = pos._ptr;
			newNode->prev = pos._ptr->prev;
			pos._ptr->prev = newNode;
			newNode->prev->next = newNode;

			return iterator(newNode);
		}


		iterator erase(iterator pos)
		{
			Node* posNode = pos._ptr;
			Node* pRet = posNode->next;
			if (posNode != head)
			{
				posNode->prev->next = posNode->next;
				posNode->next->prev = posNode->prev;
				delete posNode;
			}

			return iterator(pRet);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}

			return end();
		}


		void clear()
		{
			erase(begin(), end());
		}

		void swap(const list<T>& L)
		{
			std::swap(head, L.head);
		}

	private:
		void CreatHead()
		{
			head = new Node;
			head->next = head;
			head->prev = head;
		}

	private:
		ListNode<T>* head;
	};
}




#include <iostream>
using namespace std;

void TestMyList1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);
	cout << L2.size() << endl;
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L3(array, array + 5);
	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;

	bite::list<int> L4(L3);
}




// size()
// resize()
void TestMyList2()
{
	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L{ array, array + sizeof(array) / sizeof(array[0]) };
	cout << L.size() << endl;

	L.resize(10, 6);
	cout << L.size() << endl;
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.resize(3);
	cout << L.size() << endl;
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}




void TestMyList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L{ array, array + 5 };

	auto it = L.rbegin();
	while (it != L.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << L.front() << endl;
	cout << L.back() << endl;

	L.clear();
	if (L.empty())
		cout << L.size() << endl;
}




struct A
{
	int a;
	int b;
	int c;
};

void TestMyList4()
{
	bite::list<A> L;
	A a{ 1, 2, 3 }; // 创建一个A的对象
	L.push_back(a);

	A* pa = &a;
	pa->a = 10;

	auto it = L.begin(); // A的副本
	it->a = 100;
	it.operator->()->a = 200;  // it->->a;错误
	it.operator++();  // ++it;
}