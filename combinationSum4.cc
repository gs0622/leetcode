#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution {
public:
	int combinationSum4(vi& A, int T) {
		vi dp(T+1,-1);
		dp[0]=1;
		function <int(int,int)> helper = [&](int S, int T){
			if (dp[T]!=-1) return dp[T];
			int res=0;
			for (int i=S; i<A.size(); ++i) {
				if (T>=A[i]) {
					//res += helper(S, T-A[i]);	// allow dup
					res += helper(S+1, T-A[i]);	// no dup allowed
				}
			}
			dp[T]=res;	// memorize
			return res;
		};
		return helper(0, T);
	}
};
int main(){
	Solution s;
	vi nums{-1,1,2,3};
	cout << s.combinationSum4(nums, 4) << endl;
}
