#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // LCS, DP, O(n^2) time, O(n) space
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int m=A.size(), n=B.size();
    vector<int> dp(n+1,0);
    for (int i=0; i<m; ++i) {
      for (int j=n-1; j>=0; --j)
        if (A[i]==B[j]) dp[j+1] = 1+dp[j];
      for (int j=0; j<n; ++j)
        dp[j+1] = max(dp[j+1], dp[j]);
    }
    return dp[n];
  }
};
class Solution {
public: // LCS, DP, O(n^2) (nm) time and space
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int m=A.size(), n=B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) {
      if (A[i-1]==B[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[m][n];
  }
};
int main(){
  Solution s;
  vector<int> A1{1,4,2}, B1{1,2,4};
  cout << s.maxUncrossedLines(A1,B1) << endl;
  vector<int> A2{2,5,1,2,5}, B2{10,5,2,1,5,2};
  cout << s.maxUncrossedLines(A2,B2) << endl;
}
