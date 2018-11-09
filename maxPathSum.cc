/* post-order
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	int maxSum;
	int findMax(TreeNode* root) {
		if (!root) return 0;
		int L = findMax(root->left); 
		int R = findMax(root->right);
		int v = root->val;
		maxSum = std::max(v+L+R, maxSum);	// global max
		int r = v + std::max(L, R);		// this max
		return (r > 0)? r: 0;			// cut if negative
	}
	int helper(TreeNode* root, int& res) {
		if (!root) return 0;
		int L = helper(root->left, res);
		int R = helper(root->right, res);
		res = max(res, L+R+root->val);		// global max
		int sum = root->val + max(L, R);	// current max
		return sum>0? sum: 0;			// cut < 0
	}
public:
	// wrong? inorder
	int maxPathSum2(TreeNode* root) {
		TreeNode *cur = root;
		stack<TreeNode*> stk;
		int res = 0;
		while (cur || !stk.empty()) {
			while (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top(), stk.pop();
			res = max(res, res+cur->val);
			cur = cur->right;
		}
		return res;
	}
	int maxPathSum1(TreeNode* root) {
		int res = INT_MIN;
		helper(root, res);
		return res;
	}
	int maxPathSum(TreeNode* root) {
		maxSum = INT_MIN;
		findMax(root);
		return maxSum;
	}
};

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(2), n5(3);
    n1.left = &n2, n1.right = &n3;
    //n2.left = &n4, n2.right = &n5;
    Solution s;
    cout << s.maxPathSum(&n1) << ": " << s.maxPathSum2(&n1) << endl;
    return 0;
}
