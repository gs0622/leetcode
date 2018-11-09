/* https://leetcode.com/problems/search-in-rotated-sorted-array/description/ */
#include <iostream>
#include <vector>
using namespace std;
/*
                /
           mi? /
              /
            lo       / hi               lo --------  ----- hi
                    /                               /
                   / mi?
*/
class Solution {
public:
	// O(log(n))
	int search(vector<int>& nums, int target) {
		int mi, lo=0, hi=nums.size()-1;
		while (lo < hi) {
			mi=lo+(hi-lo)/2;
			if (nums[mi]==target) return mi;
			if (nums[mi]>nums[hi]) { // mi must be smaller than hi
				if (target>=nums[lo] && nums[mi]>target) hi=mi;
				else lo=mi+1;
			} else {
				if (target<=nums[hi] && nums[mi]<target) lo=mi+1;
				else hi=mi;
			}
		}
		// lo==hi
		if (nums[lo]==target) return lo;
		else return -1;
	}
	int search2(vector<int>& nums, int target) {
		int mi, lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			mi = lo + (hi-lo)/2;
			if (nums[mi] == target) return mi;
			if (nums[lo] <= target && nums[mi] > target ||
				nums[hi] > nums[mi] && (nums[mi] > target || nums[hi] < target))
				hi = mi-1;
			else
				lo = mi+1;
		}
		return -1;
	}
	// O(log(n))
	int search3(vector<int>& nums, int target) {
		int mi, lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			mi = lo + (hi-lo)/2;
			if (nums[mi] == target) return mi;
			if (nums[lo] <= nums[mi]) {
				if (nums[lo] <= target && nums[mi] > target)
					hi = mi-1;
				else
					lo = mi+1;
			} else { // nums[lo] > nums[mi]
				if (nums[hi] >= target && nums[mi] < target)
					lo = mi+1;
				else
					hi = mi-1;
			}
		}
		return -1;
	}
	// O(log(n))
	int search4(vector<int>& nums, int target) {
		int off, mi, lo = 0, hi = nums.size()-1;
		while (lo < hi) {
			mi = lo + (hi-lo)/2;
			//if (nums[mi] == target) return mi;
			if (nums[mi] > nums[hi])
				lo = mi+1;
			else
				hi = mi;
		}
		off = lo; // offset of real min.
		lo = 0, hi = nums.size() - 1;
		while (lo <= hi) { // normal binary-search w/ offset
			mi = lo + (hi-lo)/2;
			int mi2 = (mi+off) % nums.size();
			if (target == nums[mi2]) return mi2;
			if (target > nums[mi2]) lo = mi+1;
			else hi = mi-1;
		}
		return -1;
	}
	// O(n) linear search
	int search5(vector<int>& nums, int target) {
		for (int i = 0; i != nums.size(); ++i) {
			if (nums[i] == target) return i;
		}
		return -1;
	}
};
void test(vector<int> nums, int target) {
	Solution s;
	cout << target << ": " << s.search(nums,target) << ": " << s.search2(nums,target) << endl;
}
int main(){
	vector<int> nums {4,5,6,7,0,1,2};
	Solution s;
	test(nums, 4);
	test(nums, 2);
	test(nums, 9);
	test(nums, 5);
	test(nums, 1);
	test(nums, 7);
	test(nums, 0);
}
