#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool isPalindrome(string& s, int lo, int hi) {
		while (lo<hi)
			if (s[lo++]!=s[hi--]) return false;
		return true;
	}
public:
	// O(nk^2) hashmap approach
	vector<vector<int>> palindromePairs2(vector<string>& words) {
		unordered_map<string,int> mp;	// rev-word/index map
		int n=words.size();
		vector<vector<int>> res;
		for (int i=0; i<n; ++i) {
			string w = words[i];
			reverse(begin(w),end(w));
			mp[w]=i;
		}
		if (mp.count("")) {
			int i=mp[""];
			for (int j=0; j<n; ++j) {
				string s=words[j];
				if (j!=i && isPalindrome(s,0,s.size()-1))
					res.push_back({i, j});	// here append {"", self-palindrome}, below covers {self-parlindrome, ""}
			}
		}
		for (int i=0; i<n; ++i) {		// index
			int m=words[i].size();
			for (int j=0; j<m; ++j) {	// len
				string L=words[i].substr(0,j), R=words[i].substr(j);
				if (isPalindrome(L,0,L.size()-1) && mp.count(R) && mp[R]!=i)	// prefix-L-R
					res.push_back({mp[R],i});
				if (isPalindrome(R,0,R.size()-1) && mp.count(L) && mp[L]!=i)	// L-R-suffix
					res.push_back({i,mp[L]});
			}
		}
		return res;
	}
	// O(n^2) naive brute force, enumerate all pairs to examine
	vector<vector<int>> palindromePairs(vector<string>& words) {
		int n=words.size();
		vector<vector<int>> res;
		//function<bool(string)> helper=[](string s){
		//	for (int i=0, j=s.size()-1; i<j; ++i, --j)
		//		if (s[i]!=s[j]) return false;
		//	return true;
		//};
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (i==j) continue;
				string s=words[i]+words[j];
				if (isPalindrome(s,0,s.size()-1)) res.push_back({i,j});
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<string> words1{"bat", "tab", "cat"};
	vector<string> words2{"abcd", "dcba", "lls", "s", "sssll"};
	vector<vector<int>> res;
	res = s.palindromePairs2(words1);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
	res = s.palindromePairs2(words2);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
}
