#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool checkValidString1(string s) {
		function<bool(int,int)> helper=[&](int start, int cnt) {
			for (int i=start; i<s.size();++i) {
				if	(s[i]=='(') ++cnt;
				else if (s[i]==')') {
					if (cnt<=0)
						return false;
					--cnt;
				}
				else if (s[i]=='*')
					return helper(i+1,cnt+1)	// ')'
					    || helper(i+1,cnt-1)	// '('
					    || helper(i+1,cnt);		// skip as empty
			}
			return cnt==0;
		};
		return helper(0,0);
	}
	// naive one, 52 / 58 test cases passed.
	bool checkValidString(string s) {
		stack<char> stk;
		for (int i=0; i<s.size(); ++i) {
			if (stk.empty() && s[i]==')') return false;
			if (s[i]=='(') stk.push(s[i]);
			else if (s[i]==')') stk.pop();
			else {
				s[i]='(';
				string s1=s;
				s[i]=')';
				string s2=s;
				string s3=s.erase(i,1);
				return checkValidString(s1) || checkValidString(s2) || checkValidString(s3);
			}
		}
		return stk.empty();
	}
};
int main(){
	Solution s;
/*
	cout << s.checkValidString1("()") << endl;
	cout << s.checkValidString1("(*)") << endl;
	cout << s.checkValidString1("()") << endl;
	cout << s.checkValidString1("(()") << endl;
	cout << s.checkValidString1("(*()") << endl;
	cout << s.checkValidString1(")(") << endl;
*/
	cout << s.checkValidString("()(()(*(())()*)(*)))()))*)((()(*(((()())()))()()*)((*)))()))(*)(()()(((()*()()((()))((*((*)()") << endl;
	cout << s.checkValidString1("()(()(*(())()*)(*)))()))*)((()(*(((()())()))()()*)((*)))()))(*)(()()(((()*()()((()))((*((*)()") << endl;
}
