#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
class Solution2 {
	class UF {
		vi id;
		int cnt;
	public:
		UF(int n=10) {
			cnt=n;
			for (int i=0; i<n; ++i) id.push_back(i);
		}
		int find(int p) {
			while (p!=id[p]) p=id[p];
			return id[p];
		}
		void uni(int p, int q) {
			p=find(p), q=find(q);
			if (p!=q)	// not connected
				id[p]=q, --cnt;
		}
		int groups(void) { return cnt; }
	};
public:
/*
	+-----+
	|\ 0 /|
	| \ / |
	|3/ \1|
	|/ 2 \|
	+-----+
*/
	int regionsBySlashes(vs& grid) {
		int n=grid.size();
		UF uf(n*n*4);	// 4 pieces per grid;
		function<int(int,int,int)> map=[&](int i, int j, int k) { return (i*n+j)*4+k; };
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
			if (i>0) uf.uni(map(i,j,0), map(i-1,j,2));
			if (j>0) uf.uni(map(i,j,3), map(i,j-1,1));
			if (grid[i][j]!='/')
				uf.uni(map(i,j,0), map(i,j,1)), uf.uni(map(i,j,2), map(i,j,3));
			if (grid[i][j]!='\\')
				uf.uni(map(i,j,0), map(i,j,3)), uf.uni(map(i,j,1), map(i,j,2));
		}
		return uf.groups();
	}
};
class Solution {
public:
	int regionsBySlashes(vector<string>& grid) {
		int n=grid.size(), res=0;
		vvi g(n*3, vi(n*3, 0));
		int nn=g.size();
		for (auto i=0; i<n; ++i) for (auto j=0; j<n; ++j) {	// upscaling
			if (grid[i][j]=='/') g[i*3][j*3+2]=g[i*3+1][j*3+1]=g[i*3+2][j*3]=1;
			if (grid[i][j]=='\\') g[i*3][j*3]=g[i*3+1][j*3+1]=g[i*3+2][j*3+2]=1;
		}
		function<void(int,int)> dfs=[&](int i, int j) {
			if (i>=0 && j>=0 && i<nn && j<nn && g[i][j]==0) {
				g[i][j]=1;
				dfs(i-1,j), dfs(i+1,j), dfs(i,j-1), dfs(i,j+1);
			}
		};
		for (auto i=0; i<nn; ++i) for (auto j=0; j<nn; ++j) {
			if (g[i][j]==0) dfs(i,j), ++res;
		}
		return res;
	}
};
int main(){
	Solution2 s;
	vs S1{" /","/ "};
	cout << s.regionsBySlashes(S1) << endl;
	vs S2{"/\\","\\/"};
	cout << s.regionsBySlashes(S2) << endl;
}

