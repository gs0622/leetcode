#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
class Solution {
public:
	int rob2(TreeNode* root) {
		unordered_map<TreeNode*,int> mp;
		function<int(TreeNode*)> helper=[&](TreeNode* cur) {
			if (!cur) return 0;
			if (mp.count(cur)) return mp.find(cur)->second;
			int val=0;
			if (cur->left) val+=helper(cur->left->left)+helper(cur->left->right);
			if (cur->right) val+=helper(cur->right->left)+helper(cur->right->right);
			val=max(val+cur->val, helper(cur->left)+helper(cur->right));
			mp[cur]=val;
			return val;
		};
		return helper(root);
	}
	int rob1(TreeNode* root) {
		function<vector<int>(TreeNode*)> dfs=[&](TreeNode* cur){
			if (!cur) return vector<int>{0,0};
			auto L=dfs(cur->left), R=dfs(cur->right);
			int sumA=L[0]+R[0]+cur->val;	// cur + grandchilds
			int sumB=L[1]+R[1];		// childs
			return vector<int>{sumB, max(sumA,sumB)};
		};
		return dfs(root)[1];
	}
	int rob(TreeNode* root) {
		if (!root) return 0;
		int val=0;
		if (root->left) val+=rob(root->left->left) + rob(root->left->right);
		if (root->right) val+=rob(root->right->left) + rob(root->right->right);
		return max(val+root->val,rob(root->left)+rob(root->right));
	}
};
int main(){
	Solution s;
	TreeNode n5(1),n4(3),n3(3,0,&n5),n2(2,0,&n4),n1(3,&n2,&n3);
	cout << s.rob(&n1) << endl;
	cout << s.rob1(&n1) << endl;
	cout << s.rob2(&n1) << endl;
	
}
