/* https://leetcode.com/problems/cousins-in-binary-tree/description/
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution2 {
public:
	// level order
	bool isCousins(TreeNode* root, int x, int y) {
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n=q.size(), hasx=0, hasy=0;
			for (int i=0; i<n; ++i) {
				auto cur = q.front(); q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				if (cur->left && cur->right) {
					if (cur->left->val==x && cur->right->val==y) return false;
					if (cur->left->val==y && cur->right->val==x) return false;
				}
				if (cur->val==x) hasx=1;
				if (cur->val==y) hasy=1;
			}
			if (hasx == 1 && hasy==1) return true;
		}
		return false;
	}
};
class Solution {
public:
	// level order
	bool isCousins(TreeNode* root, int x, int y) {
		queue<TreeNode*> q;
		unordered_map<int,pair<int,TreeNode*>> mp;
		q.push(root);
		mp[root->val]={0,nullptr};
		int dep = 0;
		while (q.size()) {
			int n=q.size();
			++dep;
			for (int i=0; i<n; ++i) {
				TreeNode* cur = q.front(); q.pop();
				if (cur->left) q.push(cur->left), mp[cur->left->val] = {dep, cur};
				if (cur->right) q.push(cur->right), mp[cur->right->val] = {dep, cur};
			}
			if (mp[x].first == mp[y].first && mp[x].second != mp[y].second) return true;	// save time a bit
		}
		//if (mp[x].first == mp[y].first && mp[x].second != mp[y].second) return true;
		return false;
	}
};
int main(){}
