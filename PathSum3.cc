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
	// recursice DFS, O(n^2) in worst case
	int hasPathSum(TreeNode *root, int sum) {
		if (!root) return 0;
		function<int(TreeNode*,int)> helper=[&](TreeNode *cur, int target){
			if (!cur) return 0;
			int v=cur->val, res=(v==target)? 1: 0;
			res += helper(cur->left, target-v) + helper(cur->right, target-v);
			return res;
		};
		//     dfs		 + recursive dfs	       + recursive dfs
		return helper(root, sum) + hasPathSum(root->left, sum) + hasPathSum(root->right, sum);
	}
};
int main(){
	TreeNode n9(1),n8(-2),n7(3),n6(11),n5(2,nullptr,&n9),n4(3,&n7,&n8),n3(-3,nullptr,&n6),n2(5,&n4,&n5),n1(10,&n2,&n3);
	Solution s;
	cout << s.hasPathSum(&n1, 8) << endl;
}
