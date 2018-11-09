/* https://leetcode.com/problems/valid-palindrome-ii/description/
string, palidrome, dfs
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool helper(string& s, int lo, int hi) {
		for (int i=lo, j=hi; i<j; ++i, --j)
			if (s[i]!=s[j])
				return false;
		return true;
	}
public:
	bool validPalindrome(string s) {
		for (int i=0, j=s.size()-1; i<j; ++i, --j) {
			if (s[i] != s[j])
				return helper(s, i+1, j) || helper(s, i, j-1); 
		}
		return true;
	}
};
int main(){
	Solution s;
	cout << s.validPalindrome("aba") << endl;
	cout << s.validPalindrome("abca") << endl;
	cout << s.validPalindrome("abfca") << endl;
}
