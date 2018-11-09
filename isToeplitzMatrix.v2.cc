#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& m) {
		for (int r=0; r<m.size(); ++r)
			for (int c=0; c<m[0].size(); ++c)
				if (r>0 && c>0 && m[r][c]!=m[r-1][c-1]) return false;
		return true;
	}
	bool isToeplitzMatrix2(vector<vector<int>>& m) {
		if (m.size()==0) return false;
		int i, nr=m.size(), nc=m[0].size();

		auto fail = [&m](int sr, int sc, int nr, int nc) {
			for (int rr=sr+1, cc=sc+1; rr<nr & cc<nc; ++rr, ++cc)
				if (m[sr][sc] != m[rr][cc]) return true;
			return false;
		};
		for (i=0; i<nr; ++i)	// bottom-left half
			if (fail(i, 0, nr, nc)) return false;
		for (i=1; i<nc; ++i)	// upper-right half
			if (fail(0, i, nr, nc)) return false;
		return true;
	}
	bool isToeplitzMatrix3(vector<vector<int>>& m) {
		if (m.size()==0) return false;
		int r, c, rr, cc, nr=m.size(), nc=m[0].size();
		for (r=0, c=0; r<nr; ++r) { // bottom-left half
			for (rr=r+1, cc=c+1; rr<nr && cc<nc; ++rr, ++cc)
				if (m[r][c] != m[rr][cc]) return false;
		}
		for (r=0, c=1; c<nc; ++c) { // upper-right half
			int v=m[r][c];
			for (rr=r+1, cc=c+1; rr<nr && cc<nc; ++rr, ++cc)
				if (m[r][c] != m[rr][cc]) return false;
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<vector<int>> m1{{1,2,3,4},{5,1,2,3},{9,5,1,2}};
	cout << s.isToeplitzMatrix(m1) << endl; 
	vector<vector<int>> m2{{1,2},{2,2}};
	cout << s.isToeplitzMatrix(m2) << endl; 
	vector<vector<int>> m3{{11,74,0,93},{40,11,74,7}};
	cout << s.isToeplitzMatrix(m3) << endl; 
}
