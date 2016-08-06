#include<iostream>
using namespace std;


struct ListNode
{
	ListNode* next = NULL;
	int data;

};


//ListNode* ReverseList(ListNode* pHead)
//{
//	typedef ListNode Node;
//	Node* prev = NULL;
//	Node* cur = pHead;
//	while (cur)
//	{
//		Node* next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//	
//}

ListNode* ReverseList(ListNode* pHead) 
{
	typedef ListNode Node;
	Node* cur = pHead;
	Node* newHead = NULL;
	while (cur)
	{
		Node* tmp = cur;
		cur = cur->next;
		tmp->next = newHead;
		newHead = tmp;
	}
	return newHead;
}