/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
private:
	TreeNode *prev; // inorder previous node
	bool inorderMonotonicIncrease(TreeNode *root) {
		if (!root) return true;
		if (inorderMonotonicIncrease(root->left)) { // true then right
			if (prev && root->val <= prev->val) return false;
			prev = root; // visit
			return inorderMonotonicIncrease(root->right);
		}
		return false; // left isn't BST
	}
	bool inorderHelper(TreeNode *root, TreeNode* &prev) {
		if (!root) return true;
		if (inorderHelper(root->left, prev)) {
			if (prev && root->val <= prev->val) return false;
			prev = root;
			return inorderHelper(root->right, prev);
		}
		return false;
	}
public:
	bool isValidBST(TreeNode* root) {		// Q: what about empty list?
		if (!root) return true;
		stack<TreeNode*> s;
		TreeNode *pre = nullptr;
		while (root || !s.empty()) {
			while (root) {			// go left down to the bottom
				s.push(root);
				root = root->left;
			}
			root = s.top(), s.pop();	// the leftest
			if (pre && root->val <= pre->val)
				return false;
			pre = root;
			root = root->right;		// go right
		}
		return true;
	}
	bool isValidBST1(TreeNode* root) {
		TreeNode *prev = nullptr;
		return inorderHelper(root, prev);
	}
};

bool test1(void) {
    TreeNode n0(10), n1(5), n2(16), n3(6), n4(20);
    n0.left = &n1, n0.right = &n2;
    n2.left = &n3, n2.right = &n4;
    Solution s;
    cout << s.isValidBST(&n0) << endl;
}
bool test2(void) {
    TreeNode n0(2), n1(1), n2(3);
    n0.left = &n1, n0.right = &n2;
    Solution s;
    cout << s.isValidBST(&n0) << endl;
}
int main(void) {
    test1();
    test2();
    return 0;
}
