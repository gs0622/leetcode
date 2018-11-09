/* https://leetcode.com/problems/subtree-of-another-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left, *right;
};

class Solution {
private:
	// O(t), top-down, preorder
	bool isMatch(TreeNode *a, TreeNode *b) {
		if (!a || !b) return (a == b); // both null returns true
		return (a->val == b->val &&
			isMatch(a->left, b->left) &&
			isMatch(a->right, b->right));
    }
public:
	/* O(s*t) */
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isMatch(s, t)) return true;
		if (!s) return false;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};

int main(void) {
    struct TreeNode ss[7]= {{3,0,0}, {4,0,0}, {1,0,0}, {2,0,0}, {5,0,0}, {0,0,0}};
    struct TreeNode tt[7]= {{4,0,0}, {1,0,0}, {2,0,0}};
    struct TreeNode *s = &ss[0];
    struct TreeNode *t = &tt[0];
    s->left = &ss[1], s->right = &ss[4];
    s->left->left = &ss[2], s->left->right = &ss[3];
    t->left = &tt[1];
    t->right = &tt[2];
    Solution so;
    bool r = so.isSubtree(s, t);
    cout << r << endl;
    return 0;
}
