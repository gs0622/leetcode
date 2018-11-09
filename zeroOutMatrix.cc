#include <bitset>
#include <iostream>
#include <vector>
#include <vector>
using namespace std;
class Solution {
public:
	void zero(vector<vector<int>>& m) {
		int i, j, n=m.size();
		bitset<16> cols, rows;
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j)
				if (m[i][j]==0)
					rows[i]=1, cols[j]=1;
		}
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				if (rows[i]==1) m[i][j]=0;
				if (cols[j]==1) m[i][j]=0;
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
	vector<vector<int>> m1{{1, 0, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
	s.dump(m1);
	s.zero(m1);
	s.dump(m1);
}
