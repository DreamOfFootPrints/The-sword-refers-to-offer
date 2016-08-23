#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>



//永远保证大根堆中数的个数是最多的，相等或者大于1
class Solution {
	priority_queue<int, vector<int>, less<int> > p;//左边的数维持一个大根堆
	priority_queue<int, vector<int>, greater<int> > q;//右边的数维持一个小根堆

public:
	void Insert(int num){
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);
		if (p.size() == q.size() + 2) q.push(p.top()), p.pop();
		if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
	}
	double GetMedian(){
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}
};