#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		int n=A.size(), carry=0;
		for (int i=n-1; i>=0; --i) {
			A[i]+=K%10+carry;
			carry=A[i]/10, A[i]%=10;
			K/=10;
		}
		while (K || carry) {
			int d=K%10+carry;
			carry=d/10, d%=10, K/=10;
			A.insert(A.begin(), d);
		}
		return A;
	}
};
class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		int carry=0;
		for (auto it=A.rbegin(); it!=A.rend(); ++it) {
			*it+=K%10+carry;
			carry=*it/10, *it%=10;
			K/=10;
		}
		while (K || carry) {
			int digit=K%10+carry;
			carry=digit/10, K/=10;
			A.insert(A.begin(),digit%10);
		}
		return A;
	}
};
int main(){
	Solution2 s;
	vector<int> A1{1,2,0,0};
	for (auto n: s.addToArrayForm(A1,34)) cout << n;
	cout << endl;
	vector<int> A2{9,9,9,9,9,9,9,9,9,9};
	for (auto n: s.addToArrayForm(A2,1)) cout << n;
	cout << endl;
	vector<int> A3{7};
	for (auto n: s.addToArrayForm(A3,993)) cout << n;
	cout << endl;
}
