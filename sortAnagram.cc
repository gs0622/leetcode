#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> sortAnagram(vector<string> strs) {
		unordered_map<string, vector<string>> map;
		for (int i=0; i<strs.size(); ++i) {
			string s = strs[i];
			sort(begin(s), end(s));
			map[s].push_back(strs[i]);
		}
		vector<string> res;
		for (auto x: map)
			res.insert(end(res), begin(x.second), end(x.second));
		return res;
	}
};
using namespace std;
int main(){
	vector<string> strs{ "abc", "def", "cba", "ghi", "fde"};
	Solution s;
	vector<string> res = s.sortAnagram(strs);
	for (auto s: res) cout << s << ' ';
	cout << endl;
}
