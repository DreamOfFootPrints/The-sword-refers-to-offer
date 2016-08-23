#include<iostream>
using namespace std;




// 分析二叉树的下一个节点，一共有以下情况：
//1.二叉树为空，则返回空；  
//2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；  
//3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。 

struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	typedef TreeLinkNode Node;
	if (pNode == NULL) return NULL;

	if (pNode->right != NULL)
	{
		Node* cur = pNode->right;
		while (cur->left != NULL)
		{
			cur = cur->left;
		}
		return cur;
	}
	else
	{
		Node* cur = pNode;
		while (cur->next != NULL)
		{
			Node* parent = cur->next;
			if (parent->left == cur)
				return parent;
			cur = cur->next;
		}
	}
	return NULL;
}
















