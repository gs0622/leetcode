#include <iostream>
#include <vector>
using namespace std;
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
	Solution s;
	vector<int> nums1{10, 5, 2, 6};
	cout << s.numSubarrayProductLessThanK(nums1, 100) << endl;
	vector<int> nums2{1,1,1};
	cout << s.numSubarrayProductLessThanK(nums2, 100) << endl;
}
