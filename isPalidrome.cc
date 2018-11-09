/* https://leetcode.com/problems/valid-palindrome/description/
 string, two-pointer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		int i=0,j=s.size()-1;
		while (j>i) {
			while (!isalnum(s[i])) i+=1;
			while (!isalnum(s[j])) j-=1;
			if (j>i && tolower(s[i++])!=tolower(s[j--]))
				return false;
		}
		return true;
	}
};
int main(){
	Solution s;
	string s1{"A man, a plan, a canal: Panama"};
	string s2{"race a car"};
	string s3{"0P"};
	cout << s.isPalindrome(s3) << endl;
	cout << s.isPalindrome(s2) << endl;
	cout << s.isPalindrome(s1) << endl;
}

