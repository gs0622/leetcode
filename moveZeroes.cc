/* https://leetcode.com/problems/move-zeroes/description/ */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// O(n) two pointers
	void moveZeroes(vector<int>& nums) {
		for (int i=0, j=0; j<nums.size(); ++j) { // i: non-zero, j: cur
			if (nums[j]!=0) swap(nums[j], nums[i++]);
		}
	}
	void moveZeroes2(vector<int>& nums) {
		for (int i=0, j=0; j<nums.size();) {
			if (nums[j]==0) ++j;
			else swap(nums[j++], nums[i++]);
		}
	}
};
int main(){
	Solution s;
	vector<int> nums{0, 1, 0, 3, 12};
	s.moveZeroes(nums);
	for (auto x: nums) cout << x << " ";
	cout << endl;
}
