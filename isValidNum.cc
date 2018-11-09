#include <bits/stdc++.h>
using namespace std;
class Solution {
public:	
	bool isNumber(string s) {
		int n=s.size(), i=s.find_first_not_of(" \t");
		while (s[i]=='+' || s[i]=='-') ++i;
		bool res = false;

		while (i<n && isdigit(s[i]))	// integer part
			res=true, ++i;

		if (s[i]=='.' || s[i]=='e') {	// decimal-point/exponent (one only)
			++i;
			while (i<n && isdigit(s[i])) res=true, ++i;
		}

		while (i<n && isblank(s[i])) ++i;

		return res && i==n;
	}
};
int main(){
	Solution s;
	cout << s.isNumber("0") << endl;
	cout << s.isNumber("0.1") << endl;
	cout << s.isNumber("abc") << endl;
	cout << s.isNumber("1 a") << endl;
	cout << s.isNumber("2e10") << endl;
}
