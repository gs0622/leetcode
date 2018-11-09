/* https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
hint: sliding window
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// maintain a sliding window of char map to detect the map equal between s and p
	vector<int> findAnagrams(string s, string p) {
		vector<int> pv(256,0), sv(256,0), res;
		if (s.size() < p.size()) return res;
		for (int i=0; i<p.size(); ++i) {
			++pv[p[i]], ++sv[s[i]];
		}

		if (pv == sv)					// tricky to learn: vector's equal operator ==
			res.push_back(0);

		for (int i=p.size(); i <s.size(); ++i) {	// the sliding window
			++sv[s[i]];
			--sv[s[i-p.size()]];
			if (pv == sv)
				res.push_back(i-p.size()+1);
		}
		return res; // arr indices
	}
};
int main(){
	Solution s;
	vector<int> res;
	string s1{"cbaebabacd"}, p1{"abc"};
	res = s.findAnagrams(s1, p1);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
