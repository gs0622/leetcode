/* https://leetcode.com/problems/kth-largest-element-in-an-array/description/
array, sort, select
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	int partition(vector<int>& nums, int lo, int hi) {
		int i=lo, j=hi+1;
		int pivot=nums[lo];
		while (true) {
			while (nums[++i] > pivot)
				if (i==hi) break;
			while (nums[--j] < pivot)
				if (j==lo) break;	// redundant since [lo] acts as sentinel
			if (i>=j) break;		// cross
			swap(nums[i], nums[j]);
		}
		swap(nums[lo], nums[j]);
		return j;
	}
public:
	int findKthLargest2(vector<int>& nums, int k) {
		int lo=0, hi=nums.size()-1;
		while (lo < hi) {
			auto it = std::partition(begin(nums)+lo, begin(nums)+hi,	// [hi] as pivot, decending order
				[&nums,&hi](int n){ return n>nums[hi]; });
			auto i = distance(begin(nums), it);
			swap(nums[i], nums[hi]);

			if (i < k-1) lo=i+1;
			else if (i > k-1) hi=i-1;
			else return nums[i];
		}
		return nums[lo];
	}
	int findKthLargest1(vector<int>& nums, int k) {
		int lo=0, hi=nums.size()-1;
		while (lo < hi) {
			int i = partition(nums, lo, hi);
			if (i > k-1) hi = i-1;
			else if (i < k-1) lo = i+1;
			else return nums[i];
		}
		return nums[lo];
	}
	int findKthLargest(vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end(), std::greater<int>());
		return nums[k-1]; // kth large, index from 1
	}
};
int main(){
	Solution s;
	vector<int> nums1{2,1};
	cout << s.findKthLargest(nums1,2) << ": " << s.findKthLargest2(nums1,2) << endl;
	vector<int> nums2{3,2,1,5,6,4};
	cout << s.findKthLargest(nums2,3) << ": " << s.findKthLargest2(nums2,3) << endl;
}
