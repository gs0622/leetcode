#include <bits/stdc++.h>
using namespace std;
class Solution {
	string getRange(int from, int to) {
		string r;
		if (from == to)
			r = to_string(from);
		else
			r = to_string(from) + "->" + to_string(to);
		return r;
	}
public:
	// add start-1 and end+1, exclude prev and cur as missing range
	vector<string> missingRange(vector<int>& nums, int start, int end) {
		vector<string> res;
		int prev = start-1;
		for (int i=0; i<=nums.size(); ++i) {
			int cur = (i!=nums.size())? nums[i]: end+1;
			if (cur-prev>1) {
				if (cur-prev==2) res.push_back(to_string(prev+1));
				else res.push_back(to_string(prev+1) + "->" + to_string(cur-1));
			}
			prev=cur;
		}
		return res;
	}
	vector<string> missing(vector<int>& v) {
		int s, e, i;
		vector<string> r;
		if (0 == v.size()) {
			r.push_back("0->99");
			return r;
		}
		for (i = 1, s = i; i < v.size(); i++) {
			if (v[i] - v[i-1] == 1) {
				s = i+1;
				continue;
			}
			e = v[i] - 1;
			r.push_back(getRange(s, e));
			s = v[i]+1;
		}
		if (v[i-1] < 99) r.push_back(to_string(s) + "->99");
		return r;
	}
};
int main(void) {
	Solution s;
	vector<int> nums{0, 1, 3, 50, 75};
	//vector<string> r = s.missing(nums);
	vector<string> r = s.missingRange(nums, 0, 99);
	for (auto x: r) cout << x << " ";
	cout << endl;
	return 0;
 }
