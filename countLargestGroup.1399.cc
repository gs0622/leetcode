#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countLargestGroup(int n) {
    unordered_map<int,int> mp;
    int mx=0,res=0;
    for (int i=1;i<=n;++i) {
      int sum=0, j=i;
      while (j>0)
        sum+=j%10,j/=10;
      ++mp[sum];
      mx=max(mx,mp[sum]);
    }
    for (auto p: mp)
      if (p.second==mx)
        ++res;
    return res;
  }
};
int main(){}
