/* https://leetcode.com/problems/maximum-sum-circular-subarray/description/

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) bottom-up DP
	int maxSubarraySumCircular1(vector<int>& A) {
		int cmin=0, cmax=0, smin=INT_MAX, smax=INT_MIN, sum=0;
		for (auto n: A) {
			cmax=max(cmax+n, n);	// think why cmax is 0 initially
			smax=max(smax, cmax);	// summax = max(summax, curmax)
			cmin=min(cmin+n, n);
			smin=min(smin, cmin);
			sum+=n;			// pure sum
		}
		return smax>0? max(smax, sum-smin): smax;
	}
	// O(n^3) brute-force, TLE
	int maxSubarraySumCircular(vector<int>& A) {
		int n=A.size();
		int res = INT_MIN;
		for (int i=0; i<n; ++i) {
			for (int j=i; j<n+i; ++j) {
				int sum = 0;
				for (int k=i; k<=j; ++k) {
					sum += A[k%n];
				}
				res = max(res, sum);
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,-2,3,-2};
	cout << s.maxSubarraySumCircular(A1) << ": ";
	cout << s.maxSubarraySumCircular1(A1) << endl;
	vector<int> A2{5,-3,5};
	cout << s.maxSubarraySumCircular(A2) << ": ";
	cout << s.maxSubarraySumCircular1(A2) << endl;
	vector<int> A3{3,-1,2,-1};
	cout << s.maxSubarraySumCircular(A3) << ": ";
	cout << s.maxSubarraySumCircular1(A3) << endl;
	vector<int> A4{3,-2,2,-3};
	cout << s.maxSubarraySumCircular(A4) << ": ";
	cout << s.maxSubarraySumCircular1(A4) << endl;
	vector<int> A5{-3,-2,-1};
	cout << s.maxSubarraySumCircular(A5) << ": ";
	cout << s.maxSubarraySumCircular1(A5) << endl;
}
