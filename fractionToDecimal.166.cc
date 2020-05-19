#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    string res;
    long n=numerator,d=denominator;
    if (n!=0 && n>0^d>0) res+='-';
    n=labs(n),d=labs(d);
    res+=to_string(n/d);
    n%=d;
    if (n==0) return res;
    res+='.';
    unordered_map<int,int> mp;
    for (long i=n;i>0;i%=d) {
      if (mp.count(i)) {
        res.insert(mp[i],1,'(');
        res+=')';
        break;
      }
      mp[i]=res.size(); // {val:pos}
      i*=10;
      res+=to_string(i/d);
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.fractionToDecimal(1,2) << endl;
  cout << s.fractionToDecimal(2,3) << endl;
  cout << s.fractionToDecimal(-1,-2147483648) << endl;
}
