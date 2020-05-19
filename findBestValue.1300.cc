/* https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findBestValue(vector<int>& A, int T) {  // nlog(n)
    int mx=-1,sum=0;
    for (auto n: A) sum+=n, mx=max(mx,n);
    sort(A.begin(),A.end());
    int cnt=0,tail=A.size()-1;
    while (tail>=0 && T<sum+cnt*A[tail])
      ++cnt,sum-=A[tail--];
    if (cnt==0) return A[tail];
    int v=(T-sum)/cnt;
    if (abs(T-sum-cnt*v)<=abs(T-sum-cnt*(v+1)))
      return v;
    return v+1;
  }
};
class Solution2 {
public:
  int findBestValue(vector<int>& A, int T) {  // nlog(max(A)) binary search
    int n=A.size(),lo=0,hi=1e5;
    //sort(A.begin(),A.end());
    while (lo<hi) {
      int mi=lo+(hi-lo)/2,sum=0;
      for (auto n: A) sum+=(n>mi)?mi:n;
      if (sum<T) lo=mi+1;
      else hi=mi;
    }
    int sum1=0,sum2=0;
    for (auto n: A) {
        sum1+=(n>lo-1)? lo-1: n;
        sum2+=(n>lo)?lo:n;
    }
    return abs(sum1-T)<=abs(sum2-T)?lo-1:lo;
  }
};
int main(){
  Solution s;
  vector<int> A1{60864,25176,27249,21296,20204};
  cout << s.findBestValue(A1,56803) << endl;
}
