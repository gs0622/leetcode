/* https://leetcode.com/problems/unique-paths/description/
# array
# DP
P[i][j] = P[i-1][j] + P[i][j-1]
combination of (m+n-2)
               ------
                 m-1
e.g. (3+7-2)
      -----  = 28
       3-1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	int helper2(int r, int c, int m, int n, vector<vector<int>>& grid) {
		if (r==m-1 || c==n-1) return 1;
		if (r==m || c==n) return 0;
		if (grid[r+1][c]==-1) grid[r+1][c] = helper2(r+1, c, m, n, grid);
		if (grid[r][c+1]==-1) grid[r][c+1] = helper2(r, c+1, m, n, grid);
		return grid[r+1][c] + grid[r][c+1];	// go down or go right 
	}
	int helper1(int r, int c, int m, int n) {
		if (r==m-1 || c==n-1) return 1;
		if (r==m || c==n) return 0;
		return helper1(r+1, c, m, n) + helper1(r, c+1, m, n); // go down or go right 
	}
public:
	// O(mn) bottom-up
	int uniquePaths3(int m, int n) {
		vector<vector<int>> P(m+1, vector<int>(n+1,0)); // one extra board
		P[m-1][n]=1;
		for (int i=m-1; i>=0; --i) {
			for (int j=n-1; j>=0; --j)
				P[i][j]=P[i+1][j]+P[i][j+1];
		}
		return P[0][0];
	}
	int uniquePaths2(int m, int n) {
		vector<vector<int>> grid(m, vector<int>(n, -1));
		return helper2(0, 0, m, n, grid);
	}
	int uniquePaths1(int m, int n) {
		return helper1(0, 0, m, n);
	}
	int uniquePaths(int m, int n) {
		vector<vector<int>> P(m, vector<int>(n,1));
		for (int i=1; i<m; ++i) { // [0][1]==[1][0]==1
			for (int j=1; j<n; ++j)
				P[i][j]=P[i-1][j]+P[i][j-1];
		}
		return P[m-1][n-1];
	}
};
int main(){
	Solution s;
	cout << s.uniquePaths(3,7) << " ";
	cout << s.uniquePaths1(3,7) << " ";
	cout << s.uniquePaths2(3,7) << " ";
	cout << s.uniquePaths3(3,7) << endl;
}
