#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution2 {
public:
  int maxDistance(vvi& G) {
    int m=G.size(),n=G[0].size(),res=0;
    queue<vi> q;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      if (G[i][j]==1) q.push({i,j});
    if (q.empty()||q.size()==m*n) return -1;
    vi dirs{1,0,-1,0,1};
    while (q.size()) {
      int nn=q.size();
      for (int i=0;i<nn;++i) {
        auto cur=q.front(); q.pop();
        int r=cur[0],c=cur[1];
        for (int j=0;j<4;++j) {
          int rr=r+dirs[j],cc=c+dirs[j+1];
          if (rr>=0 && rr<m && cc>=0 && cc<n && G[rr][cc]==0)
            G[rr][cc]=-1,q.push({rr,cc});
        }
      }
      ++res;
    }
    return res-1;
  }
};
class Solution {
public:
  int maxDistance(vvi& G) {
    int m=G.size(),n=G[0].size();
    int res=0;
    queue<vi> q;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      if (G[i][j]==1)   // push pos of lands into queue
        q.push({i,j});
    if (q.empty()||q.size()==m*n)
      return -1;
    vi dirs{1,0,-1,0,1};
    while (q.size()) {	// bfs plot distance like color
      auto cur=q.front(); q.pop();
      int r=cur[0],c=cur[1];
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
  Solution2 s;
  vvi G1{{0,0,1},{0,0,0},{0,0,1}};
  cout << s.maxDistance(G1) << endl;
}
