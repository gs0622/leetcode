/*
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array A is monotone increasing if for all i <= j, A[i] <= A[j].
An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
Return true if and only if the given array A is monotonic.

Note:
1 <= A.length <= 50000
-100000 <= A[i] <= 100000

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isMonotonic1(vector<int>& A) {
		bool inc=true, dec=true;
		for (int i=1; i<(int)A.size(); ++i)
			inc&=A[i-1]<=A[i], dec&=A[i-1]>=A[i];	// &= w/ previos justification
		return inc || dec;
	}
	bool isMonotonic(vector<int>& A) {
		int n = A.size();
		if (n==1) return true;
		if (A[0]<=A[n-1]) {
			for (int i=1; i<n; ++i)
				if (A[i-1]>A[i]) return false;
		} else {
			for (int i=1; i<n; ++i)
				if (A[i-1]<A[i]) return false;
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,2,2,3};
	cout << s.isMonotonic1(A1) << endl;
	vector<int> A2{6,5,4,4};
	cout << s.isMonotonic1(A2) << endl;
	vector<int> A3{1,3,2};
	cout << s.isMonotonic1(A3) << endl;
	vector<int> A4{1,2,4,5};
	cout << s.isMonotonic1(A4) << endl;
	vector<int> A5{1,1,1};
	cout << s.isMonotonic1(A5) << endl;
}
