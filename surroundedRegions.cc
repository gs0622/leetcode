#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void solve1(vector<vector<char>>& B) {
		if (B.empty()||B[0].empty()) return;
		int m=B.size(), n=B[0].size();
		vector<int> dirs{1,0,-1,0,1};
		queue<vector<int>> q;
		function <void(void)> bfs=[&](void) {
			while (!q.empty()) {
				vector<int> p = q.front(); q.pop();
				int r=p[0], c=p[1];
				B[r][c]='o';
				for (int i=0; i<4; ++i) {
					int rr=r+dirs[i], cc=c+dirs[i+1];
					if (rr<0||cc<0||rr>=m||cc>=n) continue;
					if (B[rr][cc]=='O') q.push({rr,cc});
				}
			}
		};
		for (int i=0; i<m; ++i) {
			if (B[i][0]=='O') q.push({i,0});
			if (B[i][n-1]=='O') q.push({i,n-1});
		}
		for (int i=0; i<n; ++i) {
			if (B[0][i]=='O') q.push({0,i});
			if (B[m-1][i]=='O') q.push({m-1,i});
		}
		bfs();
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (B[i][j]=='O') B[i][j]='X';
				if (B[i][j]=='o') B[i][j]='O';
			}
		}
	}
	void solve(vector<vector<char>>& B) {
		if (B.empty()||B[0].empty()) return;
		int m=B.size(), n=B[0].size();
		vector<vector<int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
		function<void(int,int)> dfs=[&](int r, int c){
			if (B[r][c]=='X') return;
			B[r][c]='o';
			for (auto dir: dirs) {
				int rr=r+dir[0], cc=c+dir[1];
				if (rr<0||cc<0||rr>=m||cc>=n) continue;
				if (B[rr][cc]=='O') dfs(rr,cc);
			}
		};
		for (int i=0; i<m; ++i)
			dfs(i,0),dfs(i,n-1);
		for (int i=0; i<n; ++i)
			dfs(0,i),dfs(m-1,i);
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (B[i][j]=='O') B[i][j]='X';
				if (B[i][j]=='o') B[i][j]='O';
			}
		}
	}
};
int main(){
	Solution s;
	vector<vector<char>> B{
{'X','X','X','X'},
{'X','O','O','X'},
{'X','X','O','X'},
{'X','O','X','X'},
};
	s.solve1(B);
	for (auto r: B) {
		for (auto c: r) cout << c << ' ';
		cout << endl;
	}
}
