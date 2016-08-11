#include<iostream>
using namespace std;
#include<vector>


//其实就是计算2^(n-1)

int jumpFloorII(int number) 
{
	return 1 << --number;
}


//
//int jumpFloorII(int number) 
//{
//	return number >= 2 ? number : 2*jumpFloorII(number - 1);
//}