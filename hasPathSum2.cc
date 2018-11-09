#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};
class Solution {
public:
	// backtracking, dfs, stack
	vector<vector<int>> hasPathSum2(TreeNode *root, int sum) {
		if (!root) return {};
		vector<vector<int>> res;
		stack<pair<TreeNode*,vector<int>>> stk;
		stk.push(make_pair(root,vector<int>{root->val}));	// node, list
		while (!stk.empty()) {
			TreeNode* cur=stk.top().first;
			vector<int> ans=stk.top().second;
			stk.pop();
			if (!cur->left && !cur->right && accumulate(begin(ans),end(ans),0)==sum)
				res.push_back(ans);
			if (cur->left) {
				ans.push_back(cur->left->val);
				stk.push(make_pair(cur->left, ans));
				ans.pop_back();
			}
			if (cur->right) {
				ans.push_back(cur->right->val);
				stk.push(make_pair(cur->right, ans));
				ans.pop_back();
			}
		}
		return res;
	}
	// backtracking, dfs, recursion
	vector<vector<int>> hasPathSum(TreeNode *root, int sum) {
		vector<vector<int>> res;
		vector<int> ans;
		function<void(TreeNode*,int)> helper=[&](TreeNode* cur, int target) {
			if (!cur) return;
			int v=cur->val;
			ans.push_back(v);
			if (target==v && !cur->left && !cur->right) {
				res.push_back(ans);
			} else {
				helper(cur->left, target-v);
				helper(cur->right, target-v);
			}
			ans.pop_back();
		};
		helper(root, sum);
		return res;
	}
};
int main(){
	TreeNode n10(1),n9(5),n8(2),n7(7),n6(4,&n9,&n10),n5(13),n4(11,&n7,&n8),n3(8,&n5,&n6),n2(4,&n4,nullptr),n1(5,&n2,&n3);
	Solution s;
	vector<vector<int>> res;
	res = s.hasPathSum2(&n1, 22);
	for (auto nums: res) {
		for (auto n: nums)
			cout << n << ' ';
		cout << endl;
	}
}
