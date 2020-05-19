/* https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.
Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

1 <= N <= 9
0 <= K <= 9
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> numsSameConsecDiff(int N, int K) {
		vector<int> res, dig{1,2,3,4,5,6,7,8,9,0};
		if (N==1) return dig; // corner case out of the description
		function<void(int,int)> helper=[&](int n, int num) {
			if (n==0) {
				res.push_back(num);
				return;
			}
			int d = num%10;
			if (d+K<=9) helper(n-1, num*10+d+K);
			if (K && d-K>=0) helper(n-1, num*10+d-K);	// think if K==0, why dup?
		};
		for (int i=1; i<=9; ++i)
			helper(N-1,i);	// dfs
		return res;
	}
};
int main(){
	Solution s;
	for (auto n: s.numsSameConsecDiff(3,7)) cout << n << " ";
	cout << endl;
	for (auto n: s.numsSameConsecDiff(2,1)) cout << n << " ";
	cout << endl;
	for (auto n: s.numsSameConsecDiff(1,0)) cout << n << " ";
	cout << endl;
}
