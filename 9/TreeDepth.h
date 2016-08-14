#include<iostream>
using namespace std;
#include<vector>
#include<queue>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}

};


int TreeDepth(TreeNode* pRoot)
{
	if (pRoot ==  NULL) return 0;
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}