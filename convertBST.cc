/* https://leetcode.com/problems/convert-bst-to-greater-tree/description/
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  struct TreeNode *left, *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};
class Solution {
public:
  TreeNode* convertBST(TreeNode* root) {  // reverse inoder trivasal
    int sum=0;
    function<void(TreeNode*)> helper=[&](TreeNode* cur) {
      if (!cur) return;
      helper(cur->right);
      cur->val+=sum;
      sum=cur->val; // defer
      helper(cur->left);
    };
    helper(root);
    return root;
  }
};
int main(){}
