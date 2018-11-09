/* Minimum Depth of Binary Tree
   https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 */
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
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
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q;
		q.push(root);
		int depth=0;
		while (!q.empty()) {
			++depth;
			int n = q.size();
			for (int i=0; i<n; ++i) {		// per level
				TreeNode *cur = q.front();
				q.pop();
				if (!cur->left && !cur->right)	// leaf: stop now
					return depth;
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
		}
		return -1; // makes compiler happy
	}
	// O(n) time, O(n) space
	int minDepth1(TreeNode* root) {
		if (!root) return 0;
		int depth = 1;
		queue<TreeNode *> q;
		q.push(root);
		TreeNode *rightMost = root;
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			// break while in leaf
			if (cur->left  == nullptr && cur->right == nullptr) break;

			// internal node
			if (cur->left  != nullptr) q.push(cur->left);
			if (cur->right != nullptr) q.push(cur->right);
			if (cur == rightMost) { // step to next level
				depth += 1;
				rightMost = (cur->right)? cur->right: cur->left;
			}
		}
		return depth;
	}
	// dfs, inorder
	int minDepth2(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return 1+minDepth2(root->right);
		if (!root->right) return 1+minDepth2(root->left);
		return 1+min(minDepth2(root->left), minDepth2(root->right));
	}
};

int main() {
    TreeNode n0(1), n1(2), n2(3);
    n0.left = &n1, n0.right = &n2;
    Solution s;
    cout << s.minDepth(&n0) << ": " << s.minDepth1(&n0) << ": " << s.minDepth2(&n0) << endl;
    return 0;
}
