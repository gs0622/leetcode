/* https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		sort(begin(d), end(d), [](string a, string b){ return a.size()>b.size() || (a.size()==b.size() && a[0]<b[0]); });

		function<bool(string,string)> isSubsequence = [](string s, string t) {
			int i, pos=0;
			for (i=0; i<s.size(); ++i) {
				if ((pos=t.find(s[i], pos)) == string::npos) return false;
				++pos;
			}
			return true;
		};

		// return is not working inside lambda?
		//for_each(begin(d), end(d), [&](string a){
		//	if (isSubsequence(a, s)) {
		//		cout << a << endl;
		//		return a;
		//	}
		//});

		for (int i=0; i<d.size(); ++i) {
			if (isSubsequence(d[i], s))
				return d[i];
		}
		return {};
	}
};
int main(){
	Solution s;
	vector<string> dict1{"ale","apple","monkey","plea"};
	cout << s.findLongestWord("abpcplea", dict1) << endl;
	vector<string> dict2{"a","b","c"};
	cout << s.findLongestWord("abpcplea", dict2) << endl;
	vector<string> dict3{"ba","ab", "a", "b"};
	cout << s.findLongestWord("bab", dict3) << endl;
}
