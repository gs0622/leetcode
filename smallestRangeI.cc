/* https://leetcode.com/problems/smallest-range-i/description/
Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.
*/
#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
	int smallestRangeI(vector<int> A, int K) {
                int ma=INT_MIN, mi=INT_MAX;
                for (auto n: A) {
                        ma = (n > ma)? n: ma;
                        mi = (n < mi)? n: mi;
                }
                int diff = ma-mi;
                return (diff<=2*K)? 0: diff-2*K;
	}
};
int main(){
	Solution s;
	cout << s.smallestRangeI({1},0) << endl;
	cout << s.smallestRangeI({0,10},2) << endl;
	cout << s.smallestRangeI({1,3,6},3) << endl;
}
