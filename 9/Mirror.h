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

void Mirror(TreeNode *pRoot) 
{
	typedef TreeNode Node;
	if (pRoot == NULL)
		return;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
	std::swap(pRoot->left, pRoot->right);//��ʵ��һ�㻹�ǱȽ�������
}