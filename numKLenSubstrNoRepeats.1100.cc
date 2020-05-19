/*
Given a string S, return the number of substrings of length K with no repeated characters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numKLenSubstrNoRepeats(string S, int K) {
    // examine valid K
    int n=S.size(),res=0;
    vector<int> cnt(26,0);
    for (int i=0,j=0; i<=n-K+1, j<n; ++j) {
      //if (cnt[S[j]]==0) cnt[S[j]]++;
      //else {  // maintain [i:j] all unique
        while (cnt[S[j]]==1)
          cnt[S[i++]]--; // S[i]!=S[j], S[j] is going to be 2
        cnt[S[j]]++;
      //}
      if (j-i+1==K) ++res,cnt[S[i++]]--;
    }
    return res;
  }
};
class Solution2 {
public:
  int numKLenSubstrNoRepeats(string S, int K) { // brute-force
    int n=S.size(),res=0;
    for (int i=0;i<=n-K;++i) {
      string ss=S.substr(i,K);
      unordered_set<char> st(ss.begin(),ss.end());
      if (st.size()==ss.size()) ++res;
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.numKLenSubstrNoRepeats("havefunonleetcode",5) << endl;
  cout << s.numKLenSubstrNoRepeats("home",5) << endl;
}
