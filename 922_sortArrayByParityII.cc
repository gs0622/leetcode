#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int n=A.size();
		for (int i=0, j=1; i<n && j<n;) { 
			while (i<n && A[i]%2==0) i+=2;
			while (j<n && A[j]%2==1) j+=2;
			if (i<n && j<n) swap(A[i],A[j]);
		}
		return A;
	}
};
int main(){
	Solution s;
	vector<int> res;
	vector<int> A1{4,2,5,7};
	res = s.sortArrayByParityII(A1);
	for (auto n: res) cout << n << ' ';
	cout << endl;

	vector<int> A2{2,3,1,1,4,0,0,4,3,3};
	res = s.sortArrayByParityII(A2);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
