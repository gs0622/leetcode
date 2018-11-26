/*https://leetcode.com/problems/find-the-duplicate-number/description/*/
//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	int findDuplicate3(vector<int>& nums) {
		int i, n=nums.size();
		for (i=0; i<n; ++i) {
			if (nums[i]>0 && nums[i]!=i+1 &&		// not in right hole and the hole has been occupied
				nums[i] == -nums[nums[i]-1])
				return nums[i];
			while (nums[i]>0 && nums[i]!=i+1)		// put the pigeon into right hole
				swap(nums[i], nums[nums[i]-1]);
			nums[i]*=-1;					// negate as visit
		}
		throw -1;
		return 0;
	}
	// O(n) time, O(1) space: runner/walker and pigeon hole
	int findDuplicate2(vector<int>& nums) {
		if (nums.empty()) throw -1;
		int s=0, f=0;	// both slow fast start from index 0
		do {
			s=nums[s], f=nums[nums[f]];
		} while (f!=s);
		f=0;
		do {
			s=nums[s], f=nums[f];
		} while (f!=s);
		return s;
	}

	int findDuplicate1(vector<int>& nums) {
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
	// O(n) space, O(n) time, naive brute force counting
	int findDuplicate(vector<int>& nums) {
		unordered_map<int,int> m;
		for (auto n: nums) ++m[n];
		for (auto n: m)
			if (n.second == 2) return n.first;
		throw -1;
		return 0;
	}
};
int main(){
	Solution s;
	vector<int> nums0{};
	//cout << s.findDuplicate2(nums0) << endl;
	vector<int> nums1{1,2,3,4,2};
	cout << s.findDuplicate3(nums1) << endl;
	vector<int> nums2{1,2,3,4,5,6,7,8,9,7};
	cout << s.findDuplicate3(nums2) << endl;
}

