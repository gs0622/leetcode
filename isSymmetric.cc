#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		function<bool(TreeNode*,TreeNode*)> isEqual=[&](TreeNode* p, TreeNode* q) {
			if (!p || !q) return p==q;
			return p->val == q->val && isEqual(p->left, q->right) && isEqual(p->right, q->left);
		};
		return isEqual(root->left, root->right);
	}
};
int main(){
	TreeNode n7(3),n6(4),n5(4),n4(3),n3(2,&n6,&n7),n2(2,&n4,&n5),n1(1,&n2,&n3);
	Solution s;
	cout << s.isSymmetric(&n1) << endl;
}
