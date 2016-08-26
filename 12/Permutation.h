#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<string> vec;

void Process(string& str,int index)
{
	if (index == str.size())
		vec.push_back(str);
	{
		for (int i = index; i < str.size(); i++)
		{
			if (i != index&&str[i] == str[index])
				continue;

				std::swap(str[index], str[i]);
				Process(str, index + 1);
				std::swap(str[index], str[i]);

		}
	}
}

vector<string> Permutation(string str) 
{
	if (str.size() == 0) return vec;
	Process(str, 0);
	sort(str.begin(), str.end());
	return vec;
}

//类似方法：我是根据别人的改写的
//class Solution{
//public:
//	vector<string> Permutation(string str) {
//		//可以用递归来做
//		vector<string> array;
//		if (str.size() == 0)
//			return array;
//		Permutation(array, str, 0);
//		sort(array.begin(), array.end());
//		return array;
//	}
//
//	void Permutation(vector<string> &array, string str, int begin)//遍历第begin位的所有可能性
//	{
//		if (begin == str.size() - 1)
//			array.push_back(str);
//		for (int i = begin; i <= str.size() - 1; i++)
//		{
//			if (i != begin && str[i] == str[begin])//有重复字符时，跳过
//				continue;
//			swap(str[i], str[begin]);//当i==begin时，也要遍历其后面的所有字符；
//			//当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
//			Permutation(array, str, begin + 1);//遍历其后面的所有字符；
//
//			swap(str[i], str[begin]);//为了防止重复的情况，还需要将begin处的元素重新换回来
//
//			/*举例来说“abca”，为什么使用了两次swap函数
//			交换时是a与b交换，遍历；
//			交换时是a与c交换，遍历；（使用一次swap时，是b与c交换）
//			交换时是a与a不交换；
//			*/
//		}
//	}
//};
//
