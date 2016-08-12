#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>


int NumOf1(int num)
{
	int count = 0;
	while (num)
	{
		count = num % 10 == 1 ? count + 1 : count;
		num /= 10;
	}
	return count;
}

int NumberOf1Between1AndN_Solution(int n)
{
	if (n <= 0) return 0;

	int count = 0;
	for (int i = 1; i <= n; i++)
		count += NumOf1(i);
	return count;
}