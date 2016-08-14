#include<iostream>
using namespace std;
#include<vector>




struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};


int LengthAndTail(ListNode* cur, ListNode*& tail)
{
	typedef ListNode Node;
	int count = 0;

	while (cur->next !=NULL)
	{
		count++;
		cur = cur->next;
	}
	tail = cur;
	return count;
}

ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) 
{
	typedef ListNode Node;
	if (pHead1 == NULL || pHead2 == NULL) return NULL;

	Node* cur1 = pHead1,*cur2 = pHead2;

	Node* tail1 = NULL, *tail2 = NULL;
	int length1= LengthAndTail(pHead1, tail1);
	int length2 = LengthAndTail(pHead2, tail2);
	if (tail1 != tail2)
		return NULL;
	
	Node* fast = length1 > length2 ? pHead1 : pHead2;
	Node* slow = length1 > length2 ? pHead2 : pHead1;
	int dif = length1 - length2;
	while (dif)
	{
		fast = fast->next;
		dif--;
	}
	while (fast&&slow)
	{
		if (fast == slow)
			break;
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}