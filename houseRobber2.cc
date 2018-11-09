#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int n=nums.size();
		if (n==0) return 0;
		if (n==1) return nums[0];
		function<int(int,int)> helper=[&](int lo, int hi){
			int include=0, exclude=0;
			for (int j=lo; j<=hi; ++j) {
				int i=include,e=exclude;
				include=e+nums[j];
				exclude=max(i,e);
			}
			return max(include,exclude);
		};
		return max(helper(0,n-2), helper(1,n-1));
	}
};
int main(){
	Solution s;
	vector<int> nums1{2,3,2};
	vector<int> nums2{1,2,3,1};
	cout << s.rob(nums1) << endl;
	cout << s.rob(nums2) << endl;
	
}
