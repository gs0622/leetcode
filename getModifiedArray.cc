/*
Assume you have an array of length n initialized with all 0's and are given k update operations.
Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
Return the modified array after all k operations were executed.

Example:
Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:
    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]
After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]
After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]
After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
	vi getModifiedArray1(int n, vvi& updates) {
		vi res(n+1);
		for (auto u: updates)
			res[u[0]]+=u[2], res[u[1]+1]-=u[2];
		for (int i=1; i<n+1; ++i)
			res[i]+=res[i-1];
		res.pop_back();
		return res;
	}
	// naive approach
	vi getModifiedArray(int n, vvi& updates) {
		vi res(n);
		for (auto u: updates) {
			for (int i=u[0]; i<=u[1]; ++i)
				res[i]+=u[2];
		}
		return res;
	}
};
int main(){
	Solution s;
	vvi updates{{1,  3,  2},{2,  4,  3},{0,  2, -2}};
	vector<int> res = s.getModifiedArray1(5, updates);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
