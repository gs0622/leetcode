/* https://leetcode.com/problems/minimum-path-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& g) {
		int i, j, m=g.size(), n=g[0].size();
		vector<vector<long long>> dp(m+1, vector<long long>(n+1, INT_MAX));
		dp[1][0]=dp[0][1]=0;
		for (i=1; i<=m; ++i) {
			for (j=1; j<=n; ++j) {
				dp[i][j]=std::min(dp[i-1][j]+g[i-1][j-1], dp[i][j-1]+g[i-1][j-1]);
			}
		}
		return dp[m][n];
	}
};
int main(){
	Solution s;
	vector<vector<int>> m{{1,3,1},{1,5,1},{4,2,1}};
	cout << s.minPathSum(m) << endl;
}
