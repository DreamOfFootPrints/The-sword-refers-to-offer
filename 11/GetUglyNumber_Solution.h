#include<iostream>
using namespace std;

int Min(int a, int b, int c)
{
	int tmp = a < b ? a : b;
	return tmp < c ? tmp : c;
}

int GetUglyNumber_Solution(int num)
{
	if (num <= 0) return 0;
	int* res = new int[num]();
	res[0] = 1;
	int index = 1;

	int p[3] = { 0 };

	while (index < num)
	{
		int min = Min(res[p[0]] * 2, res[p[1]] * 3, res[p[2]] * 5);
		res[index] = min;

		while (res[p[0]] * 2 <= min)//为什么这里一定是<=
			++p[0];
		while (res[p[1]] * 3 <= min)
			++p[1];
		while (res[p[2]] * 5 <= min)
			++p[2];

		++index;
	}
	return res[num - 1];
}