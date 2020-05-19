/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // O(n^2) brute-force
	int maxSubArrayLen(vector<int>& nums, int k) {
		int res=0,n=nums.size();
    for (int i=0;i<n;++i) {
      int sum=0;
      for (int j=i;j<n;++j) {
        sum+=nums[j];
        if (sum==k)
          res=max(res,j-i+1);
      }
    }
    return res;
  }
	int maxSubArrayLen1(vector<int>& nums, int k) {
		int res=INT_MIN, sum=0;
		unordered_map<int,int> pre{{0,0}};		// prefix sum: 0 for sum=k
		for (int i=1; i<=nums.size(); ++i) {
			sum+=nums[i-1];
			if (pre.find(sum-k) != pre.end())
				res=max(res, i-pre[sum-k]);
			if (pre.find(sum) == pre.end())		// keep the first to archive max window
				pre[sum]=i;
		}
		return res==INT_MIN? 0: res;
	}
};
class Solution {
public:
	int maxSubArrayLen2(vector<int>& nums, int k) {
		int res = 0, sum = 0;
		unordered_map<int,int> mp;
		for (int i=0; i<nums.size(); ++i) {
			sum += nums[i];
			if (sum == k) res = max(res, i+1);
			int diff = sum-k;
			if (mp.count(diff)) res = max(res, mp[diff]);
			if (!mp.count(sum)) mp[sum]=i;
		}
		return res;
	}
	// O(n)
	int maxSubArrayLen(vector<int>& nums, int k) {
		int res=INT_MIN, sum=0;
		unordered_map<int,int> pre{{0,0}};		// prefix sum: 0 for sum=k
		for (int i=1; i<=nums.size(); ++i) {
			sum+=nums[i-1];
			if (pre.find(sum-k) != pre.end())
				res=max(res, i-pre[sum-k]);
			if (pre.find(sum) == pre.end())		// keep the first to archive max window
				pre[sum]=i;
		}
		return res==INT_MIN? 0: res;
	}
	// O(n^3) brute-force
	int maxSubArrayLen1(vector<int>& nums, int k) {
		int res=INT_MIN;
		for (int i=0; i<nums.size(); ++i) {		// enumerate all [i..j] sub arrays
			for (int j=i+1; j<nums.size(); ++j) {
				if (k == accumulate(begin(nums)+i, begin(nums)+j, 0))
					res=max(res, j-i); // between i and j but not include j
			}
		}
		return res==INT_MIN? 0: res;
	}
};
int main(){
	Solution2 s;
	vector<int> nums0{1,-1,5,-2,0};
	cout << s.maxSubArrayLen(nums0, 3) << " " << s.maxSubArrayLen1(nums0, 3) << endl;
	vector<int> nums1{1,-1,5,-2,3};
	cout << s.maxSubArrayLen(nums1, 3) << " " << s.maxSubArrayLen1(nums1, 3) << endl;
	vector<int> nums2{2,-1,2,1};
	cout << s.maxSubArrayLen(nums2, 1) << " " << s.maxSubArrayLen1(nums2, 1) << endl;
	vector<int> nums3{2,-3,2,-3,2};
	cout << s.maxSubArrayLen(nums3, -1) << " " << s.maxSubArrayLen1(nums3, -1) << endl;
}
