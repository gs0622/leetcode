/*
Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n), two pointers, sliding window
	int longest2(string s) {
		int cnt[256]={};
		int i, j, sub=0, res=0;	// i: window-left, j: window-right, sub: distinct count
		for (i=0, j=0; j<s.size(); ++j) {
			if (cnt[s[j]]==0) ++sub;
			++cnt[s[j]];
			while (sub > 2) {
				--cnt[s[i]];			// remove left most
				if (cnt[s[i]]==0) --sub;	// correct substring len if need
				++i;				// step left pointer
			}
			res=max(res,j-i+1);
		}
		return res;
	}
	int longest1(string s) {
		unordered_map<char, int> um;
		int cnt = 0, max = 0;
		for (char c: s) {
			um[c]++;
			if (um.size() < 3) cnt++, max = std::max(max, cnt);
			else um.clear(), um[c] = 1, cnt = 1;	// poor: clear() call is linear on size, of 2?
		}
		return max;
	}
	// O(n^3) brute force
	int longest3(string s) {
		int i, j, res=0;
		for (i=0; i<s.size(); ++i) {
			for (j=1; j<=s.size()-i; ++j) {
				string sub = s.substr(i,j);
				unordered_set<char> myset(begin(sub), end(sub));
				if (myset.size()>2) break;
				res = max(res, j);
			}
		}
		return res;
	}
	// O(n^3)
	int longest(string s) {
		int i,j,k,res=0;
		for (i=0;i<s.size(); ++i) {
			for (j=1; j<=s.size()-i; ++j) {
				string sub = s.substr(i, j);
				unordered_set<char> us;
				for (k=0;k<sub.size();++k) {
					us.insert(sub[k]);
					if (us.size()>2) break;
				}
				if (us.size()<=2)
					res=max(res, j);
			}
		}
		return res;
	}
};

int main(void) {
	Solution so;
	//vector<string> ss{"", "a", "ab", "aab", "bab", "babc", "bbbbcccac"};
	vector<string> ss{"a", "ab", "aab", "bab", "babc", "bbbbcccac"};
	//vector<string> ss{"babc", "bbbbcccac"};
	for (auto s: ss)
		cout << s << "=" << so.longest3(s) << ": " << so.longest1(s) << ": " << so.longest2(s) << endl;
	return 0;
}
