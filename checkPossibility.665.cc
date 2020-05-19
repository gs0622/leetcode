/* https://leetcode.com/problems/non-decreasing-array/description/
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool checkPossibility(vector<int>& A) {
    int n=A.size(),cnt=0;
    for (int i=1;i<n;++i) {
      if (A[i-1]>A[i]) {
        ++cnt;
        if (i-2<0 || A[i-2]<=A[i]) A[i-1]=A[i];
        else A[i]=A[i-1];
      }
      if (cnt>1) return false;
    }
    return true;
  }
};
int main(){
  Solution s;
  vector<int> A1{4,2,3};
  cout << s.checkPossibility(A1) << endl;
  vector<int> A2{4,2,1};
  cout << s.checkPossibility(A2) << endl;
  vector<int> A3{3,4,2,3};
  cout << s.checkPossibility(A3) << endl;
}
