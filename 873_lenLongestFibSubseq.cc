/* https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
(The time limit has been reduced by 50% for submissions in Java, C, and C++.)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lenLongestFibSubseq2(vector<int>& A) {
		int n = A.size();
		map<int, int> m; 
		for (int i = 0; i < n; i++) m[A[i]] = i;
		vector<vector<int>> dp(n, vector<int>(n, 2));
		for (int j = 1; j < n; j++)
			for (int i = 0; i < j; i++)
				if (m.find(A[j]-A[i]) != m.end() and m[A[j] - A[i]] < i)
					dp[i][j] = max(dp[i][j], dp[m[A[j] - A[i]]][i] + 1);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			ans = max(ans, dp[i][j]);
		return (ans==2)?0:ans;
	}
	// O(n^2) DP, dp[i][j] represents the length of longest sequence which ends with A[i] and A[j].
	int lenLongestFibSubseq1(vector<int>& A) {
		int n=A.size(), res=0;
		unordered_map<int,int> mp;
		for (int i=0; i<n; ++i) mp[A[i]]=i;
		vector<vector<int>> dp(n, vector<int>(n,2));
		for (int j=2; j<n; ++j) for (int i=j-1; i>0; --i) {
			int cand=A[j]-A[i];
			if (cand>=A[i]) break;			// no need to search A[i] (think: strictly increasing)
			if (mp.count(cand)==0) continue;
			dp[i][j]=dp[mp[cand]][i]+1;
			res=max(res,dp[i][j]);
		}
		return res;
	}
	// O(n^2log(max(A)))
	int lenLongestFibSubseq(vector<int>& A) {
		int n=A.size(), res=0;
		unordered_set<int> st(A.begin(), A.end());
		for (int i=0; i<n; ++i) {
			for (int j=i+1; j<n; ++j) {
				int a=A[i],b=A[j],cnt=2;	// start from 2 nums
				while (st.count(a+b))		// log(max(A))
					++cnt, b=a+b, a=b-a;
				res=max(res,cnt);
			}
		}
		return res;
	}
}; 
int main(){
	Solution s;
	vector<int> A1{1,2,3,4,5,6,7,8};
	cout << s.lenLongestFibSubseq(A1) << endl;
	cout << s.lenLongestFibSubseq1(A1) << endl;
	cout << s.lenLongestFibSubseq2(A1) << endl;
};
