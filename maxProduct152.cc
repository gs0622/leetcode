/* https://leetcode.com/problems/maximum-product-subarray/description/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxProduct2(vector<int>& nums) {
		int i, n=nums.size();
		if (n==0) return 0;
		int max_this=nums[0], min_this=nums[0], max_ans=nums[0];
		for (i=1; i<n; ++i) {
			if (nums[i]<0) std::swap(max_this,min_this);
			max_this = std::max(max_this*nums[i], nums[i]); // in case 0, reset
			min_this = std::min(min_this*nums[i], nums[i]);
			max_ans = std::max(max_this, max_ans); // keep max before 0
		}
		return max_ans;
	}
	int maxProduct1(vector<int>& nums) {
		int i, n=nums.size();
		if (n==0) return 0;
		int max_last=nums[0], min_last=nums[0], max_this, min_this, max_ans=0;
		for (i=1; i<n; ++i) {
			max_this = std::max(std::max(max_last*nums[i], min_last*nums[i]), nums[i]);
			min_this = std::min(std::min(max_last*nums[i], min_last*nums[i]), nums[i]);
			max_ans = std::max(std::max(max_last, max_this), max_ans);
			max_last = max_this;
			min_last = min_this;
		}
		return max_ans;
	}
	int maxProduct(vector<int>& nums) {
		int i, j, n=nums.size(), res=nums[0], prod=nums[0];
		for (i=0; i<n; ++i) {
			if (nums[i]==0) continue;
			prod = nums[i];
			res = max(res, prod);
			for (j=i+1; j<n; ++j) {
				if (nums[i]==0) break;
				prod *= nums[j];
				res = max(res, prod);
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums1{-2,3,-4};
	cout << s.maxProduct(nums1) << " " << s.maxProduct2(nums1) << endl;
	vector<int> nums2{200,0,20};
	cout << s.maxProduct(nums2) << " " << s.maxProduct2(nums2) << endl;
	vector<int> nums3{3,-1,4};
	cout << s.maxProduct(nums3) << " " << s.maxProduct2(nums3) << endl;
}
