/* https://leetcode.com/problems/subarray-product-less-than-k/
Your are given an array of positive integers nums.
Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution3 {
public: // O(n) two-pointer
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res=0,sum=1,n=nums.size();
    for (int i=0,j=0;i<n;++i) {
      sum*=nums[i];
      while (sum>=k) sum/=nums[j++];
      res+=i-j+1;
    }
    return res;
  }
};
class Solution2 {
public: // O(n^2) brute-force
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res=0,n=nums.size();
    for (int i=0; i<n; ++i) {     // start
      int sum=1;
      for (int j=i; j<n; ++j) {   // start to end
        sum*=nums[j];
        if (sum>=k) break;
        ++res;
      }
    }
    return res;
  }
};
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k<=1) return 0;
		int i, j, cnt=0, prod=1, n=nums.size();
		for (i=0, j=0; i<n; ++i) {
			prod *= nums[i];
			while (prod >= k) prod /= nums[j++];
			cnt += i-j+1;
		}
		return cnt;
	}
};
int main(){
	Solution3 s;
	vector<int> nums1{10, 5, 2, 6};
	cout << s.numSubarrayProductLessThanK(nums1, 100) << endl;
	vector<int> nums2{1,1,1};
	cout << s.numSubarrayProductLessThanK(nums2, 100) << endl;
}
