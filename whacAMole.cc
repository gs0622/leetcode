#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // O(n) sliding window
  int whatAMoleTwoMallets(vector<int>& A, int w) {
    int n=A.size();
    vector<int> sum(n,0);
    for (int i=0; i<n; ++i) sum[i]=(i==0)? A[i]: A[i]+sum[i-1];
    function<int(int,int)> getSum=[&](int i, int j) {
      return (i==0)? sum[j]: sum[j]-sum[i-1];
    };
    pair<int,int> ids={n-2*w,n-w};
    int mainSumTwoSubArr = getSum(n-2*w,n-w-1)+getSum(n-w,n-1);
    pair<int,int> secSubArrMax={n-w,getSum(n-w,n-1)};
    for (int i=n-2*w-1; i>=0; --i) {
      int cur = getSum(i+w,i+2*w-1);  // 1st:[n-w-1,n-2]
      if (cur > secSubArrMax.second)
        secSubArrMax={i+w,cur};
      cur = getSum(i,i+w-1) + secSubArrMax.second;
      if (cur>mainSumTwoSubArr)
        mainSumTwoSubArr=cur, ids={i,secSubArrMax.first};
    }
    /*
    for (int i=ids.first; i<ids.first+w; ++i) cout << A[i];
    cout << endl;
    for (int i=ids.second; i<ids.second+w; ++i) cout << A[i];
    cout << endl;
    */
    return mainSumTwoSubArr;
  }
  int whatAMole(vector<int>& A, int w) {
    int n=A.size(),res=0,cur=0;
    for (int i=0,j=0; i<n; ++i) {
      if (A[i]==1) ++cur;
      while ((i-j)>5) {
        cur-=A[j++];
      }
      res=max(res,cur);
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0};
  cout << s.whatAMole(A1,5) << endl;
  vector<int> A2{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0};
  cout << s.whatAMoleTwoMallets(A2,5) << endl;
}
