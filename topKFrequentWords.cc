#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    int n=words.size();
    unordered_map<string, int> mp;  // {str: cnt}
    for (auto s: words) ++mp[s];    // O(n)

    vector<set<string>> bk(n+1, set<string>());
    for (auto p: mp) {
      bk[p.second].insert(p.first); // {cnt: str}
    }

    vector<string> res;
    for (int i=n; i>0; --i) {
      while (bk[i].size()) {
        auto it = bk[i].begin();
        res.push_back(*it), bk[i].erase(it), --k;
        if (k==0) return res;
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<string> A1{"i", "love", "leetcode", "i", "love", "coding"};
  auto res = s.topKFrequent(A1, 2);
  for (auto s: res) cout << s << " ";
  cout << endl;
}
