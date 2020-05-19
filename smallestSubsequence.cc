/* https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.
Note:
1 <= text.length <= 1000
text consists of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string smallestSubsequence(string text) {
    int cnt[256]={}, pos;

    for (auto c: text)
        pos=c-'a', ++cnt[pos];

    bitset<26> st;
    string res;

    for (auto c: text) {
      pos = c-'a', --cnt[pos];
      if (st.test(pos)) continue;
      while (res.back() > c && cnt[res.back()-'a'] > 0) { // drop previous char to archive lexicographical order
        st.set(res.back()-'a', 0);  // restore non-visited while unchange the count
        res.pop_back();
      }
      st.set(pos,1);
      res+=c;
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.smallestSubsequence("cdadabcc") << endl;
  cout << s.smallestSubsequence("abcd") << endl;
  cout << s.smallestSubsequence("ecbacba") << endl;
}
