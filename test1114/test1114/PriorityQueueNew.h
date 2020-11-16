#pragma once


#include <vector>

namespace bite
{
	template<class T, class Con = vector<T>, class CMP = less<T>>
	class priority_queue
	{
	public:
		priority_queue(CMP cmp = CMP())
			:_cmp(cmp)
		{}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last, CMP cmp = CMP())
			: _con(first, last)
			, _cmp(cmp)
		{
			// _con中的元素不是堆，需要将其调成堆
			int root = ((_con.size() - 2) >> 1);
			while (root >= 0)
			{
				_AdjustDown(root);
				root--;
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			_AdjustUp();
		}

		void pop()
		{
			if (empty())
				return;

			swap(_con.front(), _con.back());
			_con.pop_back();
			_AdjustDown(0);
		}

		const T& top()const
		{
			return _con.front();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

	private:
		// 创建小堆
		void _AdjustDown(size_t parent)
		{
			size_t child = parent * 2 + 1;
			size_t size = _con.size();

			while (child < size)
			{
				if (child + 1< size && _cmp(_con[child], _con[child + 1]))
					child += 1;

				if (_cmp(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void _AdjustUp()
		{
			size_t child = _con.size() - 1;
			size_t parent = ((child - 1) >> 1);

			while (child)
			{
				if (_cmp(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
				{
					break;
				}
			}
		}

	private:
		Con _con;
		CMP _cmp;
	};
}