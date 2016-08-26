#include<iostream>
using namespace std;
#include<vector>



struct TreeNode {
  int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



TreeNode* Process(vector<int>& prev, int& preIndex, const vector<int> in, int index1, int index2)
{
	typedef TreeNode Node;
	if (preIndex == prev.size())
		return NULL;
	Node* root = new Node(prev[preIndex]);

	int pos = index1;
	while (in[pos] != prev[preIndex])
	{
		pos++;
	}
	if (index1 < pos)
		root->left = Process(prev, ++preIndex, in, index1, pos - 1);//这个++，有点难以理解
	if (pos < index2)
		root->right = Process(prev, ++preIndex, in, pos + 1, index2);
	return root;

}

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
	if (pre.size() != in.size())
		return NULL;

	int preIndex = 0;
	TreeNode* ret = Process(pre, preIndex, in, 0, in.size() - 1);
	return ret;
}