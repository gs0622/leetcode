/* https://leetcode.com/problems/unique-paths-ii/description/
array, DP, border
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& grid) {
		int i, j, m=grid.size(), n=grid[0].size();		// m, n in grid.size
		vector<vector<int>> P(m+1, vector<int>(n+1,0));
		P[0][1]=1;
		for (i=1; i<m+1; ++i) {
			for (j=1; j<n+1; ++j) {
				if (!grid[i-1][j-1]) P[i][j]=P[i-1][j]+P[i][j-1];
			}
		}
		return P[m][n];
	}
};
int main(){
	Solution s;
	//vector<vector<int>> grid{{0,0,0},{0,1,0},{0,0,0}};
	vector<vector<int>> grid{{0,1}};
	cout << s.uniquePathsWithObstacles(grid) << endl;
}
