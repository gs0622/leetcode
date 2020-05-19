#include <bits/stdc++.h>
using namespace std;
/*
		1        L = 3
	       2 3       R = 1
	      4 5
*/
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}
};
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
    int res=0;
    unordered_map<TreeNode*,int> mp;
    stack<TreeNode*> stk;
    stk.push(root);
    while (stk.size()) {
      TreeNode* cur=stk.top();
      if (cur->left && !mp.count(cur->left))
        stk.push(cur->left);
      else if (cur->right && !mp.count(cur->right))
        stk.push(cur->right);
      else {
        stk.pop();
        int L=mp[cur->left], R=mp[cur->right];
        mp[cur]=max(L,R)+1;
        res=max(res,L+R);
      }
    }
    return res;
  }
};
class Solution2 {
public:
	int diameterOfBinaryTree(TreeNode* root) {
    int res=0;
    function<int(TreeNode*)> helper=[&](TreeNode* cur){
      if (!cur) return 0;
      int L=helper(cur->left), R=helper(cur->right);
      res=max(res,L+R);
      return 1+max(L,R);
    };
    helper(root);
    return res;
  }
};
class Solution1 {
	// diameter: edges along path
	int diameterOfBinaryTree(TreeNode* root, int &diameter) {
		if (!root) return 0;
		int L = diameterOfBinaryTree(root->left, diameter);
		int R = diameterOfBinaryTree(root->right, diameter);
		diameter = max(diameter, L+R); // from L to R diameter, L+R
		return 1+max(L, R);
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		diameterOfBinaryTree(root, diameter);
		return diameter;
	}
};
int main(){
	TreeNode n4(4), n5(5), n2(2, &n4, &n5), n3(3), n1(1, &n2, &n3);
	Solution s;
	cout << s.diameterOfBinaryTree(&n1) << endl;
}
