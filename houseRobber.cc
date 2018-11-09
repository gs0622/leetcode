#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int rob1(vector<int>& nums) {
		function<int(int,int)> helper=[&](int lo, int hi) {
			int include=0, exclude=0;
			for (int j=lo; j<=hi; ++j) {
				int i=include, e=exclude;
				include = e+nums[j];
				exclude = max(e, i);
			}
			return max(include, exclude);
		};
		return helper(0, nums.size()-1);
	}
	int rob(vector<int>& nums) {
		int sumA(0), sumB(0);
		for (int i=0; i<nums.size(); ++i) {
			if (i%2) sumA=max(sumA+nums[i], sumB);
			else sumB=max(sumB+nums[i], sumA);
		}
		return max(sumA,sumB);
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,2,3,1};
	vector<int> nums2{2,7,9,3,1};
	vector<int> nums3{1};
	vector<int> nums4{2,1,1,2};
	cout << s.rob(nums1) << " " << s.rob1(nums1) << endl;
	cout << s.rob(nums2) << " " << s.rob1(nums2) << endl;
	cout << s.rob(nums3) << " " << s.rob1(nums3) << endl;
	cout << s.rob(nums4) << " " << s.rob1(nums4) << endl;
}
