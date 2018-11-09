#include <bits/stdc++.h>
using namespace std;
class MyCalendar {
	set<pair<int,int>> cal;
public:
	// check every booked schedule
	bool book(int start, int end) {
		auto p = make_pair(start,end);
		for (auto it=cal.begin(); it!=cal.end(); ++it) {
			if (start < it->second && end > it->first)
				return false;
		}
		cal.insert(p);
		return true;
	}
};
class MyCalendar2 {
	set<pair<int,int>> cal;
public:
	MyCalendar2() {}
	//   c1       c2       c3           c4
	//  |----|  |---|   |-------|	   |--|		: booked schedule
	//     |------|       |---|     |--------|	: new booking
	bool book(int start, int end) {
		auto p = cal.lower_bound({start,end});
		if (p!=cal.end() && p->first < end) // c2 & c4
			return false;
		if (p!=cal.begin() && (--p)->second > start) // c1 & c3
			return false;
		cal.insert({start,end});
		return true;
	}
};
int main(){
	MyCalendar s;
	MyCalendar2 s2;
	cout << s.book(10,20) << ' ' << s2.book(10,20) << endl;	// true
	cout << s.book(15,25) << ' ' << s2.book(15,20) << endl; // c1
	cout << s.book(20,30) << ' ' << s2.book(20,30) << endl;	// true
	cout << s.book(10,30) << ' ' << s2.book(10,30) << endl; // c4
}
