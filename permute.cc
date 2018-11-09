/* https://leetcode.com/problems/permutations/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	void helper2(vector<int> &nums, int i, vector<vector<int>>& res) {
		if (i+1==nums.size()) {
			res.push_back(nums);
			return;
		}
		for (int j=i; j<nums.size(); ++j) {
			if (i!=j) swap(nums[i], nums[j]);
			helper2(nums, i+1, res);
			if (i!=j) swap(nums[i], nums[j]);
		}
	}
	void helper(vector<int> &nums, int i, vector<int>& perm, vector<vector<int>>& ans) {
		if (i+1==nums.size()) {
			ans.push_back(nums);
			return;
		}
		for (int j=i; j<nums.size(); ++j) {
			if (i!=j) swap(nums[i], nums[j]);
			helper(nums, i+1, perm, ans);
			if (i!=j) swap(nums[i], nums[j]);
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(begin(nums), end(nums)));
		return res;
	}
	vector<vector<int>> permute1(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> perm;
		//helper(nums, 0, perm, res);
		helper2(nums, 0, res);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,3};
	vector<vector<int>> r = s.permute(nums);
	for (auto x: r) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
