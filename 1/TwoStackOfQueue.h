#include<iostream>
using namespace std;
#include<stack>

//这道题其实就是涉及到了一个倒的时机的问题
class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int tmp = stack1.top();
				stack1.pop();
				stack2.push(tmp);
			}
		}
		int top = stack2.top();
		stack2.pop();
		return top;
	}

private:
	stack<int> stack1;//用于push
	stack<int> stack2;//用于pop
};


