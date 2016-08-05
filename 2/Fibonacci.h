#include<iostream>
using namespace std;

//
//int Fibonacci(int n) 
//{
//	if (n < 2)
//		return n;
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}


int Fibonacci(int n) 
{
	if (n < 2)
		return n;
	int pre = 0;
	int res = 1;
	for (int i = 2; i <= n;i++)
	{
		int tmp = res;
		res += pre;
		pre = tmp;
	}
	return res;
}