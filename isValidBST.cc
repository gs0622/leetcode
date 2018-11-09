/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <climits>
#include <cstddef>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool validate(TreeNode *root, long long min, long max) {
		if (!root) return true;
		int val = root->val;
		if (val <= min || val >= max) return false;
		// val > min && val < max
		return validate(root->left, min, val) &&
			validate(root->right, val, max);
    }
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		// watch the boundry (min, max) of int. 
		return validate(root, LLONG_MIN, LLONG_MAX);
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
