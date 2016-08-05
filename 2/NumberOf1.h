#include<iostream>
using namespace std;


//int  NumberOf1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n&(n - 1);
//	}
//	return count;
//}

int NumberOf1(int n)
{
	int flag = 1;
	int count = 0;
	while (flag)
	{
		if (count&flag != 0)
			count++;
		flag <<= 1;
	}
	return count;
}