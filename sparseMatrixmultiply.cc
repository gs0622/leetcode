#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int r1=A.size(),c1=A[0].size(),r2=B.size(),c2=B[0].size();
    vector<vector<int>> res(r1,vector<int>(c2,0));
    vector<bool> rowA(r1), colB(c2);
    for (int i=0;i<r1;++i) for (int j=0;j<c1;++j) { // O(r1c1)
      if (A[i][j]!=0) {
        rowA[i]=true;
        break;
      }
    }
    for (int i=0;i<r2;++i) for (int j=0;j<c2;++j) { // O(r2c2)
      if (B[i][j]!=0) {
        colB[j]=true;
        break;
      }
    }
    for (int i=0;i<r1;++i) for (int j=0;j<c2;++j) { // O(r1c2)
      if (!rowA[i] || !colB[j]) continue;
      for (int k=0;k<c1;++k)
        res[i][j]+=A[i][k]*B[k][j];
    }
    return res;
  }
};
class Solution2 {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int r1=A.size(),c1=A[0].size(),r2=B.size(),c2=B[0].size();
    vector<vector<int>> res(r1,vector<int>(c2,0));
    for (int i=0;i<r1;++i) for (int j=0;j<c2;++j) { // O(r1c2c1)
      int v=0;
      for (int k=0;k<c1;++k)
        v+=A[i][k]*B[k][j];
      res[i][j]=v;
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{1,0,0},{-1,0,3}}, B1{{7,0,0},{0,0,0},{0,0,1}};
  auto res = s.multiply(A1,B1);
  for (auto r: res) {
    for (auto c: r) cout << c << " ";
    cout << endl;
  }
}
