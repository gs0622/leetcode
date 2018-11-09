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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> res;
		TreeNode *cur = root;
		while (cur || !stk.empty()) {
			while (cur) {
				res.push_back(cur->val);
				stk.push(cur);
				cur = cur->left;	
			}
			cur = stk.top(), stk.pop();
			cur = cur->right;
		}
		return res;
	}
};
int main(){
	TreeNode n3(3), n2(2, &n3, nullptr), n1(1, nullptr, &n2);
	Solution s;
	vector<int> res = s.preorderTraversal(&n1);
	for_each(begin(res), end(res), [](int n){ cout << n << ' ';}), cout << endl;

	res = s.preorderTraversal(nullptr);
}
