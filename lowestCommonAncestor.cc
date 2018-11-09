/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};
/*
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
 case 1:  p=0, q=4, root=6, root>p && root>q
 case 2:  p=7, q=9, root=6, root<p && root<q

*/
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return nullptr;
		if (root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q); // p/q/LCA are in left subtree
		if (root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
		return root;
	}
};
int main(){}
