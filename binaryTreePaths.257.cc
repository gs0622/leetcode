#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return {};
    vector<string> res;
    function<void(TreeNode*,string)> helper=[&](TreeNode* cur, string s){  // s is copy
      if (cur->left==cur->right) {
        res.push_back(s);
        return;
      } // non leaf below
      string ss=s+"->";
      if (cur->left) helper(cur->left, ss+to_string(cur->left->val));
      if (cur->right) helper(cur->right, ss+to_string(cur->right->val));
    };
    helper(root,to_string(root->val));
    return res;
  }
};
int main(){}
