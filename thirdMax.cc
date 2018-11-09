/*
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		vector<long long> top3(3, LLONG_MIN);
		for (auto n: nums) {
			if (n==top3[0]||n==top3[1]||n==top3[2]) continue;
			if (n>top3[0]) top3[2]=top3[1], top3[1]=top3[0], top3[0]=n;
			else if (n>top3[1]) top3[2]=top3[1], top3[1]=n;
			else if (n>top3[2]) top3[2]=n;
		}
		return top3[2]!=LLONG_MIN? top3[2]: top3[0];
	}
	int thirdMax1(vector<int>& nums) {
		set<int> top3;
		for (auto n: nums) {
			top3.insert(n);
			if (top3.size()>3) top3.erase(top3.begin());
		}
		return top3.size()==3? *top3.begin(): *top3.rbegin();
	}
	int thirdMax2(vector<int>& nums) {
		std::sort(nums.begin(), nums.end(), std::greater<int>());
		int i, j;
		for (i=0,j=1; i<nums.size() && j<nums.size(); ++j) {
			if (nums[i]!=nums[j])
				++i, nums[i]=nums[j];
		}
		nums.erase(nums.begin()+i+1, nums.end());
		return (nums.size()>=3)? nums[2]: nums[0];
	}
};
int main(){
	Solution s;
	vector<int> nums1{3,2,1};
	cout << s.thirdMax(nums1) << endl;
	vector<int> nums2{1,2};
	cout << s.thirdMax(nums2) << endl;
	vector<int> nums3{1,2,-2147483648};
	cout << s.thirdMax(nums3) << endl;
}
