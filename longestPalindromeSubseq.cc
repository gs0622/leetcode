/* https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n^2) dp
	int longestPalindromeSubseq2(string s) {
		int n=s.size();
		vector<vector<int>> dp(n+1, vector<int>(n));
	}

	// O(n^2) memorization
	int longestPalindromeSubseq1(string s) {
		int n=s.size();
		vector<vector<int>> dp(n, vector<int>(n));

		function<int(int,int)> helper = [&](int lo, int hi) {
			if (lo>hi) return 0;
			if (lo==hi) return 1;
			if (dp[lo][hi]) return dp[lo][hi];
			dp[lo][hi] = (s[lo] == s[hi])? 2+helper(lo+1, hi-1):
				max(helper(lo+1, hi), helper(lo, hi-1));
			return dp[lo][hi];
		};

		return helper(0, n-1);
	}

	// O(n^2) brute-force
	int longestPalindromeSubseq(string s) {
		function<int(int,int)> helper = [&](int lo, int hi) {
			if (lo>hi) return 0;
			if (lo==hi) return 1;
			return (s[lo] == s[hi])? 2+helper(lo+1, hi-1):		// [lo]==[hi], both are must in optimized ans, so +2
				max(helper(lo+1, hi), helper(lo, hi-1));	// nudge (skip one) to the right or left
		};
		return helper(0, s.size()-1);
	}
};
int main(){
	Solution s;
	string s1{"bbbab"};
	cout << s.longestPalindromeSubseq1(s1) << endl;

	string s2{"cbbd"};
	cout << s.longestPalindromeSubseq1(s2) << endl;
}
