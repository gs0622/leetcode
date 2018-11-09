#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int threeSum1(vector<int>& nums, int target) {
		int i, j, k, n=nums.size(), res=0;
		for (i=0; i<n-2; ++i) {
			j=i+1, k=n-1;
			while (j<k) { // i is fixed
				if (nums[i]+nums[j]+nums[k]<target) res+=k-j, ++j;
				else --k;
			}
		}
		return res;
	}
	// Brute-force
	//vector<vector<int>> threeSum(vector<int>& nums, int target) {
	int threeSum(vector<int>& nums, int target) {
		int i, j, k, n=nums.size();
		sort(begin(nums), end(nums));
		vector<vector<int>> res;
		set<pair<pair<int,int>,int>> set;
		for (i=0; i<n; ++i)
			for (j=i+1; j<n; ++j)
				for (k=j+1; k<n; ++k) {
					if (nums[i]+nums[j]+nums[k]<target) {
						set.insert(make_pair(make_pair(nums[i],nums[j]), nums[k]));
					}
				}
		for (auto x: set) res.push_back({x.first.first, x.first.second, x.second});
		return res.size();
	}
};

int main(void)
{
    vector<int> nums{-2,0,1,3};
    Solution s;
    cout << s.threeSum1(nums, 2) << endl;
}

