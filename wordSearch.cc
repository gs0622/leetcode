/* https://leetcode.com/problems/word-search/description/
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // TLE
  bool exist(vector<vector<char>>& bo, string w) {
    int n=w.size(),r=bo.size(),c=bo[0].size();
    vector<vector<int>> visit(r,vector<int>(c,0));
    bool res=false;
    string s;
    function<bool(int,int,int)> helper=[&](int i, int j, int k) {
      if (k==w.size()) return true;
      if (i<0||i>=r||j<0||j>=c) return false;
      if (visit[i][j]==1) return false;
      if (bo[i][j]!=w[k]) return false;
      s+=bo[i][j],visit[i][j]=1;
      bool ans = helper(i+1,j,k+1)
        || helper(i-1,j,k+1)
        || helper(i,j+1,k+1)
        || helper(i,j-1,k+1);
      s.pop_back(),visit[i][j]=0;
      return ans;
    };
    for (int i=0;i<r;++i) for (int j=0;j<c;++j)
      res |= helper(i,j,0);
    return res;
  }
};
class Solution {
	bool helper(vector<vector<char>>& bo, string s, string& w, int i, int j, int r, int c, vector<vector<int>>& vi) {
		int n=s.size();
		if (n>w.size()) return false;
		if (s==w) return true;
		vi[i][j]=1;
		char ch = w[n];
		bool ans = false;
		if (i>0 && bo[i-1][j]==ch && vi[i-1][j]==0)
			ans |= helper(bo, s+ch, w, i-1, j, r, c, vi);
		if (i<r-1 && bo[i+1][j]==ch && vi[i+1][j]==0)
			ans |= helper(bo, s+ch, w, i+1, j, r, c, vi);
		if (j>0 && bo[i][j-1]==ch && vi[i][j-1]==0)
			ans |= helper(bo, s+ch, w, i, j-1, r, c, vi);
		if (j<c-1 && bo[i][j+1]==ch && vi[i][j+1]==0)
			ans |= helper(bo, s+ch, w, i, j+1, r, c, vi);
		vi[i][j]=0;
		return ans;
	}
public:
	bool exist(vector<vector<char>>& bo, string w) {
		int i, j, r=bo.size(), c=bo[0].size();
		vector<vector<int>> vi(r, vector<int>(c, 0));
		string s;
		return helper(bo, s, w, 0, 0, r, c, vi);
	}
	bool exist2(vector<vector<char>>& bo, string w) {
		int i, j, r=bo.size(), c=bo[0].size();
		bool ans = false;
		for (i=0; i<r; ++i) {
			for (j=0; j<c; ++j) {
				if (bo[i][j]==w[0]) {
					string s=w.substr(0,1);
					vector<vector<int>> vi(r, vector<int>(c, 0));
					ans |= helper(bo, s, w, i, j, r, c, vi);
				}
			}
		}
		return ans;
	}
};
int main(){
	Solution s;
	Solution2 s2;
	vector<vector<char>> bo{{'A','B','C','E'},{'S','F','E','S'}, {'A','D','E','E'}};
	string s1{"ABCESEEEFS"};
	//string s1{"ABCCED"};
	//cout << s.exist(bo, s1) << endl;
	cout << s2.exist(bo, s1) << endl;
	cout << s.exist2(bo, s1) << endl;
}
