/* https://leetcode.com/problems/insert-interval/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct Interval {
	int start, end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};
class Solution {
public:
	// O(n)
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int i = 0;

		// push prefix
		while (i < intervals.size() && intervals[i].end < newInterval.start){
			res.push_back(intervals[i++]);
		}

		// merge intersection
		while (i < intervals.size() && intervals[i].start <= newInterval.end){
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
			i++;
		}
		res.push_back(newInterval);

		// push suffix
		while (i < intervals.size()){
			res.push_back(intervals[i++]);
		}
		return res;
	}
	// wrong
	vector<Interval> insert1(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.empty()) {
			intervals.push_back(newInterval);
			return intervals;
		}
		sort(begin(intervals), end(intervals), [](Interval a, Interval b){ return a.start < b.start; });
		int i;
		for (i=0; i<intervals.size(); ++i) {
			if (intervals[i].end < newInterval.start) continue;
			if (intervals[i].start > newInterval.end) {
				intervals.insert(begin(intervals)+i, newInterval); // ints[i] is on right
				return intervals;
			} else { // intervals[i].end >= newInterval.start && intervals[i].start <= netIntervals.end
				if (i+1<intervals.size() && intervals[i+1].start > newInterval.end) {
					intervals[i].end = max(intervals[i].end, newInterval.end);
					return intervals;
				} else {
					int j, k, s = intervals[i].start;
					for (j=i+1; j<intervals.size(); ++j)
						if (intervals[j].start > newInterval.end) break;
					intervals.erase(begin(intervals)+i, begin(intervals)+j-1);
					intervals[i].start = s;
					return intervals;
				}
			}
		}
		if (i==intervals.size())
			intervals.push_back(newInterval);
		return intervals;
	}
};

int main(){
	Solution s;
	vector<Interval> ints1{{1,3},{6,9}};
	vector<Interval> ints2{{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<Interval> res;
	res = s.insert(ints1, Interval(2,5));
	for (auto i: res) cout << i.start << ',' << i.end << ' ';
	cout << endl;
	res = s.insert(ints2, Interval(4,8));
	for (auto i: res) cout << i.start << ',' << i.end << ' ';
	cout << endl;
}
