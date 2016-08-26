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


void reversepath(vector<vector<int> > &res)
{
	int len = res.size();
	for (int i = 1; i<len; i += 2){
		reverse(res[i].begin(), res[i].end());
	}
}
vector<vector<int> > Print(TreeNode* pRoot) 
{
	typedef TreeNode Node;
	vector<vector<int> > res;
	if (!pRoot) return res;
	queue<Node*> q;
	q.push(pRoot);

	while (q.size()>0){
		vector<int> path;
		int len = q.size();
		for (int i = 0; i<len; ++i){
			Node *t = q.front();
			q.pop();
			path.push_back(t->val);
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
		}
		res.push_back(path);
	}
	reversepath(res);
	return res;
}
