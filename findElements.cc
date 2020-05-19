#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class FindElements {
  unordered_set<int> st;
public:
  FindElements(TreeNode* root) {
    function<void(TreeNode*,int)> helper=[&](TreeNode* cur, int val){
      if (!cur) return;
      cur->val=val;
      st.insert(val);
      helper(cur->left,val*2+1);
      helper(cur->right,val*2+2);
    };
    helper(root,0);
  }
  bool find(int target) {
    return st.find(target)!=st.end();
  }
};
int main(){}
