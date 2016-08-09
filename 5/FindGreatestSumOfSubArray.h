#include<iostream>
using namespace std;
#include<vector>


int FindGreatestSumOfSubArray(vector<int> array) 
{
	int size = array.size();
	if (size == 0)
		return 0;

	int cur = 0;
	int sum = 0;
	int Max = 0x80000000;

	vector<int>::iterator it = array.begin();
	while (it != array.end())
	{
		cur = *it;
		sum += cur;
		if (sum > Max)
			Max = sum;
		if (sum < 0)
			sum = 0;
		it++;
	}
	return Max;
}