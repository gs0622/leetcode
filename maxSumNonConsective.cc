#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxSum(vector<int>& nums) {
		int max1=nums[0], max2=nums[1];
		for (int i=2; i<nums.size(); ++i) {
			if (i%2==0) max1 = std::max(nums[i]+max1, max2);
			else max2 = std::max(nums[i]+max2, max1);
		}
		return std::max(max1, max2);
	}
	int maxSum2(vector<int>& nums) {
		int i, n=nums.size();
		vector<int> sums(nums.begin(), nums.end());
		for (i=2; i<n; ++i)
			sums[i] = std::max(sums[i]+*max_element(sums.begin(), sums.begin()+i-2), sums[i]);
		return *std::max_element(sums.begin(), sums.end());
	}
};
int main(){
	Solution s;
	vector<int> nums{1,12,5,4,13};
	cout << s.maxSum(nums) << " " << s.maxSum2(nums) << endl;
}
