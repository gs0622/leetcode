/* https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
https://www.geeksforgeeks.org/sum-of-bitwise-or-of-all-subarrays-of-a-given-array-set-2/
For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].

Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)
Note:

1 <= A.length <= 50000
0 <= A[i] <= 10^9

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(30n)
	int subarrayBitwiseORs2(vector<int>& A) {
		unordered_set<int> pre, cur, res;
		for (auto n: A) {
			cur = {n};
			for (auto m: pre)
				cur.insert(n|m);
			//pre = cur;
			pre.swap(cur);
			for (auto m: pre)
				res.insert(m);
		}
		return res.size();
	}
	// naive brute-force O(n^2)
	int subarrayBitwiseORs(vector<int>& A) {
		unordered_set<int> st;
		int n=A.size();
		for (int i=0; i<n; ++i) {
			int sum=0;
			for (int j=i; j<n; ++j) {
				sum |= A[j];
				st.insert(sum);	// add the sum after performing the Bitwise OR operation, save one nested loop
			}
		}
		return st.size();
	}
};
int main(){
	Solution s;
	vector<int> A1{0};
	cout << s.subarrayBitwiseORs(A1) << ": " <<  s.subarrayBitwiseORs2(A1) << endl;
	vector<int> A2{1,1,2};
	cout << s.subarrayBitwiseORs(A2) << ": " <<  s.subarrayBitwiseORs2(A2) << endl;
	vector<int> A3{1,2,4};
	cout << s.subarrayBitwiseORs(A3) << ": " <<  s.subarrayBitwiseORs2(A3) << endl;
	vector<int> A4{6,12,7};
	cout << s.subarrayBitwiseORs(A4) << ": " <<  s.subarrayBitwiseORs2(A4) << endl;
	vector<int> A5{13,4,2};
	cout << s.subarrayBitwiseORs(A5) << ": " <<  s.subarrayBitwiseORs2(A5) << endl;
}
