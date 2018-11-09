#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool isPalidrome(string &s, int i, int j) {
		while (i < j) {
			if (s[i++] != s[j--])
				return false;
		}
		return true;
	}
public:
	// O(n^2) time, O(1) space
	string longestPalindrome1(string s) {
		function<int(int,int)> helper = [&](int L, int R) {
			while (L>=0 && R<s.size() && s[L]==s[R])
				--L, ++R;
			return R-L-1; // tricky in -1, because L/R are failed window now R-L+1-2
		};
		int L=0, R=0;	// window of palindrome
		for (int i=0; i<s.size(); ++i) {
			int len1 = helper(i,i);
			int len2 = helper(i,i+1);
			int len = max(len1, len2);
			if (len > R-L)
				L=i-(len-1)/2, R=i+len/2;
		}
		return s.substr(L, R-L+1);
	}
	// O(n^3), enumerate all sub strings
	string longestPalindrome(string s) {
		int n = s.size(), max = 0;
		string res;
		for (int i=0; i<n; ++i) {		// start
			for (int j=n-1; j>=i; --j) {	// end
				if (j-i+1 < max) break;
				if (isPalidrome(s, i, j)) {
					string sub(s, i, j-i+1); // substring: (s, pos, len)
					int len = sub.size();
					if (len > max)
						res = sub, max = len;
					break;
				}
			}
		}
		return res;
	}
};

int main(void) {
	Solution s;
        cout << s.longestPalindrome("babad") << ": " << s.longestPalindrome1("babad") << endl;
        cout << s.longestPalindrome("cbbd") << ": " << s.longestPalindrome1("cbbd") << endl;
}
