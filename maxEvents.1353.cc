#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // O(d+nlogn) time, O(n) space
  int maxEvents(vector<vector<int>>& E) {
    int n=E.size(),i=0,res=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(E.begin(),E.end());
    for (int d=1;d<=1e5;++d) {
      while (pq.size() && pq.top()<d) // retair
        pq.pop();
      while (i<n && E[i][0]==d)       // in
        pq.push(E[i++][1]);
      if (pq.size())                  // one event only
        pq.pop(),++res;
    }
    return res;
  }
};
int main(){}
