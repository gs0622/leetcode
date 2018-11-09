#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
	// O(nlog(n)) dominated by sorting
	int smallestRangeII(vector<int> A, int K) {
		sort(A.begin(), A.end());
		int mi=A.front(), mx=A.back(), res=mx-mi;	// by shift +-K to 0 and 2K, init res by adding 0 to all A[i]
		for (auto i=0; i<A.size()-1; ++i) {		// examine adding 2K for each
			mx=max(mx, A[i]+2*K);
			mi=min(A[i+1], A[0]+2*K);
			res = min(res, mx-mi);
		}
		return res;
	}
};
int main(){
	Solution s;
	cout << s.smallestRangeII({1},0) << endl;
	cout << s.smallestRangeII({0,10},2) << endl;
	cout << s.smallestRangeII({1,3,6},3) << endl;
}
