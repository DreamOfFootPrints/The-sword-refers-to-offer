#include<iostream>
using namespace std;
#include<vector>
#include<map>



class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		res.push_back(ch);
		mapdata[ch]++;//使用map[ ]是极其巧妙的

	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		vector<int>::iterator it;
		for (it = res.begin(); it != res.end(); ++it)//遍历的时候，是遍历这个vector
		{
			if (mapdata[*it] == 1)
				return *it;
		}
		return '#';
	}
	map<char, int>mapdata;//一个vector
	vector<int>res;//一个map
};




