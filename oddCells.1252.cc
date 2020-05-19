#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>>& A) {
    vector<vector<bool>> B(n,vector<bool>(m,false));
    for (auto p: A) {
      for (int i=0;i<m;++i) B[p[0]][i]=!B[p[0]][i];
      for (int i=0;i<n;++i) B[i][p[1]]=!B[i][p[1]];
    }
    int res=0;
    for (auto r: B) for (auto c: r)
      res+=c;
    return res;
  }
};
class Solution2 {
public:
  int oddCells(int n, int m, vector<vector<int>>& A) {
    vector<vector<int>> B(n,vector<int>(m));
    for (auto p: A) {
      for (int i=0;i<m;++i) B[p[0]][i]++;
      for (int i=0;i<n;++i) B[i][p[1]]++;
    }
    int res=0;
    for (auto r: B) for (auto c: r)
      if (c%2) ++res;
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{0,1},{1,1}};
  cout << s.oddCells(2,3,A1) << endl;
}
