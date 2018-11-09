/* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
	// in:  {9,3,15,20,7};
	// post:{9,15,7,20,3}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int,int> inord;
		for (int i=0; i<inorder.size(); ++i)	// build map of inorder val to its idx
			inord[inorder[i]]=i;

		function<TreeNode*(int,int,int)> helper = [&](int post, int lo, int hi){
			if (lo>hi) return (TreeNode*)nullptr;		// note: without casting it crashes the compilier
			int v = postorder[post], id = inord[v];
			TreeNode *root = new TreeNode(v);
			root->right = helper(post-1, id+1, hi);		// tricky: go right in terms of post order
			root->left = helper(post-(hi-id)-1, lo, id-1);	// tricky: think why left subtree in post-(hi-id)-1 
			return root;
		};

		return helper(inorder.size()-1, 0, inorder.size()-1);
	}
};
int main(){
	Solution s;
	vector<int> inord{9,3,15,20,7}, postord{9,15,7,20,3};
	TreeNode *p;
	p = s.buildTree(inord, postord);
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
