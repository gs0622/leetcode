/* https://leetcode.com/problems/set-mismatch/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time, O(1) space
	vector<int> findErrorNums(vector<int>& nums) {
		int dup, mis;
		for (auto n: nums) {
			if (nums[abs(n)-1] < 0) dup = abs(n);
			else nums[abs(n)-1] *= -1;
		}
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i] > 0) mis = i+1;
		}
		return {dup, mis};
	}
	// Brute-force O(n) time, O(n) space
	vector<int> findErrorNums1(vector<int>& nums) {
		int dup, mis;
		unordered_map<int,int> m;
		for (auto n: nums) ++m[n];
		for (int i=1; i<=nums.size(); ++i) {
			if (m[i]==0) mis = i;
			if (m[i]==2) dup = i;
		}
		return {dup, mis};
	}
};
int main(){
	Solution s;
	/*vector<int> nums1{1,2,2,4};
	for (auto x: s.findErrorNums(nums1)) cout << x << " ";
	cout << endl;
	vector<int> nums2{3,2,2};
	for (auto x: s.findErrorNums(nums2)) cout << x << " ";
	cout << endl;*/
	vector<int> nums3{3,2,3,4,6,5};
	for (auto x: s.findErrorNums(nums3)) cout << x << " ";
	cout << endl;
}
