#include<iostream>
using namespace std;
#include<vector>
#include<list>


int LastRemaining_Solution(unsigned int n, unsigned int m)
{	
	if (m < 1 || n < 1 ) return -1;
	
	int i = 0;
	list<int> nums;
	for (int i = 0; i < n; ++i)
		nums.push_back(i);

	list<int>::iterator cur = nums.begin();
	while (nums.size() > 1)
	{
		for (int i = 0; i < m-1; ++i)
		{
			cur++;
			if (cur == nums.end())
				cur = nums.begin();
		}

		list<int>::iterator next = ++cur;
		if (next == nums.end())
			next = nums.begin();
		--cur;//这个时候要删除前一个位置，所以这么使用，并且防止迭代器失效
		nums.erase(cur);
		cur = next;
	}

	return *(cur);
}