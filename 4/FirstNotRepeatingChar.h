#include<iostream>
using namespace std;


int FirstNotRepeatingChar(string str)
{
	int size = str.size();
	if (size == 0)
		return -1;

	int map[256] = { 0 };
	for (int i = 0; i < size; i++)
	{
		map[str[i]]++;
	}
	for (int i = 0; i < size; i++)
	{
		if (map[str[i]] == 1)
			return i;
	}
	return -1;


}