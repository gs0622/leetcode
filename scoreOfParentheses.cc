/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time O(1) space
	int scoreOfParentheses1(string S) {
		int res=0, layer=0;
		for (int i=0; i<S.size(); ++i) {
			if (S[i]=='(')
				++layer;
			else
				--layer;
			if (S[i]=='(' && S[i+1]==')')
				res+=1*(1<<(layer-1));
		}
		return res;
	}
	// O(n) time O(n) space
	int scoreOfParentheses(string S) {
		int res[30]={0}, i=0;
		for (auto c: S) {
			if (c=='(') res[++i]=0;
			else res[i-1]+=max(res[i]*2,1), i--;
		}
		return res[0];
	}
};
int main(){
	Solution s;
	string s1{"()"},s2{"(())"},s3{"()()"},s4{"(()(()))"};
	cout << s.scoreOfParentheses1(s1) << endl;
	cout << s.scoreOfParentheses1(s2) << endl;
	cout << s.scoreOfParentheses1(s3) << endl;
	cout << s.scoreOfParentheses1(s4) << endl;
}
