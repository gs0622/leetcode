#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};
class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if ((root1==nullptr && root2) || (root1 && root2==nullptr)) return false;
		else if (root1!=nullptr) {	// root2!=nullptr as well
			return (root1->val == root2->val) && (
				(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
				(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
		} else return true;		// root1==root2==nullptr
	}
};
int main(){
	Solution s;
	TreeNode n8(8), n7(7), n6(6), n5(5,&n7,&n8), n4(4), n3(3,&n6,nullptr), n2(2,&n4,&n5), n1(1,&n2,&n3);
	TreeNode m8(8), m7(7), m6(6), m5(5,&m7,&m8), m4(4), m3(3,&m6,nullptr), m2(2,&m4,&m5), m1(1,&m3,&m2);
	cout << s.flipEquiv(&n1,&m1) << endl;
}
