#include<iostream>
using namespace std;
#include<string >

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


class Solution 
{
	typedef TreeNode Node;
	Node* _CreateTree(const char* a, size_t size,
		size_t& index, const char& invalid)
	{
		Node* root = NULL;
		if (index < size && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->left = _CreateTree(a, size, ++index, invalid);
			root->right = _CreateTree(a, size, ++index, invalid);
		}
		return root;
	}
public:
	char* Serialize(TreeNode *root) 
	{
		if (!root) return "#";
		string r = to_string(root->val);
		r.push_back(',');

		char *left = Serialize(root->left);
		char *right = Serialize(root->right);
		char *ret = new char[strlen(left) + strlen(right) + r.size()];
		strcpy(ret, r.c_str());
		strcat(ret, left);
		strcat(ret, right);
		return ret;
	}

	TreeNode* Deserialize(char *str) 
	{
		size_t index = 0;
		return _CreateTree(str, strlen(str), index, '#');
	}
};


//class Solution {
//private:
//	TreeNode* decode(char *&str) {
//		if (*str == '#'){
//			str++;
//			return NULL;
//		}
//		int num = 0;
//		while (*str != ',')
//			num = num * 10 + (*(str++) - '0');
//		str++;
//		TreeNode *root = new TreeNode(num);
//		root->left = decode(str);
//		root->right = decode(str);
//		return root;
//	}
//public:
//	char* Serialize(TreeNode *root) {
//		if (!root) return "#";
//		string r = to_string(root->val);
//		r.push_back(',');
//		char *left = Serialize(root->left);
//		char *right = Serialize(root->right);
//		char *ret = new char[strlen(left) + strlen(right) + r.size()];
//		strcpy(ret, r.c_str());
//		strcat(ret, left);
//		strcat(ret, right);
//		return ret;
//	}
//	TreeNode* Deserialize(char *str) {
//		return decode(str);
//	}
//};
