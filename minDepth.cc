/* Minimum Depth of Binary Tree
   https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 */
#include <bits/stdc++.h>
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
class Solution2 {
public:
	int minDepth(TreeNode* root) {
    queue<TreeNode*> q({root});
    int res=0;
    while (q.size()) {
      int n=q.size();
      ++res;
      TreeNode *cur;
      for (int i=0;i<n;++i) {
        cur=q.front(),q.pop();
        if (cur->left&&cur->right) break;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
    }
    return res;
  }
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
