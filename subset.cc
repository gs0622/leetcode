#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
While iterating through all numbers, for each new number, we can either pick it or not pick it
1, if pick, just add current number to every existing subset.
2, if not pick, just leave all existing subsets as they are.
We just combine both into our result.
*/
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int i, j, n;
		vector<vector<int>> res(1, vector<int>());	// empty one
		for (i=0; i<nums.size(); ++i) {
			n=res.size();
			for (j=0; j<n; ++j) {
				res.push_back(res[j]);		// clone all previous subset
				res.back().push_back(nums[i]);	// pick this num into subset
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,3};
	vector<vector<int>> res = s.subsets(nums);
	for (auto a: res) {
		for (auto b: a) cout << b << " ";
		cout << endl;
	}
}
