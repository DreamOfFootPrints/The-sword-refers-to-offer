#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>


//两种比较器的使用都是可以的

//template<class T>
//struct Compare
//{
//	bool operator()(const T& s1, const T& s2)
//	{
//		return s1 + s2 < s2 + s1;
//	}
//};
//
//
struct Compare
{
	bool operator()(const string& s1, const string& s2)
	{
		return s1 + s2 < s2 + s1;
	}
};

string PrintMinNumber(vector<int> numbers)
{
	string res="";
	int size = numbers.size();
	if (size == 0)
		return res;

	vector<string> vec;
	for (int i = 0; i < size; i++)
		vec.push_back(std::to_string(numbers[i]));

	struct Less
	{
		bool operator()(const string s1, const string s2)
		{
			return s1+s2 < s2+s1;
		}
	};
	
	sort(numbers.begin(), numbers.end(),Compare<string>());
	for (int i = 0; i < vec.size(); i++)
		res += vec[i];
	return res;
}