/* https://leetcode.com/problems/single-number-iii/description/
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time, O(1) space
	vector<int> singleNumber1(vector<int>& nums) {
		int x = 0;
		for (auto n: nums)
			x ^= n;				// paired n will be cancled
		int a = 0, b = 0;			// assume we have a and b are single ones
		int lsb = x & -x;			// x is a^b now, get the last bit, differ in a and b
		for (int n: nums) {			// group by lsb
			if (n & lsb)	a ^= n;		
			else		b ^= n;
		}
		return {a,b};
	}
	// O(n) time and space, naive solution
	vector<int> singleNumber(vector<int>& nums) {
		unordered_set<int> st;
		for (auto n: nums) {
			if (st.count(n)==0)
				st.insert(n);		// new
			else
				st.erase(n);		// existing in previous set
		}
		return {*st.begin(), *(++st.begin())};	// only two left
	}
};
int main(){
	Solution s;
	vector<int> A1{1,2,1,3,2,5};
	vector<int> res;
	res = s.singleNumber1(A1);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
