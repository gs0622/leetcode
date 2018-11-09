/* https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

Given a binary search tree with non-negative values, find the minimum absolute difference between values of "any" two nodes.
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}
};
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		if (!root) return 0;
		int res = INT_MAX;
		stack<TreeNode*> stk;
		TreeNode *cur = root, *pre = nullptr;
		while (cur || !stk.empty()) {
			while (cur) {
				stk.push(cur);
				cur=cur->left;
			}
			cur = stk.top(), stk.pop();
			if (pre) res = min(res, abs(cur->val-pre->val));
			pre = cur, cur = cur->right;
		}
		return res;
	}
};
int main(){
	TreeNode n2(2), n3(5, &n2, nullptr), n1(1, nullptr, &n3);
	Solution s;
	cout << s.getMinimumDifference(&n1) << endl;
}
