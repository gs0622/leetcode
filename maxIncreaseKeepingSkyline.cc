#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n^2) naive solution
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int n=grid.size();
		vector<int> rows(n,0), cols(n,0);
		int res=0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				rows[i]=max(rows[i], grid[i][j]);
				cols[j]=max(cols[j], grid[i][j]);
			}
		}
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				res+=min(rows[i],cols[j])-grid[i][j];
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> grid{{3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0}};
	cout << s.maxIncreaseKeepingSkyline(grid) << endl;
}
