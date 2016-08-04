#include<iostream>
using namespace std;
#include<stack>

//�������ʵ�����漰����һ������ʱ��������
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
	stack<int> stack1;//����push
	stack<int> stack2;//����pop
};


