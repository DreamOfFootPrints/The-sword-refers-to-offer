#include<iostream>
using namespace std;
#include<stack>


class Solution {
public:
	void push(int value)
	{
		s1.push(value);
		if (sMin.empty())//	注意这种情况	
		{
			sMin.push(value);
		}
		else
		{
			int minTop = value < sMin.top() ? value : sMin.top();
			sMin.push(minTop);
		}

	}
	void pop()
	{
		if (!s1.empty())
		{
			s1.pop();
			sMin.pop();
		}
	}
	int top()
	{
		if (!s1.empty())
		{
			return s1.top();
		}
		return 0;
	}
	int min()
	{
		if (!s1.empty())
		{
			return sMin.top();
		}
		return 0;
	}

	stack<int> s1;
	stack<int> sMin;

};