#include <bits/stdc++.h>
using namespace std;
class Solution2 {
  class UF {
    vector<int> id;
  public:
    int cnt=0;
    UF(vector<vector<char>>& G) {
      int m=G.size(),n=G[0].size();
      id.resize(m*n);
      for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
        if (G[i][j]=='1') {
          id[i*n+j]=i*n+j;
          cnt+=1; // non-union count
        }
      }
    }
    int find(int p) {
      while (p!=id[p]) p=id[p];
      return p;
    }
    void uni(int p, int q) {
      int rp=find(p),rq=find(q);
      if (rp!=rq) id[rp]=rq,--cnt;  // after union
    }
  };
public: // union-find
  int numIslands(vector<vector<char>>& G) {
    int m=G.size(),n=m?G[0].size():0,res=0;
    if (m==0||n==0) return 0;
    UF uf(G);
    function<int(int,int)> pos=[&](int r, int c){return r*n+c;};
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      if (G[i][j]=='0') continue;
      if (i<m-1 && G[i+1][j]=='1') uf.uni(pos(i,j),pos(i+1,j));
      if (j<n-1 && G[i][j+1]=='1') uf.uni(pos(i,j),pos(i,j+1));
    }
    return uf.cnt;
  }
};
class Solution {
public: // dfs
  int numIslands(vector<vector<char>>& G) {
    int m=G.size(),n=m?G[0].size():0,res=0;
    if (m==0||n==0) return 0;
    vector<int> dirs{1,0,-1,0,1};
    function<void(int,int)> dfs=[&](int i, int j){
      if (G[i][j]!='1') return; // '0' or '2'
      G[i][j]='2';  // visit
      for (int k=0;k<4;++k) {
        int r=i+dirs[k], c=j+dirs[k+1];
        if (r<0||r>=m||c<0||c>=n) continue;
        dfs(r,c);
      }
    };
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
        if (G[i][j]=='1') dfs(i,j), ++res;
    }
    return res;
  }
};
int main(){
  Solution2 s;
  vector<vector<char>> G1{{'1','1','1','1','0'},
                          {'1','1','0','1','0'},
                          {'1','1','0','0','0'},
                          {'0','0','0','0','0'}};
  cout << s.numIslands(G1) << endl;
}
