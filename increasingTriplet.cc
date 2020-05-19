/* https://leetcode.com/problems/increasing-triplet-subsequence/description/
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool increasingTriplet(vector<int>& A) {
    int i=INT_MAX, j=INT_MAX;
    for (auto n: A)
      if      (n<=i) i=n;
      else if (n<=j) j=n;
      else           return true;
    return false;
  }
};
int main(){}
