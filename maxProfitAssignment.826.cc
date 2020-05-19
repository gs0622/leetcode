#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
    int m=D.size(),n=W.size(),j=0,bst=0,res=0;
    vector<vector<int>> J;    // m jobs
    for (int i=0;i<m;++i)
      J.push_back({D[i],P[i]});
    sort(J.begin(),J.end());  // accending difficulity x m
    sort(W.begin(),W.end());  // accending ability     x n
    for (int& abi: W) {
      while (j<m && abi>=J[j][0])
        bst=max(bst,J[j++][1]);
      res+=bst;
    }
    return res;
  }
};
class Solution0 {
public: // TLE
  int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
    int m=D.size(),n=W.size(),res=0;
    for (int i=0;i<n;++i) { // workers
      int profit=0;
      for (int j=0;j<m;++j) {
        profit=max(profit,(W[i]>=D[j])? P[j]:0);
      }
      res+=profit;
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> D1{2,4,6,8,10},P1{10,20,30,40,50},W1{4,5,6,7};
  //cout << s.maxProfitAssignment(D1,P1,W1) << endl;
  vector<int> D2{68,35,52,47,86},P2{67,17,1,81,3},W2{92,10,85,84,82};
  cout << s.maxProfitAssignment(D2,P2,W2) << endl;
}
