#include<iostream>
using namespace std;
#include<vector>



int jumpFloor(int number) 
{
	return number <= 2 ? number:jumpFloor(number - 1) + jumpFloor(number - 2);
}