#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int countBattleships2(vector<vector<char>>& B) {
		int m=B.size(), n=B[0].size(), res=0;
		unordered_set<int> visit;
		vector<int> dirs{1,0,-1,0,1};
		queue<int> q;
		for (int r=0; r<m; ++r) {
			for (int c=0; c<n; ++c) {
				if (B[r][c]=='X' && visit.count(r*n+c)==0) {
					++res;			// bfs start, per 1st 'X'
					q.push(r*n+c);
					while (!q.empty()) {
						int id=q.front(); q.pop();
						for (int i=0; i<4; ++i) {
							int rr=id/n+dirs[i], cc=id%n+dirs[i+1];
							if (rr<0||cc<0||rr>=m||cc>=n||
								B[rr][cc]=='.'||visit.count(rr*n+cc))
								continue;
							visit.insert(rr*n+cc);
							q.push(rr*n+cc);
						}
					}
				}
			}
		}
		return res;
	}
	int countBattleships1(vector<vector<char>>& B) {
		int m=B.size(), n=B[0].size(), res=0;
		unordered_set<int> visit;
		function<void(int,int)> dfs = [&](int r, int c){
			vector<int> dirs{1,0,-1,0,1};
			visit.insert(r*n+c);
			for (int i=0; i<4; ++i) {
				int rr=r+dirs[i], cc=c+dirs[i+1];
				if (rr<0||cc<0||rr>=m||cc>=n||B[rr][cc]=='.'||visit.count(rr*n+cc)==1)
					continue;
				dfs(rr,cc);
			}
		};
		for (int r=0; r<m; ++r) {
			for (int c=0; c<n; ++c) {
				if (B[r][c]=='X' && visit.count(r*n+c)==0) {
					++res;
					dfs(r,c);
				}
			}
		}
		return res;
	}
	// linear, traverse all cells, count the 1st seen 'X'
	int countBattleships(vector<vector<char>>& B) {
		int m=B.size(), n=B[0].size();
		int res=0;
		for (int r=0; r<m; ++r) {
			for (int c=0; c<n; ++c) {
				if (B[r][c]=='.') continue;
				if (r>0 && B[r-1][c]=='X') continue;	// ↓
				if (c>0 && B[r][c-1]=='X') continue;	// → 
				++res;	// first seen 'X'
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<char>> B1{{'X','.','X'},
				{'.','.','X'},
				{'.','.','X'}};
	cout << s.countBattleships(B1) << endl;
	cout << s.countBattleships1(B1) << endl;
	cout << s.countBattleships2(B1) << endl;
}
