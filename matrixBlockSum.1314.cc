/* https://leetcode.com/problems/matrix-block-sum/description/

        c1  c2
     1   2   3
  r1 4   5   6
  r2 7   8   9
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  // O(mn)
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& M, int K) {
    int m=M.size(),n=M[0].size();
    vector<vector<int>> res(m,vector<int>(n));
    vector<vector<int>> sum(m+1,vector<int>(n+1));  // extra boarders: up/left
    for (int i=1;i<=m;++i) for (int j=1;j<=n;++j)
      sum[i][j]=M[i-1][j-1] // this, i.e., [0,0][i,j] block cumulative sum
        +sum[i-1][j]        // +up horizontal
        +sum[i][j-1]        // +left verfical
        -sum[i-1][j-1]      // -up/left block (dup)
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      int r1=max(0,i-K), c1=max(0,j-K);
      int r2=min(m-1,i+K), c2=min(n-1,j+K);
      // Be careful off-by-one error
      res[i][j]=sum[r2+1][c2+1]-sum[r1][c2+1]-sum[r2+1][c1]+sum[r1][c1];
    }
    return res;
  }
};
class Solution {
public:
  // remain brute-force;
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& M, int K) {
    int m=M.size(),n=M[0].size();
    vector<vector<int>> res(m,vector<int>(n));
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      int r1=max(i-K,0), c1=max(j-K,0);
      int r2=min(i+K,m-1), c2=min(j+K,n-1);
      int sum=0;
      for (int r=r1;r<=r2;++r) for (int c=c1;c<=c2;++c)
        sum+=M[r][c];
      res[i][j]=sum;
    }
    return res;
  }
};
class Solution2 {
public:
  // brute-force: O(mnK^2)
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    int m=mat.size(),n=mat[0].size();
    vector<vector<int>> res(m,vector<int>(n));
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      int sum=0;
      for (int r=(i>K)?i-K:0;r<=((i<m-K)?i+K:m-1);++r)
        for (int c=(j>K)?j-K:0;c<=((j<n-K)?j+K:n-1);++c)
          sum+=mat[r][c];
      res[i][j]=sum;
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{1,2,3},{4,5,6},{7,8,9}};
  for (auto r: s.matrixBlockSum(A1,1)) {
    for (auto c: r) cout << c << " ";
    cout << endl;
  }
}
