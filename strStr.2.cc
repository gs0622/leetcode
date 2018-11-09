#include <bits/stdc++.h>
using namespace std;

// Brute-force solution, O(nm) time.
class Solution {
public:
	int strStr1(string haystack, string needle) {
		hash<string> hs;
		size_t hh, hn = hs(needle);
		for (int i=0; i<haystack.size()-needle.size(); ++i)
			if (hs(haystack.substr(i, needle.size())) == hn) return i;
		return -1;
	}
	// O(mn) two pointer
	int strStr(string haystack, string needle) {
		for (int i = 0; ; i++) {
			for (int j = 0; ; j++) {
				if (j == needle.size()) return i;		// done
				if (i + j > haystack.size()) return -1;		// overflow
				if (haystack[i+j] != needle[j]) break;		// restart
			}
		}
	}
};

int main(void) {
    string a("mississippi");
    string b("issi");
    //string a("aaabbbccc");	// Q: what about haystack size is less than needle?
    //string b("");		// Q: what about needle is empty str?
    Solution s;
    cout << s.strStr(a, b) << endl;
    cout << s.strStr1(a, b) << endl;
    return 0;
}
