#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int nthUglyNumber(int n, int A, int B, int C) {
    long a=long(A),b=long(B),c=long(C);
    long ab=a*b/__gcd(a,b);
    long bc=b*c/__gcd(b,c);
    long ac=a*c/__gcd(a,c);
    long abc=a*bc/__gcd(a,bc);
    int lo=1,hi=2*1e9;
    while (lo<hi) {
      int mi=lo+(hi-lo)/2;
      int cnt=mi/a+mi/b+mi/c-mi/ab-mi/bc-mi/ac+mi/abc;
      if (cnt<n) lo=mi+1;
      else hi=mi;
    }
    return lo;
  }
};
int main(){
  Solution s;
  cout << s.nthUglyNumber(1000000000,2,217983653,336916467) << endl;
}
