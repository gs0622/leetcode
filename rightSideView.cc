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
	// modified preorder traversal
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		function<void(TreeNode*,int)> dfs=[&](TreeNode* cur, int lvl) {
			if (!cur) return;
			if (res.size()<lvl) res.push_back(cur->val);
			dfs(cur->right, lvl+1);
			dfs(cur->left, lvl+1);
		};
		dfs(root,1);
		return res;
	}
};
int main(){}
