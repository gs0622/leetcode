/* https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct Interval {
	int start, end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class SummaryRanges1 {
	struct cmp { bool operator()(Interval a, Interval b){ return a.start<b.start; } };
	set<Interval,cmp> st;
public:
	// O(log(n)) time per add
	void addNum(int val) {
		int start=val, end=val;
		auto it=st.lower_bound(Interval(val,val));	// think if empty container: it==end==begin
		if (it!=st.begin() && (--it)->end+1<val)	// tricky: is lower_bound-1 need to be merged?
			++it;	// no
		while (it!=st.end() && val+1>=it->start && val-1<=it->end) {
			start=min(start,it->start);
			end=max(end, it->end);
			it = st.erase(it);		// update iterator to followed one
		}
		st.insert(it, Interval(start, end));	// w/ hint
	}
	// O(n) per query
	vector<Interval> getIntervals() {
		return vector<Interval>(begin(st), end(st));
	}
};
class SummaryRanges {
	vector<Interval> v;
public:
	SummaryRanges() {}
	// O(n) time per add
	void addNum(int val) {
		function<bool(Interval,Interval)> cmp = [](Interval a, Interval b){ return a.start<b.start; };
		auto it=lower_bound(begin(v), end(v), Interval(val,val), cmp);	// not less than, i.e. greater or equal
		int start=val, end=val;
		if (it!=v.begin() && (--it)->end+1<val)	// is it connecting to lower_bound-1?
			++it;
		while (it!=v.end() && val+1 >= it->start && val-1 <= it->end) {	// merge/expand interval:
			start = min(start, it->start);
			end = max(end, it->end);
			it = v.erase(it);
		}
		v.insert(it, Interval(start, end));
	}
	// O(1) per query
	vector<Interval> getIntervals() {
		return v;
	}
};
int main(){
	SummaryRanges s;
	vector<Interval> res;
	s.addNum(6);
	res=s.getIntervals();
	for (auto p: res) cout << p.start << ',' << p.end << ' ';
	cout << endl;
	s.addNum(6);
	res=s.getIntervals();
	for (auto p: res) cout << p.start << ',' << p.end << ' ';
	cout << endl;
	s.addNum(0);
	res=s.getIntervals();
	for (auto p: res) cout << p.start << ',' << p.end << ' ';
	cout << endl;
	s.addNum(4);
	res=s.getIntervals();
	for (auto p: res) cout << p.start << ',' << p.end << ' ';
	cout << endl;
	s.addNum(8);
	res=s.getIntervals();
	for (auto p: res) cout << p.start << ',' << p.end << ' ';
	cout << endl;
}
