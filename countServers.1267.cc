#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countServers(vector<vector<int>>& G) {
    int m=G.size(), n=G[0].size();
    vector<int> rows(m), cols(n);
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      if (G[i][j]==1) rows[i]++, cols[j]++;
    int res=0;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      if (G[i][j]==1 && (rows[i]>1||cols[j]>1))  // not isolated
        res++;
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{1,0},{1,1}};
  cout << s.countServers(A1) << endl;
}
