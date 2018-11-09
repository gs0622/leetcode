#include <bits/stdc++.h>
using namespace std;

int containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	std::unordered_set<int> myset;
	for (int i = 0; i < numsSize; i++) {
		if (i > k) myset.erase(nums[i-k-1]);
		auto ret = myset.insert(nums[i]);
		if (false == ret.second)
			return 1;
	}
	return 0;
}
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> set;
		for (int i=0; i<nums.size(); ++i) {
			if (i>k) set.erase(nums[i-k-1]);
			if (set.insert(nums[i]).second == false)
				return true;
		}
		return false;
	}
/*
find out whether there are two distinct indices i and j in the array,
such that the absolute difference between nums[i] and nums[j] is at most t,
 and the absolute difference between i and j is at most k.
*/
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<int> window;	// ordered set
		int i;
		for (i=0; i<nums.size(); ++i) {
			if (i>k)
				window.erase(nums[i-k-1]);		// window is at most k
			auto it = window.lower_bound(nums[i]-t);	// x-nums[i] >= -t ==> x >= nums[i]-t 
			if (it != end(window) && *it - nums[i] <= t)	// +t
				return true;
			window.insert(nums[i]);
		}
		return false;
	}
};
int main(void)
{
	int a0[] = {1, 2, 3, 2, 5};
	int a1[] = {1, 2, 1};
	printf("%d\n", containsNearbyDuplicate(a0, sizeof(a0)/sizeof(int), 3));
	printf("%d\n", containsNearbyDuplicate(a1, sizeof(a1)/sizeof(int), 1));
	Solution s;
	vector<int> nums1{1,2,3,2,5};
	cout << s.containsNearbyDuplicate(nums1, 3) << endl;
	vector<int> nums2{1,2,1};
	cout << s.containsNearbyDuplicate(nums2, 1) << endl;
	vector<int> nums3{1,4,7,1,4,7,1,4,6};
	cout << s.containsNearbyAlmostDuplicate(nums3, 2, 2) << endl;
	return 0;
}

