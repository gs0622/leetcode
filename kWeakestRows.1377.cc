#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& M, int k) {
    int m=M.size(),n=M[0].size();
    vector<int> rows(m);
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      rows[i]+=M[i][j];
    set<pair<int,int>> st;
    for (int i=0;i<m;++i)
      st.insert({rows[i],i});
    vector<int> res;
    auto it=st.begin();
    for (int i=0;i<k;++i) {
      res.push_back(it->second), it++;
    }
    return res;
  }
};
int main(){
}
