#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int mi, lo=0, hi=nums.size()-1;
		while (lo<hi) {
			mi=lo+(hi-lo)/2;
			if (nums[mi] == target) return mi;
			if (nums[mi] < target) lo=mi+1;
			else hi=mi;
		}
		cout << lo << " " << hi << endl;
		// lo==hi
		return nums[lo]>=target? lo: lo+1;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,3,5,6};
	//cout << s.searchInsert(nums1, 5) << endl;
	//cout << s.searchInsert(nums1, 2) << endl;
	//cout << s.searchInsert(nums1, 7) << endl;
	//cout << s.searchInsert(nums1, 0) << endl;
	vector<int> nums2{1};
	cout << s.searchInsert(nums2, 1) << endl;
}
