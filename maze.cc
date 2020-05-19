/* https://leetcode.com/articles/the-maze/

There is a ball in a maze with empty spaces and walls.
The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array.
1 means the wall and 0 means the empty space.
You may assume that the borders of the maze are all walls.
The start and destination coordinates are represented by row and column indexes.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(mn)
	bool hasPath1(vector<vector<int>>& M, vector<int>& S, vector<int>& D){
		int m=M.size(), n=M[0].size();
		vector<int> dirs{1,0,-1,0,1};
		vector<vector<int>> visit(m, vector<int>(n,0));
		queue<vector<int>> q;
		q.push(S);
		while (q.size()) {
			vector<int> cur = q.front(); q.pop();
			if (cur == D)
				return true;
			//M[cur[0]][cur[1]]=-1;	// visit, while allow pass through
			visit[cur[0]][cur[1]]=1;	// visit
			for (int i=0; i<4; ++i) {
				vector<int> dir={dirs[i], dirs[i+1]};
				int r=cur[0], c=cur[1];
				while (r>=0 && c>=0 && r<m && c<n && M[r][c]!=1) {
					r+=dir[0], c+=dir[1];
				}
				r-=dir[0], c-=dir[1];
				//if (M[r][c]!=-1)
				if (visit[r][c]==0)
					q.push({r,c});
			}
		}
		return false;
	}
	// DFS
	bool hasPath(vector<vector<int>>& M, vector<int>& S, vector<int>& D){
		int m=M.size(), n=M[0].size();
		function<bool(vector<int>)> dfs=[&](vector<int> s) {
			if (s==D)
				return true;
			bool res=false;
			vector<int> dirs{1,0,-1,0,1};
			M[s[0]][s[1]]=-1;	// flip to -1 as visit
			for (int i=0; i<4; ++i) {
				vector<int> dir = {dirs[i], dirs[i+1]};
				int r=s[0], c=s[1];
				while (r>=0 && c>=0 && r<m && c<n && M[r][c]!=1) {
					r+=dir[0], c+=dir[1];
				}
				r-=dir[0], c-=dir[1];
				if (M[r][c]!=-1)
					res |= dfs({r,c});
			}
			return res;
		};
		return dfs(S);
	}
};
int main(){
	Solution s;
	vector<vector<int>> M1{ {0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{1,1,0,1,1},
				{0,0,0,0,0}}, M;
	M = M1;
	vector<int> S1{0,4}, D1{4,4};
	cout << s.hasPath(M, S1, D1) << " " << s.hasPath1(M1, S1, D1) <<  endl;
	vector<int> S2{0,4}, D2{3,2};
	cout << s.hasPath(M, S2, D2) << " " << s.hasPath1(M1, S2, D2) << endl;
}
