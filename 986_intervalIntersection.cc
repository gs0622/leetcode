#include <bits/stdc++.h>
using namespace std;
struct Interval {
	int start, end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};
class Solution2 {
public:
	vector<Interval> intervalIntersection1(vector<Interval>& A, vector<Interval>& B) {
		vector<Interval> res;
		int m=A.size(), n=B.size(), i=0, j=0;
		while (i<m && j<n) {
			if      (A[i].end<B[j].start) ++i;
			else if (B[j].end<A[i].start) ++j;
			else {
				Interval ans(max(A[i].start,B[j].start), min(A[i].end, B[j].end));
				res.push_back(ans);
				if (A[i].end < B[j].end) ++i; else ++j;
			}
		}
		while (i<m) ++i;	// do nothing
		while (j<n) ++j;
		return res;
	}
	vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
		vector<Interval> res;
		int m=A.size(), n=B.size();
		for (int i=0,j=0; i<m && j<n;) {	// same as while (i<m && j<n) w/ init i/j
			if      (A[i].end < B[j].start) ++i;
			else if (B[j].end < A[i].start) ++j;
			else {
				res.push_back(Interval(max(A[i].start,B[j].start), min(A[i].end, B[j].end)));
				if (A[i].end < B[j].end) ++i; else ++j;
			}
		}
		// dont care i left or j left
		return res;
	}
};
class Solution {
	struct cmp {
		bool operator()(Interval a, Interval b) { return a.start > b.start || (a.start == b.start && a.end > b.end); }
	};
public:
	// O(nlogn)
	vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
		priority_queue<Interval, vector<Interval>, cmp> pq;
		for (auto a: A) pq.push(a);
		for (auto b: B) pq.push(b);
		vector<Interval> res;
		while (pq.size()) {
			auto p = pq.top(); pq.pop();
			if (pq.size() && pq.top().start <= p.end) {
				res.push_back(Interval(pq.top().start, min(p.end, pq.top().end)));
				if (p.end > pq.top().end) pq.pop(), pq.push(p);
			}
		}
		return res;
	}
};
int main(){
	Solution2 s;
	//A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
	vector<Interval> A1{{0,2},{5,10},{13,23},{24,25}};
	vector<Interval> B1{{1,5},{8,12},{15,24},{25,26}};
	for (auto p: s.intervalIntersection(A1,B1)) cout << p.start << "," << p.end << " ";
	cout << endl;
	vector<Interval> A2{{3,5},{9,20}};
	vector<Interval> B2{{4,5},{7,10},{11,12},{14,15},{16,20}};
	for (auto p: s.intervalIntersection1(A2,B2)) cout << p.start << "," << p.end << " ";
	cout << endl;
}
