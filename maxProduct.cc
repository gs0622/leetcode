#include <bitset>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int maxProduct(vector<string>& words) {
		unordered_map<int, int> m;
		int res = 0;
		for (auto word: words) {
			int mask = 0, len = word.size();
			for (char c: word) mask |= 1 << (c-'a');
			m[mask] = std::max(m[mask], len);
			for (auto p: m) {
				if ((mask & p.first) == 0)
					res = std::max(res, len * p.second);
			}
		}
		return res;
	}
	int maxProduct2(vector<string>& words) {
		int i, j, n = words.size(), max = 0;
		vector<int> b(n, 0);
		for (i=0; i<n; ++i) {
			for (auto c: words[i]) {
				int mask = 1 << (c-'a');
				b[i] |= mask;
			}
		}
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				if ((b[i] & b[j]) == 0) {
					int prod = words[i].size() * words[j].size();
					if (prod > max) max = prod;
				}
			}
		}
		return max;
	}
};
int main(){
	Solution s;
	vector<string> words1{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	vector<string> words2{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	vector<string> words3{"a", "aa", "aaa", "aaaa"};

	cout << s.maxProduct(words1) << " " << s.maxProduct2(words1) << endl;
	cout << s.maxProduct(words2) << " " << s.maxProduct2(words2) << endl;
	cout << s.maxProduct(words3) << " " << s.maxProduct2(words3) << endl;
}
