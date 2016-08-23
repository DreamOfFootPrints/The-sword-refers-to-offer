#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>



//��Զ��֤����������ĸ��������ģ���Ȼ��ߴ���1
class Solution {
	priority_queue<int, vector<int>, less<int> > p;//��ߵ���ά��һ�������
	priority_queue<int, vector<int>, greater<int> > q;//�ұߵ���ά��һ��С����

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