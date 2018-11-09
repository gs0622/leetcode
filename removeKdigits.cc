/* https://leetcode.com/problems/remove-k-digits/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string removeKdigits1(string num, int k) {
		int sz = 0;
		for (int i=0; i<num.size(); ++i) {
			auto c = num[i];
			if (k && sz && c < num[sz-1])
				--sz, --k;
			num[sz++] = c;
		}
		while (!num.empty() && '0' == *begin(num)) num.erase(begin(num)), --sz;
		num.resize(sz);
		return num;
	}
	// greedy: push every digits while keep smaller one against current adding, as early (higher digit) as possible
	// stack thinking, look backward one
	string removeKdigits(string num, int k) {
		string res;
		if (k >= num.size()) return "0";	// [a]
		int need = num.size() - k;
		for (auto c: num) {
			while (k && !res.empty() && c < res.back()) {
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		res.resize(need);	// for k remaining case, namely c >= back(), shrink
		while (!res.empty() && '0' == *begin(res)) res.erase(begin(res));
		//return res.empty()? "0": res;		// [b]
		return res;	// either [a] or [b]
	}
};
using namespace std;
int main(){
	Solution s;
	cout << s.removeKdigits1("1432219", 3) << endl;	// 1 x x x 2 1 9
	cout << s.removeKdigits1("10200", 1) << endl;	// x 0 2 0 0
	cout << s.removeKdigits("10", 2) << endl;	// 0
	cout << s.removeKdigits("11", 2) << endl;	// 0
	cout << s.removeKdigits("123", 2) << endl;	// 1
}
