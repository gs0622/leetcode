/* In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(4), (O(1))
	int repeatedNTimes2(vector<int>& A) {
		int i=0,j=0,n=A.size();
		while (i==j || A[i]!=A[j]) i=rand()%n, j=rand()%n;
		return A[i];
	}
	// wrong?
	int repeatedNTimes1(vector<int>& A) {
		int cnt=1, maj=A[0], n=A.size();
		for (int i=1; i<n; ++i) {
			if (cnt==0) cnt=1, maj=A[i];
			else if (maj==A[i]) ++cnt;
			else --cnt;
		}
		// skip verification phase
		return maj;
	}
	int repeatedNTimes(vector<int>& A) {
		int n=A.size();
		unordered_map<int,int> cnt;
		for (auto a: A) ++cnt[a];
		for (auto it: cnt) if (it.second==n/2) return it.first;
		assert(0);
		return -1;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,2,3,3};
	cout << s.repeatedNTimes2(A1) << endl;
	vector<int> A2{2,1,2,5,3,2};
	cout << s.repeatedNTimes2(A2) << endl;
	vector<int> A3{5,1,5,2,5,3,5,4};
	cout << s.repeatedNTimes2(A3) << endl;
}
