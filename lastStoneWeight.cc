#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/last-stone-weight-ii/description/
class Solution2 {
public:
  int lastStoneWeightII(vector<int>& stones) {
    int n=stones.size();
    unordered_set<int> s{0};
    for (int i=0;i<n;++i) {
      unordered_set<int> t;
      for (auto n: s)
        t.insert(n+stones[i]), t.insert(n-stones[i]);
      s.swap(t);
    }
    int res=INT_MAX;
    for (auto n: s)
      res=min(res,abs(n));
    return res;
  }
};
// https://leetcode.com/problems/last-stone-weight/description/
class Solution {
public: // O(nlgn)
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(),stones.end());
    while (pq.size()>=2) {
      int x=pq.top(); pq.pop();
      int y=pq.top(); pq.pop();
      if (x!=y) pq.push(abs(x-y));
    }
    return pq.empty()? 0: pq.top();
  }
};
int main(){
  Solution s;
  vector<int> A1{2,7,4,1,8,1,9};
  cout << s.lastStoneWeight(A1) << endl;
  Solution2 s2;
  vector<int> A2{2,7,4,1,8,1};
  cout << s2.lastStoneWeightII(A2) << endl;
}
