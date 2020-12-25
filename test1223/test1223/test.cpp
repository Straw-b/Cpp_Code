#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#if 0
#include <map>
#include <string>

int main()
{
	map<string, string> m1;

	m1.insert(pair<string, string>("orange", "橘子"));
	m1.insert(pair<string, string>("apple", "苹果"));
	m1.insert(pair<string, string>("banana", "香蕉"));
	m1.insert(make_pair("peach", "桃子"));
	m1.insert(make_pair("watermelon", "西瓜"));

	// 遍历：范围for
	for (auto& e : m1)
	{
		cout << "<" << e.first << "," << e.second << ">" << endl;
	}

	cout << "----------------------------------" << endl;

	// 通过key获取与key对应的value
	cout << m1["peach"] << endl;
	cout << m1["pear"] << endl;

	m1["pear"] = "梨";
	cout << m1["pear"] << endl;

	auto ret = m1.insert(make_pair("orange", "橙子"));

	// 迭代器
	// std::map<std::string, std::string>::iterator it = m1.begin();
	cout << m1.size() << endl;
	auto it = m1.begin();
	while (it != m1.end())
	{
		cout << "<" << it->first << "," << (*it).second << ">" << endl;
		++it;
	}

	// C++11
	map<string, string> m2{ { "orange", "橘子" }, { "apple", "苹果" }, { "banana", "香蕉" } };
	auto rit = m2.rbegin();
	while (rit != m2.rend())
	{
		cout << "<" << rit->first << "," << (*rit).second << ">" << endl;
		++rit;
	}

	///////////////////////////////////////////////////
	m1.erase("orange");   // 删除指定的key

	auto pos = m1.find("orange");
	if (pos != m1.end())
	{
		m1.erase(pos);
	}

	m1.erase(m1.begin(), m1.end());   // m1.clear()
	return 0;
}
#endif




#if 0
#include <map>
#include <string>
#include <queue>

#include <set>


class Compare
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

int main()
{
	// 在以下水果中挑出员工最喜欢吃的三种水果---CVTE笔试题
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };

	// 1. 统计每个水果出现的次数
	// <水果，次数>
	map<string, size_t> m;
	for (auto& e : fruits)
		m[e]++;  // <e, 0>向map中插入--->如果e不存在返回0  如果e存在返回值e对应的次数

	// 2. 找出员工最喜欢吃的K种水果----TOP-K---priority_queue
	// 使用map中的元素构造一个大堆---->按照键值对中的次数进行比较
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());

#if 0
	// 取到员工最喜欢吃的三种水果
	vector<string> favourite;
	for (size_t i = 0; i < 3; ++i)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}

	// 水果--->按照字典方式排序
	sort(favourite.begin(), favourite.end());
#endif

	set<string> s;
	for (size_t i = 0; i < 3; ++i)
	{
		s.insert(q.top().first);
		q.pop();
	}
	return 0;
}
#endif




#if 0
#include <set>
#include <string>

// 去重 + 排序
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	set<string> s(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));

	s.insert("grape");

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif




#if 0
#include <map>

int main()
{
	multimap<string, string> m;
	m.insert(pair<string, string>("orange", "橘子"));
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(pair<string, string>("banana", "香蕉"));
	m.insert(make_pair("peach", "桃子"));
	m.insert(make_pair("watermelon", "西瓜"));
	m.insert(make_pair("orange", "橙子"));

	m.erase("orange");
	return 0;
}
#endif




#if 1
#include <set>
#include <string>

#include <functional>

int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	multiset<string, greater<string>> s;

	for (auto& e : fruits)
		cout << e << " ";
	cout << endl;

	s.insert(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));

	cout << s.count("apple") << endl;

	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

