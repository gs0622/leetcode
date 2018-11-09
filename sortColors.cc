/* https://leetcode.com/problems/sort-colors/description/
array, two-pointer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i, j, k, n=nums.size();
		for (i=0, j=0, k=n-1; j<=k; ++j) { // j: head, k: tail
			while (nums[i]==2 && i<k) swap(nums[k--], nums[i]);
			while (nums[i]==0 && i>j) swap(nums[j++], nums[i]);
		}

	}
	void sortColors1(vector<int>& nums) {
		map<int,int> m;
		for (auto n: nums) ++m[n];
		int i=0;
		for (auto x: m) {
			for (int j=0; j<x.second; ++j)
				nums[i++] = x.first;
		}
	}
	void sortColors2(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
	}
};
int main(){
	Solution s;
	vector<int> nums{0,1,2,0,1,2,0};
	s.sortColors(nums);
	for (auto n: nums) cout << n << " ";
	cout << endl;
}
