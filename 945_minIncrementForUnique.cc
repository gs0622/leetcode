#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(nlog(n)), sort, keep tracking the previous against the current one
	int minIncrementForUnique2(vector<int>& A) {
		sort(A.begin(), A.end());
		int n=A.size(), res=0;
		for (int i=1; i<n; ++i) {
			if (A[i-1]>=A[i]) {
				res+=A[i-1]+1-A[i];	// the moves
				A[i]=A[i-1]+1;		// the request one
			}
		}
		return res;
	}
	// O(nlog(n)) time, O(1) space: sort, compare req, req+1
	int minIncrementForUnique1(vector<int>& A) {
		sort(A.begin(), A.end());
		int res=0, req=0;
		for (auto i: A) {
			res+=max(req-i,0);
			req=max(i,req)+1;
		}
		return res;
	}
	// O(n^2), naive, TLE, 56 / 59 test cases passed.
	int minIncrementForUnique(vector<int>& A) {
		map<int,int> mp;
		for (auto i: A) ++mp[i];
		int res=0;
		for (auto i: mp) {
			while (i.second>1) {
				int j = i.first;
				while (mp.find(j)!=mp.end())
					++j, ++res;
				mp[j]=1, --(i.second);
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,1,1,1,1,1,1};
	cout << s.minIncrementForUnique2(A1) << endl;
	vector<int> A2{3,2,1,2,1,7};
	cout << s.minIncrementForUnique2(A2) << endl;
}
