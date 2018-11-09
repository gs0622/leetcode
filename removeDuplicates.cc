/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeDuplicates2(vector<int>& nums) {
		auto it = unique(begin(nums), end(nums)); // it: the last one not been removed, O(n)
		nums.resize(distance(begin(nums), it));
		return nums.size();
	}
	// two-pointer
	int removeDuplicates1(vector<int>& nums) {
		int i, j; // non-dup and dup pointers
		for (i=0, j=1; i<nums.size() && j<nums.size(); ++j) {
			if (nums[i]!=nums[j]) {
				++i;
				nums[i]=nums[j];
			}
		}
		nums.erase(nums.begin()+i+1, nums.end());
		//return i+1;
		return nums.size();
	}
	int removeDuplicates(vector<int>& nums) {
		for (int i=0, j=i+1; i<nums.size() && j<nums.size();) {
			if (nums[i]==nums[j]) {
				nums.erase(nums.begin()+j);
			} else
				++i,++j;
		}
		return nums.size();
	}
};
int main(){
	vector<int> nums{1,1,2,2,3,3,4};
	Solution s;
	cout << s.removeDuplicates2(nums) << endl;
	for (auto v: nums) cout << v << " ";
	cout << endl;
}
