/*
Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
	// after sorted
	// For A[i]:
	// There are i smaller numbers,
	// so there are 2 ^ i sequences in which A[i] is maximum.
	// we should do res += A[i] * (2 ^ i)
	// There are n - i - 1 bigger numbers,
	// so there are 2 ^ (n - i - 1) sequences in which A[i] is minimum.
	// we should do res -= A[i] * 2 ^ (n - i - 1)
	//
	// When A[i] is picked:  left: C(i, 0) + C(i, 1) + C(i, 2) .. C(i, i) == 2 ** i
	int sumSubseqWidths1(vi& A) {
		sort(A.begin(), A.end());
		long long res=0, n=A.size(), pow=1, mod=1e9+7;
		for (int i=0; i<n; ++i, pow=(pow<<1)%mod) {	// pow = 2**i
			// From the algorithm we expect, res = res + A[i] * (2^(i) - A[i] * 2 ^ (N-1-i)
			// BUT consider N>31, your term2^( N-1-i) might go beyond 2^31 which means overflow.
			// This is the reason to use A(N-i-1) instead of A(i) in the solution.
			// The answer brilliantly uses the reverse order during subtraction so that we don't have to calculate 'c' twice. 
			res = (res + A[i]*pow - A[n-i-1]*pow)%mod;
		}
		return (int)(res+mod)%mod;
	}
	// MLE (Memory Limit Exceeded)
	int sumSubseqWidths(vi& A) {
		int m = A.size(), sum=0;
		vvi res(1,vi());
		for (int i=0; i<m; ++i) {
			int n=res.size();
			for (int j=0; j<n; ++j) {
				res.push_back(res[j]);
				res.back().push_back(A[i]);
			}
		}
		m = res.size();
		for (int i=0; i<m; ++i) {
			if (res[i].empty()) continue;
			int min = *min_element(res[i].begin(), res[i].end());
			int max = *max_element(res[i].begin(), res[i].end());
			sum += max-min;
		}
		return sum;
	}
};
using namespace std;
int main(){
	Solution s;
	vector<int> A1{2,1,3};
	cout << s.sumSubseqWidths(A1) << ": " << s.sumSubseqWidths1(A1) << endl;
	vector<int> A2{5,69,89,92,31,16,25,45,63,40,16,56,24,40,75,82,40,12,50,62,92,44,67,38,92,22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89,4,16,94,16,77,92,9,30,13};
	cout << s.sumSubseqWidths1(A2) << endl;
}
