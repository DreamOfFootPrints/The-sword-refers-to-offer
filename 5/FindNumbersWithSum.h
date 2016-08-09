#include<iostream>
using namespace std;
#include<vector>


vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
	if (array.empty())
	{
		return array;
	}
	int left = 0, right = array.size() - 1;
	int cur = 0;
	vector<int> res;

	while (left < right)
	{
		cur = array[left] + array[right];
		if (cur == sum)
		{
			res.push_back(array[left]);
			res.push_back(array[right]);
			break;//ע����Ϊ(x,y)�˻�һ����(x+a,y-a)С��������ֱ�ӿ���������
		}
		else if (cur<sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return res;
}