#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel;
        for (string w : wordlist) {
            string lower = tolow(w), devowel = todev(w);
            cap.insert({lower, w});
            vowel.insert({devowel, w});
        }
        for (int i = 0; i < (int)queries.size(); ++i) {
            if (words.count(queries[i])) continue;
            string lower = tolow(queries[i]), devowel = todev(queries[i]);
            if (cap.count(lower)) {
                queries[i] = cap[lower];
            } else if (vowel.count(devowel)) {
                queries[i] = vowel[devowel];
            } else {
                queries[i] = "";
            }
        }
        return queries;
    }

    string tolow(string w) {
        for (auto & c: w)
            c = tolower(c);
        return w;
    }

    string todev(string w) {
        w = tolow(w);
        for (auto & c: w)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '#';
        return w;
    }
};
class Solution {
	unordered_set<char> vow{'a','e','i','o','u'};
public:
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		unordered_set<string> st(wordlist.begin(), wordlist.end());
		unordered_map<string,string> decap, devow;
		function<string(string)> tolow=[](string s) { for (auto &c: s) c=tolower(c); return s; };
		function<string(string)> todev=[&](string s) { s=tolow(s); /*tricky*/ for (auto &c: s) if (vow.count(c)) c='#'; return s; };
		for (auto w: wordlist) {
			decap.insert({tolow(w),w});	// tricky: insert but not update key []
			devow.insert({todev(w),w});
		}
		for (auto &w: queries) {
			if (st.count(w)) continue;
			string s1=tolow(w), s2=todev(w);
			if (decap.count(s1)) w=decap[s1];
			else if (devow.count(s2)) w=devow[s2];
			else w="";
		}
		return queries;
	}
};
int main(){
	Solution s;
	vector<string> res;
	vector<string> W1{"KiTe","kite","hare","Hare"}, Q1{"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
	res = s.spellchecker(W1, Q1);
	for (auto s: res) cout << s << ", ";
	cout << endl; 
}
