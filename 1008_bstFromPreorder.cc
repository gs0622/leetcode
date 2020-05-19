/* https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Return the root node of a binary search tree that matches the given preorder traversal.

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct.

hint: monotonic descreasing stack
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution2 {
public:
  // O(hlogn)
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    function<TreeNode*(int,int)> helper=[&](int lo, int hi){
      if (lo>=hi) return (TreeNode*)nullptr;    // tricky: lo>hi will has infinite recursive calls
      TreeNode* cur = new TreeNode(preorder[lo]);
      auto up = upper_bound(preorder.begin()+lo, preorder.begin()+hi, preorder[lo]);
      int j = distance(preorder.begin(), up);
      cur->left = helper(lo+1, j);
      cur->right = helper(j, hi);
      return cur;
    };
    return helper(0, preorder.size());
  }
};
class Solution {
public:
  // O(n) iterative w/ space, dummy.
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode dummy(INT_MAX);  // hook: go left
    stack<TreeNode*> stk; stk.push(&dummy);
    for (int i=0; i<preorder.size(); ++i) {
      TreeNode *tmp = nullptr, *cur = new TreeNode(preorder[i]);
      while (stk.top()->val < cur->val) // monotonic decrease stack: think preorder
        tmp = stk.top(), stk.pop();
      if (tmp) tmp->right = cur;
      else stk.top()->left = cur;
      stk.push(cur);
    }
    return dummy.left;
  }
};
int main(){
  Solution2 s;
  vector<int> A1{8,5,1,7,10,12};
  TreeNode* r = s.bstFromPreorder(A1);
  cout << r->val << endl; 
}
