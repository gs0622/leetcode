#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int closedIsland(vector<vector<int>>& G) {
    int m=G.size(),n=G[0].size(),res=0;
    function<void(int,int)> helper=[&](int r, int c) {
      if (r<0||r>=m||c<0||c>=n||G[r][c]==1) return; // out-of-bound
      G[r][c]=1;  // visit
      helper(r+1,c),helper(r-1,c),helper(r,c+1),helper(r,c-1);
    };
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      if ((i==0||j==0||i==m-1||j==n-1) && (G[i][j]==0))
        helper(i,j);
    }
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      if (G[i][j]==0) helper(i,j),++res;
    return res;
  }
};
int main(){}
