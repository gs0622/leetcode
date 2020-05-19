/*
Create string a out of substrings of string b. Return the minimum number of copies that you need to do this.

Example 1:

Input: a="zaza", b="baz"
Output: 3
Explanation:
copy1="z"
copy2="az"
copy3="a
a=copy1+copy2+copy3
https://leetcode.com/problems/shortest-way-to-form-string (premium)

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int shortestWayFormStr(string A, string B) {
    int m=A.size(), n=B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) {
      if (A[i-1]==B[j-1])  // bottom-up DP
        dp[i][j]=1+dp[i-1][j-1];
      else
        dp[i][j]=0; // sub-string
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1]); // sub-seq
    }
    int at=m, res=0;
    while (at>0) {
      int longest_end_here=*max_element(dp[at].begin(),dp[at].end());
      if (longest_end_here==0) return -1;
      at-=longest_end_here, ++res;
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.shortestWayFormStr("zaza", "baz") << endl;
}
