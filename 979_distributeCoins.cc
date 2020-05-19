#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};
class Solution {
public:
	//	3
	//    0   0
	int distributeCoins(TreeNode* root) {
		int res=0;
		function<int(TreeNode*)> helper=[&](TreeNode *cur) {	// resursive, bottom-up to re-distribute coins
			if (!cur) return 0;
			int left=helper(cur->left), right=helper(cur->right);
			res += abs(left)+abs(right);	// res+=steps
			return cur->val+left+right-1;	// given to the parent, +: give, -: need
		};
		helper(root);
		return res;
	}
};
int main(){}
