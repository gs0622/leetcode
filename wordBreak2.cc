/* https://leetcode.com/problems/word-break/description/
old: Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.


hint: word split problem, DP, two-pointer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// top-down dfs+dp recursion
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(begin(wordDict), end(wordDict));
		unordered_map<int, vector<string>> memo{{s.size(), {""}}};	// sentinel at s.size()
		// helper returns a list of all sentences that can be built from the suffix s[i:].
		function<vector<string>(int)> helper=[&](int i) {
			if (!memo.count(i)) {
				for (int j=i+1; j<=s.size(); ++j) {	// j is split point which ahead 1, j-i==substr length
					string ss=s.substr(i,j-i);	// prefix splitted at j
					if (dict.count(ss)) {
						vector<string> tails=helper(j);	// suffix s[j:]
						for (string tail: tails) {
							//memo[i].push_back(ss+(tail==""? "": ' '+tail));	// memorize
							memo[i].push_back(ss+(tail.empty()? "": ' '+tail));
						}
					}
				}
			}
			return memo[i];	// return memorized answer
		};
		vector<string> res=helper(0);
		return res;
	}
};
int main(){
	vector<string> d1{"cat", "cats", "and", "sand", "dog"};
	Solution s;
	auto res = s.wordBreak("catsanddog", d1);
	for (auto s: res) cout << s << endl;

	
}
