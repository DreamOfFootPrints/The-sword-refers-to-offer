#include<iostream>
using namespace std;




// ��������������һ���ڵ㣬һ�������������
//1.������Ϊ�գ��򷵻ؿգ�  
//2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻  
//3.�ڵ㲻�Ǹ��ڵ㡣����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ���� 

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
















