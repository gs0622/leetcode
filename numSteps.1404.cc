#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numSteps(string s) {
    int n=s.size(),res=0,carry=0;
    for (int i=n-1;i>0;--i,++res) {
      if (s[i]-'0'+carry==1)
        carry=1,++res;
    }
    return res+carry;
  }
};
class Solution1 {
public:
  int numSteps(string s) {
    int n=s.size(),add=0,carry=0;
    for (int i=n-1;i>0;--i) {
      add+=(s[i]-'0'+carry)==1;
      carry|=(s[i]=='1');
    }
    return n-1 // div
      +add+carry;
  }
};
int main(){
  Solution s;
  cout << s.numSteps("1101") << endl;
}
