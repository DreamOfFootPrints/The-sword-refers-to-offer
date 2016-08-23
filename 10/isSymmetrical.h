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





bool _IsEqual(TreeNode* left, TreeNode* right)
{
	if (!left&&!right) return true;
	if (!left&&right || !right&&left) return false;

	if (left->val != right->val) 
		return false;
	return _IsEqual(left->right, right->left) && _IsEqual(left->left, right->right);//这里一定要注意
}

bool isSymmetrical(TreeNode* pRoot)
{
	typedef TreeNode Node;
	if (pRoot == NULL) return true;

	return _IsEqual(pRoot->left, pRoot->right);
}