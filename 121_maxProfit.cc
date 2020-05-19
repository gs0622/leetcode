/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems

Base cases:
T[-1][k][0] = 0, T[-1][k][1] = -Infinity
T[i][0][0] = 0, T[i][0][1] = -Infinity

Recurrence relations:
T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])      // rest, sell
T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])    // rest, buy

k=1
T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i])
T[i][1][1] = max(T[i-1][1][1], T[i-1][0][0] - prices[i]) = max(T[i-1][1][1], -prices[i])
*/
#include <bits/stdc++.h>
using namespace std;
class Solution4 {
public:
  int maxProfit(vector<int>& P) {
    int max_end_here=0,max_so_far=0;
    for (int i=1; i<P.size(); ++i) {
      max_end_here=max(0,max_end_here+P[i]-P[i-1]);
      max_so_far=max(max_so_far,max_end_here);
    }
    return max_so_far;
  }
};
class Solution3 {
public:
  int maxProfit(vector<int>& prices) {
    int sold=0, hold=INT_MIN;     // sold: T[i][1][0], hold: T[i][1][1]
    for (auto p: prices) {
      sold = max(sold, p+hold);   // existing sold against potential profit, p+hold=p-p'
      hold = max(hold, -p);       // hold as cost in negative
    }
    return sold;
  }
};
class Solution2 {
public:
  int maxProfit(vector<int>& p) {
    stack<int> stk;
    for (int i=1; i<p.size(); ++i) {
      int tmp=p[i]-p[i-1];
      if (tmp>0) stk.push(tmp); 
    }
    int res=0;
    while (stk.size())
      res+=stk.top(), stk.pop();
    return res;
  }
};
class Solution {
public:
	int maxProfit(vector<int>& p) {
		if (p.size()<2) return 0;
		int min_p=INT_MAX, ans=0, n=p.size();
		for (auto x: p) {
			min_p = std::min(x, min_p);
			ans = std::max(x-min_p, ans);
		}
		return ans;
	}
	int maxProfit2(vector<int>& p) {
		if (p.size()<2) return 0;
		int i, j, n=p.size();
		vector<int> d(n,0);
		for (i=n-1;i>=1;--i) {
			for (j=i-1; j>=0; --j)
				d[i]=std::max(p[i]-p[j], d[i]);
		}
		return *std::max_element(d.begin(), d.end());
	}
};

int main(){
	Solution3 s;
	vector<int> p1{7, 1, 5, 3, 6, 4};
	cout << s.maxProfit(p1) << endl;
	vector<int> p2{7, 6, 4, 3, 1};
	cout << s.maxProfit(p2) << endl;
}
