#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findLengthOfLCIS(vector<int>& A) {  // O(n)
    int n=A.size(),res=0,cnt=0;
    for (int i=0;i<n;++i) {
      if (i==0 || A[i]>A[i-1]) ++cnt;
      else cnt=1;
      res=max(res,cnt);
    }
    return res;
  }
};
class Solution2 {
public:
  int findLengthOfLCIS(vector<int>& A) {  // O(n^2)
    int n=A.size(), res=0;
    for (int i=0; i<n; ++i) {
      int len=1;
      for (int j=i+1;j<n;++j)
        if (A[j]>A[j-1]) len++;
        else break;
      res=max(res,len);
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,3,5,4,7};
  cout << s.findLengthOfLCIS(A1) << endl;
}
