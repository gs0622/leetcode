/* https://leetcode.com/problems/squares-of-a-sorted-array/description/
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) two-pointer, use the sorted attribute, compare the last one
	vector<int> sortedSquares1(vector<int>& A) {
		int n=A.size(), i=0, j=n-1;
		vector<int> res(n);
		for (int k=n-1; k>=0; --k) {
			int a = abs(A[i])>abs(A[j])? A[i++]: A[j--];
			res[k]=a*a;
		}
		return res;
	}
	// O(nlog(n))
	vector<int> sortedSquares(vector<int>& A) {
		multiset<int> st;
		for (auto a: A) st.insert(a*a);
		vector<int> res;
		for (auto it=st.begin(); it!=st.end(); ++it)
			res.push_back(*it);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	vector<int> A1{-4,-1,0,3,10};
	res = s.sortedSquares1(A1);
	for (auto n: res) cout << n << " ";
	cout << endl;
	vector<int> A2{-7,-3,2,3,11};
	res = s.sortedSquares1(A2);
	for (auto n: res) cout << n << " ";
	cout << endl;
}
