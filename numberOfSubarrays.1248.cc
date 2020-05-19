/* https://leetcode.com/problems/count-number-of-nice-subarrays/description/
Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numberOfSubarrays(vector<int>& A, int k) {
    int n=A.size(),res=0;
    deque<int> dq{-1};
    for (int i=0;i<n;++i) {
      if (A[i]%2) dq.push_back(i);
      if (dq.size()>k+1) dq.pop_front();
      if (dq.size()==k+1) res+=dq[1]-dq[0];
    }
    return res;
  }
};
class Solution2 {
public:
  int numberOfSubarrays(vector<int>& A, int k) {  // TLE
    int n=A.size(), res=0, p,q;
    vector<int> B(n,0);
    for (int i=0;i<n;++i)
      if (A[i]%2==1) B[i]=1;
      else B[i]=0;
    for (int i=1;i<n;++i)
      B[i]+=B[i-1];

    for (int i=0;i<n;++i) for (int j=i;j<n;++j) {
      //if (j-i+1<k) continue;
      if (i==0 && B[j]==k) ++res;
      else if (i>0 && B[j]-B[i-1]==k) ++res;
    }
    return res;
  }
};
int main(){
  Solution s;
  Solution2 s2;
  //vector<int> A1{1,1,2,1,1};
  vector<int> A1{2,2,2,1,2,2,1,2,2,2};
  cout << s.numberOfSubarrays(A1,2) << endl;
  cout << s2.numberOfSubarrays(A1,2) << endl;
}
