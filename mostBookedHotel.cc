#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string mostBookedHotel(vector<string>& B) {
    unordered_set<string> book, free;
    unordered_map<string,int> mp;
    for (auto s: B)
      free.insert(s.substr(1));
    int n=free.size();
    vector<string> res(n);
    for (auto s: free)
      res.push_back(s);
    for (auto s: B) {
      auto ss=s.substr(1);
      if (s[0]=='+') {
        if (free.count(ss)) {
          free.erase(ss);
          book.insert(ss);
          ++mp[ss];
        }
      } else {
        if (book.count(ss)) {
          book.erase(ss);
          free.insert(ss);
        }
      }
    }
    sort(res.begin(),res.end(),[&](string a, string b){ return mp[a]>mp[b] || (mp[a]==mp[b]&&a<b);});
    return res[0];
  } 
};
int main(){
  Solution s;
  vector<string> B1{"+2A", "+1A", "-2A", "-1A", "+4F", "+2A", "-3E", "+1A"};
  cout << s.mostBookedHotel(B1) << endl;
}
