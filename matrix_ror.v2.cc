#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void ror(vector<vector<int>>& m) {
		int i, j, n=m.size();
		for (i=0; i<n/2; ++i) { // layer
			for (j=i; j<n-i-1; ++j) { // offset
				int tmp=m[i][j];
				m[i][j]		= m[n-j-1][i];
				m[n-j-1][i]	= m[n-i-1][n-j-1];
				m[n-i-1][n-j-1]	= m[j][n-i-1];
				m[j][n-i-1]	= tmp;

			}
		}
	}
	void rol(vector<vector<int>>& m) {
		int i, j, n=m.size();
		for (i=0; i<n/2; ++i) { // layer
			for (j=i; j<n-i-1; ++j) { // offset
				int tmp=m[i][j];
				m[i][j]		= m[j][n-i-1];
				m[j][n-i-1]	= m[n-i-1][n-j-1];
				m[n-i-1][n-j-1] = m[n-j-1][i];
				m[n-j-1][i] = tmp;
			}
		}
	}
	void dump(vector<vector<int>>& m) {
		for (auto r: m) {
			for (auto c: r) cout << c << " ";
			cout << endl;
		}
		cout << endl;
	}
};
int main(){
	Solution s;
	vector<vector<int>> m1{{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
	s.dump(m1);
	//s.rol(m1);
	s.ror(m1);
	s.dump(m1);
}
