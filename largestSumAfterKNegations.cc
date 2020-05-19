/* https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)
Return the largest possible sum of the array after modifying it in this way.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    sort(A.begin(),A.end());
    // flip neg, then 0 and smallest multiple times
    for (int i=0; i<A.size() && K>0 && A[i]<0; ++i, --K)
      A[i]=-A[i];
    return accumulate(A.begin(),A.end(),0)-
      (K%2)* *min_element(A.begin(),A.end())*2;
  }
};
int main(){
  Solution s;
  vector<int> A1{4,2,3};
  cout << s.largestSumAfterKNegations(A1,1) << endl;
  vector<int> A2{3,-1,0,2};
  cout << s.largestSumAfterKNegations(A2,3) << endl;
  vector<int> A3{2,-3,-1,5,-4};
  cout << s.largestSumAfterKNegations(A3,2) << endl;
}
