#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size()<3) return -1;
		int i, left, sum, n=nums.size();
		for (i=0, sum=0; i<n; ++i) sum+=nums[i];
		for (i=0, left=0; i<n; ++i) {
			if (left*2+nums[i]==sum) return i;
			left+=nums[i];
		}
		return -1;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1, 7, 3, 6, 5, 6};
	cout << s.pivotIndex(nums1) << endl;
	vector<int> nums2{1, 2, 3};
	cout << s.pivotIndex(nums2) << endl;
}
