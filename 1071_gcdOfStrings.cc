#include <bits/stdc++.h>
using namespace std;
/*
  int gcd(int a, int b)
  {
    if (0==b) return a;
    return gcd(b, a%b);
  }
*/
class Solution2 {
public:
  string gcdOfStrings(string str1, string str2) {
    int max=0, m=str1.size(), n=str2.size();
    //if (m<n) return gcdOfStrings(str2,str1);
    for (int i=1; i<=m && i<=n && str1[i-1]==str2[i-1]; ++i) {
      if (m%i==0 && n%i==0) {
        bool isdiv=true;
        string s=str1.substr(0,i);
        for (int j=2*i; isdiv && j<=m; j+=i)
          isdiv = (s == str1.substr(j-i, i));
        for (int j=2*i; isdiv && j<=n; j+=i)
          isdiv = (s == str2.substr(j-i, i));
        if (isdiv) max = i;
      }
    }
    return str1.substr(0,max);
  }
};
class Solution {
public:
/*
Try to explain it here:
Assume 2 strings are divided by T
Then:
str1 = nT
str2 = mT

n > m:
tempStr = str1-str2 = (n-m)T = kT
str2 - tempStr = (m-k)T = aT
*/
  string gcdOfStrings(string str1, string str2) {
    if (str1.size()<str2.size()) return gcdOfStrings(str2,str1);
    if (str2.empty()) return str1;
    if (str1.substr(0, str2.size()) != str2) return ""; /*nT-mT=(n-m)T*/ 
    return gcdOfStrings(str1.substr(str2.size()), str2);
  }
};
int main(){
  Solution s1;
  Solution2 s2;
  string A1{"ABABAB"}, A2{"ABAB"};
  cout << s1.gcdOfStrings(A1,A2) << ": ";
  cout << s2.gcdOfStrings(A1,A2) << endl;
}
