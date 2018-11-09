#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numSquares1(int n) {
		static vector<int> dp{0};	// make it reuse-able
		while (dp.size()<=n) {
			int m=dp.size(), square=INT_MAX;
			for (int i=1; i*i<=m; ++i)
				square=min(square,dp[m-i*i]+1);
			dp.push_back(square);
		}
		return dp[n];
	}
	int numSquares(int n) {
		vector<int> sq;
		for (int i=1; i*i<=n; ++i)
			sq.push_back(i*i);
		vector<int> dp(n+1,n+1);
		dp[0]=0;
		for (int i=1; i<=n; ++i) {
			for (auto j: sq) {
				if (j<=i) dp[i]=min(dp[i], dp[i-j]+1);
				else break;
			}
		}
		return dp[n];
	}
};
int main(){
	Solution s;
	cout << s.numSquares1(12) << endl;
	cout << s.numSquares1(13) << endl;
}
