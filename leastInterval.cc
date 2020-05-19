#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int leastInterval1(vector<char>& tasks, int n) {
		unordered_map<char,int> cnt;
		for (auto t: tasks) ++cnt[t];			// task,cnt mapping
		function<bool(char,char)> cmp = [&](char a, char b) {return cnt[a]<cnt[b];};
		priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
		for (auto p: cnt) pq.push(p.first);
		int res=0;
		while (!pq.empty()) {
			int time=0;
			vector<char> tmp;
			for (int i=0; i<n+1; ++i) {
				if (!pq.empty()) {
					tmp.push_back(pq.top()); pq.pop();
					++time;
				}
			}
			for (auto t: tmp) {
				if (--cnt[t]>0)
					pq.push(t);
			}
			res += pq.empty()? time: n+1;
		}
		return res;
	}
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char,int> cnt;
		for (auto t: tasks) ++cnt[t];			// map<task, count>
		priority_queue<pair<int,char>> pq;		// pq<count, task>, maxheap
		for (auto p: cnt)
			pq.push(make_pair(p.second, p.first));	// maxheap sorting by count
		int res=0;
		// n means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
		while (!pq.empty()) {
			int time=0;
			vector<pair<int,char>> tmp;	// schedular
			for (int i=0; i<n+1; ++i) {	// round robin w/ n intervals
				if (!pq.empty()) {	// if there is task
					tmp.push_back(pq.top()), pq.pop();
					++time;
				}
			}
			for (auto p: tmp) {
				if (--p.first)	// --count
					pq.push(p);
			}
			res += pq.empty()? time: n+1;
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<char> tasks{'A','A','A','B','B','B'};
	cout << s.leastInterval(tasks, 0) << endl;
	cout << s.leastInterval1(tasks, 0) << endl;
}
