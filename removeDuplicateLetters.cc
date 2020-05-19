/*https://leetcode.com/problems/remove-duplicate-letters/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	string removeDuplicateLetters(string s) {
    vector<int> cnt(26,0), vst(26,0);

    for (auto c: s) ++cnt[c-'a'];   // occurance

    string res;
    for (auto c: s) {
      --cnt[c-'a'];
      if (vst[c-'a']) continue;     // dup
      while (c < res.back() &&      // lex order
        cnt[res.back()-'a'])
        vst[res.back()-1] = 0, res.pop_back();
      vst[c-'a'] = 1;
      res += c;
    }
    return res;   
  }
};
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> dict(26, 0); // or 256 in terms of ascii
		vector<bool> visit(26, false);
		for (auto c: s) dict[c-'a']++; // count occurance
		string res;
		for (auto c: s) {
			dict[c-'a']--;
			if (visit[c-'a']) continue;
			while (c < res.back() && dict[res.back()-'a']) { // lexicographical check for counts remain
				visit[res.back()-'a'] = false;
				res.pop_back();
			}
			visit[c-'a'] = true;
			res += c;
		}
		return res;
	}
};
int main(){
	Solution s;
	cout << s.removeDuplicateLetters("bcabc") << endl;
	cout << s.removeDuplicateLetters("cbacdcbc") << endl;
	cout << s.removeDuplicateLetters("") << endl;
}
