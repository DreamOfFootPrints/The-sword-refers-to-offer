#include<iostream>
using namespace std;
#include<vector>

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	int size = numbers.size();
	if (size == 0)
		return 0;

	int cander = -1;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (count == 0)
		{
			cander = numbers[i];
			count = 1;
		}
		else
		{
			if (cander == numbers[i])
				count++;
			else
				count--;
		}
	}
	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == cander)
			count++;
	}
	
	if (count * 2 > size)
		return cander;
	else
		return 0;
}