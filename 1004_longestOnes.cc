/* https://leetcode.com/problems/max-consecutive-ones-iii/description/


Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 

hint: sliding window to find the longest subarray w/ K most zeros.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {   // with shrink window
public:
  int longestOnes(vector<int>& A, int K) {
    int zeros=0, n=A.size(), i,j, res=0;
    for (i=0,j=0; j<n; ++j) {
      if (A[j]==0) zeros++;
      while (zeros>K)
        if (A[i++]==0) zeros--;
      res=max(res,j-i+1);
    }
    return res;
  }
};
class Solution {  // without shrink window
public:
  int longestOnes(vector<int>& A, int K) {
    int n=A.size(), i, j;
    for (i=0,j=0; j<n; ++j) {
      if (A[j]==0) K--;           // zeros between [i..j] <= K, j steps forward
      if (K<0 && A[i++]==0) K++;  // zeros between [i..j] >K, i steps forward
    }
    return j-i;
  }
};
int main(){
  Solution2 s;
  vector<int> A1{1,1,1,0,0,0,1,1,1,1,0};
  cout << s.longestOnes(A1,2) << endl;
  vector<int> A2{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  cout << s.longestOnes(A2,3) << endl;
}
