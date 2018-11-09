#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int res=0, n=grid.size();
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
			res += grid[i][j]? grid[i][j]*4+2: 0;		// 4v+2 planes
			if (i) res -= min(grid[i-1][j], grid[i][j])*2;	// minus hidden planes in upper row
			if (j) res -= min(grid[i][j-1], grid[i][j])*2;	// minus hidden planes in left col
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> g1{{2}};
	cout << s.surfaceArea(g1) << endl;
	vector<vector<int>> g2{{1,2},{3,4}};
	cout << s.surfaceArea(g2) << endl;
	vector<vector<int>> g3{{1,0},{0,2}};
	cout << s.surfaceArea(g3) << endl;
	vector<vector<int>> g4{{1,1,1},{1,0,1},{1,1,1}};
	cout << s.surfaceArea(g4) << endl;
	vector<vector<int>> g5{{2,2,2},{2,1,2},{2,2,2}};
	cout << s.surfaceArea(g5) << endl;
}
