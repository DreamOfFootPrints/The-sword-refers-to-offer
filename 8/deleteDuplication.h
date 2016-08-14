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

//[  )
void Del(ListNode*& left, ListNode*&right)
{
	typedef ListNode Node;
	while (left != right)
	{
		Node* del = left;
		left = left->next;
	}
}

ListNode* deleteDuplication(ListNode* pHead)
{
	typedef ListNode Node;
	if (pHead == NULL) return pHead;
	ListNode* newHead = new ListNode(-1);//关键：插入一个头结点
	newHead->next = pHead;

	Node* prev = newHead, *cur = pHead, *next = cur->next;

	while (next)
	{
		if (cur->val == next->val)
		{
			Node* left, *right;
			left = cur;
			int tmp = cur->val;
			while (cur != NULL&&cur->val == tmp)//前后顺序不要颠倒
			{
				cur = cur->next;
			}
			right = cur;
			Del(left, cur);
			prev->next = cur;
			next = cur == NULL ? NULL : cur->next;
		}
		else
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	pHead = newHead->next;
	delete newHead;
	return pHead;

}




















//ListNode* deleteDuplication(ListNode* pHead)
//{
//	typedef ListNode Node;
//	if (pHead == NULL) return NULL;
//
//	Node* cur = pHead;
//	while (cur->val == cur->next->val)
//	{
//		Node* del = cur;
//		cur = cur->next;
//	}
//	if (pHead != cur)
//	{
//		Node* del = cur;
//		cur = cur->next;
//		delete del;
//		pHead = cur;
//	}
//
//	cur = pHead->next;
//	Node* prev = pHead;
//	Node* next = cur->next;
//	while (next)
//	{
//		if (next->val == cur->val)
//		{
//			while (next->val == cur->val)
//			{
//				if (next == NULL) break;
//				Node* del = next;
//				cur->next = next->next;
//				delete del;
//				next = cur->next;
//			}
//			Node* del = cur;
//			prev->next = cur->next;
//			cur = next;
//			next = next == NULL ? next : cur->next;
//		}
//		else
//		{
//			prev = prev->next;
//			cur = cur->next;
//			next = next->next;
//		}
//	}
//	return pHead;
//
//}

//这个仅仅是去重而已，但是重复的并没有删除
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	typedef ListNode Node;
//	while (pHead->val == pHead->next->val)
//	{
//		Node* del = pHead;
//		pHead = pHead->next;
//		delete del;
//	}
//	
//	Node* cur = pHead->next , *prev = phea
//;
//	while (cur)
//	{
//		if (prev->val == cur->val)
//		{
//			Node* next = cur->next;
//			prev->next = next;
//			delete cur;
//			cur = next;
//		}
//		else
//		{
//			cur = cur->next;
//			prev = prev->next;
//		}
//	}
//	return pHead;
//}