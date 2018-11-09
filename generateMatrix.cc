/* https://leetcode.com/problems/spiral-matrix-ii/description/

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n==0) return vector<vector<int>>();	// n<0?
		vector<vector<int>> res(n, vector<int>(n));
		int i, v=1, r_left=n, c_left=n, rr=0, cc=-1;
		while (1) {
			for (i=0; i<c_left; ++i) res[rr][++cc] = v++;
			if (--r_left==0) break;

			for (i=0; i<r_left; ++i) res[++rr][cc] = v++;
			if (--c_left==0) break;

			for (i=0; i<c_left; ++i) res[rr][--cc] = v++;
			if (--r_left==0) break;

			for (i=0; i<r_left; ++i) res[--rr][cc] = v++;
			if (--c_left==0) break;
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> res = s.generateMatrix(3);
	for (auto r: res) {
		for (auto c: r) cout << c << " ";
		cout << endl;
	}
}
