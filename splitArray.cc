/* https://leetcode.com/problems/split-array-largest-sum/description/
 410. Split Array Largest Sum

Given an array which consists of non-negative integers and an integer m,
you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int sum = accumulate(begin(nums), end(nums), 0);
		int max = *max_element(begin(nums), end(nums));
		if (m==1) return sum;

		function<bool(int,int)> valid = [&](int target, int m) {
			int cnt=1, sum=0;
			for (int n: nums) {
				sum+=n;			// partial sum
				if (sum>target) {	// partial > split sum, cnt+=1
					sum=n,++cnt;
					if (cnt>m) return false;	// target too small, need more than m splits
				}
			}
			return true;	// m split capable in terms of target sum
		};
		int lo=max, hi=sum;
		//int lo=nums[0], hi=sum;	// wrong: description requires a minimized largest sum, see 2nd test case
		while (lo<=hi) {
			int mi=lo+(hi-lo)/2;	// target partial sum
			if (valid(mi, m))	// transform mi into m split capable false/true search space
				hi=mi-1;
			else
				lo=mi+1;
		}
		return lo;
	}
};
int main(){
	Solution s;
	vector<int> nums1{7,2,5,10,8};
	cout << s.splitArray(nums1, 2) << endl;
	vector<int> nums2{1,2147483647};
	cout << s.splitArray(nums2, 2) << endl;
}
