/*https://leetcode.com/problems/longest-word-in-dictionary/description/*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end());
		unordered_set<string> built;
		string res;
		for (string w : words) {
			if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
				res = w.size() > res.size() ? w : res;
				built.insert(w);
			}
		}
		return res;
	}
	string longestWord2(vector<string>& words) {
		string r("");
		set<string> s;
		//std::sort(words.begin(), words.end());
		for (auto w: words) {
			s.insert(w);
		}
		for (auto w: words) {
			for (int i = 0; i < w.size(); i++) {
				if (s.count(w.substr(0, i)))
					r = w;
			}
		}
		return r;
	}
};

int main() {
	vector<string> strs1{"w","wo","wor","worl", "world"};
	vector<string> strs2{"a", "banana", "app", "appl", "ap", "apply", "apple"};
	Solution s;
	cout << s.longestWord(strs1) << " " << s.longestWord2(strs1) << endl;
	cout << s.longestWord(strs2) << " " << s.longestWord2(strs2) << endl;
	return 0;
}
