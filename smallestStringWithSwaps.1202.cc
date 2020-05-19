#include <bits/stdc++.h>
using namespace std;
class UF {
  vector<int> id;
public:
  UF(int n): id(n) { for (int i=0; i<n; ++i) id[i]=i; }
  int find(int p) { // find the root
    while (p!=id[p]) p=id[p];
    return p;
  }
  void uni(int p, int q) {
    int rp=find(p), rq=find(q);
    if (rp!=rq) id[rp]=rq;
  }
};
class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n=s.size();
    UF uf(n);
    for (auto p: pairs) uf.uni(p[0],p[1]);
    vector<vector<int>> mp(n);
    for (int i=0;i<n;++i) mp[uf.find(i)].push_back(i);  // grouping
    for (auto p: mp) {
      string ss;
      for (auto i: p) ss+=s[i];
      sort(ss.begin(),ss.end());
      for (auto i=0;i<ss.size();++i)
        s[p[i]]=ss[i];
    }
    return s;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{0,3},{1,2}};
  cout << s.smallestStringWithSwaps("dcab",A1) << endl;
  vector<vector<int>> A2{{0,3},{1,2},{0,2}};
  cout << s.smallestStringWithSwaps("dcab",A2) << endl;
  vector<vector<int>> A3{{0,1},{1,2}};
  cout << s.smallestStringWithSwaps("cba",A3) << endl;
}
