#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
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
	// O(n^2) brute-force
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
	Solution s;
	vector<int> nums1{1,-1,5,-2,3};
	cout << s.maxSubArrayLen(nums1, 3) << " " << s.maxSubArrayLen1(nums1, 3) << endl;
	vector<int> nums2{2,-1,2,1};
	cout << s.maxSubArrayLen(nums2, 1) << " " << s.maxSubArrayLen1(nums2, 1) << endl;
}
