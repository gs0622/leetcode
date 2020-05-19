#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
class Solution {
public:
	vs letterCasePermutation2(string S) {
		int n=S.size();
		vs res;
		function<void(int)> helper=[&](int i) {
			if (i==n) {
				res.push_back(S);
				return;
			}
			helper(i+1);
			if (isalpha(S[i])) {
				S[i]^=(1<<5);	// a=0x61, A=0x41
				helper(i+1);
			}
		};
		helper(0);
		return res;
	}
	// DFS
	vs letterCasePermutation1(string S) {
		int n=S.size();
		vs res;
		function<void(int,string)> helper=[&](int i, string s){
			if (i==n) {
				res.push_back(s);
				return;
			}
			if (isdigit(s[i])) {
				helper(i+1,s);
				return;
			}
			s[i] = toupper(s[i]);
			helper(i+1,s);
			s[i] = tolower(s[i]);
			helper(i+1,s);
		};
		helper(0,S);
		return res;
	}
	// Backtracking
	vs letterCasePermutation(string S) {
		int n=S.size();
		vs res;
		const int diff = 'A'-'a';
		function<void(int,string)> helper=[&](int i, string s) {
			if (i==n) {
				res.push_back(s);
				return;
			}
			if (isalpha(s[i])) {
				if (isupper(s[i])) {
					s[i]-=diff;
					helper(i+1,s);
					s[i]+=diff;
				} else {
					s[i]+=diff;
					helper(i+1,s);
					s[i]-=diff;
				}
			}
			helper(i+1,s);
		};
		helper(0,S);
		return res;
	}
};
int main(){
	Solution s;
/*
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
Input: S = "3z4"
Output: ["3z4", "3Z4"]
Input: S = "12345"
Output: ["12345"]
*/
	vs res;

	string S1{"a1b2"};
	res = s.letterCasePermutation2(S1);
	for (auto ss: res) cout << ss << " ";
	cout << endl;

	string S2{"3z4"};
	res = s.letterCasePermutation2(S2);
	for (auto ss: res) cout << ss << " ";
	cout << endl;

	string S3{"12345"};
	res = s.letterCasePermutation2(S3);
	for (auto ss: res) cout << ss << " ";
	cout << endl;
}
