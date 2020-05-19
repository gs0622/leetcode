#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<bool> res;
    int n=s.size();
    vector<vector<int>> cnt(n+1,vector<int>(26,0));
    for (int i=0;i<n;++i) {
      cnt[i+1]=cnt[i];
      ++cnt[i+1][s[i]-'a'];
    }
    for (auto q: queries) {
      int sum=0;
      for (int i=0;i<26;++i) {
        sum+=(cnt[q[1]+1][i]-cnt[q[0]][i])%2;
      }
      res.push_back(sum/2 <= q[2]);
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> Q1{{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
  for (auto q: s.canMakePaliQueries("abcda",Q1)) cout << q << " ";
  cout << endl;
}
