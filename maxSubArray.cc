/* https://leetcode.com/problems/maximum-subarray/description/
 DP, Kadane's Algorithm, divide-and-conquer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	int helper(vector<int>& nums, int lo, int hi) {
		if (lo>hi) return INT_MIN;
		int mi=lo+(hi-lo)/2;
		int L = helper(nums, lo, mi-1);
		int R = helper(nums, mi+1, hi);
		int i, lmax, rmax, sum;
		for (i=mi-1, sum=0, lmax=0; i>=lo; --i) {	// backward calculate max suffix
			sum+=nums[i];
			lmax = max(lmax, sum);
		}
		for (i=mi+1, sum=0, rmax=0; i<=hi; ++i) {	// forward calculate max prefix
			sum+=nums[i];
			rmax = max(rmax, sum);
		}
		return max(lmax+nums[mi]+rmax, max(L, R));
	}
public:
	int maxSubArray3(vector<int>& nums) {
		return helper(nums, 0, nums.size()-1);
	}
	int maxSubArray(vector<int>& nums, int k) {
		int cum=0, res=0;
		set<int> s;
		s.insert(0);
		for (int i=0; i<nums.size(); ++i) {
			cum+=nums[i];
			auto it=s.upper_bound(cum-k);
			if (it!=end(s)) res=max(res, cum-*it);
			s.insert(cum);
		}
		return res;
	}
	// Kadane's algo, O(n) time, O(1) space (Jay Kadane of Carnegie Mellon University (Bentley 1984))
	int maxSubArray2(vector<int>& nums) {
		int cur=nums[0], res=nums[0];		// 1: tweak 1 and 2 have different flavor
		for (int i=1; i<nums.size(); ++i) {
			cur=max(nums[i]+cur, nums[i]);	// 2: calculate max-end-here
			//cur=max(nums[i]+cur, 0);	// 2: this allows 0-len subarray considering negative elem
			res=max(res, cur);		//    calculate max-so-far
		}
		return res;
	}
	// f(i) = max(f(i-1)+nums[i], nums[i])
	int maxSubArray1(vector<int>& nums) {
		int i, n=nums.size();
		vector<int> sums(n, 0);
		sums[0]=nums[0];
		for (i=1; i<n; ++i) {
			sums[i] = std::max(sums[i-1]+nums[i], nums[i]);
		}
		return *max_element(sums.begin(), sums.end());
	}
	// Brute-force
	int maxSubArray(vector<int>& nums) {
		int i,j,sum,n=nums.size(), res=nums[0];
		for (i=0; i<n; ++i) {		// start index
			sum=0;
			for (j=i; j<n; ++j) {	// evaluate all sub-arr since the above start
				sum+=nums[j];
				res=max(res, sum);
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};	// 6: 4,-1,2,1
	cout << s.maxSubArray(nums) << ": " << s.maxSubArray(nums, 4) << endl;
	vector<int> nums1{-1,-2,-3};
	cout << s.maxSubArray(nums1) << ": " << s.maxSubArray2(nums1) << endl;
	vector<int> nums2{-2,1};
	cout << s.maxSubArray(nums2) << ": " << s.maxSubArray2(nums2) << endl;
}
