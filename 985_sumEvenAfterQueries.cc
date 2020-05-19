#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
	vi sumEvenAfterQueries(vi& A, vvi& queries) {
		vi res;
		int sum=0;
		for (auto n: A) if (n%2==0) sum+=n;
		for (auto q: queries) {
			int val=q[0], idx=q[1];
			if (A[idx]%2==0) sum-=A[idx];
			A[idx]+=val;
			if (A[idx]%2==0) sum+=A[idx];
			res.push_back(sum);
		}
		return res;
	}
};
int main(){
	Solution s;
	vi A1{1,2,3,4};
	vvi Q1{{1,0},{-3,1},{-4,0},{2,3}};
	for (auto n: s.sumEvenAfterQueries(A1,Q1)) cout << n << " ";
	cout << endl;
}
