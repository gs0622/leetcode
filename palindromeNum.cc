/*
https://leetcode.com/problems/palindrome-number

Determine whether an integer is a palindrome. Do this without extra space.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool palindromeNumber(int num) {
		auto reverse = [](int num){
			int rev=0;
			while (num>0)	// tricky: ignore all negative num, leave it as 0
				rev=rev*10+num%10, num/=10;
			return rev;
		};
		return num == reverse(num);
	}
	/* Bad: this uses extra space (string) */
	bool palindromeNumber1(int num) {
		string s = to_string(num);
		int i, j;
		for (i = 0, j = s.size() - 1; i < j; ++i, --j) {
			if (s[i] != s[j]) return false;
		}
		return true;
	}
};
int main(void) {
	Solution s;
	//cout << s.palindromeNumber(11) << endl;		// true
	//cout << s.palindromeNumber(121) << endl;	// true
	cout << s.palindromeNumber(-121) << endl;	//
	cout << s.palindromeNumber(1) << endl;		// true
	cout << s.palindromeNumber(12321) << endl;	// true
	cout << s.palindromeNumber(23) << endl;		// false
	cout << s.palindromeNumber(32) << endl;		// false
	cout << s.palindromeNumber(1232) << endl;	// false
}
