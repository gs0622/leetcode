#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	const string keymap[10] { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxzy" };
	void dfs(string& digits, vector<string>& ret, string& str, int n) {
		if (n >= digits.size()) {
			ret.push_back(str);
			return;
		}
		for (auto c: keymap[digits[n]-'0']) {
			str.push_back(c);
			//cout << "s: " << str << endl;
			dfs(digits, ret, str, n+1);
			str.pop_back();
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return vector<string>();
		vector<string> ret{""};
		string str;
		dfs(digits, ret, str, 0);
		return ret;
	}
	vector<string> letterCombinations2(string digits) {
		if (digits.size() == 0) return vector<string>();
		//const string keymap[10] { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxzy" };
		vector<string> ret {""};
		for (auto c: digits) {
			vector<string> tmp;
			for (auto y: ret) {
				for (auto x: keymap[c-'0']) {
					tmp.push_back(y+x);
				}
			}
			ret = tmp;
		}
		return ret;
	}
};

int main() {
	string digits("23");
	vector<string> ret;
	Solution s;
	ret = s.letterCombinations(digits);
	for (auto x: ret) cout << x << " ";
	cout << endl;
	ret.clear();
	ret = s.letterCombinations(digits);
	for (auto x: ret) cout << x << " ";
	cout << endl;
}
