/*
Given a sorted array of integers nums and integer values a, b and c.
Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.
The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
Result: [-23, -5, 1, 7]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
	// f(x)=ax^2+bx+c
	int helper(int n, int a, int b, int c) {
		return a*(n*n) + b*n + c;
	}
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		int n=nums.size();
		vector<int> res(n), tmp(n);
		for (int i=0; i<n; ++i) tmp[i] = helper(nums[i],a,b,c); // O(n)
		int i=0, j=n-1, idx=a>0? n-1: 0;
		while (i<=j) {
			if (a>0) res[idx--] = tmp[i]>tmp[j]? tmp[i++]: tmp[j--];	// concave starts from two-end to fill end
			else	 res[idx++] = tmp[i]<tmp[j]? tmp[i++]: tmp[j--];	// covex starts from two-end to fill begin
		}
		return res;
	}
};
class Solution {
	int helper(int n, int a, int b, int c) {
		return a*(n*n) + b*n + c;
	}
public:
	// O(nlogn) naive
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (auto n: nums) pq.push(helper(n,a,b,c));
		vector<int> res;
		while (pq.size()) res.push_back(pq.top()), pq.pop();
		return res;
	}
};
int main(){
	Solution2 s;
	vector<int> A1{-4,-2,2,4};
	for (auto n: s.sortTransformedArray(A1,1,3,5)) cout << n << " ";
	cout << endl;
	for (auto n: s.sortTransformedArray(A1,-1,3,5)) cout << n << " ";
	cout << endl;
}
