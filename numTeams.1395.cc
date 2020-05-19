#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numTeams(vector<int>& A) {
    int n=A.size(),res=0;
    for (int i=0;i<n;++i)
      for (int j=i+1;j<n;++j)
        for (int k=j+1;k<n;++k) {
          if ((A[i]<A[j] && A[j]<A[k]) || (A[i]>A[j] && A[j]>A[k]))
            ++res;
        }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{2,5,3,4,1};
  cout << s.numTeams(A1) << endl;
}
