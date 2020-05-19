#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& M, int sr, int sc, int newColor) {
    int m=M.size(),n=M[0].size(),oldColor=M[sr][sc];
    queue<vector<int>> q;
    q.push({sr,sc});
    vector<int> dirs{-1,0,1,0,-1};
    set<pair<int,int>> visit;
    while (q.size()) {
      auto p=q.front();q.pop();
      int r=p[0],c=p[1];
      M[r][c]=newColor;
      visit.insert({r,c});
      for (int i=0;i<4;++i) {
        int rr=r+dirs[i],cc=c+dirs[i+1];
        if (rr<0||rr>=m||cc<0||cc>=n) continue;
        if (visit.count({rr,cc})) continue;
        if (M[rr][cc]==oldColor) q.push({rr,cc});
      }
    }
    return M;
  }
};
int main(){
  Solution s;
  vector<vector<int>> M1{{0,0,0},
                         {0,1,1}};
  for (auto r: s.floodFill(M1,1,1,1)) {
    for (auto c: r)
      cout << c << " ";
    cout << endl;
  }
}
