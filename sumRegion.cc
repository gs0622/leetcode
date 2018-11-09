#include <bits/stdc++.h>
using namespace std;
class NumMatrix3 {
	vector<vector<int>> mats;	// copy of input matrix
	vector<vector<int>> cols;	// column sum
public:
	// O(mn) time and space
	NumMatrix3(vector<vector<int>> matrix) {
		if (matrix.empty()) return;
		int m=matrix.size(), n=matrix[0].size();
		mats=matrix;
		cols.resize(m+1, vector<int>(n,0));	// w/ one extra row of boarder
		for (int i=1; i<=m; ++i) {
			for (int j=0; j<n; ++j) {
				// col-sum     =>	↓↓↓↓↓↓
				cols[i][j] += cols[i-1][j]+mats[i-1][j];	// i-1 because of extra row indexing
			}
		}
	}
	// O(n) time update one col
	void update(int row, int col, int val) {
		// col-sum has one extra row at top
		for (int i=row+1; i<cols.size(); ++i)
			cols[i][col] += val-mats[row][col]; // += diff
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		int res=0;

		// col-sum has one extra row at top
		for (int i=col1; i<=col2; ++i)
			res += cols[row2+1][i]-cols[row1][i];

		return res;
	}
};
class NumMatrix2 {
	vector<vector<int>> sums;
public:
	// O(mn), immutable, one extra boarder per row/col, be careful off-by-one error
	NumMatrix2(vector<vector<int>> matrix) {
		if (matrix.empty()) return;
		int m=matrix.size(), n=matrix[0].size();
		sums.resize(m+1, vector<int>(n+1, 0));
		for (int i=1; i<=m; ++i) {		// be careful <=
			for (int j=1; j<=n; ++j)
				sums[i][j]=matrix[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];	// careful in index[i-1][j-1]
		}
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		return sums[row2+1][col2+1]-sums[row1][col2+1]-sums[row2+1][col1]+sums[row1][col1];
	}
};
class NumMatrix {
	vector<vector<int>> sums;
public:
	// O(mn)
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty()) return;
		int m=matrix.size(), n=matrix[0].size();
		sums.resize(m, vector<int>(n));
		sums[0][0]=matrix[0][0];
		for (int i=1; i<m; ++i) sums[i][0]=sums[i-1][0]+matrix[i][0];
		for (int i=1; i<n; ++i) sums[0][i]=sums[0][i-1]+matrix[0][i];
		for (int i=1; i<m; ++i) {
			for (int j=1; j<n; ++j)
				sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i][j];
		}
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		if (sums.empty()) return 0;
		if (row1==0 && col1==0) return sums[row2][col2];
		else if (row1>0 && col1>0) return sums[row2][col2]-sums[row1-1][col2]-sums[row2][col1-1]+sums[row1-1][col1-1];
		else if (row1==0) return sums[row2][col2]-sums[row2][col1-1];
		else return sums[row2][col2]-sums[row1-1][col2];
	}
};
int main(){
	vector<vector<int>> nums{{3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7},{1, 0, 3, 0, 5}};
	NumMatrix s(nums);
	NumMatrix2 s2(nums);
	NumMatrix3 s3(nums);
	cout << s.sumRegion(2,0,4,3) << endl;
	cout << s2.sumRegion(2,0,4,3) << endl;
	s3.update(4,3,1);
	cout << s3.sumRegion(2,0,4,3) << endl;
}
