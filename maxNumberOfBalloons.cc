#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char,int> s{{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};
    unordered_map<char,int> mp; // {ch:cnt}
    for (auto c: text) mp[c]++;
    int res=INT_MAX;
    for (auto c: s)
      res=min(res,mp[c.first]/c.second);
    return res;
  }
};
class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char,int> mp; // {ch:cnt}
    for (auto c: text) mp[c]++;
    int res=mp['b'];
    res=min(res,mp['a']);
    res=min(res,mp['l']/2);
    res=min(res,mp['o']/2);
    res=min(res,mp['n']);
    return res;
  }
};
int main(){
  Solution1 s;
  cout << s.maxNumberOfBalloons("balon") << endl;
  cout << s.maxNumberOfBalloons("nlaebolko") << endl;
  cout << s.maxNumberOfBalloons("loonbalxballpoon") << endl;
  cout << s.maxNumberOfBalloons("leetcode") << endl;
}
