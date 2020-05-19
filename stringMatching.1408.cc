#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> stringMatching(vector<string>& S) {
    int n=S.size();
    unordered_set<string> st;
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
      if (i==j) continue;
      if (S[i].find(S[j])!=string::npos)
        st.insert(S[j]);
    }
    vector<string> res;
    for (auto s: st) res.push_back(s);
    return res;
  }
};
int main(){
  Solution s;
  //vector<string> S1{"mass","as","hero","superhero"};
  vector<string> S1{"leetcoder","leetcode","od","hamlet","am"};
  for (auto ss: s.stringMatching(S1))
    cout << ss << endl;
}
