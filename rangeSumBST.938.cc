/* https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    string s=to_string(N);
    int dig=s.size(),n=D.size(),res=0;
    for (int i=1;i<dig;++i) res+=pow(n,i);  // e.g., 3^1+3^2...
    for (int i=0;i<dig;++i) {
      bool dup=false;
      for (string d: D) {
        if (d[0]<s[i]) res+=pow(n,dig-i-1);
        else if (d[0]==s[i]) dup=true;
      }
      if (!dup) return res;
    }
    return res+1;
  }
};
int main(){
  Solution s;
  vector<string> A1{"1","3","5","7"};
  cout << s.atMostNGivenDigitSet(A1,100) << endl;
}
