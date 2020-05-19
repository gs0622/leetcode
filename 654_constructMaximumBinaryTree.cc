/* https://leetcode.com/problems/maximum-binary-tree/description/
hint: monotonic stack algorithm
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution3 {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    vector<TreeNode*> stk;
    for (int i=0; i<nums.size(); ++i) {               // left to right
      TreeNode* cur = new TreeNode(nums[i]);
      while (stk.size() && stk.back()->val < cur->val) // pop and push to left subtree while the stk.top is smaller then cur
        cur->left = stk.back(), stk.pop_back();       // maintain a monotonic decreasing stack (1)
      if (stk.size())                                 // maintain a monotonic decreasing stack (2)
        stk.back()->right = cur;
      stk.push_back(cur);                             // defer
    }
    return stk.front();
  }
};
class Solution2 {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    vector<TreeNode*> stk{new TreeNode(nums[0])};
    for (auto i=1; i<nums.size(); ++i) {
      TreeNode* cur = new TreeNode(nums[i]);
      auto it = upper_bound(stk.rbegin(), stk.rend(), cur, [](const TreeNode* a, const TreeNode* b){
        return a->val < b->val;
      }); // custom less()
      if (it != stk.rend())   // cur is smaller than it (upper_bound)
          (*it)->right = cur;
      if (it != stk.rbegin()) // cur is larger than next(upper_bound)
          cur->left = *next(it, -1);
      stk.resize(distance(it,stk.rend()));
      stk.push_back(cur);
    }
    return stk.front();
  }
};
class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    map<int,int,greater<int>> mp;
    int n=nums.size();
    for (int i=0; i<n; ++i) // O(nlog(n))
      mp[nums[i]]=i;
    TreeNode *root = new TreeNode(mp.begin()->first);
    for (auto it=++mp.begin(); it!=mp.end(); ++it) {  // O(n)
      TreeNode** tail = &root;
      while (*tail) {
        if (it->second > mp[(*tail)->val]) tail = &((*tail)->right);
        else tail = &((*tail)->left);
      }
      *tail = new TreeNode(it->first);
    }
    return root;
  }
};
int main(){
  Solution2 s;
  vector<int> A1{3,2,1,6,0,5};
  TreeNode *r = s.constructMaximumBinaryTree(A1);
  cout << r->val << endl;
}
