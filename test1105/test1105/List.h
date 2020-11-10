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




	template<class T>
	class list
	{
		typedef ListNode<T> Node;

	public:
		typedef ListIterator<T> iterator;

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

		list(list<T>& L)
		{
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

		////////////////////////////////////////// capacity
		size_t size()
		{
			size_t count = 0;
			auto it = begin();
			while (it != end())
			{
				++count;
				++it;
			}
			return count;
		}

		bool empty()const
		{
			return head->next == head;
		}

		void resize(size_t newsize, const T& data)
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
			if (pRet != head)
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

	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L3(array, array + 5);

	bite::list<int> L4(L3);
}