/* https://leetcode.com/problems/word-break/description/
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

hint: word split problem, DP, two-pointer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(begin(wordDict), end(wordDict));
		int n=s.size();
		vector<int> dp(n+1, 0);	dp[0]=1;
		for (int i=1; i<n+1; ++i) {	// split position
			for (int j=i-1; j>=0; --j) {	// start of substr
				if (dp[j]==1 && dict.count(s.substr(j,i-j))>0) {	// why i-j?
					dp[i]=1;
					break;	// next i, no need to iterate j
				}
			}
		}
		return dp[n]==1;
	}
};
int main(){
	vector<string> d1{"leet", "code"};
	vector<string> d2{"apple", "pen"};
	vector<string> d3{"cats", "dog", "sand", "and", "cat"};
	Solution s;
	cout << s.wordBreak("leetcode", d1) << endl;
	cout << s.wordBreak("applepenapple", d2) << endl;
	cout << s.wordBreak("catsandog", d3) << endl;

	
}
