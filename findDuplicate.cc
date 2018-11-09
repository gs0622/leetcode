/*https://leetcode.com/problems/find-the-duplicate-number/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// Brute-force count, O(n) space, O(n) time
	int findDuplicate3(vector<int>& nums) {
		unordered_map<int,int> m;
		for (auto n: nums) ++m[n];
		for (auto n: m)
			if (n.second == 2) return n.first;
		return -1;
	}
	int findDuplicate2(vector<int>& nums) {
		if (!nums.size()) throw -1;
		int s=0, f=0;
		do {
			s=nums[s], f=nums[nums[f]];
		} while (f!=s);
		f=0;
		do {
			s=nums[s], f=nums[f];
		} while (f!=s);
		return s;
	}

	int findDuplicate(vector<int>& nums) {
		if (!nums.size()) return -1;
		int s=nums[0], f=nums[s];
		while (f!=s)
			s=nums[s], f=nums[nums[f]]; // tortoise and hare
		//for (f=0; f!=s;)
		//	s=nums[s], f=nums[f]; // same pace
		for (f=nums[0]; f!=s;)
			s=nums[s], f=nums[f]; // same pace
		return s;
	}
};
int main(){
	Solution s;
	vector<int> nums0{};
	cout << s.findDuplicate3(nums0) << endl;
	vector<int> nums1{1,2,3,4,2};
	cout << s.findDuplicate3(nums1) << endl;
	vector<int> nums2{1,2,3,4,5,6,7,8,9,7};
	cout << s.findDuplicate3(nums2) << endl;
}

