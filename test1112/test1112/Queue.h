#pragma once


#include <list>

namespace bite
{
	template<class T>
	class queue
	{
	public:
		queue()
		{}

		void push(const T& x)
		{
			q.push_back(x);
		}

		void pop()
		{
			q.pop_front();
		}

		T& front()
		{
			return q.front();
		}

		const T& front()const
		{
			return q.front();
		}

		T& back()
		{
			return q.back();
		}

		const T& back()const
		{
			return q.back();
		}

		size_t size()const
		{
			return q.size();
		}

		bool empty()const
		{
			return q.empty();
		}

	private:
		std::list<T> q;
	};
}