/* https://leetcode.com/problems/coin-change/description/
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, amount+1);
		dp[0] = 0;
		for (int i=1; i<=amount; ++i) {
			for (auto coin: coins) {
				if (coin <= i)
					dp[i]=std::min(dp[i], dp[i-coin]+1);
			}
		}
		return dp[amount] > amount? -1: dp[amount];
	}
};
int main(){
	Solution s;
	//vector<int> nums1{1, 2, 5};
	//cout << s.coinChange(nums1, 11) << endl;
	vector<int> nums2{2};
	cout << s.coinChange(nums2, 3) << endl;
}
