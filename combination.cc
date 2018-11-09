/* https://leetcode.com/problems/combinations/description/
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	void helper(int n, int i, int k, vector<int>&lst, vector<vector<int>>& res) {
		if (lst.size()==k) {
			res.push_back(lst);
			return;
		}
		for (int j=i; j<=n; ++j) {	// recall 1 to n
			lst.push_back(j);
			helper(n, j+1, k, lst, res);
			lst.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> lst;
		vector<vector<int>> res;
		int i=1;	// start
		helper(n, i, k, lst, res);
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
