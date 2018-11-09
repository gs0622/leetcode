/* https://leetcode.com/problems/word-search/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool helper(vector<vector<char>>& bo, string& w, int i, int j, int r, int c, int n) {
		if (n==w.size()) return true; // terminal case
		if (i<0 || j<0 || i>=r || j>=c) return false; // boundry
		if (bo[i][j]!=w[n]) return false; // base case
		// tricky 1: flip bo[i][j] as visit
		// tricky 2: use || to reduce complexity, as the answer only exist in one chosen direction
		bo[i][j]^=-1;
		bool ans = helper(bo, w, i-1, j, r, c, n+1) ||
			helper(bo, w, i+1, j, r, c, n+1) ||
			helper(bo, w, i, j-1, r, c, n+1) ||
			helper(bo, w, i, j+1, r, c, n+1);
		bo[i][j]^=-1;
		return ans;
	}
public:
	bool exist(vector<vector<char>>& bo, string w) {
		int i, j, r=bo.size(), c=bo[0].size();
		for (i=0; i<r; ++i) {
			for (j=0; j<c; ++j) {
				if (helper(bo, w, i, j, r, c, 0) == true)
					return true;
			}
		}
		return false;
	}
};
int main(){
	Solution s;
	vector<vector<char>> bo{{'A','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'}};
	string s1{"ABCCED"};
	cout << s1 << ":" << s.exist(bo, s1) << endl;
	string s2{"SEE"};
	cout << s2 << ":" << s.exist(bo, s2) << endl;
	string s3{"ABCB"};
	cout << s3 << ":" << s.exist(bo, s3) << endl;
	vector<vector<char>> bo2{{'A'}};
	string s4{"A"};
	cout << s4 << ":" << s.exist(bo2, s4) << endl;
}
