/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root==p || root==q) return root;
		TreeNode* left = lowestCommonAncestor(root->left,p,q); // p/q/lcm are in left subtree
		TreeNode* right = lowestCommonAncestor(root->right,p,q);
		if (!left) return right;
		if (!right) return left;
		return root;
	}
};
int main(){}
