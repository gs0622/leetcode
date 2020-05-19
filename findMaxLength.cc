#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findMaxLength(vector<int>& A) {
    for (auto& a: A)
      if (a==0) a=-1;
    int n=A.size(),sum=0,res=0;
    unordered_map<int,int> mp{{0,-1}};
    for (int i=0;i<n;++i) {
      sum+=A[i];
      if (mp.count(sum))
        res=max(res,i-mp[sum]);
      else
        mp[sum]=i;
    }
    return res;
  }
};
int main(){
  
}
