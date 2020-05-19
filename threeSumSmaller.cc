/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int threeSum2(vector<int>& nums, int target) {
		int i, j, k, n=nums.size(), res=0;
		for (i=0; i<n-2; ++i) {
			j=i+1, k=n-1;
			while (j<k) { // i is fixed
				if (nums[i]+nums[j]+nums[k]<target) res+=k-j, ++j;
				else --k;	// why --k but not ++j?
			}
		}
		return res;
	}
	// O(n^2)
	vector<vector<int>> threeSum1(vector<int>& nums, int target) {
		int n=nums.size();
		sort(nums.begin(), nums.end());	// O(nlogn)
		vector<vector<int>> res;
		for (int i=0; i<n-2; ++i) {
			int lo=i+1, hi=n-1;	// O(n)
			while (lo<hi) {		// two-pointer, O(n)
				if (nums[i]+nums[lo]+nums[hi]<target) {
					res.push_back({nums[i],nums[lo],nums[hi]});
					while (lo<hi && nums[lo]==nums[lo+1]) ++lo;
					while (lo<hi && nums[hi]==nums[hi-1]) --hi;
				}
				--hi;	// why --hi is better, why ++lo is wrong? think about < target and nums are sorted in accending
				//++lo;
			}
		}
		return res;
	}
	// Brute-force
	vector<vector<int>> threeSum(vector<int>& nums, int target) {
	//int threeSum(vector<int>& nums, int target) {
		int i, j, k, n=nums.size();
		sort(begin(nums), end(nums));
		vector<vector<int>> res;
		set<pair<pair<int,int>,int>> set;
		for (i=0; i<n; ++i)
			for (j=i+1; j<n; ++j)
				for (k=j+1; k<n; ++k) {
					if (nums[i]+nums[j]+nums[k]<target) {
						set.insert(make_pair(make_pair(nums[i],nums[j]), nums[k]));
					}
				}
		for (auto x: set) res.push_back({x.first.first, x.first.second, x.second});
		return res;
		//return res.size();
	}
};

int main(void)
{
	Solution s;
	vector<int> nums{-2,1,0,1,3};
	//cout << s.threeSum(nums, 2) << endl;
	for (auto list: s.threeSum1(nums, 2)) {
		for (auto n: list)cout << n << " ";
		cout << endl;
	}
}

