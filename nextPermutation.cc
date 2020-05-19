/* https://leetcode.com/problems/next-permutation/ */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, sz=nums.size();				//	  b
		for (i=sz-2; i>=0; --i)				//         rr (1213)
			if (nums[i] < nums[i+1]) break;		// e.g., 1231 -> 1312
		std::reverse(nums.begin()+i+1, nums.end());
		if (i==-1) return;	// we're done
		auto it = std::upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
		std::swap(nums[i], *it);
	}
	void nextPermutation2(vector<int>& nums) {
		int i,k=-1,l=-1;
		for (i=nums.size()-2;i>=0;--i) {
			// backward search the 1st non-reverse order digit (accending)
			if (nums[i] < nums[i+1]) {
				k=i;
				break;
			}
		}
		if (k==-1) {
			std::reverse(nums.begin(), nums.end());
			return;
		}
		for (i=nums.size()-1; i>=0; --i) {
			if (nums[i] > nums[k]) {
				l = i;
				break;
			}
		}
		std::swap(nums[k], nums[l]);
		std::reverse(nums.begin()+k+1, nums.end());
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,2,3,1};
	s.nextPermutation(nums1);
	for (auto x: nums1) cout << x << " ";
	cout << endl;
	vector<int> nums2{1,2,1,5,4,3,3,2,1};
	s.nextPermutation(nums2);
	for (auto x: nums2) cout << x << " ";
	cout << endl;
}
