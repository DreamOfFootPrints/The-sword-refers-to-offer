#include<iostream>
using namespace std;
#include<vector>


//void reOrderArray(vector<int> &array) 
//{
//	if (array.size() == 0)
//		return;
//	int left = 0;
//	int right = array.size() - 1;
//	while (left < right)
//	{
//		while (left < right && ((array[left] & 1) == 1))
//		{
//			left++;
//		}
//
//		while (left < right && ((array[right] & 1) != 1))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			std::swap(array[left], array[right]);
//			left++, right--;
//		}
//
//	}
//}

//
//void reOrderArray(vector<int> &array) 
//{
//	struct Com
//	{
//		bool operator()(int n)
//		{
//			return (n & 1) == 1;
//		}
//	};
//	if (array.size() == 0)
//		return;
//	int  size = array.size();
//	int pre = -1;
//	int cur = 0;
//	while (cur < size)
//	{
//		if (Com()(array[cur])&&(pre++!=cur))
//		{
//			std::swap(array[cur], array[pre]);
//		}
//		cur++;
//	}
//}


//插入排序的变形
void reOrderArray(vector<int> &array)
{
	if (array.size() == 0)
		return;
	struct Com
	{
		bool operator()(int n)
		{
			return (n & 1) == 1;
		}
	};
	for (int i = 0; i < array.size() - 1; i++)//这一步是关键
	{
		int end = i;
		int tmp = array[end + 1];
		if (Com()(tmp))
		{
			while (end >= 0 && !Com()(array[end]))
			{
				array[end + 1] = array[end];
				end--;
			}
			array[end + 1] = tmp;
		}
		
	}

}