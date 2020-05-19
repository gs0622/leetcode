/* https://leetcode.com/problems/first-missing-positive/description/
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums){
		int i, n=nums.size();
		for (i=0; i<n; ++i)
			while (nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
				swap(nums[i], nums[nums[i]-1]); // put into bucket
		for (i=0; i<n; ++i)
			if (nums[i]!=i+1) return i+1;
		return n+1;
	}
	// wrong approach
	int firstMissingPositive1(vector<int>& nums){
		unordered_set<int> sets;
		int min = INT_MAX;
		for (auto n: nums) {
			if (n>=0) min = std::min(min, n);
			sets.insert(n);
		}
		if (min<0) min=0;
		for (int i=min; i<min+nums.size(); ++i)
			if (sets.count(i)==0) return i;
		return min+nums.size();
	}
};
int main(){
	Solution s;
	//vector<int> nums1{1,2,0};
	//cout << s.firstMissingPositive(nums1) << endl;
	//vector<int> nums2{3,4,-1,1};
	//cout << s.firstMissingPositive(nums2) << endl;
	vector<int> nums3{-1,4,2,1,9,10};
	cout << s.firstMissingPositive(nums3) << endl;
}
