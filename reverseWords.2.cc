#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void reverseWord3(string &s) {
		istringstream iss(s);		// stringstream is fine as well
		string word, res;
		iss >> res;			// 1st word to the last, this avoids tailing space
		while (iss >> word)
			res = word + " " + res;	// reverse order
		s.swap(res);
	}
	void reverseWord2(string &s) {
		istringstream iss(s);
		string w;
		iss >> s;			// 1st word -> the last word w/o space
		while(iss >> w)
			s = w + " " + s;
		if(s[0] == ' ') s = "";
	}
	void reverseWord1(string& s) {
		stack<char> stk;
		string tmp(s);
		auto it = s.rbegin();
		for (auto c: tmp) {
			if (c == ' ') {
				while (!stk.empty())
					*it++ = stk.top(), stk.pop();
				*it++ = ' ';
			} else 
				stk.push(c);
		}
		while (!stk.empty())
			*it++ = stk.top(), stk.pop();
	}
	void reverseWord(string& s) {
		// TODO: take care leading, tailing, and multiple spaces
		reverse(begin(s), end(s));
		int tok=0, pre=0;
		while ((tok=s.find(' ', tok)) != string::npos) {
			//while (s[tok+1] == ' ') { s.erase(tok, 1); continue; }
			reverse(begin(s)+pre, begin(s)+tok);
			tok+=1, pre=tok;
		}
		reverse(begin(s)+pre, end(s)); // lastly, tok==npos
	}
};
int main(){
	Solution so;
	string s{"the sky is   blue"};
	so.reverseWord3(s);
	cout << s << endl;
}
