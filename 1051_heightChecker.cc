#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int heightChecker(vector<int>& H) {
    vector<int> A=H;
    int n=H.size(), res=0;
    // [1,1,4,2,1,3]
    // [1,1,1,2,3,4]
    stable_sort(A.begin(), A.end());
    for (int i=0; i<n; ++i)
      if (A[i]!=H[i]) ++res;
    return res;
  }
};
class Solution {
public:
  int heightChecker(vector<int>& H) {
    int res=0;
    stable_sort(H.begin(), H.end(), [&](int a, int b){ if (a>b) ++res; return (a<=b); });
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,1,4,2,1,3};
  cout << s.heightChecker(A1) << endl;
}
