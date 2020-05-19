#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int twoSumLessThanK(vector<int>& A, int K) {
    sort(A.begin(),A.end());
    int lo=0, hi=A.size()-1, max=INT_MIN;
    while (lo<hi) {
      int sum = A[lo]+A[hi];
      if (sum>K) --hi;
      else if (sum==K) return K;
      else max=sum, ++lo; // less than K
    }
    return max;
  }
};
int main(){
  Solution s;
  vector<int> A1{34,23,1,24,75,33,54,8};
  cout << s.twoSumLessThanK(A1,60) << endl;
  vector<int> A2{10, 5, 2, 6};
  cout << s.twoSumLessThanK(A2,100) << endl;
}
