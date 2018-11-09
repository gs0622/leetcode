/*Given a string s and a string t, check if s is subsequence of t.*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s == "") return true;
		int i = 0, j = 0;
		while (i < t.size()) {
			if (s[j] == t[i]) ++j; // has s[j], step j one forward
			++i; // t[i] step forward
			if (j == s.size()) return true;
		}
		return false;
	}
	bool isSubsequence1(string s, string t) {
		int i, j; // i for s, j or s[i-1] in t
		for (i=0, j=0; i<s.size(); ++i) {
			if ((j = t.find(s[i], j)) == string::npos) // s[i] not found?
				return false;
			else ++j;
		}
		return true;
	}
	bool isSubsequence2(string s, string t) {
		char *ss = (char *) s.c_str(), *tt = (char *)t.c_str();
		while (*tt && *ss) ss += (*ss == *tt++);
		return !(*ss);
	}
};
int main(){
	string s("abc");
	string t("ahbgdc");
	Solution so;
	cout << so.isSubsequence(s,t) << endl;
	cout << so.isSubsequence1(s,t) << endl;
	cout << so.isSubsequence2(s,t) << endl;
}
