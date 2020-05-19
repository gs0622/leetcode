/* https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

hint: sliding window
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> findAnagrams1(string s, string p) {
		unordered_map<char,int> mp;
		for (auto c: p) ++mp[c];	// char count of pattern string 'p'
		int cnt=mp.size();
		int begin=0,end=0;        // two pointers
		vector<int> res;
		while (end < s.size()) {
			char c=s[end];
			if (mp.count(c)) {
				--mp[c];		// seen c of 'p' in s
				if (mp[c]==0) --cnt;	// consumed one char
			}
			++end;

			while (cnt==0) {		// consumed all char of p (pattern)
				char tmp=s[begin];	// scan from pointer of 'begin'
				if (mp.count(tmp)) {	// key remains there while value in 0
					++mp[tmp];	// re-fill and exit loop
					if (mp[tmp]>0) ++cnt;
				}
				if (end-begin==p.size())	// examine valid anagram once cnt==0
					res.push_back(begin);
				++begin;
			}
		}
		return res;
	}
	// maintain a sliding window of char map to detect the map equal between s and p
	vector<int> findAnagrams(string s, string p) {
		vector<int> pv(256,0), sv(256,0), res;
		if (s.size() < p.size()) return res;
		for (int i=0; i<p.size(); ++i) {
			++pv[p[i]], ++sv[s[i]];
		}

		if (pv == sv)					// tricky to learn: vector's equal operator ==
			res.push_back(0);

		for (int i=p.size(); i <s.size(); ++i) {	// the sliding window
			++sv[s[i]];
			--sv[s[i-p.size()]];
			if (pv == sv)
				res.push_back(i-p.size()+1);
		}
		return res; // arr indices
	}
};
int main(){
	Solution s;
	vector<int> res;
	string s1{"cbaebabacd"}, p1{"abc"};
	res = s.findAnagrams1(s1, p1);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
