/*
# monotonous increase stack
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time and space
	int sumSubarrayMins1(vector<int>& A) {
		int n=A.size();
		stack<pair<int,int>> stk_ple, stk_nle;	// previous/next less element stack in pair of value-index
		vector<int> ple(n), nle(n);
		for (int i=0; i<n; ++i)
			ple[i]=i+1, nle[i]=n-i;
		for (int i=0; i<n; ++i) {
			while (!stk_ple.empty() && stk_ple.top().first > A[i])		// loop of looking for previous less
				stk_ple.pop();
			ple[i]=stk_ple.empty()? i+1: i-stk_ple.top().second;
			stk_ple.push({A[i], i});					// regular push

			while (!stk_nle.empty() && stk_nle.top().first > A[i]) {	// loop of assigning next less on previous
				auto x = stk_nle.top(); stk_nle.pop();
				nle[x.second] = i-x.second;
			}
			stk_nle.push({A[i],i});
		}
		int res=0, mod=1e9+7;
		for (int i=0; i<n; ++i)
			res = res+A[i]*ple[i]*nle[i], res%=mod;
		return res;
	}
	// O(n^3) Brute-force
	int sumSubarrayMins(vector<int>& A) {
		int n = A.size();
		long long sum = 0;
		for (int i=0; i<n; ++i) {       // start
			for (int j=i; j<n; ++j) {     // end
				int cmin = INT_MAX;
				for (int k=i; k<=j; ++k) {  // iterate
					cmin = min(cmin, A[k]);
				}
				sum += cmin;
			}
		}
		return (int)(sum%1000000007);
	}
};
int main(){
	Solution s;
	vector<int> A1{3,1,2,4};
	cout << s.sumSubarrayMins(A1) << endl;
	cout << s.sumSubarrayMins1(A1) << endl;
}
