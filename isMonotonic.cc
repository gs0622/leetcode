#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
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
	cout << s.isMonotonic(A1) << endl;
	vector<int> A2{6,5,4,4};
	cout << s.isMonotonic(A2) << endl;
	vector<int> A3{1,3,2};
	cout << s.isMonotonic(A3) << endl;
	vector<int> A4{1,2,4,5};
	cout << s.isMonotonic(A4) << endl;
	vector<int> A5{1,1,1};
	cout << s.isMonotonic(A5) << endl;
}
