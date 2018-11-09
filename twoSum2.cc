/* sorted arr of twosum */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int lo=0, hi=nums.size()-1;
		while (lo<hi) {
			int sum = nums[lo] + nums[hi];
			if (sum < target) ++lo;
			else if (sum > target) --hi;
			else return {lo+1, hi+1};
		}
		throw runtime_error("no solution");
	}   
};
int main(){
	Solution s;
	vector<int> nums1{2, 7, 11, 15};
	vector<int> ret = s.twoSum(nums1, 9);
	for (auto x: ret) cout << x << " ";
	cout << endl;
	vector<int> nums2{2,3,4};
	ret = s.twoSum(nums2, 6);
	for (auto x: ret) cout << x << " ";
	cout << endl;
}
