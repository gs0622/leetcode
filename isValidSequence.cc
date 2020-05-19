#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    int n=arr.size();
    function<bool(TreeNode*,int)> helper=[&](TreeNode* cur, int i){
      if (!cur) return false;
      if (i==n-1 && !cur->left && !cur->right && cur->val==arr[i])
        return true;
      if (i<n && cur->val==arr[i])
        return helper(cur->left,i+1)||helper(cur->right,i+1);
      return false;
    };
    return helper(root,0);
  }
};
int main(){}
