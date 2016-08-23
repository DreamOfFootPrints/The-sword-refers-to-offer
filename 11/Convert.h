#include<iostream>
using namespace std;



struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};




void ConvertNode(TreeNode *pNode, TreeNode*& pRe)
{
	if (pNode == NULL)
		return;

	if (pNode->left != NULL)
	{
		ConvertNode(pNode->left, pRe);
	}

	pNode->left = pRe;
	if (pRe != NULL)
	{
		(pRe)->right = pNode;
	}
	pRe = pNode;
	if (pNode->right != NULL)
	{
		ConvertNode(pNode->right, pRe);
	}
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode *pRe = NULL;
	ConvertNode(pRootOfTree, pRe);

	while (pRe != NULL && pRe->left != NULL)
	{
		pRe = pRe->left;
	}

	return pRe;
}
