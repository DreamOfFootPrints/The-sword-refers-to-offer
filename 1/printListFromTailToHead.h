#include<iostream>
using namespace std;
#include<vector>


struct ListNode
{
	int val;
	ListNode* next;
};

vector<int> printListFromTailToHead(struct ListNode* head)
{
	typedef ListNode Node;
	vector<int> list;
	Node* cur = head;
	while (cur)
	{
		Node* next = cur->next;
		vector<int>::iterator it= list.begin();
		list.insert(it, cur->val);
		cur = next;
	}
	return list;

}