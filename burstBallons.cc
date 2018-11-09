/* https://leetcode.com/problems/burst-balloons/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(begin(nums),1);
		nums.insert(end(nums),1);
		vector<vector<int>> dp(n+2,vector<int>(n+2));
		for (int k=2; k<n+2; ++k) {
			for (int L=0; L<n+2-k; ++L) {
				int R = L + k;
				for (int i=L+1; i<R; ++i)
					dp[L][R] = max(dp[L][R], nums[L]*nums[i]*nums[R] + dp[L][i]+dp[i][R]);
			}
		}
		return dp[0][n+1];
	}
};
int main(){
	Solution s;
	vector<int> nums{3,1,5,8};
	cout << s.maxCoins(nums) << endl;
}
