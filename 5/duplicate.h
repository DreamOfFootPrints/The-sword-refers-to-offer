#include<iostream>
using namespace std;


bool duplicate(int numbers[], int length, int* duplication) 
{
	if (length<= 0)
		return false;

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] != i)
		{
			int cur = numbers[i], index = i;
			int tmp = 0;
			while (cur!=index)
			{
				index = numbers[i];
				tmp = numbers[index];
				if (cur == numbers[index])
				{
					*duplication = cur;
					return true;
				}
				numbers[index] = cur;
			}
		}
	}
	return false;
}