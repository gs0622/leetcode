#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	void permutation(vector<int> nums, vector<vector<int>>& ans, int i) {
		int sz = nums.size();
		if (i==sz-1) {
			ans.push_back(nums);
			return;
		}
		for (int j=i; j<sz; ++j) {
			if (i!=j && nums[i]==nums[j]) continue; // skip dup permutations
			std::swap(nums[i], nums[j]);
			permutation(nums, ans, i+1);
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		std::sort(nums.begin(), nums.end()); // O(nlog(n))
		vector<vector<int>> ans;
		permutation(nums, ans, 0);
		return ans;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,1,2};
	vector<vector<int>> r = s.permuteUnique(nums);
	for (auto x: r) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
