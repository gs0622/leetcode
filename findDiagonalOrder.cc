#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return {};
		vector<pair<int,int>> dirs{{-1,1},{1,-1}};
		vector<int> res;
		int r=0, c=0, d=0, m=matrix.size(), n=matrix[0].size();
		for (int i=0; i<m*n; ++i) {
			res.push_back(matrix[r][c]);
			r+=dirs[d].first;	// d=0 or 1
			c+=dirs[d].second;
			if (r==m) r=m-1,c+=2, d=1-d;	// note the order of 4 lines below
			if (c==n) c=n-1,r+=2, d=1-d;
			if (r<0) r=0, d=1-d;
			if (c<0) c=0, d=1-d;
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9}};
	for (auto n: s.findDiagonalOrder(m)) cout << n << ' ';
	cout << endl;
}
