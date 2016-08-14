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




vector<int> PrintFromTopToBottom(TreeNode *root) 
{
	typedef TreeNode Node;
	vector<int> vec;
	if (root == NULL) return vec;

	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		vec.push_back(front->val);
		if (front->left != NULL) q.push(front->left);
		if (front->right != NULL) q.push(front->right);
	}
	return vec;
}







