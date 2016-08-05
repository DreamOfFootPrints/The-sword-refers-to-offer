#include<iostream>
using namespace std;

double Abs(double a)
{
	return a < 0 ? -a : a;
}

bool Equal(double n1, double n2)
{
	int expsion = 0.0000000001;
	if (Abs(n1 - n2) < expsion)
	{
		return true;
	}
	return false;
}


double _Power(int base, int exponent)
{
	double res = 1.0;
	for (int i = 0; i < exponent; i++)
		res *= base;
	return res;
}

double Power(double base, int exponent) 
{
	//浮点数0.0是不能直接进行比较的，所以要借助于函数
	if (Equal(base, 0.0))
		return 0.0;

	bool posi = exponent >= 0 ? true : false;
	double res = _Power(base, Abs(exponent));
	if (!posi)
		res = 1 / res;
	return res;
		
}