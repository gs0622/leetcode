#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		for (int i=0; i<nums.size(); ++i) {
			while (nums[i] != nums[nums[i]-1])
				swap(nums[i], nums[nums[i]-1]);
		}
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i] != i+1)
				res.push_back(i+1);
		}
		return res;
	}
};
int main(){
	//vector<int> nums{4,3,2,7,8,2,3,1};
		//	 1,2,3,4,    7,8
	vector<int> nums{1,2,3,4,5,6,7,8};
	Solution s;
	vector<int> res = s.findDisappearedNumbers(nums);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
