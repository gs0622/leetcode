#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximalSquare(vector<vector<char>>& M) {
    int n=M.size(), m=M[0].size(), sz=0;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
      if (!i||!j||M[i][j]=='0')
        dp[i][j]=M[i][j]-'0';
      else  // max 'Square'
        dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
      sz=max(sz, dp[i][j]);
    }
    return sz*sz;
  }
};
int main(){
}
