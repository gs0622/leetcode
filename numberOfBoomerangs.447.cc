#include <bits/stdc++.h>
using namespace std;
class Solution {
  int numberOfBoomerangs(vector<vector<int>>& P) {
    unordered_map<int,unordered_set<int>> mp;
    int n=P.size();
    for (int i=0;i<n;++i) {
      for (int j=i+1;j<n;++j) {
        int d=(P[i][0]-P[j][0])*(P[i][0]-P[j][0])+(P[i][1]-P[j][1])*(P[i][1]-P[j][1]);
        mp[d].insert(i),mp[d].insert(j);
      }
    }
    int res=0;
    for (auto p: mp) {
      if (p.second.size()<3) continue;
      int c=p.second.size();
      res+=c*(c-1)/3;
    }
    return res;
  }
};
int main(){}
