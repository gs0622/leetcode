#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& A) {
    int n=A.size();
    queue<vector<int>> q;
    q.push({0,0});
    vector<int> res;
    while (q.size()) {
      auto r=q.front()[0],c=q.front()[1]; q.pop();
      res.push_back(A[r][c]);
      if (c==0 && r+1<n) q.push({r+1,c});
      if (c+1<A[r].size()) q.push({r,c+1});
    }
    return res;
  }
};
class Solution1 {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& A) {
    int n=A.size();
    map<int,vector<int>> mp;
    for (int i=0;i<n;++i) {
      int m=A[i].size();
      for (int j=0;j<m;++j) {
        mp[i+j].push_back(A[i][j]);
      }
    }
    vector<int> res;
    for (auto it: mp)
      res.insert(res.end(),it.second.begin(),it.second.end());
    return res;
  }
};
int main(){
  Solution s;
}
