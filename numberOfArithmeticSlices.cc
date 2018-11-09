/* https://leetcode.com/problems/arithmetic-slices/description/

hint: math
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numberOfArithmeticSlices1(vector<int>& nums) {
		int res=0, cnt=0;
		for (int i=2; i<nums.size(); ++i) {
			if (nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
				++cnt, res+=cnt;	// think 1-2-3 -> 1-2->3->4
			else
				cnt=0;
		}
		return res;
	}
	int numberOfArithmeticSlices(vector<int>& nums) {
		int len=2, res=0;
		for (int i=2; i<nums.size(); ++i) {
			if (nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) ++len;
			else res += (len-2)*(len-1)/2, len=2;
		}
		return (len==2)? res: res+(len-2)*(len-1)/2;	// if (len>2) res += (len-2)*(len-1)/2
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,2,3,4};
	vector<int> nums2{1,2,3,8,9,10};
	cout << s.numberOfArithmeticSlices(nums1) << ": " << s.numberOfArithmeticSlices1(nums1) << endl;
	cout << s.numberOfArithmeticSlices(nums2) << ": " << s.numberOfArithmeticSlices1(nums2) << endl;
}
