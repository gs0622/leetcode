#include <algorithm>
#include <cstddef>
using namespace std;
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
private:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
public:
	// top-down recursion, O(n^2) time, O(n) stack space
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		return abs(L - R) <= 1) &&
			isBalanced(root->left) &&
			isBalanced(root->right);
	}
};

int main() {
	return 0;
}
