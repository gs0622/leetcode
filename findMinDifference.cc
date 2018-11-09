/* https://leetcode.com/problems/minimum-time-difference/description/
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
e.g.
Input: ["23:59","00:00"]
Output: 1

string
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findMinDifference(vector<string>& tp) {
		int n = tp.size();
		vector<int> nums(n);

		for (int i=0; i<n; ++i)
			nums[i] = stoi(tp[i].substr(0, 2)) * 60 + stoi(tp[i].substr(3, 2));	// hh*60 + mm
		sort(begin(nums), end(nums));
		int res = 1440; // max: 24*60
		for (int i=0; i<n; ++i) {
			int diff = abs(nums[i]-nums[(i-1+n)%n]);
			diff = min(diff, 1440-diff);
			res = min(res, diff);
		}
		return res;
	}
	int findMinDifference1(vector<string>& tp) {
		int n = tp.size();
		vector<int> tp2;
		for (auto& t: tp) {
			int hh = stoi(t.substr(0, 2));
			int mm = stoi(t.substr(3, 2));
			tp2.push_back(hh*60+mm);
		}
		int res = 1440; // 24*60
		sort(begin(tp2), end(tp2));
		for (int i=0; i<n; ++i) {
			int diff = abs(tp2[i]-tp2[(i-1+n)%n]);	// trick: (i-1+n)%n round elem [-1] (aka. 0-1) to elem [n-1]
			diff = min(diff, 1440-diff);
			res = min(res, diff);
		}
		return res;
	}
};
int main(){
	vector<string> tp{"23:59","00:00"};
	Solution s;
	cout << s.findMinDifference(tp) << endl;
}
