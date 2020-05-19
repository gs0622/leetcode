/*
Given a string S, return the number of substrings of length K with no repeated characters.
Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.
Example 2:

Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.

Note:
1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // O(n) two-pointer
  int maxKLenSubstrNoRepeats(string S, int K) {
    int cnt[256]={}, n=S.size(), res=0;
    for (int i=0,j=0,sub=0; i<n; ++i) {
      if (cnt[S[i]]==0) ++sub;
      ++cnt[S[i]];
      while (cnt[S[i]]>1) {
        --cnt[S[j]];
        if (cnt[S[j]]==0) --sub;
        ++j;
      }
      if (sub>=K) ++res;
    }
    return res;
  }
};
class Solution {
public:
  int maxKLenSubstrNoRepeats(string S, int K) {
    int res=0, n=S.size();
    for (int i=0;i<n-K;++i) {
      int cnt[256]={}, flag=1;
      for (int j=i; j<i+K; ++j) {
        ++cnt[S[j]];
        if (cnt[S[j]]>1) {
          flag=0;
          break;
        }
      }
      if (flag) ++res;
    }
    return res;
  }
};
int main(){
  Solution2 s;
  cout << s.maxKLenSubstrNoRepeats("havefunonleetcode",5) << endl;
  cout << s.maxKLenSubstrNoRepeats("home",6) << endl;
}
