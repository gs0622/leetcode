#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<string> simplifiedFractions(int n) {
    vector<string> res;
    for (int i=1;i<=n;++i) {
      for (int j=1;j<i;++j)
        if (i!=j&&__gcd(i,j)==1) {
          res.push_back(to_string(j)+"/"+to_string(i));
        }
    }
    return res;
  }
};
int main(){}
