/* https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

# inorder, dfs
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
class Solution3 {
public:
	int maxDepth(TreeNode* root) {  // level-order BFS
    TreeNode* cur=root;
    queue<TreeNode*> q;
    q.push(cur);
    int res=0;
    while (q.size()) {
      ++res;
      int n=q.size();
      for (int i=0; i<n; ++i) {
        cur = q.front(); q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
    }
    return res;
  }
};
class Solution2 {
public:
/*
    3
   / \
  9  20
    /  \
   15   7
*/
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
    TreeNode *cur = root;
    int d=0, res=0;
    stack<pair<TreeNode*,int>> stk;
    while (cur||stk.size()) {
      while (cur) {
        stk.push({cur,++d});
        cur = cur->left;
      }
      auto p=stk.top();stk.pop();
      cur=p.first,d=p.second;
      res = max(res, d);
      cur=cur->right;
    }
    return res;
  }
};
class Solution {
public:
	// O(n)
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	}
};

int main() {
    return 0;
}
