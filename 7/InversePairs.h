#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>


//但是没有通过测试用例
void Merge(vector<int>& arr, int* tmp, int begin1, int end1, int begin2, int end2, int& sum)
{
	int left2 = begin2, right2 = end2;

	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
		{
			tmp[index++] = arr[begin2];
			sum += begin2 - left2 + 1;
			begin2++;
		}

	}
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
		sum += right2 - left2 + 1;
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
}


void _MergeSort(vector<int>& arr, int* tmp, int left, int right, int& sum)
{
	if (left < right)//gap=2后，两两进行合并放入tmp中
	{
		int mid = left + (right - left) / 2;
		_MergeSort(arr, tmp, left, mid, sum);
		_MergeSort(arr, tmp, mid + 1, right, sum);
		Merge(arr, tmp, left, mid, mid + 1, right, sum);
		for (int i = left; i <= right; i++)
		{
			arr[i] = tmp[i];
		}
	}
}


int InversePairs(vector<int>& data)
{
	int size = data.size();
	if (size == 0) return 0;

	int sum = 0;
	int* tmp = new int[size]();
	_MergeSort(data, tmp, 0, size - 1, sum);
	return sum;
}