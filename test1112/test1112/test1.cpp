#define _CRT_SECURE_NO_WARNINGS 1


// OJ题目
#if 0
// 用栈实现队列
// 请你仅使用两个栈实现先入先出队列
class MyQueue 
{
public:
	MyQueue() 
	{}

	void push(int x) 
	{
		s1.push(x);
	}

	int pop() 
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		int ret = s2.top();
		s2.pop();
		return ret;
	}

	int peek() // 返回队列开头的元素
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		return s2.top();
	}

	bool empty() 
	{
		return s1.empty() && s2.empty();
	}

private:
	stack<int> s1; // 模拟入栈
	stack<int> s2; // 模拟出栈
};




// 用队列实现栈
class MyStack {
public:

	MyStack() 
	{}

	void push(int x) 
	{
		if (!q1.empty())
			q1.push(x);

		else
			q2.push(x);
	}

	int pop() 
	{
		int ret = 0;
		if (!q1.empty())
		{
			// 将q1中前n-1个元素导入到q2中
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}

			ret = q1.front();
			q1.pop();
		}
		else
		{
			// 将q2中前n-1个元素导入到q1中
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}

			ret = q2.front();
			q2.pop();
		}

		return ret;
	}

	int top() 
	{
		if (!q1.empty())
			return q1.back();

		else
			return q2.back();
	}

	bool empty() 
	{
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1;
	queue<int> q2;
};



// 数组中的第K个最大元素
// 在未排序的数组中找到第 k 个最大的元素

class Solution 
{
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		priority_queue<int> q(nums.begin(), nums.end()); // 小于方式创建，大堆
		// 将优先级队列中前k-1个元素删除掉
		for (int i = 0; i < k - 1; ++i)
			q.pop();

		return q.top();


		//sort(nums.begin(), nums.end(), greater<int>());
		//return nums[k-1];
	}
};


#endif