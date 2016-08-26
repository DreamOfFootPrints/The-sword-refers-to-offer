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


vector<vector<int> > Print(TreeNode* pRoot) 
{
	typedef TreeNode Node;
	vector<vector<int>> res;
	if (pRoot == nullptr)
		return res;
	queue<Node*> dq;
	dq.push(pRoot);
	int curNum = 1;
	int next = 0;
	vector<int> temp;
	while (!dq.empty())
	{
		Node * p = dq.front();
		dq.pop();
		temp.push_back(p->val);
		curNum--;
		if (p->left != nullptr)
		{
			dq.push(p->left);
			next++;
		}
		if (p->right != nullptr)
		{
			dq.push(p->right);
			next++;
		}

		if (curNum == 0)
		{
			res.push_back(temp);
			temp.clear();
			curNum = next;
			next = 0;
		}
	}
	return res;

}