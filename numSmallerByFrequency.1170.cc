#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  vector<int> numSmallerByFrequency(vector<string>& Q, vector<string>& W) {
    int m=Q.size(), n=W.size();
    function<int(string&)> f=[](string& s) {
      char ch=*min_element(begin(s),end(s));
      return count(begin(s),end(s),ch);
    };
    vector<int> cnt(11), res;
    for (auto w: W) {
      int freq=f(w);
      for (int i=freq-1;i>=0;--i) ++cnt[i]; // running sum
    }
    for (auto q: Q)
      res.push_back(cnt[f(q)]);
    return res;
  }
};
class Solution {
public: //nlgn
  vector<int> numSmallerByFrequency(vector<string>& Q, vector<string>& W) {
    int m=Q.size(),n=W.size();
    vector<int> fQ(m), fW(n);
    for (auto& s: Q) sort(s.begin(),s.end());
    for (auto& s: W) sort(s.begin(),s.end());
    for (int i=0;i<m;++i) fQ[i]=count(Q[i].begin(),Q[i].end(),*Q[i].begin());
    for (int i=0;i<n;++i) fW[i]=count(W[i].begin(),W[i].end(),*W[i].begin());
    sort(fW.begin(),fW.end());
    vector<int> res;
    for (auto q: fQ) {
      auto it=upper_bound(fW.begin(),fW.end(), q);
      res.push_back((it==fW.end())? 0: fW.end()-it);
    }
    return res;
  }
};
int main(){
  Solution2 s;
  vector<string> Q1{{"cbd"}}, W1{{"zaaaz"}};
  //for (auto n: s.numSmallerByFrequency(Q1,W1)) cout << n << " ";
  cout << endl;
  vector<string> Q2{"bbb","cc"}, W2{"a","aa","aaa","aaaa"};
  //for (auto n: s.numSmallerByFrequency(Q2,W2)) cout << n << " ";
  cout << endl;
  vector<string> Q3{"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"},
    W3{"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
  for (auto n: s.numSmallerByFrequency(Q3,W3)) cout << n << " ";
  cout << endl;
}
