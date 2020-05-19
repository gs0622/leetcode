#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    int n=colsum.size();
    vector<vector<int>> res(2,vector<int>(n));
    for (int i=0;i<n;++i) {
      res[0][i]=colsum[i]==2 || (colsum[i]==1 && upper>lower);
      res[1][i]=colsum[i]==2 || (colsum[i]==1 && res[0][i]==0);
      upper-=res[0][i],lower-=res[1][i];
    }
    return (upper==0 && lower==0)? res: vector<vector<int>>();
  }
};
class Solution2 {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    int n=colsum.size();
    vector<vector<int>> res(2,vector<int>(n));
    for (int i=0;i<n;++i) {
      if (colsum[i]==0) continue;
      else if (colsum[i]==2) res[0][i]=res[1][i]=1, upper-=1, lower-=1;
    }
    for (int i=0;i<n;++i) {
      if (colsum[i]==0||colsum[i]==2) continue;
      if (upper>0) res[0][i]=1, --upper;
      else if (lower>0) res[1][i]=1, --lower;
      else if (colsum[i]==1) return {};
    }
    if (upper!=0||lower!=0) return {};
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,1,1};
  auto res=s.reconstructMatrix(2,1,A1);
  //vector<int> A1{2,1,2,0,1,0,1,2,0,1};
  //auto res=s.reconstructMatrix(5,5,A1);
  //vector<int> A1{2,2,1,1};
  //auto res=s.reconstructMatrix(2,3,A1);
  if (res.empty()) return 0;
  int n=res[0].size();
  for (int i=0;i<2;++i) {
    for (int j=0;j<n;++j) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
