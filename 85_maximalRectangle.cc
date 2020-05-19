/* https://leetcode.com/problems/maximal-rectangle/description/
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Input:
[                         s
  ["1","0","1","0","0"],  0
  ["1","0","1","1","1"],  0
  ["1","1","1","1","1"],  0
  ["1","0","0","1","0"]   0
]
Output: 6
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int n=matrix.size(), m=matrix[0].size(), res=0;
    vector<int> h(m+1,0);           // height per col, last col is the sentinel
    for (int i=0; i<n; ++i) {       // row wise
      stack<int> stk;
      for (int j=0; j<m+1; ++j) {   // col wise
          if (j<m) {
            if (matrix[i][j]=='1') ++h[j];
            else h[j]=0;
          }
          while (stk.size() && h[stk.top()]>h[j]) {
            int H = h[stk.top()]; stk.pop();
            int W = stk.empty()? j: j-stk.top()-1;
            int A = H*W;
            res = max(res, A);
          }
          stk.push(j);
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<char>> A1{
    {'1','0','1','0','0'},  // 1,0,1,0,0,0
    {'1','0','1','1','1'},  // 2,0,2,1,1,0
    {'1','1','1','1','1'},  // 3,1,3,2,2,0
    {'1','0','0','1','0'}   // 4,0,0,3,0,0
  };
  cout << s.maximalRectangle(A1) << endl;
}
