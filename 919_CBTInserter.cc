#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};
class CBTInserter {
	TreeNode *r;
	queue<TreeNode*> q;
public:
	// O(n)
	CBTInserter(TreeNode* root) {
		r = root, q.push(root);
		while (q.front()->left && q.front()->right) {	// node has 2 leaves
			q.push(q.front()->left), q.push(q.front()->right), q.pop();
		}
		// now queue is in one with single leaf node, or no-leaf one
	}
	// O(1) insert
	int insert(int v) {
		TreeNode* next = new TreeNode(v);
		TreeNode* cur = q.front();
		if (!cur->left)
			cur->left = next;
		else {
			cur->right = next;
			q.push(cur->left), q.push(cur->right), q.pop();
		}
		return cur->val;
	}
};
class CBTInserter1 {
	TreeNode *r;
public:
	// O(1)
	CBTInserter1(TreeNode* root) { r = root; }
	// O(n), level-order, BFS
	int insert(int v) {
		queue<TreeNode*> q;
		q.push(r);
		while (true) {	// Traverse the binary tree by level order
			TreeNode* cur=q.front(); q.pop();
			if (cur->left && cur->right) {
				q.push(cur->left), q.push(cur->right);
			} else {
				TreeNode *next = new TreeNode(v);
				if (!cur->left) cur->left = next;
				else cur->right = next;
				return cur->val;
			}
		}
	}
	TreeNode* get_root() { return r; }
};
int main(){
}
