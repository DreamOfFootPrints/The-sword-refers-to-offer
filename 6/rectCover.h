#include<iostream>
using namespace std;
#include<vector>



int rectCover(int number) 
{
	return number <= 2 ? number : rectCover(number - 1) + rectCover(number - 2);
}