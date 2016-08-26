#include<iostream>
using namespace std;
#include<vector>
#include<deque>

class SlideWindow {
public:
	vector<int> slide(vector<int> arr, int n, int w)
	{
		int size = arr.size();
		if (size == 0)  return arr;
		deque<int> deq;
		vector<int> res;



		for (int i = 0; i < size; i++)
		{
			if (deq.empty())
			{
				deq.push_back(i);
			}
			else
			{
				while (!deq.empty() && arr[deq.back()] <= arr[i])//经典的插入排序的写法
				{
					deq.pop_back();
				}
				deq.push_back(i);
			}
			if (i >= w - 1)
			{
				while (deq.front()<(i - w + 1))//其实这个可以使用if，因为最多也就pop一次
				{
					deq.pop_front();
				}
				res.push_back(arr[deq.front()]);
			}
		}

		return res;
	}
};


//别人写的，借鉴一下
//vector<int> maxInWindows(const vector<int>& a, unsigned int k){
//	vector<int> res;
//	deque<int> s;
//	for (unsigned int i = 0; i < a.size(); ++i){
//		while (s.size() && a[s.back()] <= a[i]) s.pop_back();
//		while (s.size() && i - s.front() + 1 > k) s.pop_front();
//		s.push_back(i);
//		if (k && i + 1 >= k) res.push_back(a[s.front()]);
//	}
//	return res;
//}