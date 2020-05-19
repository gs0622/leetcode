#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution2 {
public:
  int numSubmatrixSumTarget(vvi& M, int T) {
    int m=M.size(), n=M[0].size(), res=0;
    for (int i=0; i<m; ++i) for (int j=1; j<n; ++j)
      M[i][j]+=M[i][j-1];
    for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) {
      unordered_map<int,int> mp{{0,1}};
      int sum=0;
      for (int k=0; k<m; ++k) {
        sum+=M[j][k];
        res += mp[sum-T];
        mp[sum]++;
      }
      return res;
    }
  }
};
class Solution {
public:
  int numSubmatrixSumTarget(vvi& M, int T) {
    int m=M.size(), n=M[0].size(), res=0;
    vi col(n);
    for (int r=0; r<m; ++r) {                 // row start    O(n)
      for (int i=0; i<n; ++i)                 // col setup for col sum per (rr-r+1) row(s)
        col[i]=0;

      for (int rr=r; rr<m; ++rr) {            // row iterate  O(n^2)
        for (int cc=0; cc<n; ++cc)            // col iterate  O(n^3)
          col[cc]+=M[rr][cc];
        int sum=0;
        unordered_map<int,int> pre{{0,1}};
        for (auto c: col) {                   // O(n)
          sum += c;
          res += pre[sum-T];
          pre[sum]++;
        }
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  vvi M1{{0,1,0},{1,1,1},{0,1,0}};
  cout << s.numSubmatrixSumTarget(M1,0) << endl;
  vvi M2{{1,-1},{-1,1}};
  cout << s.numSubmatrixSumTarget(M2,0) << endl;
}
