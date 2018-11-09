/*
[LeetCode] Verify Preorder Sequence in Binary Search Tree
e.g.

	5
      2  6
    1  3

preorder: 5, 2, 1, 3, 6
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool helper(vector<int>& nums, int lo, int hi, long long min, long long max) {
		if (lo > hi) return true;
		int val = nums[lo], i;
		if (val <= min || val >= max) return false;
		for (i=lo+1; i<=hi; ++i)
			if (nums[i] >= val) break;	// [lo...i-1] are left subtree
		return helper(nums, lo+1, i-1, min, val) &&
			helper(nums, i, hi, val, max);
	}
public:
	bool verifyPreorder2(vector<int>& nums) {
		return helper(nums, 0, nums.size()-1, LLONG_MIN, LLONG_MAX);
	}
	bool verifyPreorder1(vector<int>& nums) {
		int low = INT_MIN, i = -1;
		for (auto n: nums) {
			if (n < low) return false;
			while (i>=0 && n > nums[i])
				low = nums[i--];
			nums[++i] = n;
		}
		return true;
	}
	bool verifyPreorder(vector<int>& nums) {
		stack<int> stk;
		int low = INT_MIN;
		for (auto n: nums) {
			if (n < low) return false;			// exame left subtree
			while (!stk.empty() && n > stk.top()) {		// deal w/ right
				low = stk.top();
				stk.pop();
			}
			stk.push(n);
		}
		return true;
	}
};
int main(){
	vector<int> nums1{5,2,1,3,6};
	vector<int> nums2{5,2,1,6,3};
	Solution s;
	cout << s.verifyPreorder2(nums1) << endl;	// true
	cout << s.verifyPreorder2(nums2) << endl;	// false
}

