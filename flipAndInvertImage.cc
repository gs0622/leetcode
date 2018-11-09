#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (auto& row: A) {
			reverse(begin(row), end(row));
			for (auto& cell: row)
				cell = (cell==0)? 1:0;
		}
		return A;
	}
};
int main(){
	Solution s;
	vector<vector<int>> A1{{1,1,0},{1,0,1},{0,0,0}};
	vector<vector<int>> A2{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
	vector<vector<int>> res;
	res = s.flipAndInvertImage(A1);
	for (auto r: res) {
		for (auto c: r) cout << c << ' ';
		cout << '\t';
	}
	cout << endl;

	res = s.flipAndInvertImage(A2);
	for (auto r: res) {
		for (auto c: r) cout << c << ' ';
		cout << '\t';
	}
	cout << endl;
}

