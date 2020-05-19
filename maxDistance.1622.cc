#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxDistance(vector<vector<int>>& G) {
    int m=G.size(),n=G[0].size(),res=0;
    queue<pair<int,int>> q;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      if (G[i][j]) q.push({i,j});
    if (q.empty()||q.size()==m*n) return -1;
    vector<int> dirs{1,0,-1,0,1};
    while (q.size()) {
      auto cur=q.front(); q.pop();
      int r=cur.first,c=cur.second;
      res=G[r][c];
      for (int i=0;i<4;++i) {
        int rr=r+dirs[i],cc=c+dirs[i+1];
        if (rr>=0 && rr<m && cc>=0 && cc<n && G[rr][cc]==0)
          G[rr][cc]=res+1, q.push({rr,cc});
      }
    }
    return res-1;
  }
};
int main(){
  Solution s;
  vector<vector<int>> G1{{1,0,1},{0,0,0},{1,0,1}};
  cout << s.maxDistance(G1) << endl;
}
