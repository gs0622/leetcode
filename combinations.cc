/* https://leetcode.com/problems/combinations/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	void helper(int n, int i, int k, vector<int>&cmb, vector<vector<int>>& res) {
		if (k==0) {
			res.push_back(cmb);
			return;
		}
		for (int j=i; j<=n; ++j) {
			cmb.push_back(j);
			helper(n, j+1, k-1, cmb, res);
			cmb.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> cmb;
		vector<vector<int>> res;
		int i=1;
		helper(n, i, k, cmb, res);
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> res = s.combine(4,2);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
