#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    string s1,s2;
    function<void(TreeNode*,string&)> helper=[&](TreeNode* cur, string& s) {
      if (!cur) return;
      if (cur->left==cur->right) {
        s+=to_string(cur->val)+"#";
        return;
      }
      helper(cur->left,s),helper(cur->right,s);
    };
    helper(root1,s1),helper(root2,s2);
    return s1==s2;
  }
};
class Solution3 {
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1,s2;
    function<int(stack<TreeNode*>&)> helper=[&](stack<TreeNode*>& s){
      while (1) {
        TreeNode* cur=s.top(); s.pop();
        if (cur->left == cur->right) return cur->val; // this is leaf, stop here
        if (cur->right) s.push(cur->right); // think why right then left, hint: stack order
        if (cur->left) s.push(cur->left);
      }
    };
    s1.push(root1), s2.push(root2);
    while (s1.size() && s2.size()) {
      if (helper(s1)!=helper(s2))
        return false;
    }
    return s1.empty() && s2.empty();
  }
};
class Solution2 {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        function<void(TreeNode*, vector<int>&)> helper=[&](TreeNode* root, vector<int>& L) {
          if (root->left==root->right) {
            L.push_back(root->val);
            return;
          }
          if (root->left) helper(root->left, L);
          if (root->right) helper(root->right, L);
        };
        helper(root1,leaf1);
        helper(root2,leaf2);
        return leaf1==leaf2;
    }
};
int main(){}
