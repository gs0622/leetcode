/* 
hint: sieve_of_eratosthenes
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  long long MOD=1000000007;
public:
  int numPrimeArrangements(int n) {
    vector<bool> P(n+1,false);   // P for prime
    fill(P.begin()+2,P.end(),true);
    for (int i=2;i*i<=n; ++i) {
      if (P[i]) {
        for (int j=i*i;j<=n;j+=i)
          P[j]=false;
      }
    }
    int cnt=count(P.begin(),P.end(),true);
    function<long long(long long)> factorial=[&](long long i){
      return (i==0||i==1)?1:factorial(i-1)*i%MOD;
    };
    return factorial(cnt)*factorial(n-cnt)%MOD;
  }
};
int main(){
  Solution s;
  cout << s.numPrimeArrangements(5) << endl;
  cout << s.numPrimeArrangements(100) << endl;
}
