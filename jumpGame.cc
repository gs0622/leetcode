/* https://leetcode.com/problems/jump-game/description/
# array
# greedy
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i, reach;
		for (reach=0, i=0; i<nums.size()-1 && i<=reach; ++i) {
			reach = std::max(i+nums[i], reach);
			//cout << i << " -> " << reach << endl;
		}
		return reach >= nums.size()-1;
	}
};
int main(){
	Solution s;
	vector<int> nums1{2,3,1,1,4}; // return true
	vector<int> nums2{3,2,1,0,4}; // return false
        vector<int> nums3{0,2,3}; // return false
        vector<int> nums4{2,0}; // return true
        cout << s.canJump(nums1) << endl;
        cout << s.canJump(nums2) << endl;
        cout << s.canJump(nums3) << endl;
        cout << s.canJump(nums4) << endl;
}
