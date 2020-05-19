#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  bool uniqueOccurrences(vector<int>& arr) {  // O(n) counting sort
    int cnt[2001]={},mp[1001]={};
    for (auto n: arr) ++cnt[n+1000];
    for (int i=0;i<2001;++i) {
      if (cnt[i] && ++mp[cnt[i]]>1)
        return false;
    }
    return true;
  }
};
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> mp;
    unordered_set<int> st;
    for (int n: arr) ++mp[n];             // {val:freq}
    for (auto p: mp) st.insert(p.second);
    return st.size()==mp.size();
  }
};
int main(){}

