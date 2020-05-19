/*
https://leetcode.com/problems/unique-binary-search-trees-ii/description/
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
hint: divide-and-conquer
*/
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
  vector<TreeNode*> generateTrees(int n) {
    function<vector<TreeNode*>(int,int)> helper=[&](int s, int e){
      vector<TreeNode*> res; 
      if (s>e) {
        res.push_back(nullptr);
        return res;
      }
      for (int i=s;i<=e;++i) {
        vector<TreeNode*> L=helper(s,i-1);
        vector<TreeNode*> R=helper(i+1,e);
        for (auto p: L) for (auto q: R) {
          TreeNode *root = new TreeNode(i);
          root->left=p,root->right=q;
          res.push_back(root);
        }
      }
      return res;
    };
    vector<TreeNode*> r=helper(1,n);
    return r;
  }
};
int main(){
  Solution s;
  for (auto n: s.generateTrees(3)) cout << n->val << " ";
  cout << endl;
}
