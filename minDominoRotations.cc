/* https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
We may rotate the i-th domino, so that A[i] and B[i] swap values.
Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
If it cannot be done, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n=A.size();
    for (int i=0,a=0,b=0; i<n; ++i) {
      if ((A[i]!=A[0]) && (B[i]!=A[0])) break;
      if (A[i]!=A[0]) ++a;
      if (B[i]!=A[0]) ++b;
      if (i==n-1) return min(a,b);
    }// if both A[0] and B[0] exist in all dominoes, it shall be half-half
    for (int i=0,a=0,b=0; i<n; ++i) {
      if ((A[i]!=B[0]) && (B[i]!=B[0])) break;
      if (A[i]!=B[0]) ++a;
      if (B[i]!=B[0]) ++b;
      if (i==n-1) return min(a,b);
    }
    return -1;
  }
};
int main(){
  Solution s;
  vector<int> A1{2,1,2,4,2,2}, B1={5,2,6,2,3,2};
  cout << s.minDominoRotations(A1,B1) << endl;
  vector<int> A2{1,2,1,1,1,2,2,2},B2{2,1,2,2,2,2,2,2};
  cout << s.minDominoRotations(A2,B2) << endl;
}
