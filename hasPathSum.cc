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
	// dfs
	bool hasPathSum(TreeNode *root, int sum) {
		if (!root) return false;
		int v = root->val;
		if (v==sum && !root->left && !root->right) return true;
		return hasPathSum(root->left, sum-v) || hasPathSum(root->right, sum-v);
	}
};
int main(){
	TreeNode n9(1),n8(2),n7(7),n6(4,nullptr,&n9),n5(13),n4(11,&n7,&n8),n3(8,&n5,&n6),n2(4,&n4,nullptr),n1(5,&n2,&n3);
	TreeNode m2(2),m1(1,&m2,nullptr);
	Solution s;
	cout << s.hasPathSum(&n1, 22) << endl;
	cout << s.hasPathSum(&m1, 1) << endl;
}
