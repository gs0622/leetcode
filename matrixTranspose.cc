/* https://leetcode.com/problems/transpose-matrix/description/
Given a matrix A, return the transpose of A.
The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
Note:
1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int m=A.size(), n=A[0].size();
		vector<vector<int>> res(n,vector<int>(m));
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
			res[j][i] = A[i][j];
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> A1{{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> A2{{1,2,3},{4,5,6}};
	vector<vector<int>> res;
	res = s.transpose(A1);
	for (auto r: res) {
		for (auto c: r) cout << c << ' ';
		cout << endl;
	}
	cout << endl;
	res = s.transpose(A2);
	for (auto r: res) {
		for (auto c: r) cout << c << ' ';
		cout << endl;
	}
}
