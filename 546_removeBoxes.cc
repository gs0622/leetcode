/* https://leetcode.com/problems/remove-boxes/description/
Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

Example 1:
Input:

[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int removeBoxes(vector<int>& B) { // dfs + dp memo
    int n=B.size();
    int memo[100][100][100]={0};
    function<int(int,int,int)> dfs=[&](int lo, int hi, int k) {
      if (lo>hi) return 0;
      if (memo[lo][hi][k]!=0) return memo[lo][hi][k];
      while (lo<hi && B[hi]==B[hi-1]) --hi,++k;     // shrink right
      memo[lo][hi][k]=dfs(lo,hi-1,0) + (k+1)*(k+1); // go left and count right scores
      for (int i=lo; i<hi; ++i)
        if (B[i]==B[hi])
          memo[lo][hi][k]=max(memo[lo][hi][k], dfs(lo,i,k+1)+dfs(i+1,hi-1,0));
      return memo[lo][hi][k];
    };
    return dfs(0,n-1,0);
  }
};
int main(){
  Solution s;
  vector<int> B1{1, 3, 2, 2, 2, 3, 4, 3, 1};
  cout << s.removeBoxes(B1) << endl;
}
