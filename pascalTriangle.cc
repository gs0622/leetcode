/*https://leetcode.com/problems/pascals-triangle/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int rows) {
		vector<vector<int>> res;
		for (int r=0; r<rows; ++r) {
			long long x=1;
			res.push_back({});
			for (int k=0; k<=r; ++k) {
				res.back().push_back(x);
				x = x*(r-k)/(k+1);
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> rows = s.generate(5);
	for (auto r: rows) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
}
