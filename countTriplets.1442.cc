#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  // a=b, a^a=a^b=>0=a^b
  int countTriplets(vector<int>& A) { // O(n^2)
    int n=A.size(),res=0,sum=0;
    vector<int> mp(n+1,0);
    for (int i=1;i<n;++i)
      mp[i]=A[i-1]^mp[i-1];
    for (int i=0;i<n+1;++i) {
      for (int k=i+1;k<n+1;++k)
        if (mp[i]==mp[k])
          res+=k-i-1;
    }
    return res;
  }
};
class Solution2 {
public:
  int countTriplets(vector<int>& A) { // O(n^3)
    unordered_map<int,int> mp;
    int n=A.size(),res=0,sum=0;
    for (int i=0;i<n;++i)
      sum^=A[i],mp[i]=sum;
    for (int i=0;i<n;++i) {
      for (int j=i+1;j<n;++j) {
        for (int k=j;k<n;++k) {
          int a=mp[j-1]^(i==0?0:mp[i]);
          int b=mp[k]^mp[j-1];
          if (a==b) ++res;
        }
      }
    }
    return res;
  }
};
class Solution1 {
public:
  int countTriplets(vector<int>& A) { // O(n^4)
    int n=A.size(),a,b,res=0;
    for (int i=0;i<n;++i) {
      for (int j=i+1;j<n;++j) {
        for (int k=j;k<n;++k) {
          a=0,b=0;
          for (int ii=i;ii<j;++ii)
            a^=A[ii];
          for (int jj=j;jj<=k;++jj)
            b^=A[jj];
          if (a==b) ++res;
        }
      }
    }
    return res;
  }
};
int main(){
  Solution s;
}
