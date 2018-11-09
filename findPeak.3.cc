/* https://leetcode.com/problems/find-peak-element/description/
A peak element is an element that is greater than its neighbors.

Given an input array nums, where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.

# binary search
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	int helper(vector<int>& nums, int lo, int hi) {
		if (lo==hi) return lo;
		int mi=lo+(hi-lo)/2;
		if (nums[mi]>nums[mi+1])
			return helper(nums, lo, mi);
		else
			return helper(nums, mi+1, hi);
	}
public:
	int findPeakElement4(vector<int>& nums) {
		function<int(int,int)> bsearch = [&](int lo, int hi){
			if (lo==hi) return lo;
			int mi=lo+(hi-lo)/2;
			if (nums[mi]<nums[mi+1]) return bsearch(mi+1,hi);	// accending
			else return bsearch(lo,mi);				// decending
		};
		return bsearch(0, nums.size()-1);
	}
	// O(log(n)) search for invariant
	int findPeakElement2(vector<int>& nums) {
		return helper(nums, 0, nums.size()-1);
	}
	// O(log(n)) search for invariant
	int findPeakElement1(vector<int>& nums) {
		if (nums.size()==1) return 0;
		int mi, lo=0, hi=nums.size()-1;
		while (lo<hi) {
			mi = lo+(hi-lo)/2;
			if (nums[mi]<nums[mi+1])	// accending
				lo=mi+1;
			else
				hi=mi;
		}
		return lo;
	}
	// O(n) smarter linear scan to find a local peak
	int findPeakElement(vector<int>& nums) {
		//if (nums.size()<2) return 0;
		for (int i=1; i<nums.size(); ++i)
			if (nums[i]<nums[i-1]) return i-1;
		return nums.size()-1;
	}
	// O(n) linar scan all and keep max
	int findPeakElement3(vector<int>& nums) {
		int max = 0;
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i]>nums[max]) max = i;
		}
		return max;
	}
};
void test(vector<int> nums);
void test1() { vector<int> nums{1}; test(nums); }	// 1
void test2() { vector<int> nums{1,2,3,1}; test(nums); }	// 3
void test3() { vector<int> nums{1,2}; test(nums); }	// 2
void test4() { vector<int> nums{2,1}; test(nums); }	// 2
int main(){
	test1();
	test2();
	test3();
	test4();
}
void test(vector<int> nums){
	Solution s;
	cout << s.findPeakElement(nums) << ": ";
	cout << s.findPeakElement1(nums) << ": ";
	cout << s.findPeakElement2(nums) << ": ";
	cout << s.findPeakElement4(nums) << endl;
}
