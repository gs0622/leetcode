/* https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
 string, subsequence, sort, lambda

The longest uncommon subsequence is defined as the longest subsequence of one of these strings and
this subsequence should not be any subsequence of the other strings.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool helper(string s, string t) {
                int i, j;       // index of s and t;
                for (i=0, j=0; i<s.size(); ++i) {
                        if ((j = t.find(s[i], j)) == string::npos) return false;        // there is no s[i]
                        ++j;
                }
                return true;    // s is subsequence of t
	}
public:
	int findLUSlength(vector<string>& strs) {
		sort(begin(strs), end(strs), [](string a, string b){ return a.size() > b.size(); });

		function<bool(string,string)> isSubsequence = [&](string s, string t){
			int i, j;	// index of s and t;
			for (i=0, j=0; i<s.size(); ++i) {
				if ((j = t.find(s[i], j)) == string::npos) return false;	// there is no s[i]
				++j;
			}
			return true;	// s is subsequence of t
		};
		for (int i=0; i<strs.size(); ++i) {
			bool noSubsequence = true;
			for (int j=0; j<strs.size() && (j<i||strs[i].size()==strs[j].size()); ++j) {
				if (i!=j && isSubsequence(strs[i], strs[j])) {
					noSubsequence = false;
					break;
				}
			}
			if (noSubsequence) return strs[i].size();
		}
		return -1;
	}
	int findLUSlength1(vector<string>& strs) {
		std::sort(strs.begin(), strs.end(), [](string a, string b){return a.size() > b.size();});
		for (int i = 0; i < strs.size(); i++){
			bool is_subsequence = false;
			for (int j = 0; j < strs.size() && (j < i || strs[i].size() == strs[j].size()); j++){
				if (i != j && helper(strs[i], strs[j])){
						is_subsequence = true;
						break;
				}
			}
				if (!is_subsequence)
					return strs[i].size();
		}
		return -1;
	}
};
int main(){
	vector<string> strs1{"aba", "cdc", "eae"};
	vector<string> strs2{"aaa", "aa", "a"};
	vector<string> strs3{"aabbcc", "aabbcc","c"};
	Solution s;
	cout << s.findLUSlength(strs3) << endl;
	cout << s.findLUSlength1(strs3) << endl;
}
