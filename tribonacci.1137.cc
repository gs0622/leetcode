#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
    int tribonacci(int n) {
      if (n==0) return 0;
      if (n==1 || n==2) return 1;
      int t0=0,t1=1,t2=1,t3=t2+t1+t0;
      for (int i=3;i<=n;++i) {
        t3=t2+t1+t0;
        t0=t1,t1=t2,t2=t3;
      }
      return t3;
    }
};
class Solution {
    int memo[100];
public:
    Solution() { for (int i=0;i<100;++i) memo[i]=-1; }
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        if (memo[n]!=-1) return memo[n];
        int res=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        memo[n]=res;
        return res;
    }
};
int main(){
  Solution2 s;
  cout << s.tribonacci(4) << endl;
  cout << s.tribonacci(25) << endl;
}
