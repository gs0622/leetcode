#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// two pointers
	int removeElement(vector<int>& nums, int val) {
		std::sort(nums.begin(), nums.end());
		int i,j; // non-dup and dup pointers
		for (i=0,j=1; j<nums.size();++j) {
			if (nums[i]!=nums[j]) {
				++i;
				nums[i]=nums[j];	// shift
			} // else if (nums[i]==nums[j]) j++
		}
		nums.erase(nums.begin()+i+1, nums.end());
		return nums.size();
	}
};
int main(){
	Solution s;
	vector<int> nums{3,2,2,3};
	cout << s.removeElement(nums, 3) << endl;
	for (auto x: nums) cout << x << " ";
	cout << endl;
}
