#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//��С�ľ��Ǵ�С��������less<int>

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> res;
	int size = input.size();
	if (size < k)
		return res;
	;
	
	sort(input.begin(), input.end(), less<int>());
	for (int i = 0; i < k; i++)
		res.push_back(input[i]);
	return res;
}