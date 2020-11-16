#pragma once


#include <deque>

namespace bite
{
	template<class T, class Con = std::deque<T>> // µ×²ãÄ¬ÈÏÈÝÆ÷£¬Ë«¶Ë¶ÓÁÐ
	class stack
	{
	public:
		stack()
		{}

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			if (empty()) 
				return;

			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con.back();
		}

		int size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

	private:
		Con _con;
	};
}
