/* https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m=A.size(),n=B.size(),res=0;
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for (int i=1;i<m;++i) for (int j=1;j<n;++j)
      if (A[i-1]==B[j-1]) dp[i][j]=1+dp[i-1][j-1],res=max(res,dp[i][j]);
      else dp[i][j]=0;
    return res;
  }
};
int main(){}
