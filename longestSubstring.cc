/* https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int longestSubstring1(string s, int k) {
		if (s.empty()) return 0;
		if (k==0) return s.size();
		unordered_map<char,int> mp;
		for (auto c: s) ++mp[c];
		int idx=0;
		while (idx<s.size() && mp[s[idx]]>=k) ++idx;
		if (idx==s.size()) return s.size();
		int L = longestSubstring1(s.substr(0, idx), k);
		while (idx<s.size() && mp[s[idx]]<k) ++idx;
		int R = longestSubstring1(s.substr(idx), k);
		return max(L,R);
	}
	// O(n^2) in worse case, lowercase-letters-only suggests bitmask
	int longestSubstring(string s, int k) {
		int n=s.size(), res=INT_MIN;
		for (int i=0; i<n; ++i) {			// per start
			int cnt[26]={}, mask=0;			// reset count and mask
			for (int j=i; j<n; ++j) {		// moving window
				int id=s[j]-'a';		// char index
				++cnt[id];			// count up
				if (cnt[id]<k) mask |= (1<<id);	// pending
				else mask &= ~(1<<id);		// sastify >=k (not less than k) per char
				if (mask==0)			// sastify >=k in window
					res=max(res,j-i+1);
			}
		}
		return res==INT_MIN? 0: res;
	}
};
int main(){
	Solution s;
	cout << s.longestSubstring("",2) << endl;
	cout << s.longestSubstring("aaabb",3) << endl;
	cout << s.longestSubstring1("abcadababb",2) << endl;
	cout << s.longestSubstring("abcadababb",2) << endl;
}
