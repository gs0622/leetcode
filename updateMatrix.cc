#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// BFS:
	// Some small tricks:
	// 1. At beginning, set cell value to Integer.MAX_VALUE if it is not 0.
	// 2. If newly calculated distance >= current distance, then we don't need to explore that cell again.
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int i, j, m=matrix.size(), n=matrix[0].size();
		queue<pair<int,int>> q;
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (matrix[i][j]==0)
					q.push(make_pair(i,j));
				else
					matrix[i][j]=INT_MAX;
			}
		}

		vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

		while (!q.empty()) {
			auto p = q.front(); q.pop();
			for (auto d: dirs) {
				int r = p.first + d.first;
				int c = p.second + d.second;
				if (r<0 || r>=m || c<0 || c>=n) continue;			// skip invalid dir
				if (matrix[r][c] <= matrix[p.first][p.second]) continue;	// nothing to relax
				matrix[r][c] = matrix[p.first][p.second]+1;			// relax: beautiful move
				q.push(make_pair(r,c));
			}
		}
		return matrix;
	}
	vector<vector<int>> updateMatrix1(vector<vector<int>>& matrix) {
		int i, j, m=matrix.size(), n=matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (matrix[i][j]==0)
					dp[i][j]=0;
				else {
					if (i>0	  && dp[i-1][j]!=INT_MAX && dp[i][j]>dp[i-1][j]+1) dp[i][j]=dp[i-1][j]+1;
					if (j>0   && dp[i][j-1]!=INT_MAX && dp[i][j]>dp[i][j-1]+1) dp[i][j]=dp[i][j-1]+1;
					if (i<m-1 && dp[i+1][j]!=INT_MAX && dp[i][j]>dp[i+1][j]+1) dp[i][j]=dp[i+1][j]+1;
					if (j<n-1 && dp[i][j+1]!=INT_MAX && dp[i][j]>dp[i][j+1]+1) dp[i][j]=dp[i][j+1]+1;
				}
			}
		}
		for (i=m-1; i>=0; --i) {
			for (j=n-1; j>=0; --j) {
				if (matrix[i][j]==0)
					dp[i][j]=0;
				else {
					if (i>0	  && dp[i-1][j]!=INT_MAX && dp[i][j]>dp[i-1][j]+1) dp[i][j]=dp[i-1][j]+1;
					if (j>0   && dp[i][j-1]!=INT_MAX && dp[i][j]>dp[i][j-1]+1) dp[i][j]=dp[i][j-1]+1;
					if (i<m-1 && dp[i+1][j]!=INT_MAX && dp[i][j]>dp[i+1][j]+1) dp[i][j]=dp[i+1][j]+1;
					if (j<n-1 && dp[i][j+1]!=INT_MAX && dp[i][j]>dp[i][j+1]+1) dp[i][j]=dp[i][j+1]+1;
				}
			}
		}
		return dp;
	}
};
int main(){
	Solution s;
	//vector<vector<int>> matrix{{0,0,0},{0,1,0},{0,0,0}};
	vector<vector<int>> matrix{{0,0,0},{0,1,0},{1,1,1}};
	vector<vector<int>> res = s.updateMatrix(matrix);
	for (auto r: res) {
		for (auto c: r) cout << c << ' ';
		cout << endl;
	}
}
