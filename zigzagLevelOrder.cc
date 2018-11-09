/* https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
*/
#include <bits/stdc++.h>
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};
using namespace std;
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		bool zigzag=false;
		while (!q.empty()) {
			int n=q.size();
			vector<int> ans;
			for (int i=0; i<n; ++i) {
				TreeNode *cur=q.front(); q.pop();
				ans.push_back(cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			if (zigzag)
				reverse(begin(ans), end(ans));
			res.push_back(ans);	// level
			zigzag=!zigzag;
		}
		return res;
	}
};
int main(){
	TreeNode n5(7),n4(15),n3(20,&n4,&n5),n2(9),n1(1,&n2,&n3);
	Solution s;
	vector<vector<int>> res = s.zigzagLevelOrder(&n1);
	for (auto r: res) {
		for (auto c: r) cout << c << ' ';
		cout << endl;
	}
}
