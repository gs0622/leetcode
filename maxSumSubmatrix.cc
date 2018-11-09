#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
	int maxSumSubmatrix1(vvi& mat, int k) {
		int m=mat.size(), n=mat[0].size(), res=INT_MIN;
		int L, R;
		for (L=0; L<n; ++L) {
			vi tmp(m,0);
			for (R=L; R<n; ++R) {
				for (int i=0; i<m; ++i)
					tmp[i]+=mat[i][R];	// col sum
				set<int> myset;
				myset.insert(0);
				int cur_sum=0, cur_max=INT_MIN;
				for (int i=0; i<m; ++i) {	// Kadane in terms of rows/cols [i][L..R]
					cur_sum+=tmp[i];	// col/row sum
					auto it=myset.lower_bound(cur_sum-k);	// these two awesome, -k first, then -*it would be less-or-equal to k
					if (it!=end(myset)) cur_max=max(cur_max, cur_sum-*it);
					myset.insert(cur_sum);	// record the sum for query
				}
				res=max(res, cur_max);
			}
		}
		return res;
	}
	// brute force O(n^4)
	int maxSumSubmatrix(vvi& mat, int k) {
		int m=mat.size(), n=mat[0].size(), res=INT_MIN;
		vvi sums(mat);
		for (int i=1; i<m; ++i)
			sums[i][0]+=sums[i-1][0];
		for (int i=1; i<n; ++i)
			sums[0][i]+=sums[0][i-1];
		// O(n^2)
		for (int i=1; i<m; ++i) {
			for (int j=1; j<n; ++j)
				sums[i][i]+=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
		}
		// O(n^4)
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				for (int ii=i; ii<m; ++ii)
					for (int jj=j; jj<n; ++jj) {
						int tmp = sums[ii][jj]-sums[i][j];
						if (tmp<=k)
							res=max(res,tmp);
					}
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vvi m1{{1,0,1},{0,-2,3}};
	//cout << s.maxSumSubmatrix1(m1, 2) << endl;
	vvi m2{	{ 1, 2,-1,-4,-20},
		{-8,-3, 4, 2,  1},
		{ 3, 8,10, 1,  3},
		{-4,-1, 1, 7, -6}};
	//cout << s.maxSumSubmatrix1(m2, 2) << endl;
	vvi m3{{2,2,-1}};
	cout << s.maxSumSubmatrix1(m3, 0) << endl;
	vvi m4{ { 5,-4,-3, 4},
		{-3,-4, 4, 5},
		{ 5, 1, 5,-4}};
	cout << s.maxSumSubmatrix(m4, 8) << endl;
	cout << s.maxSumSubmatrix1(m4, 8) << endl;
}
