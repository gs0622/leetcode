/*https://leetcode.com/problems/repeated-substring-pattern/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		auto it=(s+s).substr(1, s.size()*2-2).find(s);
		return (s+s).substr(1, s.size()*2-2).find(s) != -1;
	}
	bool repeatedSubstringPattern1(string s) {
		if (s.size()==1) return false;
		for (int i=1; i<=s.size()/2; ++i) {
			string rol(s);
			std::rotate(rol.begin(), rol.begin()+i, rol.end());
			if (s == rol) return true;
		}
		return false;
	}
	// wrong one by thinking of set
	bool repeatedSubstringPattern2(string s) {
		if (s.size()==1) return false;
		set<char> sets;
		for (auto c: s) sets.insert(c);
		int i, len=s.size(), sublen=sets.size();
		string pat=s.substr(0,sublen);
		for (i=sublen; i<len; i+=sublen) {
			string subs=s.substr(i,sublen);
			if (subs != pat) return false;
		}
		return true;
	}
};
int main(){
	Solution s;
	string s0("abab");
	cout << s.repeatedSubstringPattern(s0) << ": " << s.repeatedSubstringPattern1(s0) << endl;
	string s1("aba");
	cout << s.repeatedSubstringPattern(s1) << ": " << s.repeatedSubstringPattern1(s1) << endl;
	string s2("abcabcabcabc");
	cout << s.repeatedSubstringPattern(s2) << ": " << s.repeatedSubstringPattern1(s2) << endl;
	string s3("abaababaab");
	cout << s.repeatedSubstringPattern(s3) << ": " << s.repeatedSubstringPattern1(s3) <<  endl;
}
