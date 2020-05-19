#include <bits/stdc++.h>
using namespace std;
class Solution2 {
  class UF {
    vector<int> id;
  public:
    UF(vector<vector<int>>& G) {
      int m=G.size(),n=G[0].size();
      id.resize(m*n);
      for (int i=0;i<m;++i)   // 2D grid to 1D union find
        for (int j=0;j<n;++j)
          if (G[i][j]==1) id[i*n+j]=i*n+j;
          else id[i*n+j]=-1;
    }
    int find(int p) {
      while (p!=id[p]) p=id[p];
      return p;
    }
    void uni(int p, int q) {
      int rp=find(p),rq=find(q);
      if (rp!=rq) id[rp]=rq;
    }
    int maxgroup() {
      int n=id.size(),res=0;
      vector<int> cnt(n,0);
      for (int i=0; i<n; ++i) { // n==O(mn)
        if (id[i]!=-1) {
          int root=find(id[i]);
          ++cnt[root];
          res=max(res,cnt[root]);
        }
      }
      return res;
    }
  };
public: // union-find
  int maxAreaOfIsland(vector<vector<int>>& G) {
    int m=G.size(),n=m?G[0].size():0,res=0;
    if (m==0||n==0) return 0;
    UF uf(G);
    function<int(int,int)> pos=[&](int r, int c){return r*n+c;};
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      if (G[i][j]==0) continue;
      if (i<m-1 && G[i+1][j]==1) uf.uni(pos(i,j),pos(i+1,j));
      if (j<n-1 && G[i][j+1]==1) uf.uni(pos(i,j),pos(i,j+1));
    }
    return uf.maxgroup();
  }
};
class Solution {
public: // dfs
  int maxAreaOfIsland(vector<vector<int>>& G) {
    if (G.empty()||G[0].empty()) return 0;
    int m=G.size(),n=G[0].size(),res=0;
    function<int(int,int)> dfs=[&](int i, int j){
      if (i>=0 && i<m && j>=0 && j<n && G[i][j]==1) { // think about what is the (virtual) 'edge'
        G[i][j]=2;  // visit
        return 1+dfs(i+1,j)+dfs(i-1,j)+dfs(i,j+1)+dfs(i,j-1);
      }
      return 0;
    };
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
        if (G[i][j]==1) res=max(res,dfs(i,j));
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> G1{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
  cout << s.maxAreaOfIsland(G1) << endl;
}
