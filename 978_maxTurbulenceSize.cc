/* https://leetcode.com/problems/longest-turbulent-subarray/description/

A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.

Note:

1 <= A.length <= 40000
0 <= A[i] <= 10^9

Q: what if A.length == 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		int inc=1,dec=1,res=1,n=A.size();	// trick: why reset in 1? read the question
		for (int i=1;i<n;++i) {
			if      (A[i]>A[i-1]) inc=dec+1, dec=1;
			else if (A[i]<A[i-1]) dec=inc+1, inc=1;
			else inc=1,dec=1;
			res=max(res,max(inc,dec));
		}
		return res;	
	}
};
int main(){
}
