/* https://leetcode.com/problems/score-after-flipping-matrix/description/

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	void flipRow(vector<vector<int>>& A, int row) {
		int cols = A[0].size();
		for (int i=0; i<cols; ++i)
			A[row][i]=A[row][i]==1? 0: 1;
	}
	void flipCol(vector<vector<int>>& A, int col) {
		int rows = A.size();
		for (int i=0; i<rows; ++i)
			A[i][col]=A[i][col]==1? 0: 1;
	}
public:
	int matrixScore1(vector<vector<int>>& A) {
		int m=A.size(), n=A[0].size(), res=(1<<(n-1))*m;
		for (int j=1; j<n; ++j) {	// for each col
			int same=0;
			for (int i=0; i<m; ++i)	// for each row
				if (A[i][j]==A[i][0]) ++same;
			res+=(1<<(n-1-j))*(max(same, m-same));	// 0's or 1's
		}
		return res;
	}
	int matrixScore(vector<vector<int>>& A) {
		int n=A.size(), m=A[0].size();
		vector<int> col(m, 0);
		for (int i=0; i<n; ++i) {
			if (A[i][0]==0)
				flipRow(A, i);
			for (int j=0; j<m; ++j)
				if (A[i][j]==1)
					++col[j];
		}
		for (int i=0; i<m; ++i)
			if (col[i]<=(n/2))
				flipCol(A, i);
		int res=0, carry=0, shift=0;
		for (int i=m-1; i>=0; --i) {
			int sum=0;
			for (int j=0; j<n; ++j)
				sum+=A[j][i]<<shift;
			sum+=carry, carry=0, shift++;
			res+=sum;
		}
		return res; 
	}
};
int main(){
	Solution s;
	vector<vector<int>> A1{{0,0,1,1},{1,0,1,0},{1,1,0,0}};
	cout << s.matrixScore(A1) << endl;
	
}
