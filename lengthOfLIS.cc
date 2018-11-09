/*
DP, LIS (Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(nlog(n)), https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
	int lengthOfLIS(vector<int>& nums) {
		vector<int> ans;
		for (int i=0; i<nums.size(); ++i) {
			auto it = std::lower_bound(ans.begin(), ans.end(), nums[i]);
			if (it == ans.end()) ans.push_back(nums[i]); // append
			else *it = nums[i]; // replace
		}
		return ans.size();
	}
	// O(n^2) DP
	int lengthOfLIS2(vector<int>& nums) {
		int i, j, sz = nums.size(), res=0;
		vector<int> LIS(sz, 1);
		for (i=1; i<sz; ++i) {			// max ending here
			for (j=0; j<i; ++j) {		// evaluate from 0 to i-1
				if (nums[i] > nums[j]) {
					LIS[i] = max(LIS[i], LIS[j]+1);
					res = max(res, LIS[i]);
				}
			}
		}
		//return (sz == 0)? 0: *std::max_element(LIS.begin(), LIS.end());
		return res;
	}
};
int main(){
	vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
	Solution s;
	cout << s.lengthOfLIS(nums) << endl;
	cout << s.lengthOfLIS2(nums) << endl;
}
