#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int waterPlants(vector<int>& A, int cap1, int cap2) {
    int n=A.size(), res=0,c1=0,c2=0;
    for (int i=0,j=n-1;i<=j; ++i,--j) {
      if (i==j) {
        while (c1+c2<A[i])
          res+=1,A[i]-=c1+c2,c1=cap1,c2=cap2;
      } else {
        if (c1<A[i]) ++res, c1=cap1;
        if (c1>A[i]) c1-=A[i];
        else {
          while (A[i]-c1>0) {
            ++res,A[i]-=c1,c1=cap1;
          }
          c1-=A[i];
        }
        if (c2<A[j]) ++res, c2=cap2;
        if (c2>A[j]) c2-=A[j];
        else {
          while (A[j]-c2>0) {
            ++res,A[j]-=c2,c2=cap2;
          }
          c2-=A[j];
        }
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  //vector<int> A1{2,4,5,1,2};
  vector<int> A1{50,12,70};
  cout << s.waterPlants(A1,5,7) << endl;
}
