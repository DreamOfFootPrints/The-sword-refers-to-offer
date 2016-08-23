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



TreeNode* _Find(TreeNode* pRoot, unsigned int& k)
{
	TreeNode* res = NULL;
	if (pRoot != NULL)
	{
		res=_Find(pRoot->left, k);
		if (res != NULL) return res;
		
		if (--k == 0)//注意仅仅是这里才--，不是上下都--，一定要想明白
			return pRoot;
		
		res=_Find(pRoot->right,k);
		if (res != NULL) return res;

	}
	
	return res;
}

TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
{
	if (pRoot == NULL) return NULL;

	return _Find(pRoot, k);
}