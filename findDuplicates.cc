/* https://leetcode.com/problems/find-all-duplicates-in-an-array/description
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

#array
#pigeonhole

*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		for (auto n: nums) {
			if (nums[abs(n)-1] < 0)
				res.push_back(abs(n));
			else
				nums[abs(n)-1] *= -1;
		}
		return res;
	}
	vector<int> findDuplicates1(vector<int>& nums) {
		vector<int> res;
		for (int i=0; i<nums.size(); i++) {
			if (nums[abs(nums[i])] >= 0)
				nums[abs(nums[i])] = -nums[abs(nums[i])];
			else
				res.push_back(abs(nums[i]));
		}
		return res;
	}
	vector<int> findDuplicates2(vector<int>& nums) {
		vector<int> res;
		int i = 0;
		while (i < nums.size()) {
		    if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
		    else i++;
		}
		for (i = 0; i < nums.size(); i++) {
		    if (nums[i] != i + 1) res.push_back(nums[i]);
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums1{4,3,2,7,8,2,3,1};
	//std::sort(nums1.begin(), nums1.end());
	for (auto v: nums1) cout << v << " ";
	cout << endl;
	//std::sort(nums1.begin(), nums1.end());

	for (auto v: s.findDuplicates(nums1)) cout << v << " ";
	cout << endl;
	for (auto v: nums1) cout << v << " ";
	cout << endl;
}
