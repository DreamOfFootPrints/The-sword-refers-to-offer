#include<iostream>
using namespace std;
#include<vector>



void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
{
	int size = data.size();
	if (size == 0) return;

	int eO = 0;
	for (int i = 0; i < size; i++)
		eO ^= data[i];
	*num1 = *num2 = 0;
	int rightOne = eO&(~eO + 1);
	for (int i = 0; i < size; i++)
	{
		if ((data[i] & rightOne) != 0)
			*num1 ^= data[i];
	}
	*num2 = *num1^eO;
}
