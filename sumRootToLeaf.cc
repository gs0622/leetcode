#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left,*right;
  TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};
class Solution2 {
public: // O(n) time, O(logn) (resursive) space
  int sumRootToLeaf(TreeNode* cur, int sum=0) {
    if (!cur) return 0;
    sum=sum*2 + cur->val;
    if (cur->left==cur->right) return sum;  // left==right==nullptr: count it
    return sumRootToLeaf(cur->left,sum)+sumRootToLeaf(cur->right,sum);
  }
};
class Solution {
public:
  int sumRootToLeaf(TreeNode* root) {
    int res=0,sum=0,tmp;
    stack<pair<TreeNode*,int>> stk;
    TreeNode *cur=root;
    while (cur || stk.size()) {
      while (cur) {
        sum=sum*2+cur->val;
        if (cur->left==cur->right) res+=sum;  //leaf
        stk.push({cur,sum});
        cur=cur->left;
      } // nullptr
      auto top=stk.top(); stk.pop();
      cur=top.first, sum=top.second;
      cur=cur->right;
    }
    return res;
  }
};
int main(){
  Solution s;
/*
  TreeNode n[7]={{1},{0},{1},{0},{1},{0},{1}};
  n[0].left=&n[1],n[0].right=&n[2];
  n[1].left=&n[3],n[1].right=&n[4];
  n[2].left=&n[5],n[2].right=&n[6];
*/
  TreeNode n[2]={{1},{0}};
  n[0].right=&n[1];
  cout << s.sumRootToLeaf(&n[0]) << endl;
}
