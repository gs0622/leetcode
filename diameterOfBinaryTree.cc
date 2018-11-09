#include <bits/stdc++.h>
using namespace std;
/*
		1        L = 3
	       2 3       R = 1
	      4 5
*/
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}
};
class Solution {
	// diameter: edges along path
	int diameterOfBinaryTree(TreeNode* root, int &diameter) {
		if (!root) return 0;
		int L = diameterOfBinaryTree(root->left, diameter);
		int R = diameterOfBinaryTree(root->right, diameter);
		diameter = max(diameter, L+R); // from L to R diameter, L+R
		return 1+max(L, R);
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		diameterOfBinaryTree(root, diameter);
		return diameter;
	}
};
int main(){
	TreeNode n4(4), n5(5), n2(2, &n4, &n5), n3(3), n1(1, &n2, &n3);
	Solution s;
	cout << s.diameterOfBinaryTree(&n1) << endl;
}
