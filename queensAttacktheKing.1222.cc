#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& Q, vector<int>& K) {
    int board[8][8]={};
    for (auto q: Q) board[q[0]][q[1]]=1;
    vector<vector<int>> res;
    for (int i=-1;i<=1;++i) for (int j=-1;j<=1;++j) {
      if (i==0 && j==0) continue;
      auto x=K[0]+i,y=K[1]+j;
      while (min(x,y)>=0 && max(x,y)<8) {
        if (board[x][y]==1) {
          res.push_back({x,y});
          break;
        }
        x+=i,y+=j;
      }
    }
    return res;
  }
};
int main(){
}
