#include<iostream>
using namespace std;

//void Reverse(string& str, int left, int right)
//{
//	while(left < right)
//	{
//		std::swap(str[left], str[right]);
//		left++, right--;
//	}
//}
//
//string LeftRotateString(string str, int n) 
//{
//	int size = str.size();
//	Reverse(str, 0, n - 1);
//	Reverse(str, n, size-1);
//	Reverse(str, 0, size-1);
//	return str;
//}

string LeftRotateString(string str, int n) 
{
	int size = str.size();
	reverse(str.begin(), str.begin() + n);
	reverse(str.begin() + n, str.end());
	reverse(str.begin(), str.end());
	return str;
}