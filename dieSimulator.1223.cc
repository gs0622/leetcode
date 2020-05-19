/*
A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 
Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.
Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.

Constraints:
1 <= n <= 5000
rollMax.length == 6
1 <= rollMax[i] <= 15

hint: DP(pos, last) which means we are at the position pos having as last the last character seen.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int dieSimulator(int n, vector<int>& A) {
    int dp[5001][6][16]={};
    function<int(int,int,int)> helper=[&](int left, int last, int cnt){
      if (left==0) return 1;  // base case
      if (last!=-1 && dp[left][last][cnt]>0) return dp[left][last][cnt];
      int res=0;
      for (int i=0;i<6;++i) {
        if (last==i&&cnt==A[i]) continue;   // trim;
        res=(res+helper(left-1,i,i==last?cnt+1:1))%1000000007;
      }
      if (last!=-1) dp[left][last][cnt]=res;
      return res;
    };
    return helper(n,-1,0);
  }
};
class Solution2 {
public:
  int dieSimulator(int n, vector<int>& A) {
    function<int(int,int,int)> helper=[&](int left, int last, int cnt){
      if (left==0) return 1;
      int res=0;
      for (int i=0;i<6;++i) {
        if (i==last&&cnt==A[i]) continue;           // bound
        res=(res+helper(left-1,i,i==last?cnt+1:1))%1000000007;  // select
      }
      return res;
    };
    return helper(n,-1,0);
  }
};
class Solution1 {
public:
  int dieSimulator(int n, vector<int>& A) {
    int res=0;
    function<void(int,int,int)> helper=[&](int left, int last, int cnt){
      if (left==0) {
        res=(res+1)%1000000007;
        return;
      }
      for (int i=0;i<6;++i) {
        if (last==i && cnt==A[i]) continue; // bound
        helper(left-1,i,i==last?cnt+1:1);
      }
    
    };
    helper(n,-1,0);
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{2,5,7,2,8,7};
  cout << s.dieSimulator(10,A1) << endl;
}
