#include<iostream>
using namespace std;
#include<vector>

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int>> res;
	int  mid = (sum + 1) / 2;
	int left = 1, right = 1;
	vector<int> tmp;
	tmp.push_back(right);
	int add = 1;
	while ((left <= right) && (left < mid) && (right < sum))
	{
		if (add == sum)
		{
			vector<int> copy = tmp;
			res.push_back(copy);
			tmp.erase(tmp.begin());//不要忘记left要++，要不然会产生死循环
			add -= left;
			left++;
		}
		else if (add < sum)
		{
			tmp.push_back(++right);
			add += right;
		}
		else
		{
			tmp.erase(tmp.begin());
			add -= left;
			left++;
		}
	}
	return res;
}
















//vector<vector<int> > FindContinuousSequence(int sum) 
//{
//	vector<vector<int>> res;
//	int end = sum / 2 + 1;
//	int left = 0, right = 0;
//	vector<int> tmp;
//	tmp.push_back(right);
//	int add = 0;
//	while (left<=right&&left <= end&&right<=sum)
//	{
//		if (add == sum)
//		{
//			vector<int> copy = tmp;
//			res.push_back(copy);
//		}
//		else if (add < sum)
//		{
//			tmp.push_back(++right);
//			add = right;
//		}
//		else
//		{
//			tmp.erase(tmp.begin());
//			add -= left;
//			if (++left > right)
//				break;
//		}
//	}
//	return res;
//}