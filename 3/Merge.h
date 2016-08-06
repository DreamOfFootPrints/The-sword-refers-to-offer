#include<iostream>
using namespace std;


struct ListNode
{
	ListNode* next = NULL;
	int val;

};



ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	typedef ListNode Node;
	if (pHead1 == NULL || pHead2 == NULL)
		return pHead1 == NULL ? pHead2 : pHead1;

	Node* newHead = pHead1->val > pHead2->val ? pHead2 : pHead1;
	Node* cur1 = newHead;
	Node* cur2 = cur1 == newHead ? pHead2 : pHead1;
	Node* prev = NULL;
	while (cur1&&cur2)
	{
		if (cur2->val < cur1->val)
		{
			Node*next = cur2->next;
			prev->next = cur2;
			cur2->next = cur1;
			prev = cur2;
			cur2 = next;
		}
		else
		{
			prev = cur1;
			cur1 = cur1->next;
		}

	}
	if (cur1 == NULL)
	{
		prev->next = cur2;
	}
	return newHead;
}