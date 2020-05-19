/* https://leetcode.com/problems/permutations-ii/description/

#backtracking
#dfs
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	vector<int> nextPermutation(vector<int> nums) {
		int i, sz=nums.size();
		for (i=sz-2; i>=0; --i) {
			// backward search the 1st non-reverse order digit
			if (nums[i] < nums[i+1]) break;
		}
		std::reverse(nums.begin()+i+1, nums.end());
		if (i==-1) return nums;
		auto it = std::upper_bound(nums.begin()+i+1, nums.end(), nums[i]);	// swim up to archive 'next'
		swap(nums[i], *it);
		return nums;
	}
public:
	vector<vector<int>> permuteUnique1(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		do {
			res.push_back(tmp);
		} while (next_permutation(tmp.begin(), tmp.end()));
		return res;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> ret = nextPermutation(nums);
		ans.push_back(ret);
		while (ret != nums) {
			ret = nextPermutation(ret);
			ans.push_back(ret);
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,1,2};
	vector<vector<int>> r;
	r = s.permuteUnique(nums);
	for (auto x: r) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
	cout << endl;
	r = s.permuteUnique1(nums);
	for (auto x: r) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
