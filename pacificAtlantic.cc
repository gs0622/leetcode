#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
	vector<pii> pacificAtlantic1(vector<vector<int>>& M) {
		if (M.empty()) return {};
		int m=M.size(), n=M[0].size();
		vvi visit1(m, vi(n));	// visit1 is for pacific
		vvi visit2(m, vi(n));
		vi dirs{1,0,-1,0,1};
		function<void(int,int,vvi&)> dfs = [&](int r, int c, vvi& visit) {
			visit[r][c]=1;
			for (int i=0; i<4; ++i) {
				int rr=r+dirs[i], cc=c+dirs[i+1];
				if (rr<0||cc<0||rr>=m||cc>=n) continue;
				if (visit[rr][cc]) continue;
				if (M[r][c]>M[rr][cc]) continue;
				dfs(rr,cc,visit);
			}
		};
		for (int i=0; i<m; ++i) {
			dfs(i,0,visit1);
			dfs(i,n-1,visit2);
		}
		for (int i=0; i<n; ++i) {
			dfs(0,i,visit1);
			dfs(m-1,i,visit2);
		}
		vector<pii> res;
		for (int i=0; i<m; ++i) {
			for (int j=0; j<m; ++j) {
				if (visit1[i][j]==1 && visit2[i][j]==1)
					res.push_back(make_pair(i,j));
			}
		}
		return res;
	}
	// BFS
	vector<pii> pacificAtlantic(vector<vector<int>>& M) {
		if (M.empty()) return {};
		queue<pii> q1, q2;				// q1 is for pacific
		int m=M.size(), n=M[0].size();
		vector<vector<int>> visit1(m, vector<int>(n));	// visit1 is for pacific
		vector<vector<int>> visit2(m, vector<int>(n));

		// init
		for (int i=0; i<m; ++i) {
			q1.push(make_pair(i,0));
			q2.push(make_pair(i,n-1));
		}
		for (int j=0; j<n; ++j) {
			q1.push(make_pair(0,j));
			q2.push(make_pair(m-1,j));
		}
		vector<int> dirs{1,0,-1,0,1};

		// traverse pacific
		while (!q1.empty()) {
			pii cur=q1.front(); q1.pop();
			int r=cur.first, c=cur.second;
			visit1[r][c]=1;
			for (int i=0; i<4; ++i) {	// 4 edges
				int rr=r+dirs[i], cc=c+dirs[i+1];
				if (rr<0||cc<0||rr>=m||cc>=n||visit1[rr][cc]) continue;
				if (M[r][c]>M[rr][cc]) continue;	// tricky: explore higher/equal water, not flow to it
				q1.push(make_pair(rr,cc));
			}
		}

		// traverse pacific
		while (!q2.empty()) {
			pii cur=q2.front(); q2.pop();
			int r=cur.first, c=cur.second;
			visit2[r][c]=1;
			for (int i=0; i<4; ++i) {	// 4 edges
				int rr=r+dirs[i], cc=c+dirs[i+1];
				if (rr<0||cc<0||rr>=m||cc>=n||visit2[rr][cc]) continue;
				if (M[r][c]>M[rr][cc]) continue;
				q2.push(make_pair(rr,cc));
			}
		}

		// justify
		vector<pii> res;
		for (int r=0; r<m; ++r) {
			for (int c=0; c<n; ++c) {
				if (visit1[r][c]==1 && visit2[r][c]==1)
					res.push_back(make_pair(r,c));
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	//			    0......n-1
	vector<vector<int>> matrix{{1,2,2,3,5},		// 0
				   {3,2,3,4,4},		// .
				   {2,4,5,3,1},		// .
				   {6,7,1,4,5},		// .
				   {5,1,1,2,4}};	// m-1
	vector<pii> res;
	res = s.pacificAtlantic(matrix);
	for (auto p: res) cout << p.first << "," << p.second << " ";
	cout << endl;

	res = s.pacificAtlantic1(matrix);
	for (auto p: res) cout << p.first << "," << p.second << " ";
	cout << endl;
}
