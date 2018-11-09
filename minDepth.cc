/* Minimum Depth of Binary Tree
   https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 */
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
public:
	// O(n) time, O(log(n)) space, dfs but keep min, bottom-up
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return 1+minDepth(root->right);
		if (!root->right) return 1+minDepth(root->left);
		return 1+std::min(minDepth(root->left), minDepth(root->right));
	}
};

int main() {
    return 0;
}
