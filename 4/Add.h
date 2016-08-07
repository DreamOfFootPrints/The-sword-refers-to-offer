#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = num1^num2;//记住这里是^异或
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 == 0);
	return sum;

}