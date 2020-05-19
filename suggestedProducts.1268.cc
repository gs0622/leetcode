#include <bits/stdc++.h>
using namespace std;
class Solution {
typedef vector<string> vs;
typedef vector<vs> vvs;
public:
  vvs suggestedProducts(vs& P, string S) {
    sort(P.begin(),P.end());    // O(nlgn)
    vvs res;
    string s;
    auto it=P.begin();
    for (auto c: S) {
      s+=c;
      it=lower_bound(it,P.end(),s);
      vs sug;
      for (int i=0;i<3;++i) {
        if (it+i==P.end()) break;
        string ss=*(it+i);
        if (ss.find(s)==string::npos)
          break;
        sug.push_back(ss);
      }
      res.push_back(sug);
    }
    return res;
  }
};
class Solution2 {
typedef vector<string> vs;
typedef vector<vs> vvs;
public:
  vvs suggestedProducts(vs& products, string searchWord) {
    unordered_map<string,vs> mp;
    sort(products.begin(),products.end());  // O(nlgn)
    for (auto p: products) {  // O(n)
      for (int i=1;i<=p.size();++i) {
        mp[p.substr(0,i)].push_back(p);
      }
    }
    //for (auto& v: mp) sort(v.second.begin(),v.second.end());
    vvs res;
    for (int i=1;i<=searchWord.size();++i) {
      auto it=mp[searchWord.substr(0,i)].begin();
      int sz=mp[searchWord.substr(0,i)].size();
      res.push_back(vs(it,it+min(3,sz)));
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<string> A1{"mobile","mouse","moneypot","monitor","mousepad"};
  for (auto ss: s.suggestedProducts(A1,"mouse")) {
    for (auto sss: ss) cout << sss << " ";
    cout << endl;
  }
}
