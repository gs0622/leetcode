/*
Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end).
Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

How to calculate overlap of 2 intervals?
Assume a start earlier than b, (if not reverse),
there could be 3 case, but in any case, an overlap(either positive or negative) can always be represented as:
(max(a0, b0), min(a1, b1))

case 1: b ends before a ends:
a: a0 |-------------| a1
b:     b0 |-----| b1

case 2: b ends after a ends:
a: a0 |--------| a1
b:     b0 |--------| b1

case 3: b starts after a ends: (negative overlap)
a: a0 |----| a1
b:              b0 |----| b1

#operlap
#array
*/
#include <bits/stdc++.h>
using namespace std;
class MyCalendarTwo {
	vector<pair<int,int>> cal;
	class MyCalendarOne {
		vector<pair<int,int>> cal;
	public:
		bool book(int start, int end) {
			for (auto p: cal) if (max(p.first, start) < min(p.second, end)) return false;
			cal.push_back({start,end});
			return true;
		}
	};
public:
	bool book(int start, int end) {
		MyCalendarOne ovp;
		function<pair<int,int>(int,int,int,int)> overlap=[](int s0, int e0, int s1, int e1) {
			return make_pair(max(s0,s1), min(e0,e1));
		};
		for (auto p: cal)
			if (max(p.first, start) < min(p.second, end)) {
				auto q=overlap(p.first,p.second,start,end);
				if (ovp.book(q.first,q.second)==false) return false;	// overlap w/ operlapped cal.
			}
		cal.push_back({start,end});
		return true;
	}
};
int test1(){
	MyCalendarTwo s;
	cout << s.book(10,20) << endl;	// true
	cout << s.book(50,60) << endl;	// true
	cout << s.book(10,40) << endl;	// true
	cout << s.book(5,15) << endl;	// false
	cout << s.book(5,10) << endl;	// true
	cout << s.book(25,55) << endl;	// true
}
int test2(){
	MyCalendarTwo s;
	cout << s.book(24,40) << endl;	// true
	cout << s.book(43,50) << endl;	// true
	cout << s.book(27,43) << endl;	// true
	cout << s.book(5,21) << endl;	// true
	cout << s.book(30,40) << endl;	// false
	cout << s.book(14,29) << endl;	// false
}
int main(){
	test2();
}
