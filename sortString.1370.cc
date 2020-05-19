#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string sortString(string s) {
    int n=s.size(), cnt[26]={}, i, j;
    for (auto c: s) ++cnt[c-'a'];
    string res;
    while (res.size()<n) {
      for (int i=0;i<26;++i)
        if (cnt[i]>0)
          res+=i+'a',--cnt[i];
      for (int j=25;j>=0;--j)
        if (cnt[j]>0)
          res+=j+'a',--cnt[j];
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.sortString("aaaabbbbcccc") << endl;
  cout << s.sortString("rat") << endl;
  cout << s.sortString("leetcode") << endl;
}
