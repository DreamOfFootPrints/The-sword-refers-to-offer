#include<iostream>
using namespace std;



bool _StartValid(string& str)
{
	
	int size = str.size();
	if (str[0] != '-'&&str[0] != '+' && (str[0] > '9' || str[0] < '0'))
		return false;
	if ((str[0] == '+' || str[0] == '-') && (str[1] == '0' || size == 1))
		return false;
	if (str[0] == '0' && str[1] != '0')
		return false;
	return true;
}



bool g_InvalidInput = false;
int StrToInt(string str) 
{
	g_InvalidInput = false;
	int size = str.size();
	if (size == 0)
		return 0;
	

	struct Com
	{
		bool operator()(const char ch) const
		{
			if (ch != '-'&&ch != '+' && (ch >= '9' || ch <= '0'))
				return false;
			else
				return true;
		}
	};

	if (!_StartValid(str))
	{
		g_InvalidInput = true;
		return 0;
	}

	int min = 0x80000000;//注意这里不是0xFFFFFFFF
	int minq =  min/ 10;
	int minr = min % 10;
	int posi = str[0] == '-' ? false : true;

	int cur = 0, res = 0;

	for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < size; i++)
	{
		if (!Com()(str[i]))
		{
			g_InvalidInput = true;
			return 0;
		}
		cur = '0' - str[i];//注意一定要加上引号

		if (res < minq || (res == minq&&cur < minr))
		{
			g_InvalidInput = true;
			return 0;
		}

		res = res*10+cur;
	}
	if (posi == true && res == min)//这里要小心
	{
		g_InvalidInput = true;
		return 0;
	}

	return posi == false ? res : -res;
}