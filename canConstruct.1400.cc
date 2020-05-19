#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool canConstruct(string s, int k) {
    int cnt[26]={},odd=0,n=s.size();
    for (auto c: s)
      cnt[c-'a']^=1;
    for (int i=0;i<26;++i)
      odd+=cnt[i];
    return odd<=k && k<=n;
  }
};
int main(){}
