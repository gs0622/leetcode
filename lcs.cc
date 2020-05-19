#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  pair<int,string> longestCommonSubsequence1(string a, string b) {
    int m=a.size(),n=b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;++i) for (int j=1;j<=n;++j) {
      if (a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    string res;
    int i=m, j=n;
    while (i>0 && j>0) {
      if (a[i-1]==b[j-1]) res=a[i-1]+res, --i, --j;
      else if (dp[i-1][j]>dp[i][j-1]) --i;
      else --j;
    }
    return {dp[m][n],res};
  }
  int longestCommonSubsequence(string a, string b) {
    int m=a.size(),n=b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;++i) for (int j=1;j<=n;++j) {
      if (a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[m][n];
  }
};
int main(){
  Solution s;
  cout << s.longestCommonSubsequence("AGGTAB","GXTXAYB") << endl;
  auto p = s.longestCommonSubsequence1("AGGTAB","GXTXAYB");
  cout << p.first << " " << p.second << endl;
}
