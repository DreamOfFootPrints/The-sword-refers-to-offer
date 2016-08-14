#include<queue>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}

};


int _Hight(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	int leftDepth = _Hight(pRoot->left);
	int rightDepth = _Hight(pRoot->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
	if (pRoot == NULL)
		return true;
	
	int bf = _Hight(pRoot->left) - _Hight(pRoot->right);
	return abs(bf) < 2 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

}