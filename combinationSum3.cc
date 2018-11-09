/*
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	void helper(int k, int n, int j, vector<int>& s, vector<vector<int>>& r) {
		if (k==0 && n==0) {
			r.push_back(vector<int>(s.begin(), s.end()));
			return;
		} else if (k<0)
			return;
		for (int i=j; i<=9; ++i) {
			if (i>n) break;
			s.push_back(i);
			helper(k-1, n-i, i+1, s, r);
			s.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> r;
		vector<int> s;
		helper(k, n, 1, s, r);
		return r;
	}
};
int main(){
	Solution s;
	vector<vector<int>> res;
	res = s.combinationSum3(3,15);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
