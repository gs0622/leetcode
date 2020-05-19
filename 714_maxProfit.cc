/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int sold=0, hold=-50000;
    for (auto p: prices) {
      int tmp = sold;
      sold = max(sold, p+hold);     // existing sold vs. potential profit
      hold = max(hold, tmp-p-fee);  // hold keeps the cost and fee in negative 
    }
    return sold;
  }
};
int main(){
  Solution s;
  vector<int> A1{1, 3, 2, 8, 4, 9};
  cout << s.maxProfit(A1,2) << endl;
}
