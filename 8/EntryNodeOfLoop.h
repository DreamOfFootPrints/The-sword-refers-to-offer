#include<iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};




ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	typedef ListNode Node;
	if (pHead == NULL||pHead->next ==NULL) //记得加上这个判断
		return NULL;

	Node* fast = pHead, *slow = pHead;
	while (fast != NULL&&fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (fast == NULL)
		return NULL;

	slow = pHead;
	while (fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}