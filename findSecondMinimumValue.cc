/* https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
	// dfs inorder triversal
	int findSecondMinimumValue2(TreeNode* root) {
		set<int> ans;
		function<void(TreeNode *)> dfs=[&](TreeNode *cur){
			if (!cur) return;
			dfs(cur->left);
			ans.insert(cur->val);
			dfs(cur->right);
		};
		dfs(root);
		return ans.size()<2? -1: *(++ans.begin());
	}
	// stack inorder triversal
	int findSecondMinimumValue(TreeNode* root) {
		TreeNode *cur=root;
		stack<TreeNode*> stk;
		set<int> ans;
		while (cur||!stk.empty()) {
			while (cur) {
				stk.push(cur), cur=cur->left;
			}
			cur=stk.top(); stk.pop();
			ans.insert(cur->val);
			cur=cur->right;
		}
		return ans.size()<2? -1: *(++ans.begin());
	}
};
int main(){}
