/*
https://leetcode.com/problems/find-and-replace-in-string/description/
# priority_queue
# data augmentation
# transfer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
typedef vector<int> vi;
typedef vector<string> vs;
public:
    string findReplaceString(string S, vi& indexes, vs& sources, vs& targets) {
      priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
      for (int i=0; i<indexes.size(); ++i) pq.push({indexes[i],i});
      while (pq.size()) {
        auto p=pq.top(); pq.pop();
        if (S.substr(p.first,sources[p.second].size())==sources[p.second])
          S=S.substr(0,p.first)+targets[p.second]+S.substr(p.first+sources[p.second].size(),string::npos);
      }
      return S;
    }
};
class Solution {
typedef vector<int> vi;
typedef vector<string> vs;
public:
    string findReplaceString(string S, vi& indexes, vs& sources, vs& targets) {
      int n=S.size();
      unordered_map<int,int> mp;
      for (int i=0; i<indexes.size(); ++i) mp[indexes[i]]=i;
      priority_queue<pair<int,vector<string>>, vector<pair<int,vector<string>>>> pq;
      for (auto i: indexes) {
        int j=mp[i];
        pq.push({i, vector<string>{sources[j],targets[j]}});
      }
      while (pq.size()) {
        auto p=pq.top(); pq.pop();
        string s=S.substr(p.first,p.second[0].size());  // pos,len
        if (s==p.second[0])
          S=S.substr(0,p.first)+p.second[1]+S.substr(p.first+p.second[0].size(),string::npos);
      }
      return S;
    }
};
int main(){
  Solution2 s;
  string S1{"abcd"};
  vector<int> A1{0,2};
  vector<string> So1{"a","cd"}, Ta1{"eee","ffff"};
  cout << s.findReplaceString(S1,A1,So1,Ta1) << endl;
}
