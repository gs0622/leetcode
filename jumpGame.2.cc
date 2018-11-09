/* https://leetcode.com/problems/jump-game-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int i=0, step=0, end=0, n=nums.size(), reach=0;
		while (end < n-1) {	// image go on a tree
			++step;
			for (;i<=end; ++i) {
				reach = std::max(reach, i+nums[i]);
				if (reach >= n-1) return step;
			}
			if (end == reach) break; // stuck at reach
			end = reach;
		}
		return n==1? 0: -1;
	}
};
int main(){
	Solution s;
	vector<int> nums1{2,3,1,1,4};
	cout << s.jump(nums1) << endl;
	vector<int> nums2{1,2,3};
	cout << s.jump(nums2) << endl;
}
