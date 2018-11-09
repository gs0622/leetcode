#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		string s2(s.rbegin(), s.rend());
		int i, n=s.size();
		for (i=n; i>=0; --i) {
			cout << s.substr(0,i) << " - " << s2.substr(n-i) << endl;
			if (s.substr(0,i)==s2.substr(n-i, string::npos))
				break;
		}
		cout << s2.substr(0,n-i) << " + " << s << endl;
		return s2.substr(0,n-i) + s;
	}
};
int main(){
	Solution s;
	string s1{"aacecaaa"};
	cout << s.shortestPalindrome(s1) << endl;
	string s2{"abcd"};
	cout << s.shortestPalindrome(s2) << endl;
}
