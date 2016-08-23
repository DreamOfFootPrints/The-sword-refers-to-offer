#include<iostream>
using namespace std;
#include<vector>



struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};



vector<vector<int>> res;
vector<int> tmp;


void Process(TreeNode* root, int Sum)
{
	if (root == NULL) return;
	tmp.push_back(root->val);
	if (Sum-root->val  == 0&&!root->left&&!root->right)//必须这样，因为NULL不代表没有另外方向的子树
		res.push_back(tmp);
	Process(root->left, Sum - root->val);
	Process(root->right, Sum - root->val);
	tmp.pop_back();
}


vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
{
	if (root == NULL) return res;
	Process(root, expectNumber);
	return res;
}