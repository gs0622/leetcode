#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int i, rr=nums.size(), cc=nums[0].size();
		if (rr*cc != r*c) return nums; // unable to reshape
		vector<vector<int>> res(r, vector<int>(c));
		for (i=0; i<r*c; ++i) res[i/c][i%c] = nums[i/cc][i%cc];
		return res;
	}
	vector<vector<int>> matrixReshape2(vector<vector<int>>& nums, int r, int c) {
		int i, j, rr=nums.size(), cc=nums[0].size();
		if (rr*cc != r*c) return nums; // unable to reshape
		vector<int> tmp;
		for (auto row: nums) {
			for (auto col: row) tmp.push_back(col); // reshape to (1, r*c)
		}
		vector<vector<int>> res;
		for (i=0; i<r; ++i) {
			res.push_back(vector<int>(tmp.begin()+i*c, tmp.begin()+i*c+c));
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> nums{{1,2},{3,4},{5,6},{7,8}};
	vector<vector<int>> res = s.matrixReshape(nums, 2, 4);
	for (auto r: res) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
	res = s.matrixReshape(nums, 1, 8);
	for (auto r: res) {
		for (auto c: r) cout << c << " ";
		cout << endl;
}	}
