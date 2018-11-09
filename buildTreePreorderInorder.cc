/* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

in short, build root w/ preorder val along w/ inoder indices to split left/right subtrees
*/
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
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
		unordered_map<int,int> inmap;
		for (int i=0; i<inorder.size(); ++i)	// val -> inorder idx map
			inmap[inorder[i]]=i;

		stack<TreeNode*> stk;
		TreeNode *root = new TreeNode(preorder[0]);
		stk.push(root);
		for (int i=1; i<preorder.size(); ++i) {
			TreeNode *cur = new TreeNode(preorder[i]);
			if (inmap[cur->val] < inmap[stk.top()->val]) {
				// tricky: think why this new node must be last one's left child, hint: preorder
				stk.top()->left = cur;
			} else {
				TreeNode *parent;
				while (!stk.empty() && inmap[cur->val] > inmap[stk.top()->val]) {
					// flush out left subtree until cur's parent, in terms of inorder index still less then cur
					parent = stk.top(), stk.pop();
				}
				parent->right = cur;
			}
			stk.push(cur);
		}
		return root;
	}
	// pre: {3,9,20,15,7}
	// in:  {9,3,15,20,7};
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		unordered_map<int,int> inord;
		for (int i=0; i<inorder.size(); ++i)	// build map of inorder val to its idx
			inord[inorder[i]]=i;
		// preorder to build nodes, inorder to split left/right subtrees
		function<TreeNode*(int,int,int)> helper = [&](int pre, int lo, int hi){
			if (lo>hi) return (TreeNode*)nullptr;		// note: without casting it crashes the compilier
			int v = preorder[pre], id = inord[v];
			TreeNode *root = new TreeNode(v);
			root->left = helper(pre+1, lo, id-1);
			root->right = helper(pre+(id-lo)+1, id+1, hi); // tricky: think about why "pre+(id-lo)+1", left subtree size+1
			return root;
		};

		return helper(0, 0, inorder.size()-1);
	}
};
int main(){
	Solution s;
	//vector<int> preord{3,9,20,15,7}, inord{9,3,15,20,7};
	vector<int> preord{7,10,4,3,1,2,8,11}, inord{4,10,3,1,7,11,8,2};
	TreeNode *p;
	p = s.buildTree1(preord, inord);
	queue<TreeNode*> q;
	q.push(p);
	while (!q.empty()) {
		int n = q.size();
		for (int i=0; i<n; ++i) {
			TreeNode *cur = q.front(); q.pop();
			cout << cur->val << ' ';
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
		cout << endl; // level end
	}
}
