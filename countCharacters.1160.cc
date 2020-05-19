/*
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.
1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countCharacters(vector<string>& words, string chars) {
    vector<int> cnt(26,0);
    for (auto c: chars) cnt[c-'a']++; // translate to counts, like buckets
    int res=0;
    for (auto w: words) {
      vector<int> cnt1(cnt);
      bool match=true;
      for (auto c: w) {
        if (--cnt1[c-'a'] < 0) {      // no char 'c', means cannot form this word 'w'
          match=false;
          break;
        }
      }
      if (match) res+=w.size();
    }
    return res;
  }
};
int main(){}
