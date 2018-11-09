#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Solution {
    void reverse(char *p, char *q) {
        if (!p || !q) return; 
        while (p < q) {
            if (*p != *q)
                *p ^= *q, *q ^= *p, *p ^= *q;
            ++p, --q;
        }
    }
public:
	// argue the tailing space, i.e. " "
	void reverseWords(string &s) {
		while (s.end()[-1]==' ') s.erase(s.end()-1);
		std::reverse(s.begin(), s.end());
		while (s.end()[-1]==' ') s.erase(s.end()-1);
		int beg = 0, tok = 0;
		while ((tok = s.find(' ', tok)) != string::npos) {
			std::reverse(s.begin()+beg, s.begin()+tok);
			beg = tok + 1;
			tok = beg;
		}
		std::reverse(s.begin()+beg, s.end());
	}	
    void reverseWords2(string &s) {
        char *p = (char *) s.c_str();
        reverse(p, p + s.size() - 1);
        cout << s << endl;
        size_t pos = 0;
        char *q = (char *) s.c_str();
        while (std::string::npos != (pos = s.find(' ', pos))) {
            reverse(q, p + pos - 1);
            q = p + pos + 1;
            pos += 1;
        }
        reverse(q, p + s.size() - 1);
    }
};

int main() {
    Solution s;
    string s0("the sky is blue");
    s.reverseWords(s0);
    cout << s0 << endl;
    string s1(" ");
    s.reverseWords(s1);
    cout << s1 << endl;
    return 0;
}
