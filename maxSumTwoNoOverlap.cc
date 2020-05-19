#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // O(n) two pass, sliding window to track Lmax, Mmax, and optimal result
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
      int n=A.size();
      for (int i=1;i<n;++i) A[i]+=A[i-1];
      int Lmax=A[L-1],Mmax=A[M-1],res=A[L+M-1];     // assume res=A[0:L]+A[L:L+M-1]
      for (int i=L+M;i<n;++i) {                     // think L+M==0+L+M in size of L+M+1
        Lmax=max(Lmax,A[i-M]-A[i-L-M]);             // think the smallest i-M==L+M-M==L, A[L]-A[0]
        Mmax=max(Mmax,A[i-L]-A[i-L-M]);
        res=max(res,max(Lmax+A[i]-A[i-M],Mmax+A[i]-A[i-L])); // 3 options: think why exclusive? left-right align
      }
      return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{0,6,5,2,2,5,1,9,4};
  cout << s.maxSumTwoNoOverlap(A1,1,2) << endl;
}
