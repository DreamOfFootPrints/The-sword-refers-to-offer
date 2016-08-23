#include<iostream>
using namespace std;
#include<queue>


int Sum_Solution(int n)
{
	int val = (int)(pow(n, 2) + n) >> 1;
	return val;
}


//int Sum_Solution(int n) 
//{
//	int val = n;
//	val && ( val+=Sum_Solution(val - 1));
//	return val;
//}