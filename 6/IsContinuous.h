#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//这个其实就是最简单的找空的方式
bool IsContinuous(vector<int> numbers)
{
	if (numbers.empty())
	{
		return false;
	}
	sort(numbers.begin(), numbers.end());
	int count = 0;
	int size = numbers.size();
	int index =count= 0;
	while (index<size&&numbers[index]==0)
	{
		index++;
		count++;
	}
	int black = 0;
	for (int i = index+1; i < size; i++)//这里是比较巧妙的
	{
		if (numbers[i - 1] == numbers[i])
			return false;

		black += numbers[i] - numbers[i - 1];
	}
	
	return black <= count ? true : false;

}
