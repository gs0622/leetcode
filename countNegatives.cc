/* https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
Return the number of negative numbers in grid.
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  int countNegatives(vector<vector<int>>& G) { // O(m+n)
    int m=G.size(),n=G[0].size(),r=m-1,c=0,res=0;
    while (r>=0&&c<n) {
      if (G[r][c]>=0) ++c;
      else res+=n-c,--r;
    }
    return res;
  }
};
class Solution2 {
  int countNegatives(vector<vector<int>>& grid) { // O(mn)
    int res=0;
      for (auto r: grid) for (auto c: r)
        if (c<0) ++res;
    return res;
  }
};
int main(){}
