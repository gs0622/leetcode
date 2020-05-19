#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int m=matrix.size(), n=matrix[0].size(), res=0;
    vector<int> flip(n);
    for (int i=0, cnt=0; i<m; ++i, cnt=0) {
      for (int j=0; j<n; ++j)
        flip[j]=1-matrix[i][j];
      for (int j=i; j<m; ++j)
        if (matrix[j]==matrix[i] || matrix[j]==flip)
          ++cnt;
      res=max(res,cnt);
    }
    return res;
  }
};
class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int m=matrix.size(), n=matrix[0].size(), res=0, cnt;
    function<bool(int,int)> helper=[&](int i, int j) {
      if (matrix[i][0]==matrix[j][0]) { // same
        for (int k=1; k<n; ++k)
          if (matrix[i][k]!=matrix[j][k])
            return false;
      } else {
        for (int k=1; k<n; ++k)
          if (matrix[i][k]==matrix[j][k])
            return false;
      }
      return true;
    };
    for (int i=0; i<m; ++i) {
      cnt = 0;
      for (int j=i; j<m; ++j)
        if (helper(i,j)) ++cnt;
      res = max(res,cnt);
    }
    return res;
  }
};
typedef vector<int> vi;
typedef vector<vi> vvi;
int main(){
  Solution2 s;
  vvi M1{{0,0,0},{0,0,1},{1,1,0}};
  cout << s.maxEqualRowsAfterFlips(M1) << endl;
}
