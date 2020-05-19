#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int longestCommonSubsequence(string s1, string s2) {
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for (int i=1;i<=m;++i) for (int j=1;j<=n;++j) {
      if (s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[m][n];
  }
};
class Solution {
public:
  int longestCommonSubsequence(string s1, string s2) {
    int m=s1.size(),n=s2.size();
    if (m==0||n==0) return 0;
    if (s1[m-1]==s2[n-1])
      return 1+longestCommonSubsequence(s1.substr(0,m-1),s2.substr(0,n-1));
    else
      return max(longestCommonSubsequence(s1.substr(0,m-1),s2),
                 longestCommonSubsequence(s1,s2.substr(0,n-1)));
  }
};
int main(){
  Solution2 s;
  cout << s.longestCommonSubsequence("abcde","ace") << endl;
}
