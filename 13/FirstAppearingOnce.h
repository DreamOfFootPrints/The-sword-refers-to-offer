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
		mapdata[ch]++;//ʹ��map[ ]�Ǽ��������

	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		vector<int>::iterator it;
		for (it = res.begin(); it != res.end(); ++it)//������ʱ���Ǳ������vector
		{
			if (mapdata[*it] == 1)
				return *it;
		}
		return '#';
	}
	map<char, int>mapdata;//һ��vector
	vector<int>res;//һ��map
};




