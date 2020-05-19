/* https://leetcode.com/problems/permutations/description/

Given a collection of distinct integers, return all possible permutations.
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
	vector<vector<int>> permute3(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		do {
			res.push_back(tmp);
		} while (next_permutation(tmp.begin(), tmp.end()));
		return res;
	}
	vector<vector<int>> permute2(vector<int>& nums) {
		vector<int> tmp=nums;
		vector<vector<int>> res;
		int n=nums.size();
		function<void(int)> helper=[&](int i) {
			if (i+1==n) {
				res.push_back(tmp);
				return;
			}
			for (auto j=i; j<n; ++j) {
				swap(tmp[i],tmp[j]);	// don't care i==j
				helper(i+1);
				swap(tmp[i],tmp[j]);
			}
		};
		helper(0);
		return res;
	}
	vector<vector<int>> permute1(vector<int>& nums) {
		vector<int> tmp=nums;
		vector<vector<int>> res(1,tmp);
		next_permutation(begin(tmp), end(tmp));
		while (tmp!=nums) {
			res.push_back(tmp);
			next_permutation(begin(tmp), end(tmp));
		}
		return res;
	}
	vector<vector<int>> permute(vector<int>& nums) {
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
	//vector<int> nums{3,2,1};
	vector<vector<int>> res;
	res = s.permute(nums);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
	cout << endl;
	res = s.permute3(nums);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
