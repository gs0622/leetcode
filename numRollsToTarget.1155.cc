#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
  int numRollsToTarget(int d, int f, int target) {
    int dp[31][1001]={};
    function<int(int,int)> helper=[&](int D, int T) {
      if (D==0 || T<=0) return (int)(D==T);
      if (dp[D][T]!=0) return dp[D][T]-1;
      int res=0;
      for (int i=1;i<=f;++i)
        res=(res+helper(D-1,T-i))%1000000007;
      dp[D][T]=res+1;
      return res;
    }; 
    return helper(d,target);
  }
};
class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    if (d==0 || target<=0) return (int)(d==target);
    int res=0;
    for (int i=0;i<=f;++i)
      res=(res+numRollsToTarget(d-1,f,target-i))%1000000007;
    return res;
  }
};
int main(){
  Solution1 s;
  cout << s.numRollsToTarget(1,6,3) << endl;
  cout << s.numRollsToTarget(2,6,7) << endl;
  cout << s.numRollsToTarget(2,5,10) << endl;
  cout << s.numRollsToTarget(1,2,3) << endl;
  cout << s.numRollsToTarget(30,30,500) << endl;
}
