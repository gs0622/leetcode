#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void gameOfLife1(vector<vector<int>>& board) {
		int m=board.size(), n=m? board[0].size(): 0;
		vector<vector<int>> res(m,vector<int>(n,0));
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
			int cnt=0;
			for (int r=max(i-1,0); r<min(i+2,m); ++r) for (int c=max(j-1,0); c<min(j+2,n); ++c)
				cnt+=board[r][c]&1;
			if (cnt==3 || cnt-board[i][j]==3) board[i][j]|=2;
		}
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j)
			board[i][j]>>=1;
	}
	void gameOfLife(vector<vector<int>>& board) {
		int m=board.size(), n=board[0].size();
		vector<vector<int>> res(m, vector<int>(n,0));
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
			int cnt=0;
			if (i-1>=0 && board[i-1][j]==1) ++cnt; 
			if (j-1>=0 && board[i][j-1]==1) ++cnt; 
			if (i-1>=0 && j-1>=0 && board[i-1][j-1]==1) ++cnt; 
			if (i-1>=0 && j+1<n && board[i-1][j+1]==1) ++cnt; 
			if (i+1<m && board[i+1][j]==1) ++cnt; 
			if (j+1<n && board[i][j+1]==1) ++cnt;
			if (i+1<m && j+1<n && board[i+1][j+1]==1) ++cnt; 
			if (i+1<m && j-1>=0 && board[i+1][j-1]==1) ++cnt; 
			if (board[i][j]==1 && cnt>=2 && cnt<=3) res[i][j]=1;
			if (board[i][j]==0 && cnt==3) res[i][j]=1;
		}
		board.swap(res);
	}
};
int main(){
	Solution s;
	vector<vector<int>> B1{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	for (auto r: B1) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
	cout << endl;
	s.gameOfLife1(B1);
	for (auto r: B1) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
}
