/* https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.
A node is deepest if it has the largest depth possible among any node in the entire tree.
The subtree of a node is that node, plus the set of all descendants of that node.
Return the node with the largest depth such that it contains *all* the deepest nodes in it's subtree.


 hint: LCA, maxDepth of binary tree
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
class Solution {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if (!root) return nullptr;
		function<int(TreeNode*)> maxDepth=[&](TreeNode* cur) {
			if (!cur) return 0;
			return 1+max(maxDepth(cur->left),maxDepth(cur->right));
		};
		int left=maxDepth(root->left), right=maxDepth(root->right);
		if (left==right) return root;
		else if (left>right) return subtreeWithAllDeepest(root->left);
		else return subtreeWithAllDeepest(root->right);
	}
};
int main(){
	TreeNode n9(4),n8(7),n7(8),n6(0),n5(2,&n8,&n9),n4(6),n3(1,&n6,&n7),n2(5,&n4,&n5),n1(3,&n2,&n3);
	Solution s;
	TreeNode* res = s.subtreeWithAllDeepest(&n1);
	cout << res->val << endl;
}
