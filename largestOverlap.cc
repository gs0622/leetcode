/* https://leetcode.com/problems/image-overlap/description/
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?
Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
class Solution {
	int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int m=A.size(), n=A[0].size(), res=0;
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (A[i][j]==1 && B[i][j]==1)
					++res;
			}
		}
		return res;
	}
public:
	int largestOverlap2(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<int> LA, LB;
		int N = A.size();
		unordered_map<int, int> count;
		for (int i = 0; i < N * N; ++i) if (A[i / N][i % N] == 1) LA.push_back(i / N * 100 + i % N);
		for (int i = 0; i < N * N; ++i) if (B[i / N][i % N] == 1) LB.push_back(i / N * 100 + i % N);
		for (int i: LA) for (int j: LB) count[i - j]++;
		int res = 0;
		for (auto it: count) res = max(res, it.second);
		return res;
	}
	
	int largestOverlap1(vector<vector<int>>& A, vector<vector<int>>& B) {
		int n=A.size(), res=0;
		vector<vector<int>> cnt(2*n+1, vector<int>(2*n+1,0));	// +-2n
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {	// n^4 inside
			if (A[i][j]==1) {
				for (int ii=0; ii<n; ++ii) for (int jj=0; jj<n; ++jj) {
					if (B[ii][jj]==1)
						++cnt[i-ii+n][j-jj+n];	// +-2n
				}
			}
		}
		for (auto row: cnt) for (auto n: row)
			res=max(res,n);
		return res;
	}
	// O(n^6) time, O(n^2) space
	// https://leetcode.com/problems/image-overlap/solution/
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int n=A.size(), res=0;
		vector<pair<int,int>> A2,B2;
		for (int i=0; i<n*n; ++i) {		// n^2 loop
			if (A[i/n][i%n]==1) A2.push_back(make_pair(i/n, i%n));
			if (B[i/n][i%n]==1) B2.push_back(make_pair(i/n, i%n));
		}
		set<pair<int,int>> Bset(begin(B2),end(B2));
		set<pair<int,int>> seen;
		for (auto a: A2) for (auto b: B2) {	// n^4 loop?
			auto delta = make_pair(b.first-a.first, b.second-a.second);
			if (!seen.count(delta)) {
				seen.insert(delta);
				int cnt=0;
				for (auto p: A2) {
					if (Bset.count(make_pair(p.first+delta.first, p.second+delta.second)))
						++cnt;
				}
				res=max(res,cnt);
			}
		}
		return res;	
	}
};
int main(){
	vvi A{{1,1,0},
	      {0,1,0},
              {0,1,0}};
	vvi B{{0,0,0},
              {0,1,1},
              {0,0,1}};
	Solution s;
	cout << s.largestOverlap(A,B) << ' ' << s.largestOverlap1(A,B) << endl;
}
