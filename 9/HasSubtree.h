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


//����û�д��󣬽����ǲ��������ǲ����������ͨ�������е�����

bool Check(TreeNode* A, TreeNode* B)
{
	if (!A&&!B) return true;
	if ((!A&&B) || (!B&&A)) return false;
	if (A->val != B->val)
		return false;
	
	return Check(A->left, B->left) && Check(A->right, B->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	typedef TreeNode Node;
	if (!pRoot2)  return true;
	if (!pRoot1&&pRoot2) return false;

	if (Check(pRoot1, pRoot2)) return true;

	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}



