/* https://leetcode.com/problems/swim-in-rising-water/description/

On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

hint: binary search, dfs, union find

*/
#include <bits/stdc++.h>
using namespace std;
class UF {
	vector<int> id;
public:
	int find(int p) {	// find root
		while (p != id[p]) p = id[p];
		return p;
	}
	UF(int n=10) {
		for (int i=0; i<n; ++i) id.push_back(i);
	}
	bool isConnect(int p, int q) {
		return find(p) == find(q);
	}
	void uni(int p, int q) {
		if (isConnect(p, q)) return;
		int rp = find(p), rq = find(q);
		id[rp] = rq;
	}
};

class UF2 {
	unordered_map<int,int> id;
public:
	UF2(int n) {
		for (int i=0; i<n; ++i)
			id[i]=i;
	}
	int find(int p) {
		if (p==id[p]) return p;
		return find(id[p]);
	}
	bool isConnect(int p, int q) {
		return find(p)==find(q);
	}
	void uni(int p, int q) {
		int rp=find(p), rq=find(q);
		if (rp!=rq) id[rp]=rq;
	}
};

class Solution {
public:
	// binary search + BFS, O(n^2*log(n)) n^2*(log(n^2))=n^2*(2log(n))
	int swimInWater3(vector<vector<int>>& grid) {
		int n=grid.size();
		int lo=0, hi=n*n-1;
		function<bool(int)> bfs = [&](int mi){
			vector<int> dirs{1,0,-1,0,1};
			unordered_set<int> visit;
			queue<int> q;
			q.push(0);
			int w = grid[mi/n][mi%n];
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				visit.insert(cur);
				int row=cur/n, col=cur%n;
				for (int i=0; i<4; ++i) {
					int r=row+dirs[i], c=col+dirs[i+1];
					if (r<0||c<0||r>=n||c>=n||
						visit.count(r*n+c)||grid[r][c]>w)
						continue;
					if (r==n-1&&c==n-1) return true;
					q.push(r*n+c);
				}
			}
			return false;
		};
		while (lo<hi) {
			int mi=lo+(hi-lo)/2;
			if (bfs(mi))
				hi=mi;
			else lo=mi+1;
		}
		return lo;
	}
	// binary search + DFS, O(n^2*log(n))
	int swimInWater2(vector<vector<int>>& grid) {
		int n=grid.size();
		function<bool(int)> valid = [&](int mi){
			vector<vector<int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
			unordered_set<int> visit;
			function<bool(int,int,int)> dfs = [&](int r, int c, int w) {
				visit.insert(r*n+c);
				for (int i=0; i<4; ++i)	{	// 4 edges
					int rr=r+dirs[i][0], cc=c+dirs[i][1];
					if (rr<0 || rr>=n || cc<0 || cc>=n ||
						visit.count(rr*n+cc) || grid[rr][cc]>w)	// <- eliminate higher waterlevel neighber
						continue;
					if (rr==n-1 && cc==n-1)
						return true;	// bingo!
					if (dfs(rr,cc,w)) return true;;
				}
				return false;
			};
			int r=mi/n, c=mi%n;
			return dfs(0, 0, grid[r][c]);	// always varify from [0][0], O(n^2)
		};
		int lo=0, hi=n*n-1;			// boundries
		while (lo<hi) {				// binary search takes O(log(n))
			int mi=lo+(hi-lo)/2;
			if (valid(mi)) hi=mi;		// embedded O(n^2) dfs
			else lo=mi+1;
		}
		return lo;
	}
	// BFS + priority_queue
	// Dijkstra using Priority Queue, O(n^2logn), 20 ms;
	// In every step, find lowest water level to move forward, so using PQ rather than queue
	int swimInWater1(vector<vector<int>>& grid) {
		unordered_set<int> visit;
		function<bool(pair<int,int>& a, pair<int,int>& b)> cmp = [](pair<int,int>& a, pair<int,int>& b) {return a.first > b.first;};
		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
		pq.push(make_pair(grid[0][0], 0));		// water(depth)-coordination(2D->1D)
		vector<vector<int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
		int n=grid.size(), res=0;
		while (!pq.empty()) {
			pair<int,int> top = pq.top(); pq.pop();	// lowest water level
			int r=top.second/n, c=top.second%n;
			res=max(res, grid[r][c]);
			if (r==n-1 && c==n-1) return res;
			for (auto d: dirs) {			// evaluate 4-way neighborhood
				int i=r+d[0], j=c+d[1], idx=i*n+j;
				if (i<0 || i>=n || j<0 || j>=n || visit.count(idx)) continue;
				pq.push(make_pair(grid[i][j], idx));
				visit.insert(idx);
			}
		}
		return res;
	}
	// O(n^2) brute force union find
	int swimInWater(vector<vector<int>>& grid) {
		int n=grid.size(); // n-by-n
		UF g(n*n);
		priority_queue<int, vector<int>, greater<int>> pq;		// minheap
		for (auto row: grid) {
			for (auto cell: row) pq.push(cell);
		}
		int time = pq.top(); pq.pop();
		while (!g.isConnect(0, n*n-1)) {				// think grids in a plane of UF
			for (int i=0; i<n; ++i) {				// scan all n-by-n grids
				for (int j=0; j<n; ++j) {
					if (grid[i][j] > time) continue;	// elevation > water deep
					// percolation model, look right and down
					if (i<n-1 && grid[i+1][j] <= time)	// union grid[i][j] to grid[i+1][j]
						g.uni(i*n+j, (i+1)*n+j);
					if (j<n-1 && grid[i][j+1] <= time)	// union grid[i][j] to grid[i][j+1] 
						g.uni(i*n+j, i*n+j+1);
				}
			}
			if (g.isConnect(0, n*n-1)) break;
			time = pq.top(), pq.pop();
		}
		return time;
	} 
};

class Solution2 {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int n=grid.size();	//n-by-n
		UF uf(n*n);
		priority_queue<int,vector<int>,greater<int>> pq;
		for (auto row: grid) for (auto col: row) pq.push(col);	// O(n*n*log(n*n))
		int t=pq.top(); pq.pop();
		while (uf.find(0)!=uf.find(n*n-1)) {
			for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
				if (grid[i][j]>t) continue;	// not yet
				// grid[i][j]<=t, try swin
				if (i+1<n && grid[i+1][j]<=t) uf.uni(i*n+j,(i+1)*n+j);
				if (j+1<n && grid[i][j+1]<=t) uf.uni(i*n+j,i*n+j+1);
			}
			if (uf.find(0)==uf.find(n*n-1)) break;
			t=pq.top(), pq.pop();
			// skip double break;
		}
		return t;
	}
};
int main(){
	Solution s;
	Solution2 s2;
	vector<vector<int>> grid{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
	cout << s2.swimInWater(grid) << endl;
	cout << s.swimInWater(grid) << endl;
	cout << s.swimInWater1(grid) << endl;
	cout << s.swimInWater2(grid) << endl;
	cout << s.swimInWater3(grid) << endl;
}
