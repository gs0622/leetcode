#include <iostream>
#include <list>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
	}
	TreeNode* invertTree2(TreeNode* root) {
		if (!root) return nullptr;
		TreeNode *L = invertTree(root->left);
		TreeNode *R = invertTree(root->right);
		root->left = R;
		root->right = L;
		return root;
	}
};
int main(){
	Solution s;
	struct TreeNode n0();
	lists[0]
}
