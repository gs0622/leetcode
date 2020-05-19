#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  string base(int n, int neg=-2, string res="") {
    assert(neg<0);
    while (n!=0) {
      int rem=n%neg;
      n/=neg;
      if (rem<0) rem+=-neg, n+=1;
      res=to_string(rem)+res;
    }
    return res.empty()? "0": res;
  }
};
class Solution {
public:
  string base2(int N, string res="") {
    while (N!=0) {
      int rem=N%2;
      N/=2;
      res=to_string(rem)+res;
    }
	  return res.empty()? "0": res;
  }
  string baseNeg2(int N, string res="") {
    while (N!=0) {
      int rem=N%-2;
      N/=-2;
      if (rem<0) rem+=2,N+=1;
      res=to_string(rem)+res;
    }
	  return res.empty()? "0": res;
  }
};
int main(){
  Solution s;
  cout << s.baseNeg2(-2) << endl;
  cout << s.baseNeg2(3) << endl;
  cout << s.baseNeg2(4) << endl;
  cout << s.baseNeg2(0) << endl;
  cout << s.base2(-2) << endl;
  cout << s.base2(3) << endl;
  cout << s.base2(4) << endl;
  cout << s.base2(0) << endl;
}
