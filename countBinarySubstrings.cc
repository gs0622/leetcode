/* https://leetcode.com/problems/count-binary-substrings/description/
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int countBinarySubstrings3(string s) {
		int res=0, cur=1, pre=0, n=s.size();
		for (int i=1; i<n; ++i) {
			if (s[i-1]==s[i]) ++cur;	// until 1/0 flip
			else {
				res+=min(pre,cur);	// e.g., 0001111 => min(3,4)
				pre=cur;
				cur=1;
			}
		}
		return res;
	}
	int countBinarySubstrings(string s) {
		int ans=0, base=0, slow=0, n=s.size();
		while (base<n) {
			int fast=0;
			while (s[base]==s[base+fast]) fast+=1; // until 1/0 flip
			ans += min(slow,fast);
			base+=fast;
			slow=fast;
		}
		return ans;
	}
	int countBinarySubstrings2(string s) {
		int ans=0, prev=0, cur=1;
		for (int i=1; i<s.size(); ++i) {
			cout << s.substr(0, i+1) << endl;
			if (s[i]==s[i-1]) cur+=1;
			else prev=cur, cur=1;
			if (prev>=cur) ans+=1;
		}
		return ans;
	}
	vector<string> substrs(string s) {
		vector<string> ss;
		for (int i=0; i<s.size(); ++i) {
			for (int j=2; j<=s.size()-i; j+=2) ss.push_back(s.substr(i, j));
		}
		return ss;
	}
};
int main(){
	Solution s;
	//vector<string> ss = s.substrs("000111");
	//vector<string> ss = s.substrs("11100");
	//for (auto sss: ss) cout << sss << endl;
	cout << s.countBinarySubstrings("00110011") << endl;
	//cout << s.countBinarySubstrings("00110") << endl;
}
