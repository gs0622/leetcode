/* https://leetcode.com/problems/combinations/description/
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
e.g.,
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
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
	vector<vector<int>> combine1(int n, int k) {
		vector<vector<int>> res;
		vector<int> tmp;
		function<void(int)> helper=[&](int i) {
			if (tmp.size()==k) {		// list size is already in k, push into result, then return
				res.push_back(tmp);
				return;
			}
			for (int j=i; j<=n; ++j) {
				tmp.push_back(j);	// {1} -> {1,2}
				helper(j+1);
				tmp.pop_back();		// {1,2} -> {1}, up on k
			}
		};
		helper(1);
		return res;
	}
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
	vector<vector<int>> res;
	res  = s.combine(4,2);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
	cout << endl;
	res  = s.combine1(4,2);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
