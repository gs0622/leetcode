/*https://leetcode.com/problems/missing-number/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum1 = accumulate(nums.begin(), nums.end(), 0);
		int sum2 = (nums.size()+0)*(nums.size()+1)/2;
		return sum2-sum1;
	}
};
int main(){
	Solution s;
	vector<int> nums1{3,0,1};
	cout << s.missingNumber(nums1) << endl;
	vector<int> nums2{9,6,4,2,3,5,7,0,1};
	cout << s.missingNumber(nums2) << endl;
}

