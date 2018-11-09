#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int i, j, rows=dungeon.size(), cols=dungeon[0].size();
		vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
		dp[rows][cols-1]=dp[rows-1][cols]=0;
		for (i=rows-1; i>=0; --i) {
			for (j=cols-1; j>=0; --j) {
				int need = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
				dp[i][j]=need<=0? 1: need;
			}
		}
		return dp[0][0];
	}
};
int main(){
	Solution s;
	vector<vector<int>> d{{-2,-3,3},{-5,-10,1},{10,30,-5}};
	//vector<vector<int>> d{{-3,5}};
	cout << s.calculateMinimumHP(d) << endl;
}
