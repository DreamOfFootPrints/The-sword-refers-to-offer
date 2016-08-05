#include<iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;

};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	typedef ListNode Node;
	Node* fast = pListHead;
	Node* slow = pListHead;
	while (fast&&k)
	{
		fast = fast->next;
		k--;
	}
	if (k > 0)
	{
		return NULL;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}