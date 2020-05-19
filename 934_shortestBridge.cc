/* https://leetcode.com/problems/shortest-bridge/description/
In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
	int shortestBridge(vvi& A) {
		int m=A.size(), n=A[0].size(), found=0;
		function<void(int,int)> dfs=[&](int r, int c) {
			if (r<0||c<0||r>=m||c>=n||A[r][c]==0||A[r][c]==2) return;
			A[r][c]=2;
			dfs(r-1,c), dfs(r+1,c), dfs(r,c-1), dfs(r,c+1);
		};
		queue<vi> q;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (!found && A[i][j]==1)
					dfs(i,j), found = 1;
				if (found && A[i][j]==1)
					q.push({i,j});
			}
		}
		vi dirs{1,0,-1,0,1};
		int level = 0;
		while (!q.empty()) {	// BFS, level order
			int nn = q.size();
			for (int i=0; i<nn; ++i) {
				vi cur = q.front(); q.pop();
				for (int j=0; j<4; ++j) {
					int r = cur[0]+dirs[j], c = cur[1]+dirs[j+1];
					if (r<0||c<0||r>=m||c>=n||A[r][c]==1) continue;
					if (A[r][c]==2)
						return level;
					A[r][c]=1;	// 0->1 as visit
					q.push({r,c});
				}
			}
			++level;
		}
		return 0;
	}
};
using namespace std;
int main(){
	Solution s;
	vvi A1{{0,1},{1,0}};
	cout << s.shortestBridge(A1) << endl;
	vvi A2{{0,1,0},{0,0,0},{0,0,1}};
	cout << s.shortestBridge(A2) << endl;
	vvi A3{{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
	cout << s.shortestBridge(A3) << endl;
}
