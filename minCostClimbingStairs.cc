/* https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int i, n=cost.size(), sum=0;
		if (n<3) return std::min(cost[0], cost[1]);
		vector<int> dp(n, 0);
		dp[0]=cost[0],dp[1]=cost[1];
		for (i=2; i<n; ++i) dp[i]=std::min(dp[i-1],dp[i-2]) + cost[i];
		return std::min(dp[n-1], dp[n-2]);
	}
};
int main(){
	Solution s;
	vector<int> nums1{10, 15, 20};
	cout << s.minCostClimbingStairs(nums1) << endl;
	vector<int> nums2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	cout << s.minCostClimbingStairs(nums2) << endl;
}
