#include <bits/stdc++.h>
using namespace std;
class Solution {
	struct ugly {
		int val, mul, prime;
		ugly(int v, int m, int p): val(v), mul(m), prime(p) {}
	};
public:
	int nthUglyNumber(int n) {
		function <bool(struct ugly, struct ugly)> mygreater=[](struct ugly a, struct ugly b){ return a.val>b.val; };
		priority_queue<ugly, vector<ugly>, decltype(mygreater)> pq(mygreater);
		pq.push(ugly(2,1,2)), pq.push(ugly(3,1,3)), pq.push(ugly(5,1,5));
		vector<int> res(1,1);
		for (int i=1; i<n; ++i) {
			res.push_back(pq.top().val);
			while (res.back() == pq.top().val) {
				ugly top = pq.top(); pq.pop();
				pq.push(ugly(top.prime*res[top.mul], top.mul+1, top.prime));
			}
		}
		return res[n-1];
	}
};
int main(){
	Solution s;
	cout << s.nthUglyNumber(10) << endl;
}
