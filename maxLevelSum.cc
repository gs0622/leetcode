/* https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level X such that the sum of all the values of nodes at level X is maximal.
Example 1:
Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Note:
    The number of nodes in the given tree is between 1 and 10^4.
    -10^5 <= node.val <= 10^5

*/
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxLevelSum(TreeNode* root) {
    int res=1,lvl=1,cmax=INT_MIN;
    queue<TreeNode*> q; q.push(root);
    while (q.size()) {
      int n=q.size(),sum=0;
      for (int i=0;i<n;++i) {
        TreeNode *cur=q.front(); q.pop();
        sum+=cur->val;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      if (sum>cmax) {
        res=lvl,cmax=sum;
        cout << res << ": " << cmax << endl;
      }
      ++lvl;
    }
    return res;
  }
};
int main(){
  Solution s;
  TreeNode n0(989),n1(10250),n2(98693),n3(-89388),n4(-32127);
  n0.right=&n1,n1.left=&n2,n1.right=&n3,n3.right=&n4;
  cout << s.maxLevelSum(&n0) << endl;
}

