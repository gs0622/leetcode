#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& A) {
      int n=A.size(),res=0,max=0;
      vector<int> dp(n), cnt(n);
      for (int i=0;i<n;++i) {
        dp[i]=cnt[i]=1;
        for (int j=0;j<i;++j) {
          if (A[i]>A[j]) {
            if (dp[i]==dp[j]+1)
              cnt[i]+=cnt[j];
            if (dp[i]<dp[j]+1) {
              dp[i]=dp[j]+1;
              cnt[i]=cnt[j];
            }
          }
        }
        if (max==dp[i])
          res+=cnt[i];
        if (max<dp[i]) {
          max=dp[i];
          res=cnt[i];
        }
      }
      return res;
    }
};
int main(){
  Solution s;
  vector<int> A1{1,3,5,4,7};
  //vector<int> A1{2,2,2,2,2};
  cout << s.findNumberOfLIS(A1) << endl;
}
