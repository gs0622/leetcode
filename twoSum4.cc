#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool dfs(TreeNode* root, int k, unordered_set<int>& s) {
		if (!root) return false;
		if (s.count(k - root->val))
			return true;
		s.insert(root->val);
		return dfs(root->left, k, s) || dfs(root->right, k, s);

	}
	void inorder(TreeNode *cur, vector<int>& nums) {
		if (!cur) return;
		inorder(cur->left, nums);
		nums.push_back(cur->val);
		inorder(cur->right, nums);
	}
public:
	bool findTarget1(TreeNode* root, int k) {
		vector<int> nums;
		inorder(root, nums); // get sorted array
		int lo=0, hi=nums.size()-1;
		while (lo<hi) {
			int sum = nums[lo]+nums[hi];
			if (sum < k) ++lo;
			else if (sum > k) --hi;
			else return true;
		}
		return false;
	}
	// O(n) dfs
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> s;
		return dfs(root, k, s);
	}
};

int main(){
	Solution s;
	TreeNode n0(5);
	TreeNode n1(3);
	TreeNode n2(6);
	TreeNode n3(2);
	TreeNode n4(4);
	TreeNode n5(7);
	n0.left=&n1, n0.right=&n2, n1.left=&n3, n1.right=&n4, n2.right=&n5;
	cout << s.findTarget1(&n0, 9) << endl;
}
