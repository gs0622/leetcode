/* https://leetcode.com/problems/merge-intervals/description/
 * array, sort, lambda expression
*/
#include <bits/stdc++.h>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> merge(vector<Interval>& ints) {
		if (ints.empty()) return {};
		sort(begin(ints), end(ints), [](Interval a, Interval b){return a.start < b.start;});
		vector<Interval> res(1, ints[0]);
		for (int i=1; i<ints.size(); ++i) {
			if (ints[i].start > res.back().end) res.push_back(ints[i]);	// no overlap
			else res.back().end = max(res.back().end, ints[i].end);
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<Interval> ints{{1,3},{2,6},{8,10},{15,18}};
	vector<Interval> res = s.merge(ints);
	for (auto x: res) cout << x.start << "," << x.end << " ";
	cout << endl;
}
