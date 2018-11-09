#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string reverseOnlyLetters(string S) {
		for (int i=0, j=S.size()-1; i<j; ++i, --j) {
			while (i<j && !isalpha(S[i])) ++i;
			while (i<j && !isalpha(S[j])) --j;
			if (i<j) swap(S[i], S[j]);
		}
		return S;
	}
};
int main(){
	Solution s;
	cout << s.reverseOnlyLetters("ab-cd") << endl;
	cout << s.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
	cout << s.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
	cout << s.reverseOnlyLetters("ghzAb") << endl;
	cout << s.reverseOnlyLetters("7_28]") << endl;
}
