/* https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)
Example 1:

Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Note:
The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution2 {
public: // preorder
  int maxAncestorDiff(TreeNode* root, int mi=100000, int ma=0) {
    stack<tuple<TreeNode*,int,int>> stk;
    TreeNode* cur=root;
    int res=0;
    while (cur||stk.size()) {
      while (cur) {
        ma=max(cur->val,ma);
        mi=min(cur->val,mi);
        stk.push({cur,mi,ma});
        cur=cur->left;
      }
      auto t=stk.top();stk.pop();  //leaf
      cur=get<0>(t),mi=get<1>(t),ma=get<2>(t);
      res=max(res,ma-mi);
      cur=cur->right;
    }
    return res;
  }
};
class Solution {
public: // preorder
  int maxAncestorDiff(TreeNode* root, int mi=100000, int ma=0) {
    if (!root) return ma-mi;
    ma=max(root->val,ma);
    mi=min(root->val,mi);
    return max(maxAncestorDiff(root->left, mi, ma),
               maxAncestorDiff(root->right, mi, ma));
  }
};
int main(){
}
