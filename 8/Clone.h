#include<iostream>
using namespace std;
#include<vector>


struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};



RandomListNode* Clone(RandomListNode* pHead)
{
	typedef RandomListNode Node;
	if (pHead == NULL) return NULL;

	Node* cur = pHead;
	//插入中间节点
	while (cur)
	{
		Node* mid = new Node(cur->label);
		Node* next = cur->next;
		cur->next = mid;
		mid->next = next;
		cur = next;
	}
	
	//copy随机指针
	Node* newHead = cur->next, *newCur = newHead;
	cur = pHead;
	while (cur)
	{
		newCur->random = cur->random == NULL ? NULL : cur->random->next;
		cur = cur->next->next;
		newCur = newCur->next == NULL ? NULL : newCur->next->next;
	}
	//取下来
	cur = pHead, newCur = newHead;
	while (cur)
	{
		Node* oldNext = cur->next->next;
		Node* newNext = newCur->next == NULL ? NULL : newCur->next->next;
		cur->next = oldNext, cur = oldNext;
		newCur->next = newNext, newCur= newNext;
	}
	return newHead;

}