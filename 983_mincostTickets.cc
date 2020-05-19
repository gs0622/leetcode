/* https://leetcode.com/problems/minimum-cost-for-tickets/description/
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.
 

Note:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// track travel days: O(n) time, O(38) space
	int mincostTickets2(vector<int>& days, vector<int>& costs) {
		queue<vector<int>> last07, last30;	// expire date, cost
		int res=0;
		for(auto d: days){
			while(last07.size() && last07.front()[0]+7  <= d) last07.pop();	// expire
			while(last30.size() && last30.front()[0]+30 <= d) last30.pop();
			last07.push({d, res+costs[1]});					// O(7) space, max in 7
			last30.push({d, res+costs[2]});					// O(30) space, max in 30
			res = min({res+costs[0], last07.front()[1], last30.front()[1]});
		}
		return res;
	}
	// O(n) time, track 31 days only, memory optimization, rolling
	int mincostTickets1(vector<int>& days, vector<int>& costs) {
		unordered_set<int> st(days.begin(), days.end());
		int dp[31]={};
		for (auto i=1; i<=365; ++i) {
			if (st.count(i))
				dp[i%31]=min({dp[(i-1)%31]+costs[0], dp[max(0,i-7)%31]+costs[1], dp[max(0,i-30)%31]+costs[2]});
			else
				dp[i%31]=dp[(i-1)%31];
		}
		return dp[365%31];
	}
	// O(n) time, track all calendar days, simple and easy to understand
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		int dp[366]={};						// 0,1,...365, ascending cost or equal
		unordered_set<int> st(days.begin(), days.end());	// O(n) dump the schedule into hashset
		for (auto i=1; i<=365; ++i) {				// O(365>=n)
		//for (auto i=1; i<=days.back(); ++i) {			// O(n)
			if (st.count(i)) dp[i]=min(dp[i-1]+costs[0], min(dp[max(0,i-7)]+costs[1], dp[max(0,i-30)]+costs[2]));
			else dp[i]=dp[i-1];
		}
		return dp[365];
		//return dp[days.back()];
	}
};
int main(){
	Solution s;
	vector<int> D1{1,4,6,7,8,20}, C1{2,7,15};
	//vector<int> D1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}, C1{2,7,15};
	cout << s.mincostTickets(D1,C1) << endl;
	cout << s.mincostTickets1(D1,C1) << endl;
	cout << s.mincostTickets2(D1,C1) << endl;
}
