/* https://leetcode.com/problems/set-matrix-zeroes/description/
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
                        ^^^^^^^^^^^^^^^^ hint for in-place  
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// in-place
	void setZeroes(vector<vector<int>>& mat) {
		int i, j, r=-1, c=-1, m=mat.size(), n=mat[0].size();
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (mat[i][j]==0) r=i, c=j;
			}
		}
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j)
				if (i==r || j==c) mat[i][j]=0;
		}
	}
	// O(m+n) space
	void setZeroes2(vector<vector<int>>& mat) {
		int i, j, m=mat.size(), n=mat[0].size();
		vector<int> r_mask(m,0);
		vector<int> c_mask(n,0);
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (mat[i][j]==0) r_mask[i]=1, c_mask[j]=1;
			}
		}
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j)
				if (r_mask[i]==1 || c_mask[j]==1)	
					mat[i][j]=0;
		}
	}
};
int main(){
	Solution s;
	//vector<vector<int>> mat(5,vector<int>(5,1));
	//mat[2][2]=0;
	vector<vector<int>> mat{{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
	for (auto r: mat) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
	cout << endl;
	s.setZeroes(mat);
	for (auto r: mat) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
}
