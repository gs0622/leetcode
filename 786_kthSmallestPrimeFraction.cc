/* https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

            5   3   2   1
	+--------
      1 | 1/5  1/3 1/2  1
      2 | 2/5  2/3  1   2
      3 | 3/5    1 3/2  3
      5 |   1  5/3 5/2  5
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> kthSmallestPrimeFraction1(vector<int>& A, int K) {
		int n=A.size();
		vector<int> B(A.rbegin(), A.rend());

		// tuple: val,row,col
		struct mygreater {
			bool operator()(tuple<double,int,int>& a, tuple<double,int,int>& b) {
				return get<0>(a) > get<0>(b);
			}
		};
		priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>>, mygreater> pq; // minheap

		for (int i=0; i<n; ++i)
			pq.push(make_tuple((double)A[i]/B[0], i, 0));

		int cnt = K, row, col;
		while (cnt--) {
			tuple<double,int,int> top = pq.top(); pq.pop();
			row = get<1>(top), col = get<2>(top);
			if (col < n-1)
				pq.push(make_tuple((double)A[row]/B[col+1], row, col+1));
		}
		return {A[row], B[col]};
	}
	// brute-force, TLE
	vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		int n=A.size();
		vector<int> B(A.rbegin(), A.rend());
		map<double, pair<int,int>> C;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				C[(double)A[i]/B[j]] = make_pair(i, j);
			}
		}
		auto it = C.begin();
		assert(C.size()>=K);
		for (int i=1; i<K; ++i, ++it);	// 'it' is in the 1st thus i starts from 1
		return {A[it->second.first], B[it->second.second]};
	}
};
int main(){
	Solution s;
	vector<int> A1{1,2,3,5};
	vector<int> res = s.kthSmallestPrimeFraction1(A1, 3);
	cout << res[0] << ' ' << res[1] << endl;
	vector<int> A2{1,7};
	res = s.kthSmallestPrimeFraction(A2, 1);
	cout << res[0] << ' ' << res[1] << endl;
}
