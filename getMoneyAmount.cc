#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// top-down DP
	int getMoneyAmount1(int n) {
		vector<vector<int>> dp(n+1, vector<int>(n+1));
		function<int(int,int)> helper=[&](int s, int e) {
			if (s>=e) return 0;
			if (dp[s][e]!=0) return dp[s][e];
			int res=INT_MAX;
			for (int i=s; i<=e; ++i) {
				int tmp=i+max(helper(s,i-1), helper(i+1, e));
				res=min(res,tmp);
			}
			dp[s][e]=res;
			return res;
		};
		return helper(1, n);
	}
	// bottom-up DP
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n+1, vector<int>(n+1));
		for (int j=2; j<=n; ++j) {
			for (int i=j-1; i>0; --i) {
				int gMin=INT_MAX;
				for (int k=i+1; k<j; ++k) {
					int lMax=k+max(dp[i][k-1], dp[k+1][j]);
					gMin=min(gMin, lMax);
				}
				dp[i][j]=i+1==j? i: gMin;
			}
		}
		return dp[1][n];
	}
};
int main(){
	Solution s;
	cout << s.getMoneyAmount(5) << endl;
	cout << s.getMoneyAmount1(5) << endl;
}
