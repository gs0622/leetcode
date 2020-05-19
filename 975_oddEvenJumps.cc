/* https://leetcode.com/problems/odd-even-jump/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	// O(nlogn) time, O(n) space
	int oddEvenJumps(vector<int>& A) {
		int n=A.size(), res=1;
		vector<int> higher(n), lower(n);
		lower[n-1]=higher[n-1]=1;
		map<int,int> mp{{A[n-1],n-1}};	// val,index
		for (int i=n-2; i>=0; --i) {
			auto hi=mp.lower_bound(A[i]), lo=mp.upper_bound(A[i]);
			if (hi!=mp.end()) higher[i]=lower[hi->second];
			if (lo!=mp.begin()) lower[i]=higher[(--lo)->second];
			if (higher[i]) ++res;	// consider 1st step is odd
			mp[A[i]]=i;
		}
		return res;
	}
};
class Solution {
	// execute one jump
	int oddJump(vector<int>& A, int from) {
		int n=A.size(), cur=INT_MAX, to=INT_MAX;
		for (int i=from+1; i<n; ++i) {
			if (A[i]>=A[from] && A[i]<cur)
				cur=A[i], to=i;
		}
		return to;
	}
	int evenJump(vector<int>& A, int from) {
		int n=A.size(), cur=INT_MIN, to=INT_MIN;
		for (int i=from+1; i<n; ++i) {
			if (A[i]<=A[from] && A[i]>cur)
				cur=A[i], to=i;
		}
		return to;
	}
public:
	// O(n^2) naive, TLE
	int oddEvenJumps(vector<int>& A) {
		int n=A.size(), res=1;
		for (int i=0; i<n-1; ++i) {
			int jump=1, from=i, to=i;
			while (true) {
				if (jump%2) {	// odd jump
					to = oddJump(A, from);
					if (to == n-1 || to == INT_MAX) break;
					from = to;	// next jump
				} else {
					to = evenJump(A, from);
					if (to == n-1 || to == INT_MIN) break;
					from = to;
				}
				++jump;
			}
			if (to == n-1) ++res;
		}
		return res;	
	}
};
int main(){
	Solution2 s;
	vector<int> A1{10,13,12,14,15};
	cout << s.oddEvenJumps(A1) << endl;
	vector<int> A2{2,3,1,1,4};
	cout << s.oddEvenJumps(A2) << endl;
	vector<int> A3{5,1,3,4,2};
	cout << s.oddEvenJumps(A3) << endl;
}
