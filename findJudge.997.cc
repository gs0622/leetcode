#include <bits/stdc++.h>
using namespace std;
class UF {
  vector<int> id;
public:
  int find(int p) {
    while (p!=id[p])
      p=id[p];
    return p;
  }
  UF(int n) {
    id.resize(n+1);
    for (int i=1;i<=n;++i)
      id[i]=i;
  }
  void uni(int p, int q) {
    int rp=find(p),rq=find(q);
    if (rp!=rq) id[rp]=rq;
  }
};
// why UF is not working? think N = 3, trust = [[1,3],[2,3],[3,1]]
class Solution {
public://m=T.size(),n=N => O(m) time, O(n) space
  int findJudge(int N, vector<vector<int>>& T) {
    vector<int> T1(N+1),T2(N+1);  // T1: trusts to, T2: trusted by
    for (auto t: T)
      ++T1[t[0]],++T2[t[1]];
    for (int i=1;i<=N;++i)  // O(N)
      if (T1[i]==0 && T2[i]==N-1)
        return i;
    return -1;
  }
};
int main(){}
