/* https://leetcode.com/problems/nth-magical-number/description/

A positive integer is magical if it is divisible by either A or B.
Return the N-th magical number.  Since the answer may be very large, return it modulo 10^9 + 7.

Note:
1 <= N <= 10^9
2 <= A <= 40000
2 <= B <= 40000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // O(log(10^14))
  int nthMagicalNumber(int N, int A, int B) {
    long lo=2, hi=1e14, lcm=A*B/__gcd(A,B), mod=1e9+7;
    while (lo<hi) {
      long mi=lo+(hi-lo)/2;
      if ((mi/A+mi/B-mi/lcm)<N) lo=mi+1;
      else hi=mi;
    }
    return lo%mod;
  }
};
class Solution {
public: // wrong because it does not consider LCM
  int nthMagicalNumber(int N, int A, int B) {
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(A), pq.push(B);
    for (int i=1,j=N,mul=1; i<=N; i+=2) {
      int top=pq.top(); pq.pop(), --j;
      if (j==0) return top;
      top=pq.top(), pq.pop(), --j;
      if (j==0) return top;
      ++mul;
      pq.push(A*mul), pq.push(B*mul);
    }
  }
};
int main(){
  Solution2 s;
  cout << s.nthMagicalNumber(4,2,3) << endl;
  cout << s.nthMagicalNumber(5,2,4) << endl;
  cout << s.nthMagicalNumber(3,6,4) << endl;
  cout << s.nthMagicalNumber(1000000000,40000,40000) << endl;
}
