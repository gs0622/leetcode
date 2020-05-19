/* https://leetcode.com/problems/subarray-sum-equals-k/description/ */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution2 {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int,int> pre{{0,1}};
		int res=0, sum=0;
		for (auto n: nums) {
			sum += n;
			res += pre[sum-k];
			pre[sum]++;
		}
		return res;
	}
};
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int,int> pre{{0,1}};
		int ans=0, sum=0;
		for (auto i=0; i<nums.size(); ++i) {
			sum += nums[i];
			ans += pre[sum-k];
			pre[sum] += 1;
		}
		return ans;
	}
  // brute-force
	int subarraySum2(vector<int>& nums, int k) {
		int i, j, n=nums.size(), sum, cnt=0;
		for (i=0; i<n; ++i) {
			sum = 0, j;
			for (j=i; j<n; ++j) {
				sum += nums[j];
				if (sum==k) cnt+=1;
			}
		}
		return cnt;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,1,1};
	cout << s.subarraySum(nums1, 2) << " " << s.subarraySum2(nums1, 2)<< endl;
	vector<int> nums2{1};
	cout << s.subarraySum(nums2, 0) << " " << s.subarraySum2(nums2, 0)<< endl;
	vector<int> nums3{28,54,7,-70,22,65,-6};
	cout << s.subarraySum(nums3, 100) << " " << s.subarraySum2(nums3, 100)<< endl;
}
