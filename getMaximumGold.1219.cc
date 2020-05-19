/* https://leetcode.com/problems/path-with-maximum-gold/description/
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:
Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int getMaximumGold(vector<vector<int>>& G) {
    int m=G.size(),n=G[0].size();
    vector<int> dirs{1,0,-1,0,1};
    int sum, res=0;
    function<void(int,int)> helper=[&](int x, int y){
      int cur=G[x][y];
      sum+=cur, G[x][y]=0,res=max(res,gold);  // visit
      for (int i=0;i<4;++i) {
        int xx=x+dirs[i],yy=y+dirs[i+1];
        if (xx<0||xx>=m||yy<0||yy>=n||G[xx][yy]==0) continue;
        helper(xx,yy);
      }
      G[x][y]=cur,gold-=cur;  // backtracing
    };
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      if (G[i][j]==0) continue;
      sum=0;
      helper(i,j);  // start from (i,j) w/ gold
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> G1{{0,6,0},{5,8,7},{0,9,0}};
  cout << s.getMaximumGold(G1) << endl;
}
