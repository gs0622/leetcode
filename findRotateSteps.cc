#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // O(mn^2)
  int findRotateSteps(string ring, string key) {
    int n=ring.size(), m=key.size();
    vector<vector<int>> dp(m+1,vector<int>(n));
    for (int i=m-1; i>=0; --i) for (int j=0; j<n; ++j) {
      dp[i][j]=INT_MAX;
      for (int k=0; k<n; ++k) {
        if (ring[k]==key[i]) {
          int diff=abs(j-k), step=min(diff,n-diff);
          dp[i][j]=min(dp[i][j],step+dp[i+1][k]);
        }
      }
    }
    return dp[0][0]+m;
  }
};
int main(){
  Solution s;
  cout << s.findRotateSteps("godding", "gd") << endl;
}
