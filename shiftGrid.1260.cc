#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& G, int k) {
    int n=G.size(),m=G[0].size();
    k%=n*m;
    vector<vector<int>> res(n,vector<int>(m));
    for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
      int r=(i*m+j+k)%(n*m)/m,c=(j+k)%m;
      res[r][c]=G[i][j];
    }
    return res;
  }
};
class Solution1 {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& G, int k) {
    int n=G.size(),m=G[0].size();
    vector<vector<int>> res(n,vector<int>(m));
    for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
      int r=(i+(j+k)/m)%n,c=(j+k)%m;
      res[r][c]=G[i][j];
    }
    return res;
  }
};
int main(){}
