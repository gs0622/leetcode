/*HTTPS://LEETCode.com/problems/daily-temperatures/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time and space
	vector<int> dailyTemperatures(vector<int>& t) {
		stack<int> s;
		vector<int> r(t.size(), 0);	//  If there is no future day for which this is possible, put 0 instead.
		for (int i=0; i<t.size(); ++i) {
			while (!s.empty() && t[i]>t[s.top()]) {   // use t[i] to exame every s.top() as candidate
				r[s.top()]=i-s.top();
				s.pop();
			}
			s.push(i);	// push index into stack
		}
		return r;
	}
	vector<int> dailyTemperatures1(vector<int>& t) {
		multimap<int,int> mp;	// temperature-index map
		vector<int> res(t.size(), 0);
		for (int i=0; i<t.size(); ++i) {
			auto it = mp.lower_bound(t[i]);
			if (it != mp.begin()) {
				for (auto it2=mp.begin(); it2!=it; ++it2) {
					if (t[i] > it2->first) {
						res[it2->second] = i-it2->second;
						mp.erase(it2);
					}
				}
			}
			mp.insert({t[i],i});
		}
		return res;
	}
	// O(n^2) Brute-force 
	vector<int> dailyTemperatures2(vector<int>& t) {
		vector<int> res(t.size());
		int i, j, n=t.size();
		for (i=0; i<n; ++i) {
			j=i+1;
			while (j<n && t[j]<=t[i]) ++j;  // break until a warmer day j
			res[i] = j==n? 0: j-i;
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res, temps1{73, 74, 75, 71, 69, 72, 76, 73};
	res = s.dailyTemperatures(temps1);
	for (auto d: res) cout << d << " ";
	cout << endl;
	res.clear();
	res = s.dailyTemperatures1(temps1);
	for (auto d: res) cout << d << " ";
	cout << endl;
	vector<int> temps2{89,62,70,58,47,47,46,76,100,70};
	res.clear();
	res = s.dailyTemperatures(temps2);
	for (auto d: res) cout << d << " ";
	cout << endl;
	res.clear();
	res = s.dailyTemperatures1(temps2);
	for (auto d: res) cout << d << " ";
	cout << endl;
}
