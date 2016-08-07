#include<iostream>
using namespace std;
#include<vector>


void _AdjustDown(vector<int>& res,int parent,int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size)&&(res[child + 1] >= res[child]))
		{
			child++;
		}
		if (res[child] > res[parent])
		{
			std::swap(res[child], res[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	int size = input.size();
	vector<int> res;
	if (size <k||k<0)
	{
		return input;
	}


	for (int i = 0; i < k; i++)
	{
		res.push_back(input[i]);
	}

	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		_AdjustDown(res, i, k);
	}

	for (int i = k; i < size; i++)
	{
		if (input[i] < res[0])
		{
			res[0] = input[i];
			_AdjustDown(res, 0, k);

		}
	}
	return res;
}