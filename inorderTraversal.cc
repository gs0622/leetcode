#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	void inorder(TreeNode *cur, vector<int>&res) {
		if (!cur) return;
		inorder(cur->left, res);
		res.push_back(cur->val);
		inorder(cur->right, res);
	}
public:
	vector<int> inorderTraversal1(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return {};
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode *cur = root;
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur=cur->left;
			}
			cur=s.top();
			s.pop();
			res.push_back(cur->val);
			cur=cur->right;
		}
		return res;
	}
};
int main(){
	Solution s;
	TreeNode n0(2);
	TreeNode n1(1);
	TreeNode n2(3);
	n0.left=&n1, n0.right=&n2;
	vector<int> res = s.inorderTraversal1(&n0);
	copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
	cout << endl;
}
