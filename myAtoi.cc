/* 
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int myAtoi2(string s) {
		int i=0, j=s.size()-1, sign=1;
		while (s[i]==' ') ++i;
		while (s[j]==' ') --j;
		//while (s[i]=='-'||s[i]=='+')
		//	sign*=(s[i++]=='-')?-1:1;
		if (s[i]=='-'||s[i]=='+')
			sign=1-2*(s[i++]=='-');
		int res=0;
		for (; i<=j; ++i) {
			if (!isdigit(s[i])) break;
			if (res>INT_MAX/10 || (res==INT_MAX/10 && s[i]-'0'>7))
				return sign==1? INT_MAX: INT_MIN;
			res=res*10+s[i]-'0';
		}
		return res*sign;
	}
	int myAtoi(string s) {
		int i=0, sign=1;
		long long res=0;
		for (i=0; i<s.size(); ++i) if (!isspace(s[i])) break;
		if (s[i]=='-') sign=-1, ++i;
		else if (s[i]=='+') ++i;
		while (i<s.size()) {
			int ch = s[i];
			if (!isdigit(ch)) break;
			res = res*10 + (ch-'0');
			++i;
		}
		return (int)(res*sign);
	}
};
int main(){
	Solution s;
	cout << s.myAtoi2("-+2") << endl;
	cout << s.myAtoi2("-123") << endl;
	cout << s.myAtoi2("+123") << endl;
	cout << s.myAtoi2("123") << endl;
	cout << s.myAtoi2("0") << endl;
	cout << s.myAtoi2("-91283472332") << endl;
	cout << s.myAtoi2("words and 987") << endl;
	cout << s.myAtoi2("4193 with words") << endl;
}
