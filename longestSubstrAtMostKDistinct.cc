/*
Given a string S, find the length of the longest substring T that contains at most K distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	int longest(string s, int k) {
    int n=s.size(), res=0, sub=0;
    //cout << s << ": " << k << endl;
    for (int i=0,j; i<n; ++i,sub=0) {
      int cnt[256]={};        // empty counters
      for (j=i; j<n; ++j) {
        if (cnt[s[j]]==0) ++sub;
        ++cnt[s[j]];
        if (sub>k) {
          //cout << s.substr(i, (j-1)-i+1) << endl;
          break;
        }
      }
      res=max(res,(j-1)-i+1);
    }
    return res;
  }
};
class Solution {
public:
	int longest1(string s, int k) {
    int cnt[256]={};
    int i, j, sub=0, res=0;                   // i: window-left, j: window-right, sub: distinct count
    //cout << s << ": " << k << endl;
    for (i=0, j=0; j<s.size(); ++j) {
        if (cnt[s[j]]==0) ++sub;              // distunct update
            ++cnt[s[j]];
            while (sub > k) {                 // maintain K distinct invariant 
              --cnt[s[i]];                    // remove left most
              if (cnt[s[i]]==0) --sub;        // correct substring len if need
              ++i;                            // step left pointer
            }
            //cout << s.substr(i, (j-i+1)) << endl;
            res=max(res,j-i+1);
    }
    return res;
	}
	int longest(string s, int k) {
		unordered_map<char, int> um;
		int cnt = 0, max = 0;
		for (char c: s) {
			um[c]++;
			if (um.size() <= k) cnt++, max = std::max(max, cnt);
			else um.clear(), um[c] = 1, cnt = 1;	// poor: clear() call is linear on size, of 2?
		}
		return max;
	}
};

int main(void) {
	Solution s;
	cout << s.longest1("eceba", 2) << endl;
	cout << s.longest1("eceba", 3) << endl;
	return 0;
}
