#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char,int> mp;
		for (auto c: t) ++mp[c];
		int n=s.size(),i=0,j=0,cnt=mp.size(),len=INT_MAX,head=0;
		string r;
		while (i<n) {
			if (mp.count(s[i])) {
				--mp[s[i]];			// tricky: could be nagative
				if (mp[s[i]]==0) --cnt;
			}
			++i;
			while (cnt==0) {
				if (mp.count(s[j])) {
					++mp[s[j]];
					if (mp[s[j]]>0) ++cnt;	// tricky: only when the count goes postive
				}
				if (i-j<len)
					len=i-j,head=j;
				++j;
			}
		}
		return len==INT_MAX? "": s.substr(head,len);
	}
};
int main(){
	Solution s;
	cout << s.minWindow("a", "aa") << endl;
	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}
