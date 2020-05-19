#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& m) {
		int n=m.size();
		for (int i=0; i<n/2; ++i) {       // shells in n/2 layers
			for (int j=i; j<n-i-1; ++j) {
				int tmp=m[i][j];
				m[i][j]=m[n-j-1][i];
				m[n-j-1][i]=m[n-i-1][n-j-1];
				m[n-i-1][n-j-1]=m[j][n-i-1];
				m[j][n-i-1]=tmp;
			}
		}
	}
};
int main(){
	Solution s;
	vector<vector<int>> m{{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
	s.rotate(m);
	for (auto r: m) {
		for (auto c: r) cout << c << ' ';
		cout << endl;
	}
}
