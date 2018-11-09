#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int i, mul, n=nums.size();
		vector<int> res(n);
		for (i=0,mul=1; i<n; ++i) res[i]=mul, mul*=nums[i];
		for (i=n-1,mul=1; i>=0; --i) res[i]*=mul, mul*=nums[i];
		return res;
	}
	vector<int> productExceptSelf2(vector<int>& nums) {
		int prod=1;
		for (auto num: nums) prod *= num;
		for (auto& num: nums) num = prod/num;
		return nums;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,3,4};
	vector<int> res = s.productExceptSelf(nums);
	for (auto num: res) cout << num << " ";
	cout << endl;
}
