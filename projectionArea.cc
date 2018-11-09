/* https://leetcode.com/problems/projection-area-of-3d-shapes/discuss/156726/C++JavaPython-Straight-Forward

front-back projection area on xz = sum(max value for every col)
right-left projection area on yz = sum(max value for every row)
top-down projection area on xy = sum(1 for every v > 0)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int res=0, n=grid.size(); // n-by-n
		for (int i=0; i<n; ++i) {	// xz plane: counting max v per col
			int v=0;
			for (int j=0; j<n; ++j)
				v = max(v, grid[i][j]);
			res+=v;
		}
		for (int j=0; j<n; ++j) {	// yz plane: counting max v per row
			int v=0;
			for (int i=0; i<n; ++i)
				v = max(v, grid[i][j]);
			res+=v;
		}
		for (int i=0; i<n; ++i) {	// xy plane: counting existing grids
			for (int j=0; j<n; ++j)
				if (grid[i][j]) ++res;
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> G1{{1,2},{3,4}};
	cout << s.projectionArea(G1) << endl;
	vector<vector<int>> G5{{2,2,2},{2,1,2},{2,2,2}};
	cout << s.projectionArea(G5) << endl;
}
