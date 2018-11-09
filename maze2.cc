#include <bits/stdc++.h>
using namespace std;
/*
#dfs
*/
class Solution {
public:
	int shortestDistance(vector<vector<int>>& M, vector<int>& S, vector<int>& D) {
		int m=M.size(), n=M[0].size();
		vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
		vector<int> dirs{1,0,-1,0,1};
		function<void(vector<int>)> dfs=[&](vector<int> s) {
			if (s==D) return;
			for (int i=0; i<4; ++i) {
				vector<int> d{dirs[i], dirs[i+1]};
				int r=s[0], c=s[1], dst=dist[r][c];
				while (r>=0 && c>=0 && r<m && c<n && M[r][c]!=1)
					r+=d[0],c+=d[1],++dst;
				r-=d[0],c-=d[1],--dst;
				if (dist[r][c]>dst) {
					dist[r][c]=dst;
					dfs({r,c});
				}
			}
		};
		dist[S[0]][S[1]]=0;
		dfs(S);
		return dist[D[0]][D[1]]==INT_MAX? -1:  dist[D[0]][D[1]];
	}
	// DFS
	bool hasPath(vector<vector<int>>& M, vector<int>& S, vector<int>& D){
		int m=M.size(), n=M[0].size();
		vector<vector<int>> vis(m, vector<int>(n,0));
		vector<int> dirs{1,0,-1,0,1};
		function<bool(vector<int>)> dfs=[&](vector<int> s) {
			if (s==D)
				return true;
			bool res=false;
			vis[s[0]][s[1]]=1;
			for (int i=0; i<4; ++i) {
				vector<int> dir = {dirs[i], dirs[i+1]};
				int r=s[0], c=s[1];
				while (r>=0 && c>=0 && r<m && c<n && M[r][c]!=1)
					r+=dir[0], c+=dir[1];
				r-=dir[0], c-=dir[1];
				if (vis[r][c]==0)
					res |= dfs({r,c});
			}
			return res;
		};
		return dfs(S);
	}
};
int main(){
	Solution s;
	vector<vector<int>> M{	{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{1,1,0,1,1},
				{0,0,0,0,0}};
	vector<int> S1{0,4}, D1{4,4};
	cout << s.hasPath(M, S1, D1) << ": " << s.shortestDistance(M,S1,D1) << endl;
	vector<int> S2{0,4}, D2{3,2};
	cout << s.hasPath(M, S2, D2) << ": " << s.shortestDistance(M,S2,D2) << endl;
}
