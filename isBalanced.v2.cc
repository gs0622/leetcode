/* https://leetcode.com/problems/balanced-binary-tree/description/
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
private:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		int left = maxDepth(root->left);
		if (left == -1) return -1;
		int right = maxDepth(root->right);
		if (right == -1) return -1;
		if (abs(left - right)>1) return -1;
		return max(left, right) + 1;
}
public:
	// bottom-up recursion, O(n) time, O(n) stack space
	bool isBalanced(TreeNode* root) {
	return (maxDepth(root) != -1);
}
};

int main() {
    return 0;
}
