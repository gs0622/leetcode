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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> row;
			int n=q.size();
			for (int i=0; i<n; ++i) {
				TreeNode *cur = q.front(); q.pop();
				row.push_back(cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			res.push_back(row);
		}
		reverse(begin(res), end(res));
		return res;
	}
};
int main(){}
