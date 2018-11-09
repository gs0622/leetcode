/* https://leetcode.com/problems/non-overlapping-intervals/description/

hint: greedy: apply the earlist finish time greedy strategy to maximize request, reverse thinking to fit the question
https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization

concrete example:
    |---||---||---||---|
       |---||---||---|
       |---|     |---|
       |---|     |---|
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
	// O(nlog(n)) time, n for invervals
	int eraseOverlapIntervals(vector<Interval>& ints) {
		if (ints.size() < 2) return 0;
		sort(begin(ints), end(ints), [](Interval a, Interval b){return a.end < b.end;});
		int end = ints[0].end, cnt=1;	// end, non-overlap invervals cnt
		for (int i=1; i<ints.size(); ++i) {
			if (ints[i].start>=end)	// compatible
				end = ints[i].end, ++cnt;
		}
		return ints.size()-cnt;		// total - max compatible = erase
	}
};
int main(){
	Solution s;
	vector<Interval> ints1{{1,2},{2,3},{3,4},{1,3}};	// {1,2}, {2,3}, {1,3}, {3,4}, or {1,2}, {1,3},{2,3}, {3,4}
	vector<Interval> ints2{{1,2},{1,2},{1,2}};
	vector<Interval> ints3{{1,2},{2,3}};
	vector<Interval> ints4{{1,100},{11,22},{1,11},{2,12}};
	cout << s.eraseOverlapIntervals1(ints1) << endl;
	cout << s.eraseOverlapIntervals1(ints2) << endl;
	cout << s.eraseOverlapIntervals1(ints3) << endl;
	cout << s.eraseOverlapIntervals1(ints4) << endl;
}
