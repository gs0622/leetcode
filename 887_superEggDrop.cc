#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution3 {
public: // O(KlogN) Time, O(NK) Space
  int superEggDrop(int K, int N) {  // K eggs, N floors
    vvi dp(N+1,vi(K+1,0));
    int m=0;
    while (dp[m][K]<N) {
      ++m;
      for (int k=1; k<=K; ++k)
        dp[m][k]=dp[m-1][k-1]+dp[m-1][k]+1;
    }
    return m;
  }
};
class Solution2 {
public: // time: O(O(KN^2)) brute-force DP, dp[k][n] = min(1 + max(dp[k-1][i-1], dp[k][n-i])) i = 1...n
  int superEggDrop(int K, int N) {  // K eggs, N floors
    vvi dp(K+1,vi(N+1,0));
    function<int(int,int)> helper=[&](int k, int n) {
      if (n<=1 || k==1) return n;
      if (dp[k][n]>0) return dp[k][n];
      int lo=1, hi=n, res=max(k,n);
      while (lo<hi) {
        int mi=lo+(hi-lo)/2;
        int left=helper(k-1,mi-1);
        int right=helper(k,n-mi);
        res=min(res,max(left,right)+1);
        if (left==right) break;
        else if (left<right) lo=mi+1;
        else hi=mi;
      }
      dp[k][n]=res;
      return res;
    };
    return helper(K,N);
  }
};
class Solution {
public: // time: O(O(KN^2)) brute-force DP, dp[k][n] = min(1 + max(dp[k-1][i-1], dp[k][n-i])) i = 1...n
  int superEggDrop(int K, int N) {  // K eggs, N floors
    vvi dp(K+1,vi(N+1,0));
    function<int(int,int)> helper=[&](int k, int n){
      if (n<=1) return n;
      if (k==1) return n;
      if (dp[k][n]>0) return dp[k][n];
      int res=max(n,k);
      for (int i=1; i<=n; ++i) {            // O(n): access to floors[1:n]
        int left=helper(k-1,i-1);           // O(kn^2): if the egg breaks, downstair: dp[k-1][i-1]
        int right=helper(k,n-i);            // O(kn^2): if the egg does not break: dp[k][n-i]
        res = min(res, max(left,right)+1);  // +1 for one throw
      }
      dp[k][n]=res;
      return res;
    };
    return helper(K,N); // moves
  }
};
int main(){
  Solution2 s;
  cout << s.superEggDrop(1,2) << endl;
  cout << s.superEggDrop(2,6) << endl;
  cout << s.superEggDrop(3,14) << endl;
  cout << s.superEggDrop(4,5000) << endl;
}
