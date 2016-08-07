#include<iostream>
using namespace std;


string ReverseSentence(string str)
{
	int size = str.size();
	int left = -1, right = -1;
	
	for (int i = 0; i < size; i++)
	{
		if (str[i] != ' ')
		{
			left = i == 0 || str[i - 1] == ' ' ? i : left;
			right = i == size - 1 || str[i + 1] == ' ' ? i : right;
		}
		if (left != -1 && right != -1)
		{
			reverse(str.begin() + left, str.begin() + right+1);
			left = -1;
			right = -1;
		}
	}
	reverse(str.begin(), str.end());
	return str;
}