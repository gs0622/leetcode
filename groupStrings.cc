/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  // Q: are there duplicate string?
  // A: yes? use multiset, no? set is enough; multiset/set keep strings are in lexicographic order
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string,multiset<string>> mp;
    map<string,multiset<string>> mp;
    for (auto s: strings) {
      string t;
      for (auto c: s)
        t += to_string((c+26-s[0])%26) + ",";
      mp[t].insert(s);
    }
    vector<vector<string>> res;
    for (auto it: mp)
      res.push_back(vector<string>(it.second.begin(), it.second.end()));
    return res;
  }
};
class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string,multiset<string>> mp;
    for (auto s: strings) {
      string t;
      for (auto c: s) // encode
        t += to_string(abs(c-s[0])) + ",";
      mp[t].insert(s);
    } 
    vector<vector<string>> res;
    for (auto it: mp) {
      res.push_back(vector<string>());  // 1D push
      for (auto s: it.second)
        res.back().push_back(s);        // 2D push
    }
    return res;
  }
};
int main(){
  Solution2 s;
  vector<string> A1{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  for (auto g: s.groupStrings(A1)) {
    for (auto s: g) cout << s << " ";
    cout << endl;
  } 
}
