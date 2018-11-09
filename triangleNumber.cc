#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n^2)
	int triangleNumber1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res=0;
		for (int k=nums.size()-1; k>1; --k) {	// why k>1?
			int i=0, j=k-1;
			while (i<j) {
				if (nums[i]+nums[j]>nums[k])	// given k,j, i could be 
					res+=j-i, --j;
				else ++i;
			}
		}
		return res;
	}
	// O(n^3)
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res=0;
		for (int i=0; i<nums.size(); ++i) for (int j=i+1; j<nums.size(); ++j) for (int k=j+1; k<nums.size(); ++k)
			if (nums[i]+nums[j]>nums[k])
				++res;
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{2,2,3,4};
	cout << s.triangleNumber(nums) << endl;
	cout << s.triangleNumber1(nums) << endl;
}
