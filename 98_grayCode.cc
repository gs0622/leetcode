/* https://leetcode.com/problems/gray-code/description/
The gray code is a binary numeral system where "two successive values differ in only one bit".
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// gray(i)=i^(i/2)
	vector<int> grayCode1(int n) {
		vector<int> res;
		for (int i=0; i<(1<<n); ++i) {
			res.push_back(i^(i>>1));
		}
		return res;
	}
	// backtracking
	vector<int> grayCode(int n) {
		bitset<32> bits;
		vector<int> res;
		function<void(int)> helper=[&](int i) {
			if (i==0) {
				res.push_back(bits.to_ulong());
				//cout << bits << endl;
				return;
			}
			helper(i-1);		// not flip
			bits.flip(i-1);
			helper(i-1);		// flip
		};
		helper(n);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	res=s.grayCode1(3);
	for (auto n: res) cout << n << " ";
	cout << endl;
}
