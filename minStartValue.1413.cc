#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minStartValue(vector<int>& A) {
    int n=A.size(),res=0,sum=0;
    for (int i=0;i<n;++i) {
      sum+=A[i];
      res=min(res,sum);
    }
    return 1-res;
  }
};
int main(){
  Solution s;
  vector<int> A1{-3,2,-3,4,2};
  cout << s.minStartValue(A1) << endl;
}
