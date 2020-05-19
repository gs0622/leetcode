/* https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution3 {
public:
	// O(nk) naive greedy
	int minKBitFlips(vector<int>& A, int K) {
		int res=0, n=A.size();
		for (int i=0; i<n; ++i) {			// O(n)
			if (A[i]==0) {				// retro: minimum number of K-bit flips
				if (i+K >= n-1) return -1;
				for (int j=i; j<i+K; ++j)	// O(k)
					A[j]=!A[j];		// flip
				++res;
			}
		}
		return res;
	}
};
class Solution2 {
public:
	// O(n) greedy
	int minKBitFlips(vector<int>& A, int K) {
		queue<int> q;	// flips
		int n=A.size(), res=0;
		for (int i=0; i<n; ++i) {
			if (A[i]==(q.size()%2? 1: 0))	// odd w/ 1: flip, even w/ 0: flip
				++res, q.push(i+K-1);
			if (q.size() && q.front()<=i)
				q.pop();
		}
		return q.empty()? res: -1;
	}
};
class Solution {
public:
	// naive BFS, TLE
	int minKBitFlips(vector<int>& A, int K) {
		int res=0, n=A.size();
		string a(n,'0'), b(n,'1');
		for (int i=0; i<n; ++i) a[i]+=A[i];
		queue<string> q;			// queue
		unordered_set<string> visit;		// marker of visit
		q.push(a);				// push root
		while (!q.empty()) {
			int m=q.size();
			for (int i=0; i<m; ++i) {	// level order
				string cur = q.front(); q.pop();
				if (cur==b) return res; 
				visit.insert(cur);	// visited
				for (int j=0; j<=n-K; ++j) {
					string tmp = cur;
					for (int k=j; k<j+K; ++k)
						tmp[k]=('1'-tmp[k])+'0';
					if (visit.count(tmp)==0)	// skip visited
						q.push(tmp);
				}
			}
			++res;
		}
		return -1;
	}
};
int main(){
	Solution3 s;
	vector<int> A1{0,1,0};
	cout << s.minKBitFlips(A1,1) << endl;
	vector<int> A2{1,1,0};
	cout << s.minKBitFlips(A2,2) << endl;
	vector<int> A3{0,0,0,1,0,1,1,0};
	cout << s.minKBitFlips(A3,3) << endl;
	vector<int> A4{1,0,1,1,0,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1};
	cout << s.minKBitFlips(A4,5) << endl;
}
