/* 
Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	/* monotonic decrease stack 0, i, ...
	*/
	int maxWidthRamp1(vector<int>& A) {
		int res=0, n=A.size();
		stack<int> s;
		for (int i=0; i<n; ++i)
			if (s.empty() || A[s.top()]>A[i])
				s.push(i);
		for (int i=n-1; i>res; --i)
			while (s.size() && A[i]>=A[s.top()])
				res=max(res, i-s.top()), s.pop();
		return res;
	}
	// O(n^2) brute-force, TLE
	int maxWidthRamp(vector<int>& A) {
		int res=0, n=A.size();
		for (int i=0; i<n; ++i) for (int j=n-1; j>=0; --j) {
			if (i>=j || A[i]>A[j]) continue;
			res = max(res, j-i);
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> A1{6,0,8,2,1,5};
	cout << s.maxWidthRamp(A1) << ": " ;
	cout << s.maxWidthRamp1(A1) << endl;
	vector<int> A2{9,8,1,0,1,9,4,0,4,1};
	cout << s.maxWidthRamp(A2) << ": " ;
	cout << s.maxWidthRamp1(A2) << endl;
}
