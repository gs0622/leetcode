#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int balancedStringSplit(string s) {
    int n=s.size(),l=0,r=0,res=0;
    for (int i=0;i<n;++i) {
      if (s[i]=='L') ++l;
      else ++r;
      if (l==r) ++res,l=r=0;
    }
    return res;
  }
};
int main(){
}
