#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
};
class Solution {
public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) { // time: O(n), space: O(h)
    function<TreeNode*(TreeNode*)> helper=[&](TreeNode* cur){
      if (!cur) return (TreeNode*)nullptr;
      cur->left = helper(cur->left);
      cur->right = helper(cur->right);
      if (cur->left==cur->right && cur->val==target) return (TreeNode*)nullptr;
      return cur;
    };
    return helper(root);
  }
};
int main(){}
