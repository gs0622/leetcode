#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int nthSuperUglyNumber1(int n, vector<int>& P) {
		
	}
	// buggy
	int nthSuperUglyNumber(int n, vector<int>& P) {
		int m=P.size();
		struct mygreater {
			bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b) { return get<0>(a) > get<0>(b); }
		};
		priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, mygreater> pq;	// minheap

		for (int i=0; i<m; ++i)
			pq.push(make_tuple(P[i], 1, P[i]));	// candidate / mul / prime-factor

		vector<int> res(1,1);
		for (int i=1; i<n; ++i) {
			int ugly=get<0>(pq.top());
			res.push_back(ugly);
			while(ugly==get<0>(pq.top())) {
				tuple<int,int,int> top=pq.top(); pq.pop();
				int mul=get<1>(top), prime=get<2>(top);
				pq.push(make_tuple(prime*res[mul], mul+1, prime));
			}
		}
		return res[n-1];
	}
};
int main(){
	vector<int> P1{2,7,13,19};
	vector<int> P2{2,3,11,13,17,23,29,31,37,47};
	Solution s;
	//cout << s.nthSuperUglyNumber(12, P1) << endl;
	cout << s.nthSuperUglyNumber(40, P2) << endl;
}
