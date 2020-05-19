/* https://leetcode.com/problems/find-lucky-integer-in-an-array/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findLucky(vector<int>& A) {
    int cnt[501]={};
    for (auto n: A) ++cnt[n];
    for (int i=500;i>=1;--i)
      if (i==cnt[i])
        return i;
    return -1;
  }
};
class Solution1 {
public:
  int findLucky(vector<int>& A) {
    int res=0;
    unordered_map<int,int> mp;
    for (auto n: A) ++mp[n];
    for (auto p: mp) {
      if (p.first==p.second) res=max(res,p.first);
    }
    return res==0? -1: res;
  }
};
int main(){}
