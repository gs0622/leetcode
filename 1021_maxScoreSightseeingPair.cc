/* https://leetcode.com/problems/best-sightseeing-pair/description/
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.
The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int maxScoreSightseeingPair(vector<int>& A) { // O(n)
    int res=0, cur=0;
    for (auto a: A) {
      res=max(res,cur+a);
      cur=max(cur, a)-1;
    }
    return res;
  }
};
class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& A) { // naive O(n^2)
    int n=A.size(), res=0;
    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j)
      res=max(res,A[i]+A[j]+i-j);
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{8,1,5,2,6};
}
