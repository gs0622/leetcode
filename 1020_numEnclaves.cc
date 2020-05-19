#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numEnclaves(vector<vector<int>>& A) {
    int n=A.size(), m=A[0].size();
    function<void(int,int)> dfs=[&](int i, int j){
      if (i<0||j<0||i==n||j==m||A[i][j]!=1) return; // tricky: A[i][j]!=1 is the key
      A[i][j]=0;
      dfs(i-1,j), dfs(i+1, j), dfs(i,j-1), dfs(i, j+1);
    };
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
      if (i*j==0||i==n-1||j==m-1)
        dfs(i,j);
    }
    return accumulate(A.begin(), A.end(), 0, [](int s, vector<int>& r){ return s+accumulate(r.begin(),r.end(),0); });
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  cout << s.numEnclaves(A1) << endl;
}
