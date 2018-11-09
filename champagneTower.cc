#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// O(row^2) time and space 
	double champagneTower(int poured, int query_row, int query_glass) {
		double res[101][101] = {};
		res[0][0]=poured;
		for (int i=0; i<100; ++i) {
			for (int j=0; j<=i; ++j) {
				if (res[i][j]>=1) {
					double left = res[i][j]-1;
					res[i+1][j]+=left/2;
					res[i+1][j+1]+=left/2;
					res[i][j]=1;
				}
			}
		}
		return res[query_row][query_glass];
	}
};

int main() {
	Solution s;
	cout << s.champagneTower(1,1,1) << endl;
	cout << s.champagneTower(2,1,1) << endl;
	cout << s.champagneTower(4,2,1) << endl;
}
