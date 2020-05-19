#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string nearestPalindromic(string S) {
    int n=S.size();
    set<long> cand;
    cand.insert((long)pow(10,n)+1);
    cand.insert((long)pow(10,n-1)-1);
    long prefix=stol(S.substr(0,(n+1)/2));
    for (long i=-1; i<=n; ++i) {
      string p=to_string(prefix+i); // 12->11
      string pp=p+string(p.rbegin()+(n&1),p.rend());
      cand.insert(stol(pp));
    }
    long num=stol(S), minDiff=LONG_MAX, diff, minVal;
    cand.erase(num);
    for (long val: cand) {
      diff=abs(val-num);
      if (diff<minDiff)
        minDiff=diff, minVal=val;
      else if (diff==minDiff)
        minVal=min(minVal, val);
    }
    return to_string(minVal);
  }
};
int main(){
  Solution s;
  cout << s.nearestPalindromic("1234") << endl;
  cout << s.nearestPalindromic("123") << endl;
}
