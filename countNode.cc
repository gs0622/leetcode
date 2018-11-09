/**
 * Definition for a binary tree node.
 */
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	int inorder(TreeNode* cur) {
		if (!cur) return 0;
		int nodes = inorder(cur->left);
		nodes += inorder(cur->right);
		return nodes+1;	
	}
public:
	int countNodes(TreeNode* root) {
		return inorder(root);
	}
};

