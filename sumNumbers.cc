/* https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
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
public:
	int sumNumbers1(TreeNode* root) {
		function<int(TreeNode*,int)> helper=[&](TreeNode* cur, int sum) {
			if (!cur) return 0;
			if (!cur->left && !cur->right) return sum*10+cur->val;
			return helper(cur->left, sum*10+cur->val) + helper(cur->right, sum*10+cur->val);
		};
		return helper(root,0);
	}
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		int sum=0;
		vector<int> nums;
		function<void(TreeNode*)> helper=[&](TreeNode* cur) {
			if (!cur) return;
			nums.push_back(cur->val);
			if (!cur->left && !cur->right) {
				int cum=0;
				for (int i=0; i<nums.size(); ++i)
					cum=cum*10+nums[i];
				sum+=cum;
				nums.pop_back();
				return;
			}
			helper(cur->left);
			helper(cur->right);
			nums.pop_back();
		};
		helper(root);
		return sum;
	}
};
int main(){
	TreeNode n1(4),n2(9),n3(0),n4(5),n5(1);
	n1.left=&n2,n1.right=&n3,n2.left=&n4,n2.right=&n5;
	Solution s;
	cout << s.sumNumbers1(&n1) << endl;
}
