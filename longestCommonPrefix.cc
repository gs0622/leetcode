#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(m+log(n))
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		function<bool(int)> isCommonPrefix = [&](int n){
			string s = strs[0].substr(0, n);
			for (int i=1; i<strs.size(); ++i) {
				if (s != strs[i].substr(0, n))
					return false;
			}
			return true;
		};
		auto it = min_element(begin(strs), end(strs), [&](string a, string b){return a.size()<b.size();});
		int n = it->size();
		int lo=0, hi=n;
		// true ....| false
		while (lo<hi) {
			int mi=lo+(hi-lo)/2;
			if (isCommonPrefix(mi+1)) lo=mi+1;
			else hi=mi;
		}
		// lo==hi
		return strs[0].substr(0, lo);	// lo is the 1st of false, while it is the len of truth
	}
	// O(mn) Brute force verfical scan, m for strs number, n for prefix string len
	string longestCommonPrefix1(vector<string>& strs) {
		//sort(begin(strs), end(strs), [&](string a, string b){return a.size() < b.size();}); 
		string res;	// prefix string
		for (int i=0; i<strs[0].size(); ++i) {
			for (int j=0; j<strs.size(); ++j) {
				//if (strs[j][i] != strs[0][i])
				if (i < strs[j].size() && strs[j][i] != strs[0][i])
					return res;
			}
			res += strs[0][i];
		}
		return res;
	}
};
int main(void)
{
	Solution s;

	vector<string> strs1{"foo223", "foo22312", "foo22342"};
	//cout << s.longestCommonPrefix(strs1) << ": " << s.longestCommonPrefix1(strs1) << endl;

	vector<string> strs2{"aoo223", "boo22312", "coo22342"};
	//cout << s.longestCommonPrefix(strs2) << ": " << s.longestCommonPrefix1(strs2) << endl;

	vector<string> strs3;
	//cout << s.longestCommonPrefix(strs3) << ": " << s.longestCommonPrefix1(strs3) << endl;
	cout << s.longestCommonPrefix(strs3) << endl;
}

