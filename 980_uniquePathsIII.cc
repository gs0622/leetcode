/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

# brute-force backtracking, be careful off-by-one
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int uniquePathsIII1(vector<vector<int>>& grid) {
		vector<int> s;
		int m=grid.size(), n=grid[0].size(), empty=0;
		// search start point, count empty
		for (auto i=0; i<m; ++i) for (auto j=0; j<n; ++j) {
			if (grid[i][j]==1) s={i,j};
			else if	(grid[i][j]!=-1) empty++;
		}
		// backtracking helper
		function<int(int,int,int)> helper=[&](int r, int c, int s) {
			if (r<0||r>=m||c<0||c>=n||grid[r][c]==-1) return 0;
			if (grid[r][c]==2) return s==empty? 1: 0;
			grid[r][c]=-1;
			int steps = helper(r+1,c,s+1)+helper(r-1,c,s+1)+helper(r,c+1,s+1)+helper(r,c-1,s+1);
			grid[r][c]=0;
			return steps;
		};
		return helper(s[0],s[1],0);
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		vector<int> s, e;
		int m=grid.size(), n=grid[0].size(), empty=1, res=0;	// empty count starts from 1 as it is treated as an empty slot as well: "walk over every non-obstacle square exactly once"
		for (auto i=0; i<m; ++i) for (auto j=0; j<n; ++j) {
			if (grid[i][j]==1) s={i,j};
			else if (grid[i][j]==2) e={i,j};
			else if (grid[i][j]==0) ++empty;
		}
		function<void(int,int)> helper=[&](int r, int c) {
			if (r<0||r>=m||c<0||c>=n||grid[r][c]<0) return;
			if (r==e[0]&&c==e[1]&&empty==0) {++res; return;}
			--empty,grid[r][c]=-2;	// -1 is obstacle, -2 for temp
			helper(r+1,c), helper(r-1,c), helper(r,c+1),helper(r,c-1);
			++empty,grid[r][c]=0;
		};
		helper(s[0],s[1]);
		empty=empty;
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> G1{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
	cout << s.uniquePathsIII1(G1) << endl;
	vector<vector<int>> G2{{1,0,0,0},{0,0,0,0},{0,0,0,2}};
	cout << s.uniquePathsIII1(G2) << endl;
	vector<vector<int>> G3{{0,1},{2,0}};
	cout << s.uniquePathsIII1(G3) << endl;
}
