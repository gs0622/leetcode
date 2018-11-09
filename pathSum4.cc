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
	int pathSum1(vector<int> nums) {
		TreeNode root(nums[0]%10);
		for (int i=1; i<nums.size(); ++i) {
			int dep=nums[i]/100, pos=(nums[i]/10)%10, val=nums[i]%10;
			--pos;
			TreeNode *cur=&root;
			for (int j=dep-2; j>=0; --j) {
				if (pos<(1<<j)) {
					//if (!cur->left)
						cur->left = new TreeNode(val);
					cur = cur->left;
				} else {
					//if (!cur->right)
						cur->right = new TreeNode(val);
					cur = cur->right;
				}
				pos %= 1<<j;
			}
		}
		int res=0;
		function<void(TreeNode*,int)> dfs=[&](TreeNode *cur, int sum) {
			if (!cur) return;
			sum+=cur->val;
			if (!cur->left && !cur->right)
				res += sum;
			dfs(cur->left, sum);
			dfs(cur->right, sum);
		};
		dfs(&root, 0);
		return res;
	}
	int pathSum(vector<int> nums) {
		unordered_map<int,int> mp;	// 10*dep+pos as key
		for (int n: nums)
			mp[n/10]=n%10;		// 10*dep+pos, val
		int res=0;
		function<void(int,int)> dfs=[&](int node, int sum) {
			if (!mp.count(node)) return;
			int dep=node/10, pos=node%10, left=(dep+1)*10+ (2*pos)-1, right=left+1;
			sum+=mp[node];
			if (!mp.count(left) && !mp.count(right)) {	// leaf
				res+=sum;
			} else {
				dfs(left, sum);
				dfs(right, sum);
			}
		};
		dfs(nums[0]/10, 0);
		return res;
	}
};
int main(){
	Solution s;
	// 3-digit, dep,pos,val
	vector<int> nums{113,215,221};
	cout << s.pathSum(nums) << endl;
	cout << s.pathSum1(nums) << endl;
}
