/* https://www.cnblogs.com/grandyang/p/5297683.html
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
  int shortestDistance(vvi& G) {
    int m=G.size(),n=G[0].size(),val=0,res;
    vvi sum=G;
    vi dirs{1,0,-1,0,1};
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      if (G[i][j]==1) {
        res=INT_MAX;
        vvi dst=G;
        queue<vi> q; q.push({i,j});
        while (q.size()) {
          auto cur=q.front(); q.pop();
          for (int k=0;k<4;++k) {
            int r=cur[0]+dirs[k],c=cur[1]+dirs[k+1];
            if (r>=0 && r<m && c>=0 && c<n && G[r][c]==val) {
              --G[r][c];
              dst[r][c]=dst[cur[0]][cur[1]]+1;
              sum[r][c]+=dst[r][c]-1;
              q.push({r,c});
              res=min(res,sum[r][c]);
            }
          }
        }
        --val;
      }
    }
    return res==INT_MAX?-1:res;
  }
};
int main(){
  Solution s;
  vvi G1{{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
  cout << s.shortestDistance(G1) << endl;
}
