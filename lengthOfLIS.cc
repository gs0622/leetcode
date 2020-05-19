/*
DP, LIS (Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLIS(vector<int>& A) { // O(n^2) time, O(n^2) space
    int n=A.size();
    vector<vector<int>> memo(n+1, vector<int>(n,-1));
    function<int(int,int)> helper=[&](int pre, int cur) {
      if (cur==n) return 0;
      if (memo[pre+1][cur]!=-1) return memo[pre+1][cur];
      int taken=0;
      if (pre==-1||A[cur]>A[pre])
        taken=1+helper(cur,cur+1);
      int nottaken=helper(pre,cur+1);
      memo[pre+1][cur]=max(taken,nottaken);
      return memo[pre+1][cur];
    };
    return helper(-1,0);
  }
  int lengthOfLIS1(vector<int>& A) { // O(2^n) time, O(n^2) space
    int n=A.size();
    function<int(int,int)> helper=[&](int preVal, int cur) {
      if (cur==n) return 0;
      int taken=0;
      if (A[cur]>preVal)
        taken=1+helper(A[cur],cur+1);
      int nottaken=helper(preVal,cur+1);
      return max(taken,nottaken);
    };
    return helper(INT_MIN,0);
  }
};
class Solution2 {
public:
	// O(nlog(n)), https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
	int lengthOfLIS(vector<int>& nums) {
		vector<int> ans;
		for (int i=0; i<nums.size(); ++i) {
			auto it = std::lower_bound(ans.begin(), ans.end(), nums[i]);
			if (it == ans.end()) ans.push_back(nums[i]); // append
			else *it = nums[i]; // replace
		}
		return ans.size();
	}
	// O(n^2) DP
	int lengthOfLIS2(vector<int>& nums) {
		int i, j, sz = nums.size(), res=0;
		vector<int> LIS(sz, 1);
		for (i=1; i<sz; ++i) {			// max ending here
			for (j=0; j<i; ++j) {		// evaluate from 0 to i-1
				if (nums[i] > nums[j]) {
					LIS[i] = max(LIS[i], LIS[j]+1);
					res = max(res, LIS[i]);
				}
			}
		}
		//return (sz == 0)? 0: *std::max_element(LIS.begin(), LIS.end());
		return res;
	}
};
int main(){
	vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
	Solution s;
	Solution2 s2;
	cout << s.lengthOfLIS(nums) << endl;
	cout << s2.lengthOfLIS(nums) << endl;
	cout << s2.lengthOfLIS2(nums) << endl;
}
