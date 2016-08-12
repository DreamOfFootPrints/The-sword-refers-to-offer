#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>

int BinarySearch(vector<int>& a,int k)
{
	int left = 0;
	int right = a.size() - 1;
	while (left <= right)//这里一定是有等号的
	{
		int mid = left + (right - left)/2;
		if (a[mid] == k)
			return mid;
		else if (a[mid] < k)
			left = k + 1;
		else
			right = k - 1;
	}
	return -1;
}

int GetNumberOfK(vector<int> data, int k) 
{
	int index = BinarySearch(data, k);
	if (index == -1) return 0;

	int left = index - 1, right = index + 1;
	int size = data.size();
	while (left >= 0 && data[left] == k)
		left--;
	while (right <= size - 1 && data[right] == k)
		right++;

	return right - left - 1;
}