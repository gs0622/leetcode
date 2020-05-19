/* https://leetcode.com/problems/max-consecutive-ones-iii/description/

Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int longestOnes(vector<int>& A, int K) {
    int n=A.size(),res=0;
    for (int i=0,j=0,zeros=0;i<n;++i) {
      zeros+=1-A[i];
      while (zeros>K)
        if (A[j++]==0) --zeros;
      res=max(res,i-j+1);
    }
    return res;
  }
};
int main(){}
