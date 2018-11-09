/**
 * https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Given an array where elements are sorted in ascending order, convert it to a height
 * balanced BST.
 * Definition for a binary tree node.
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
	// inorder
	TreeNode* sortedArrayToBST1(vector<int>& nums, int& i, int lo, int hi) {
		if (lo > hi) return nullptr;
		int mi = lo + (hi-lo)/2;
		TreeNode *left = sortedArrayToBST1(nums, i, lo, mi-1);
		TreeNode *root = new TreeNode(nums[i]);
		++i;
		root->left = left;
		root->right = sortedArrayToBST1(nums, i, mi+1, hi);
		return root;
	}
	// O(n) time, O(log(n)) space, binary search, preorder.
	TreeNode* sortedArrayToBST(vector<int>& nums, int lo, int hi) {
		if (hi < lo) return nullptr;
		int mi = lo + (hi - lo) / 2;
		TreeNode *p = new TreeNode(nums[mi]);
		p->left = sortedArrayToBST(nums, lo, mi - 1);
		p->right = sortedArrayToBST(nums, mi + 1, hi); 
		return p;
	}
public:
	// dfs
	int maxDepth(TreeNode *root) {
		if (!root) return 0;
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		if (abs(L-R) > 1) return -1;
		return 1+max(L, R);	
	}
	bool isBalanced(TreeNode *root) {
		return maxDepth(root) != -1;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		//return sortedArrayToBST(nums, 0, nums.size() - 1);
		int i=0;
		return sortedArrayToBST1(nums, i, 0, nums.size() - 1);
	}
};

int main() {
	vector<int> nums{1,2,3,4,5,6,7,8};
	Solution s;
	TreeNode *p = s.sortedArrayToBST(nums);
	//cout << p->val << endl;
	cout << s.isBalanced(p) << endl;
}

