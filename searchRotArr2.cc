/* https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/ */
#include <iostream>
#include <vector>
using namespace std;
/*
		/
	   mi? /
              / 
            lo       / hi		lo --------  ----- hi
		    /			            /
		   / mi?
*/
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty()) return false;
		int lo=0, hi=nums.size()-1;
		while (lo<hi) {
			int mi=lo+(hi-lo)/2; 
			if (target == nums[mi]) return true;	// found
			if (nums[mi] > nums[lo]) {		// case 1
				if (target < nums[mi] && target >= nums[lo]) hi=mi;
				else lo=mi+1;
			} else if (nums[mi] < nums[lo]) {	// case 2
				if (target > nums[mi] && target <= nums[hi]) lo=mi+1;
				else hi=mi;
			} else ++lo;				// case 3
		}
		return nums[lo] == target;
	}
	bool search3(vector<int>& nums, int target) {
		int mi, lo=0, hi=nums.size()-1;
		while (lo<hi) {
			mi=lo+(hi-lo)/2;
			if (nums[mi]==target) return true;
			if (nums[mi] > nums[hi]) {
				if (nums[mi] > target && target >= nums[lo]) hi=mi;
				else lo = mi+1;
			} else if (nums[mi] < nums[hi]) {
				if (nums[mi] < target && target <= nums[hi]) lo=mi+1;
				else hi = mi;
			} else // nums[mi]==nums[hi]
				--hi;
		}
		return nums[lo]==target? true: false;
	}
	// wrong approach?
	bool search1(vector<int>& nums, int target) {
		int off=0, mi, n=nums.size(), lo=0, hi=n-1;
                while (lo < hi) {
                        mi = lo + (hi-lo)/2;
                        if (nums[mi] > nums[lo])
				lo = mi+1;
                        else if (nums[mi] < nums[lo])
				hi = mi;
                        else
				++lo;
                } // end while lo==hi
                off=lo, lo=0, hi=n-1;
                while (lo <= hi) {
                        mi = lo + (hi-lo)/2;
                        if      (target < nums[(mi+off)%n]) hi=mi-1;
                        else if (target > nums[(mi+off)%n]) lo=mi+1;
                        else return true; // bingo
                }
                return false;

	}
	bool search2(vector<int>& nums, int target) {
		for (int i=0; i<nums.size(); ++i)
			if (nums[i] == target) return true;
		return false;
	}
};
int main(){
	Solution s;
	//vector<int> nums1{4,5,6,7,0,1,2};
	//vector<int> nums1{2,2,2,0,2,2};
	vector<int> nums1{3,1,1};
	//vector<int> nums1{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	cout << s.search(nums1, 3) << " " << s.search3(nums1, 3) << endl;
	vector<int> nums2{3,5,1};
	cout << s.search(nums2, 1) << " " << s.search3(nums2, 1) << endl;
	//cout << s.search(nums1, 8) << " " << s.search2(nums1, 8) << endl;
}
