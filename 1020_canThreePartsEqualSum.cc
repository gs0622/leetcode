#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  // O(n) naive: TLE, fixed by skipping non candidate
  bool canThreePartsEqualSum(vector<int>& A) {
    int n=A.size(), parts=0, tot = 0;
    for (int i=0; i<n; ++i) tot+=A[i];
    if (tot%3!=0) return false;
    for (int i=0, sum=0; i<n && parts<3; ++i) {
      sum+=A[i];
      if (sum==tot/3) sum=0, ++parts;
    }
    return parts==3;
  }
};
class Solution {
public:
  // O(n^2) -> O(n) naive: TLE, fixed by skipping non candidate
  bool canThreePartsEqualSum(vector<int>& A) {
    int n=A.size();
    vector<int> sums{A[0]};
    for (int i=1; i<A.size(); ++i)
      sums.push_back(sums.back()+A[i]);
    int cand = sums[n-1]/3;
    for (int i=0; i<n; ++i) {
      if (sums[i]!=cand) continue;  // fix O(n^2) TLE to O(n)
      for (int j=n-1; j>i; --j) {
        if (cand==sums[n-1]-sums[j] && cand==sums[j]-cand)
          return true;
      }
    }
    return false;
  }
};
int main(){
  Solution2 s;
  vector<int> A1{0,2,1,-6,6,-7,9,1,2,0,1};
  cout << s.canThreePartsEqualSum(A1) << endl;  // expect true
  vector<int> A2{0,2,1,-6,6,7,9,-1,2,0,1};
  cout << s.canThreePartsEqualSum(A2) << endl;  // expect false
  vector<int> A3{3,3,6,5,-2,2,5,1,-9,4};
  cout << s.canThreePartsEqualSum(A3) << endl;  // expect true
}
