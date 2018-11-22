#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution {
public:
	bool validMountainArray2(vi& A) {
		if (A.size() < 3 || A[0] > A[1]) return false;
		auto peak = false;
		for (auto i = 1; i < A.size(); ++i) {
			if (peak & A[i - 1] < A[i] || A[i - 1] == A[i]) return false;
			peak = A[i - 1] > A[i];
		}
		return peak;
	}
	// O(n) two pointer
	bool validMountainArray1(vi& A) {
		auto i=A.begin(), j=prev(A.end());
		while (A.size() && next(i)!=A.end() && *i < *next(i)) ++i;
		while (A.size() && prev(j)!=A.begin() && *prev(j)>*j) --j;
		return next(i)!=A.end() && j!=A.begin() && i==j;
	}
	// O(n) two pointer iterate from two sides
	bool validMountainArray(vi& A) {
		int n = A.size(), i=0, j=n-1;
		while (i+1<n && A[i]<A[i+1])	// look forward for ascending
			++i;
		while (j>0 && A[j-1]>A[j])	// look backward for descending
			--j;
		return i!=n-1 && j!=0 && i==j;
	}
};
int main(){
	Solution s;
	vi A0{0,1,2,4,2,1};
	cout << s.validMountainArray1(A0) << endl;
	vi A1{2,1};
	cout << s.validMountainArray1(A1) << endl;
	vi A2{3,5,5};
	cout << s.validMountainArray1(A2) << endl;
	vi A3{0,3,2,1};
	cout << s.validMountainArray1(A3) << endl;
};
