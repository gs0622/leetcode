#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int i, j, n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (i=0; i<n; ++i) dp[i][i] = nums[i];
		for (i=1; i<n; ++i) {
			for (j=0; j+i<n; ++j)
				dp[j][j+i] = std::max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
		}
		return dp[0][n-1] >= 0;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,5,2};
	cout << s.PredictTheWinner(nums1) << endl;
	vector<int> nums2{1,5,233,7};
	cout << s.PredictTheWinner(nums2) << endl;
}
