#include <bits/stdc++.h>
/*
b[n-1][0]......... b[n-1][n-1]
             :
	     :
b[0][0] .......... b[0][n-1]
*/
using namespace std;
class Solution {
	bool isValid(vector<string>& b, int row, int col, int n) {	// check before only
		for (int i=0; i<row; ++i)				// scan this col of old rows
			if (b[i][col]=='Q')
				return false;
		for (int i=row-1, j=col-1; i>=0 && j>=0; --i, --j)	// scan 45
			if (b[i][j]=='Q')
				return false;
		for (int i=row-1, j=col+1; i>=0 && j<n; --i, ++j)	// scan 135
			if (b[i][j]=='Q')
				return false;
		return true;
	}
	void helper(vector<vector<string>>& res, vector<string>& b, int row, int &n) {
		if (row == n) {			// base case
			res.push_back(b);
			return;
		}
		for (int col=0; col<n; ++col) {	// enumarate all combinations
			if (isValid(b, row, col, n)) {
				b[row][col]='Q';
				helper(res, b, row+1, n);
				b[row][col]='.';	// backtrack
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> b(n, string(n,'.'));	// board
		helper(res, b, 0, n);
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<string>> res = s.solveNQueens(4);
	for (auto b: res) {
		for (auto bb: b) cout << bb << endl;
	}
}
